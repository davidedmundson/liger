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
#ifndef POPULATIONENTRY_H
#define POPULATIONENTRY_H

#include <tigon/tigon_global.h>
#include <tigon/tigonconstants.h>
#include <tigon/Log/LogEntry.h>

namespace Tigon {
namespace Representation {
class ISet;
} // namespace Representation
namespace Log {

using namespace Tigon::Representation;

class LIGER_TIGON_EXPORT PopulationEntry : public LogEntry
{
public:
    PopulationEntry(ISet* pop);
    PopulationEntry(ISet* pop, const TString &name,
                    const Json::JsonObject &additinalFields);
    ~PopulationEntry();

private:
    PopulationEntry();
};

} // namespace Log
} // namespace Tigon

#endif // POPULATIONENTRY_H
