/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#ifndef POULISMASSAPORTVIEW_H
#define POULISMASSAPORTVIEW_H

#include "ui_poulismassaview.h"


/**
 * This class serves as the main window for poulismassaport.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author %{AUTHOR} <%{EMAIL}>
 * @version %{VERSION}
 */
class PoulisMassaPortView : public QWidget
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    explicit PoulisMassaPortView(QWidget *parent);

    /**
     * Default Destructor
     */
    ~PoulisMassaPortView() override;

public Q_SLOTS:
    void switchColors();
    void handleSettingsChanged();

private:
    // this is the name of the root widget inside our Ui file
    // you can rename it in designer and then change it here
    Ui::PoulisMassaPortView m_ui;
};

#endif // POULISMASSAPORTVIEW_H
