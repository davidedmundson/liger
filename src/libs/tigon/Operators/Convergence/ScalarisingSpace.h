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

#include <tigon/Operators/Convergence/IConvergence.h>
#include <tigon/tigon_global.h>

namespace Tigon {
namespace Operators {

class LIGER_TIGON_EXPORT ScalarisingSpace : public IConvergence
{
    HANDLE_READ_PROPERTIES_BEGIN(IConvergence)
    READ(ReferenceSetSize, TP_referenceSetSizeScalarisingSpace)
    HANDLE_READ_PROPERTIES_END

    HANDLE_WRITE_PROPERTIES_BEGIN(IConvergence)
    WRITE(ReferenceSetSize, int, TP_defineReferenceSetSizeScalarisingSpace)
    HANDLE_WRITE_PROPERTIES_END

    DECLARE_CLASS(Tigon::Operators::ScalarisingSpace)

public:
    ScalarisingSpace();
    ScalarisingSpace(Tigon::Representation::IPSet* ipset);
    ~ScalarisingSpace();

    void evaluateNode();

    // Information about the node.
    TString     name();
    TString     description();

    // Properties
    void TP_defineReferenceSetSizeScalarisingSpace(int s);
    int  TP_referenceSetSizeScalarisingSpace()      const;

private:
    void initialise();
    void createReferenceSet();
    TVector<double>           m_ideal;
    TVector<double>           m_antiIdeal;
    TVector<TVector<double> > m_initRefSet;
    int                       m_refSetSize;
};

} // namespace Operators
} // namespace Tigon
