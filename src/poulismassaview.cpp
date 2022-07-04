/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

// application headers
#include "poulismassaview.h"

#include "PoulisMassaSettings.h"
#include "poulismassadebug.h"


PoulisMassaPortView::PoulisMassaPortView(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);
    handleSettingsChanged();
}

PoulisMassaPortView::~PoulisMassaPortView()
{
}

void PoulisMassaPortView::switchColors()
{
    // switch the foreground/background colors of the label
    QColor color = PoulisMassaPortSettings::colorBackground();
    PoulisMassaPortSettings::setColorBackground(PoulisMassaPortSettings::colorForeground());
    PoulisMassaPortSettings::setColorForeground(color);

    handleSettingsChanged();
}

void PoulisMassaPortView::handleSettingsChanged()
{
    qCDebug(POULISMASSA) << "PoulisMassaPortView::handleSettingsChanged()";
    QPalette palette = m_ui.templateLabel->palette();
    palette.setColor(QPalette::Window, PoulisMassaPortSettings::colorBackground());
    palette.setColor(QPalette::WindowText, PoulisMassaPortSettings::colorForeground());
    m_ui.templateLabel->setPalette(palette);

    // i18n : internationalization
    m_ui.templateLabel->setText(i18n("This project is %1 days old", PoulisMassaPortSettings::ageInDays()));
}

