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
// Name:        catalog_volume.cpp
// Purpose:     
// Author:      
// Modified by: 
// Created:     31/12/2006 18:42:48
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 31/12/2006 18:42:48

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "catalog_volume.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include <wx/dir.h>
#include <wx/filename.h>
#include "catalog_volume.h"
#include "utils.h"
#include "data_interface/volumes.h"
#include "data_interface/paths.h"
#include "data_interface/files.h"
#include "data_interface/data_error.h"

#ifdef __WXMSW__
#include "windows_specific.h"
#endif

////@begin XPM images
////@end XPM images

/*!
 * CDialogCatalogVolume type definition
 */

IMPLEMENT_DYNAMIC_CLASS( CDialogCatalogVolume, wxDialog )

/*!
 * CDialogCatalogVolume event table definition
 */

BEGIN_EVENT_TABLE( CDialogCatalogVolume, wxDialog )

////@begin CDialogCatalogVolume event table entries
    EVT_TREE_SEL_CHANGED( wxID_TREECTRL, CDialogCatalogVolume::OnDirCtrlSelChanged )

    EVT_BUTTON( ID_GET_VOLUME_NAME, CDialogCatalogVolume::OnGetVolumeNameClick )

    EVT_BUTTON( ID_BUTTON_CATALOG, CDialogCatalogVolume::OnButtonCatalogClick )

////@end CDialogCatalogVolume event table entries

END_EVENT_TABLE()

/*!
 * CDialogCatalogVolume constructors
 */

CDialogCatalogVolume::CDialogCatalogVolume( )
{
    Init();
}

CDialogCatalogVolume::CDialogCatalogVolume( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}

/*!
 * Dialog creator
 */

bool CDialogCatalogVolume::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin CDialogCatalogVolume creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end CDialogCatalogVolume creation
    return true;
}

/*!
 * Member initialisation 
 */

void CDialogCatalogVolume::Init()
{
////@begin CDialogCatalogVolume member initialisation
    m_DirControl = NULL;
    m_VolumePath = NULL;
    m_VolumeName = NULL;
    m_CurrentFolder = NULL;
////@end CDialogCatalogVolume member initialisation
}
/*!
 * Control creation for Dialog
 */

void CDialogCatalogVolume::CreateControls()
{    
////@begin CDialogCatalogVolume content construction
    CDialogCatalogVolume* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText4 = new wxStaticText( itemDialog1, wxID_STATIC, _("Select the volume to catalog"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemStaticText4, 0, wxALIGN_LEFT|wxALL, 5);

    m_DirControl = new wxGenericDirCtrl( itemDialog1, ID_DIR_CTRL, _T(""), wxDefaultPosition, wxSize(-1, 150), wxDIRCTRL_DIR_ONLY, _T("All files (*.*)|*.*"), 0 );
    itemBoxSizer3->Add(m_DirControl, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText6 = new wxStaticText( itemDialog1, wxID_STATIC, _("You can also type the volume path"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemStaticText6, 0, wxALIGN_LEFT|wxALL, 5);

    m_VolumePath = new wxTextCtrl( itemDialog1, ID_VOLUME_PATH, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(m_VolumePath, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText8 = new wxStaticText( itemDialog1, wxID_STATIC, _("Volume name"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemStaticText8, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer9, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM, 5);

    m_VolumeName = new wxTextCtrl( itemDialog1, ID_VOLUME_NAME, _T(""), wxDefaultPosition, wxSize(200, -1), 0 );
    itemBoxSizer9->Add(m_VolumeName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton11 = new wxButton( itemDialog1, ID_GET_VOLUME_NAME, _("Get volume name"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer9->Add(itemButton11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer12, 0, wxGROW|wxTOP|wxBOTTOM, 5);

    wxButton* itemButton13 = new wxButton( itemDialog1, ID_BUTTON_CATALOG, _("Catalog"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer12->Add(itemButton13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer12->Add(5, 5, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton15 = new wxButton( itemDialog1, wxID_CANCEL, _("&Close"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer12->Add(itemButton15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CurrentFolder = new wxStaticText( itemDialog1, ID_CURRENT_FOLDER, _("Current folder"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(m_CurrentFolder, 0, wxGROW|wxALL|wxADJUST_MINSIZE, 5);

////@end CDialogCatalogVolume content construction

	m_CurrentFolder->SetLabel( "" );
}

/*!
 * Should we show tooltips?
 */

bool CDialogCatalogVolume::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap CDialogCatalogVolume::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin CDialogCatalogVolume bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end CDialogCatalogVolume bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon CDialogCatalogVolume::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin CDialogCatalogVolume icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end CDialogCatalogVolume icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_GET_VOLUME_NAME
 */

void CDialogCatalogVolume::OnGetVolumeNameClick( wxCommandEvent& event ) {
	event.Skip(false);	// to suppress a warning
#ifdef __WXMSW__
	wxString path = m_DirControl->GetPath();
	if( !path.EndsWith(wxT("\\")) )
		path += wxT("\\");
	wxString vn = GetVolumeName( path );
	m_VolumeName->SetValue( vn );
#endif
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CATALOG
 */

void CDialogCatalogVolume::OnButtonCatalogClick( wxCommandEvent& event )
{
	event.Skip(false);	// to suppress a warning
	
	wxString path = m_VolumePath->GetValue();
	if( path == "" ) {
		CUtils::MsgErr( _("The volume path is missing") );
		return;
	}
	wxString vn = m_VolumeName->GetValue();
	if( vn == "" ) {
		CUtils::MsgErr( _("The volume name is missing") );
		return;
	}

	wxCursor curCursor = GetCursor();
	SetCursor(wxCursor(wxCURSOR_WAIT));

	// starts a transaction
	CBaseDB* db = CBaseDB::GetDatabase();
	db->TransactionStart();

	wxFileName dirName( path, wxEmptyString );

	// writes the volume row
	CVolumes vol;
	vol.VolumeName = vn;
	try {
		vol.DbInsert();
	}
	catch( CDataErrorException& e ) {
		if( e.GetErrorCause() == CDataErrorException::Unique ) {
			SetCursor(curCursor);
			CUtils::MsgErr( _("This volume name is already present in the database") );
			return;
		}
		else
			throw;
	}

	// catalogs the folders
	CNullableLong FatherID;
	FatherID.SetNull(true);
	CatalogSingleFolder( db, path, vol.VolumeID, FatherID, NULL );

	// commits the transaction
	db->TransactionCommit();

	m_VolumeName->SetValue( wxT("") );
	m_CurrentFolder->SetLabel( "" );
	SetCursor(curCursor);
}


void CDialogCatalogVolume::CatalogSingleFolder( CBaseDB* db, wxString path, long VolumeID, CNullableLong& FatherID, CFiles* PathFile  ) {
	wxString fileName;

	// shows the path in the dialog box
	m_CurrentFolder->SetLabel( path );

	// writes the path row
	wxFileName dirName( path, wxEmptyString );
	CPaths pth;
	pth.VolumeID = VolumeID;
	pth.PathName = dirName.GetPath(0);
	pth.PathName = pth.PathName.AfterLast( wxFileName::GetPathSeparator() );	// only takes the last part of the full path
	pth.FatherID = FatherID;
	pth.DbInsert();

	// adds the path id and stores the FILES info about this folder
	if( PathFile != NULL ) {
		PathFile->PathFileID = pth.PathID;
		PathFile->DbInsert();
	}

	// reads all file names
	wxDir dir(path);
	bool cont = dir.GetFirst(&fileName, wxT(""), wxDIR_FILES );
	while( cont ) {
		// stores the file row
		wxFileName fn( path, fileName );
		CFiles file;
		file.FileName = fileName;
		file.FileExt = fn.GetExt();
		file.DateTime = fn.GetModificationTime();
		file.FileSize = fn.GetSize();
		file.PathID = pth.PathID;
		file.PathFileID.SetNull(true);
		file.DbInsert();

		cont = dir.GetNext(&fileName);
	}

	// now reads all the subfolders
	cont = dir.GetFirst(&fileName, wxT(""), wxDIR_DIRS );
	while( cont ) {
		wxFileName dirName( path, wxEmptyString );
		dirName.AppendDir( fileName );

		// stores the folder as a file to simplify data retrieval
		CFiles file;
		file.FileName = fileName;
		file.FileExt = "";
		file.DateTime = dirName.GetModificationTime();
		file.FileSize = 0;
		file.PathID = pth.PathID;
//		file.DbInsert();

		CatalogSingleFolder( db, dirName.GetPath(), VolumeID, pth.PathID, &file );
		cont = dir.GetNext(&fileName);
	}

}

/*!
 * wxEVT_COMMAND_TREE_SEL_CHANGED event handler for ID_DIR_CTRL
 */

void CDialogCatalogVolume::OnDirCtrlSelChanged( wxTreeEvent& WXUNUSED(event) )
{
	// copies the selected path to the text box
	wxString p = m_DirControl->GetPath();
	if( !p.empty() ) {
		m_VolumePath->SetValue( p );
	}
}

