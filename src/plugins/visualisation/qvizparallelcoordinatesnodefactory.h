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
#ifndef QVIZPARALLELCOORDINATESNODEFACTORY_H
#define QVIZPARALLELCOORDINATESNODEFACTORY_H
#include <visualisation/visualisation_global.h>
#include <visualisation/qvizparallelcoordinatesnode.h>

#include <designer/iengine/iprocessnodefactory.h>

#include <QToolButton>
#include <QObject>

namespace Designer {
class IProcessNode;
}

namespace Visualisation {

class VISUALISATION_EXPORT QvizParallelCoordinatesNodeFactory : public Designer::IProcessNodeFactory
{
    Q_OBJECT

public:
    QvizParallelCoordinatesNodeFactory();

    Designer::IProcessNode* createProcessNode();
    QString className() { return QString("Visualisation::QvizParallelCoordinatesNode"); }
    bool isSelected();
    void unSelect();

private:
    QToolButton* m_toolBoxButton;
};

} // namespace Visualisation


#endif // QVIZPARALLELCOORDINATESNODEFACTORY_H
