/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#ifndef POULISMASSAPORTWINDOW_H
#define POULISMASSAPORTWINDOW_H

#include <KXmlGuiWindow>

#include "ui_settings.h"
#include "PoulisMassaSettings.h"

class PoulisMassaPortView;

/**
 * This class serves as the main window for poulismassaport.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author %{AUTHOR} <%{EMAIL}>
 * @version %{VERSION}
 */
class PoulisMassaPortWindow : public KXmlGuiWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    PoulisMassaPortWindow();

    /**
     * Default Destructor
     */
    ~PoulisMassaPortWindow() override;

private Q_SLOTS:
    /**
     * Create a new window
     */
    void fileNew();

    /**
     * Open the settings dialog
     */
    void settingsConfigure();

private:
    // this is the name of the root widget inside our Ui file
    // you can rename it in designer and then change it here
    Ui::Settings m_settings;
    QAction *m_switchAction;
    PoulisMassaPortView *m_poulismassaportView;
};

#endif // POULISMASSAPORTWINDOW_H
