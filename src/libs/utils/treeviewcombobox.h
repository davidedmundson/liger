/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef TREEVIEWCOMBOBOX_H
#define TREEVIEWCOMBOBOX_H

#include "utils_global.h"

#include <QComboBox>
#include <QTreeView>

namespace Utils {

class LIGER_UTILS_EXPORT TreeViewComboBoxView : public QTreeView
{
    Q_OBJECT
public:
    TreeViewComboBoxView(QWidget *parent = 0);
    void adjustWidth(int width);
};

class LIGER_UTILS_EXPORT TreeViewComboBox : public QComboBox
{
    Q_OBJECT
public:
    TreeViewComboBox(QWidget *parent = 0);

    void wheelEvent(QWheelEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void setCurrentIndex(const QModelIndex &index);
    bool eventFilter(QObject* object, QEvent* event);
    void showPopup();
    void hidePopup();

    TreeViewComboBoxView *view() const;

private:
    QModelIndex indexBelow(QModelIndex index);
    QModelIndex indexAbove(QModelIndex index);
    QModelIndex lastIndex(const QModelIndex &index);

    TreeViewComboBoxView *m_view;
    bool m_skipNextHide;
};
}

#endif // TREEVIEWCOMBOBOX_H
