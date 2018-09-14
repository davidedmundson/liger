/****************************************************************************
**
** Copyright (C) 2012-2018 The University of Sheffield (www.sheffield.ac.uk)
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
****************************************************************************/
#include <qtigon/operators/initialisations/qoplhsinitnode.h>
#include <qtigon/dialogs/qoperatordiag.h>
#include <qtigon/qtigonutils.h>

#include <designer/iengine/iport.h>
#include <designer/iengine/iportlink.h>
#include <designer/iengine/inputport.h>
#include <designer/iengine/outputport.h>

#include <coreplugin/coreconstants.h>
#include <coreplugin/messagemanager.h>
#include <coreplugin/editormanager/editormanager.h>
#include <coreplugin/icore.h>

#include <tigon/Tigon.h>
using Tigon::TObject;

#include <QFile>
#include <QColor>
#include <QMessageBox>
#include <QString>

#include <QDebug>

using namespace QTigon;
using namespace Designer;
using namespace Tigon::Operators;

QOpLHSInitNode::QOpLHSInitNode()
    : m_dialog(new QOperatorDiag)
{
    m_text         = QString("C");
    m_procType     = OPERATOR_NODE;
    m_outlineColor = Qt::darkBlue;
    m_backgroundColor = Qt::white;
    setNumberOfOutputs(1);
    setNumberOfInputs(1);
    setData(new LHSInit);

    QFile img_file(":/qtigon/images/qoplhsinitnode.svg");
    if(img_file.exists()) {
        setSvg(":/qtigon/images/qoplhsinitnode.svg");
    } else {
        setSvg(":/qtigon/images/default_qopnode.svg");
    }
    img_file.close();

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);

    initializeNode();
    connect(m_dialog, SIGNAL(opDataChanged()),
            this, SIGNAL(nodePropertiesChangedSignal()));       
}

QOpLHSInitNode::~QOpLHSInitNode()
{
    delete m_dialog;
}

void QOpLHSInitNode::updateProcessState(ProcessState state)
{
    switch(state) {
    case Designer::ProcessState::NODE_RUNNING:
        m_dialog->setInputDisabled();
        break;
    case Designer::ProcessState::NODE_DONE:
        m_dialog->setInputDisabled(false);
        break;
    default:
        m_dialog->setInputDisabled(false);
        break;
    }
    IProcessNode::updateProcessState(state);
}

void QOpLHSInitNode::readDataProperties(QXmlStreamReader &xmlReader)
{
    xmlReader.readNextStartElement(); //todo remove
    TObject* thisOp = static_cast<TObject*>(data());
    while(!xmlReader.isEndElement() || !(xmlReader.name() == "Properties")) {
        xmlReader.readNext();
        if(xmlReader.isStartElement()) {
            if(xmlReader.name() != "TigonOperator") {
                assignPropertyToObject(thisOp, &xmlReader);
            }
        }
    }
}

void QOpLHSInitNode::writeDataProperties(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeAttribute("ProcessType", "OPERATOR_NODE");
    TObject* thisOp = static_cast<TObject*>(data());
    xmlWriter.writeTextElement("TigonOperator",
                               QString::fromStdString(thisOp->className()));
    propertiesToXml(thisOp, &xmlWriter);
}

void QOpLHSInitNode::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    LHSInit* thisOp = static_cast<LHSInit*>(data());
    if(thisOp) {
        m_dialog->setup(thisOp);
        m_dialog->show();
        m_dialog->raise();
    }
}