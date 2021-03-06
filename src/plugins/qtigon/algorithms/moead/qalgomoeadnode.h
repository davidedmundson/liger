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
#pragma once 

#include <qtigon/qtigon_global.h>
#include <qtigon/qtigonconstants.h>
#include <qtigon/dialogs/qalgorithmdialog.h>
#include <designer/iengine/iprocessnode.h>

#include <QObject>

namespace QTigon {

class QAlgoMOEADNode : public Designer::IProcessNode
{
    Q_OBJECT

public:
    QAlgoMOEADNode();
    ~QAlgoMOEADNode();
    void updateProcessState(Designer::ProcessState state);

protected:
	void readDataProperties(QXmlStreamReader &xmlReader);
	void writeDataProperties(QXmlStreamWriter &xmlWriter);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    QAlgorithmDialog* m_dialog;
};

} // namespace QTigon