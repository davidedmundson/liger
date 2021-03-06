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
#ifndef EXAMPLEINITIALISATION_H
#define EXAMPLEINITIALISATION_H
#include <tigon/Operators/Initialisation/IInitialisation.h>

namespace Tigon {
namespace Operators {

class LIGER_TIGON_EXPORT ExampleInitialisation : public IInitialisation
{
    Q_OBJECT

public:
    ExampleInitialisation();
    ExampleInitialisation(Tigon::Representation::IPSet* ipset);
    virtual ~ExampleInitialisation();

    void evaluateNode();

    // Information about the node.
    QString     name();
    QString     description();
    QStringList propertyNames();
    QStringList propertyDescriptions();

private:


};

} // namespace Operators
} // namespace Tigon

#endif // EXAMPLEINITIALISATION_H
