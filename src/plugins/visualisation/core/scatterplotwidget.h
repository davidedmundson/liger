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
#ifndef SCATTERPLOTWIDGET_H
#define SCATTERPLOTWIDGET_H
#include <visualisation/core/visualisationwidget.h>
#include <tigon/Representation/Elements/IElement.h>

#include <QObject>

QT_BEGIN_NAMESPACE
class QComboBox;
QT_END_NAMESPACE

namespace Visualisation {

class ScatterPlotWidget : public VisualisationWidget
{
    Q_OBJECT

public:
    explicit ScatterPlotWidget(QWidget *parent = 0);
    ~ScatterPlotWidget();
    void initialise();
    void setSelectedIndices(const QVariantList& selected);
    void setXLabels(const QStringList &xlabels);
    void setYLabels(const QStringList &ylabels);

public slots:
    void updateSelectedIndices();

protected:
    void showVariableSelectionForm();

private:
    QComboBox*   m_xcombo;
    QComboBox*   m_ycombo;
};

}

#endif // SCATTERPLOTWIDGET_H
