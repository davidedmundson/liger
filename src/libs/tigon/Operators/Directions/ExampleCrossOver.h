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
#ifndef EXAMPLECROSSOVER_H
#define EXAMPLECROSSOVER_H
#include <tigon/Operators/Directions/IDirection.h>

namespace Tigon {
namespace Operators {

class LIGER_TIGON_EXPORT ExampleCrossOver : public IDirection
{
    Q_OBJECT

public:
    ExampleCrossOver();
    ExampleCrossOver(Tigon::Representation::IPSet* ipset);
    virtual ~ExampleCrossOver();

    void evaluateNode();

    // Information about the node.
    QString     name();
    QString     description();

    // Properties
    QStringList propertyNames();
    QStringList propertyDescriptions();

private:
    void initialise();
    QString m_name;
    QString m_description;
};

} // namespace Operators
} // namespace Tigon

#endif // EXAMPLECROSSOVER_H
