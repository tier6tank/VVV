/*
	This file is part of VVV (Virtual Volumes View)

	Copyright (C) 2007, the VVV Development team

	Author: Fulvio Senore

    VVV is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    VVV is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with VVV; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/////////////////////////////////////////////////////////////////////////////
// Name:        catalog_volume.h
// Purpose:     
// Author:      
// Modified by: 
// Created:     31/12/2006 18:42:48
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 31/12/2006 18:42:48

#ifndef _CATALOG_VOLUME_H_
#define _CATALOG_VOLUME_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "catalog_volume.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/dirctrl.h"
////@end includes

#include <wx/stattext.h>
#include "data_interface/base_db.h"
#include "data_interface/db_null.h"
#include "data_interface/files.h"
#include "window_position.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxGenericDirCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG_CATALOG_VOLUME 10002
#define ID_DIR_CTRL 10007
#define ID_VOLUME_PATH 10023
#define ID_VOLUME_NAME 10008
#define ID_GET_VOLUME_NAME 10009
#define ID_BUTTON_CATALOG 10010
#define ID_CURRENT_FOLDER 10024
#define SYMBOL_CDIALOGCATALOGVOLUME_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_CDIALOGCATALOGVOLUME_TITLE _("Catalog volume")
#define SYMBOL_CDIALOGCATALOGVOLUME_IDNAME ID_DIALOG_CATALOG_VOLUME
#define SYMBOL_CDIALOGCATALOGVOLUME_SIZE wxSize(400, 300)
#define SYMBOL_CDIALOGCATALOGVOLUME_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * CDialogCatalogVolume class declaration
 */

class CDialogCatalogVolume: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( CDialogCatalogVolume )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    CDialogCatalogVolume( );
    CDialogCatalogVolume( wxWindow* parent, wxWindowID id = SYMBOL_CDIALOGCATALOGVOLUME_IDNAME, const wxString& caption = SYMBOL_CDIALOGCATALOGVOLUME_TITLE, const wxPoint& pos = SYMBOL_CDIALOGCATALOGVOLUME_POSITION, const wxSize& size = SYMBOL_CDIALOGCATALOGVOLUME_SIZE, long style = SYMBOL_CDIALOGCATALOGVOLUME_STYLE );

	// destructor
    ~CDialogCatalogVolume( );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_CDIALOGCATALOGVOLUME_IDNAME, const wxString& caption = SYMBOL_CDIALOGCATALOGVOLUME_TITLE, const wxPoint& pos = SYMBOL_CDIALOGCATALOGVOLUME_POSITION, const wxSize& size = SYMBOL_CDIALOGCATALOGVOLUME_SIZE, long style = SYMBOL_CDIALOGCATALOGVOLUME_STYLE );

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin CDialogCatalogVolume event handler declarations

    /// wxEVT_COMMAND_TREE_SEL_CHANGED event handler for ID_DIR_CTRL
    void OnDirCtrlSelChanged( wxTreeEvent& event );

#if defined(__WXMSW__)
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_GET_VOLUME_NAME
    void OnGetVolumeNameClick( wxCommandEvent& event );

#endif
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CATALOG
    void OnButtonCatalogClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
    void OnHelpClick( wxCommandEvent& event );

////@end CDialogCatalogVolume event handler declarations

////@begin CDialogCatalogVolume member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end CDialogCatalogVolume member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin CDialogCatalogVolume member variables
    wxGenericDirCtrl* m_DirControl;
    wxTextCtrl* m_VolumePath;
    wxTextCtrl* m_VolumeName;
    wxStaticText* m_CurrentFolder;
////@end CDialogCatalogVolume member variables

private:

	// catalogs the files in a folder and recursively
	// calls itself for each subfolder
	// PathFile contains the data of the file that will store data about the current folder (if not NULL)
	//   each instance of this method will add the ID oof the path and it will save it in the database
	void CatalogSingleFolder( CBaseDB* db, wxString path, long VolumeID, CNullableLong& FatherID, CFiles* PathFile );

	CWindowPosition m_WindowPosition;

	// Windows-specific version because the standard one was rather slow
#ifdef __WXMSW__
	void CatalogSingleFolderWindows( CBaseDB* db, wxString path, long VolumeID, CNullableLong& FatherID, CFiles* PathFile );
#endif

};

#endif
    // _CATALOG_VOLUME_H_
