/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

// application headers
#include "poulismassawindow.h"

#include "poulismassaview.h"
#include "poulismassadebug.h"

// KF headers
#include <KActionCollection>
#include <KConfigDialog>


PoulisMassaPortWindow::PoulisMassaPortWindow()
    : KXmlGuiWindow()
{
    m_poulismassaportView = new PoulisMassaPortView(this);
    setCentralWidget(m_poulismassaportView);

    KActionCollection* actionCollection = this->actionCollection();
    m_switchAction = actionCollection->addAction(QStringLiteral("switch_action"));
    m_switchAction->setText(i18nc("@action", "Switch Colors"));
    m_switchAction->setIcon(QIcon::fromTheme(QStringLiteral("fill-color")));
    connect(m_switchAction, &QAction::triggered, m_poulismassaportView, &PoulisMassaPortView::switchColors);

    KStandardAction::openNew(this, SLOT(fileNew()), actionCollection);
    KStandardAction::quit(qApp, SLOT(closeAllWindows()), actionCollection);
    KStandardAction::preferences(this, SLOT(settingsConfigure()), actionCollection);

    setupGUI();
}

PoulisMassaPortWindow::~PoulisMassaPortWindow()
{
}

void PoulisMassaPortWindow::fileNew()
{
    qCDebug(POULISMASSA) << "PoulisMassaPortWindow::fileNew()";
    (new PoulisMassaPortWindow)->show();
}

void PoulisMassaPortWindow::settingsConfigure()
{
    qCDebug(POULISMASSA) << "PoulisMassaPortWindow::settingsConfigure()";
    // The preference dialog is derived from prefs_base.ui
    //
    // compare the names of the widgets in the .ui file
    // to the names of the variables in the .kcfg file
    //avoid to have 2 dialogs shown
    if (KConfigDialog::showDialog(QStringLiteral("settings"))) {
        return;
    }

    KConfigDialog *dialog = new KConfigDialog(this, QStringLiteral("settings"), PoulisMassaPortSettings::self());
    QWidget *generalSettingsPage = new QWidget;
    m_settings.setupUi(generalSettingsPage);
    dialog->addPage(generalSettingsPage, i18nc("@title:tab", "General"), QStringLiteral("package_setting"));
    connect(dialog, &KConfigDialog::settingsChanged, m_poulismassaportView, &PoulisMassaPortView::handleSettingsChanged);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}
