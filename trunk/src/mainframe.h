/*
	This file is part of VVV (Virtual Volumes View)

	Copyright (C) 2007, the VVV Development team

	Author: Fulvio Senore

    VVV is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with VVV; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/////////////////////////////////////////////////////////////////////////////
// Name:        mainframe.h
// Purpose:     
// Author:      
// Modified by: 
// Created:     29/12/2006 12:41:00
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 29/12/2006 12:41:00

#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "mainframe.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
#include "wx/statusbr.h"
#include "wx/splitter.h"
#include "wx/treectrl.h"
#include "wx/listctrl.h"
////@end includes

#include "data_interface/volumes.h"
#include "data_interface/paths.h"
#include "data_interface/files.h"
#include "data_interface/virtual_paths.h"
#include "data_interface/virtual_files.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_MAIN_FRAME 10000
#define ID_CATALOG_VOLUME 10001
#define ID_VIEW_PHYSICAL 10011
#define ID_VIEW_VIRTUAL 10012
#define ID_STATUSBAR1 10004
#define ID_SPLITTERWINDOW1 10003
#define ID_TREE_CONTROL 10005
#define ID_LIST_CONTROL 10006
#define SYMBOL_CMAINFRAME_STYLE wxDEFAULT_FRAME_STYLE|wxCAPTION
#define SYMBOL_CMAINFRAME_TITLE _("VVV")
#define SYMBOL_CMAINFRAME_IDNAME ID_MAIN_FRAME
#define SYMBOL_CMAINFRAME_SIZE wxSize(400, 300)
#define SYMBOL_CMAINFRAME_POSITION wxDefaultPosition
////@end control identifiers
#define ID_TREE_CONTROL_VIRTUAL 10007

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * CMainFrame class declaration
 */

class CMainFrame: public wxFrame
{    
    DECLARE_CLASS( CMainFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    CMainFrame( );
    CMainFrame( wxWindow* parent, wxWindowID id = SYMBOL_CMAINFRAME_IDNAME, const wxString& caption = SYMBOL_CMAINFRAME_TITLE, const wxPoint& pos = SYMBOL_CMAINFRAME_POSITION, const wxSize& size = SYMBOL_CMAINFRAME_SIZE, long style = SYMBOL_CMAINFRAME_STYLE );

	virtual ~CMainFrame();

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_CMAINFRAME_IDNAME, const wxString& caption = SYMBOL_CMAINFRAME_TITLE, const wxPoint& pos = SYMBOL_CMAINFRAME_POSITION, const wxSize& size = SYMBOL_CMAINFRAME_SIZE, long style = SYMBOL_CMAINFRAME_STYLE );

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin CMainFrame event handler declarations

    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_OPEN
    void OnOPENClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT
    void OnEXITClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_CATALOG_VOLUME
    void OnCatalogVolumeClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_VIEW_PHYSICAL
    void OnViewPhysicalClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_VIEW_VIRTUAL
    void OnViewVirtualClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_TREE_SEL_CHANGED event handler for ID_TREE_CONTROL
    void OnTreeControlSelChanged( wxTreeEvent& event );

    /// wxEVT_COMMAND_TREE_ITEM_EXPANDING event handler for ID_TREE_CONTROL
    void OnTreeControlItemExpanding( wxTreeEvent& event );

////@end CMainFrame event handler declarations

////@begin CMainFrame member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end CMainFrame member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin CMainFrame member variables
////@end CMainFrame member variables

    /// wxEVT_COMMAND_TREE_ITEM_EXPANDING event handler for ID_TREE_CONTROL_VIRTUAL
    void OnTreeControlVirtualItemExpanding( wxTreeEvent& event );

    /// wxEVT_COMMAND_TREE_SEL_CHANGED event handler for ID_TREE_CONTROL_VIRTUAL
    void OnTreeControlVirtualSelChanged( wxTreeEvent& event );

private:

	// fills the physical tree control
	void LoadTreeControl(void);
	// loads a volume and its folders in the tree control
	void LoadVolumeInTreeControl( CVolumes vol, wxTreeCtrl* tctl, wxTreeItemId rootID);
	// loads a folder in the tree control, adding its subfolder to be able to show the "+" near folders with subfolders
	void LoadFolderInTreeControl( long VolumeID, wxTreeCtrl* tctl, wxTreeItemId fatherTreeID, long fatherID);

	// fills the virtual tree control
	void LoadVirtualTreeControl(void);
	void LoadVirtualFolderInTreeControl( wxTreeCtrl* tctl, wxTreeItemId fatherTreeID, long fatherID);

	// create the headers for the list control in report mode
	void CreateListControlHeaders(void);
};

#endif
    // _MAINFRAME_H_
