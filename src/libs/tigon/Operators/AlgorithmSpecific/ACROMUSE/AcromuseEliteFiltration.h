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
#ifndef ACROMUSEELITEFiltration_H
#define ACROMUSEELITEFiltration_H
#include <tigon/Operators/Filtrations/IFiltration.h>
#include <tigon/tigon_global.h>

namespace Tigon {
namespace Operators {

class LIGER_TIGON_EXPORT AcromuseEliteFiltration : public IFiltration
{

public:
    AcromuseEliteFiltration();
    AcromuseEliteFiltration(Tigon::Representation::IPSet* ipset);
    virtual ~AcromuseEliteFiltration();

    void evaluateNode();

    // Information about the node.
    TString     name();
    TString     description();

    // Properties

protected:
    void initialise();
    TString m_name;
    TString m_description;

};

} // namespace Operators
} // namespace Tigon

#endif // ACROMUSEELITEFiltration_H
