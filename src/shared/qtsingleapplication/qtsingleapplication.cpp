/****************************************************************************
**
** Copyright (C) 2012-2017 The University of Sheffield (www.sheffield.ac.uk)
**
** This file is part of Liger.
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General 
** Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** This is a modified version of qtsingleapplication.cpp from Qt Creator version 2.6.81
** Filename: qtsingleapplication.cpp 
** Path:     QTC_ROOT/src/shared/qtsingleapplication 
** Date:     11/11/2012
**
****************************************************************************/

#include "qtsingleapplication.h"
#include "qtlocalpeer.h"

#include <qtlockedfile.h>

#include <QDir>
#include <QFileOpenEvent>
#include <QSharedMemory>
#include <QWidget>

namespace SharedTools {

static const int instancesSize = 1024;

static QString instancesLockFilename(const QString &appSessionId)
{
    const QChar slash(QLatin1Char('/'));
    QString res = QDir::tempPath();
    if (!res.endsWith(slash))
        res += slash;
    return res + appSessionId + QLatin1String("-instances");
}

QtSingleApplication::QtSingleApplication(const QString &appId, int &argc, char **argv)
    : QApplication(argc, argv),
      firstPeer(-1),
      pidPeer(0)
{
    this->appId = appId;

    const QString appSessionId = QtLocalPeer::appSessionId(appId);

    // This shared memory holds a zero-terminated array of active (or crashed) instances
    instances = new QSharedMemory(appSessionId, this);
    actWin = 0;
    block = false;

    // First instance creates the shared memory, later instances attach to it
    const bool created = instances->create(instancesSize);
    if (!created) {
        if (!instances->attach()) {
            qWarning() << "Failed to initialize instances shared memory: "
                       << instances->errorString();
            delete instances;
            instances = 0;
            return;
        }
    }

    // QtLockedFile is used to workaround QTBUG-10364
    QtLockedFile lockfile(instancesLockFilename(appSessionId));

    lockfile.open(QtLockedFile::ReadWrite);
    lockfile.lock(QtLockedFile::WriteLock);
    qint64 *pids = static_cast<qint64 *>(instances->data());
    if (!created) {
        // Find the first instance that it still running
        // The whole list needs to be iterated in order to append to it
        for (; *pids; ++pids) {
            if (firstPeer == -1 && isRunning(*pids))
                firstPeer = *pids;
        }
    }
    // Add current pid to list and terminate it
    *pids++ = QCoreApplication::applicationPid();
    *pids = 0;
    pidPeer = new QtLocalPeer(this, appId + QLatin1Char('-') +
                              QString::number(QCoreApplication::applicationPid()));
    connect(pidPeer, SIGNAL(messageReceived(QString,QObject*)), SIGNAL(messageReceived(QString,QObject*)));
    pidPeer->isClient();
    lockfile.unlock();
}

QtSingleApplication::~QtSingleApplication()
{
    if (!instances)
        return;
    const qint64 appPid = QCoreApplication::applicationPid();
    QtLockedFile lockfile(instancesLockFilename(QtLocalPeer::appSessionId(appId)));
    lockfile.open(QtLockedFile::ReadWrite);
    lockfile.lock(QtLockedFile::WriteLock);
    // Rewrite array, removing current pid and previously crashed ones
    qint64 *pids = static_cast<qint64 *>(instances->data());
    qint64 *newpids = pids;
    for (; *pids; ++pids) {
        if (*pids != appPid && isRunning(*pids))
            *newpids++ = *pids;
    }
    *newpids = 0;
    lockfile.unlock();
}

bool QtSingleApplication::event(QEvent *event)
{
    if (event->type() == QEvent::FileOpen) {
        QFileOpenEvent *foe = static_cast<QFileOpenEvent*>(event);
        emit fileOpenRequest(foe->file());
        return true;
    }
    return QApplication::event(event);
}

bool QtSingleApplication::isRunning(qint64 pid)
{
    if (pid == -1) {
        pid = firstPeer;
        if (pid == -1)
            return false;
    }

    QtLocalPeer peer(this, appId + QLatin1Char('-') + QString::number(pid, 10));
    return peer.isClient();
}

bool QtSingleApplication::sendMessage(const QString &message, int timeout, qint64 pid)
{
    if (pid == -1) {
        pid = firstPeer;
        if (pid == -1)
            return false;
    }

    QtLocalPeer peer(this, appId + QLatin1Char('-') + QString::number(pid, 10));
    return peer.sendMessage(message, timeout, block);
}

QString QtSingleApplication::applicationId() const
{
    return appId;
}

void QtSingleApplication::setBlock(bool value)
{
    block = value;
}

void QtSingleApplication::setActivationWindow(QWidget *aw, bool activateOnMessage)
{
    actWin = aw;
    if (!pidPeer)
        return;
    if (activateOnMessage)
        connect(pidPeer, SIGNAL(messageReceived(QString,QObject*)), this, SLOT(activateWindow()));
    else
        disconnect(pidPeer, SIGNAL(messageReceived(QString,QObject*)), this, SLOT(activateWindow()));
}


QWidget* QtSingleApplication::activationWindow() const
{
    return actWin;
}


void QtSingleApplication::activateWindow()
{
    if (actWin) {
        actWin->setWindowState(actWin->windowState() & ~Qt::WindowMinimized);
        actWin->raise();
        actWin->activateWindow();
    }
}

} // namespace SharedTools
