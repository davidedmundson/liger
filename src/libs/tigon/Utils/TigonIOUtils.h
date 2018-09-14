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
#ifndef TIGONIOUTILS_H
#define TIGONIOUTILS_H

#include <tigon/tigon_global.h>
#include <tigon/tigonconstants.h>

#include <tigon/Core/TString.h>

namespace Tigon {

LIGER_TIGON_EXPORT TString readAll(const TString &file);
LIGER_TIGON_EXPORT bool writeToFile(const TString& content, const TString& file);
LIGER_TIGON_EXPORT bool removeFile(const TString& file);

}
#endif // TIGONIOUTILS_H