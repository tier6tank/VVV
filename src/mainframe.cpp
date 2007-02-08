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
// Name:        mainframe.cpp
// Purpose:     
// Author:      
// Modified by: 
// Created:     29/12/2006 12:41:00
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 29/12/2006 12:41:00

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "mainframe.h"
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
#include "catalog_volume.h"
////@end includes

#include "wx/filename.h"
#include "mainframe.h"

////@begin XPM images
////@end XPM images

#include "graphics/folder_closed.xpm"
#include "graphics/folder_opened.xpm"
#include "graphics/removable.xpm"
#include "graphics/deffile.xpm"


////////////////////////////////////////////////////////////////
// class to hold tree item data
////////////////////////////////////////////////////////////////

class MyTreeItemData : public wxTreeItemData {
public:
	MyTreeItemData( const wxString& desc, long VolumeID, long PathID, bool IsVolume ) : 
	                m_desc(desc), m_VolumeID(VolumeID), m_PathID(PathID), m_IsVolume(IsVolume), m_AlreadyOpened(false) {}
	const wxString& GetDesc() const { return m_desc; }
	long GetVolumeID(void) { return m_VolumeID; }
	long GetPathID(void) { return m_PathID; }
	bool IsVolume(void) { return m_IsVolume; }
	bool AlreadyOpened(void) { return m_AlreadyOpened; }
	void SetAlreadyOpened(void) { m_AlreadyOpened = true; }
private:
	wxString m_desc;
	long m_VolumeID, m_PathID;
	bool m_IsVolume;	// true if this node is a volume and not a folder
	bool m_AlreadyOpened;	// true if this node has already been opened
};





/*!
 * CMainFrame type definition
 */

IMPLEMENT_CLASS( CMainFrame, wxFrame )

/*!
 * CMainFrame event table definition
 */

BEGIN_EVENT_TABLE( CMainFrame, wxFrame )

////@begin CMainFrame event table entries
    EVT_MENU( wxID_OPEN, CMainFrame::OnOPENClick )

    EVT_MENU( wxID_EXIT, CMainFrame::OnEXITClick )

    EVT_MENU( ID_CATALOG_VOLUME, CMainFrame::OnCatalogVolumeClick )

    EVT_TREE_SEL_CHANGED( ID_TREE_CONTROL, CMainFrame::OnTreeControlSelChanged )
    EVT_TREE_ITEM_EXPANDING( ID_TREE_CONTROL, CMainFrame::OnTreeControlItemExpanding )

////@end CMainFrame event table entries

END_EVENT_TABLE()

/*!
 * CMainFrame constructors
 */

CMainFrame::CMainFrame( )
{
    Init();
}

CMainFrame::CMainFrame( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
}

/*!
 * Prova creator
 */

bool CMainFrame::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin CMainFrame creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    Centre();
////@end CMainFrame creation
    return true;
}

/*!
 * Member initialisation 
 */

void CMainFrame::Init()
{
////@begin CMainFrame member initialisation
////@end CMainFrame member initialisation
}
/*!
 * Control creation for Prova
 */

void CMainFrame::CreateControls()
{    
////@begin CMainFrame content construction
    // Generated by DialogBlocks, 07/02/2007 21:05:51 (unregistered)

    CMainFrame* itemFrame1 = this;

    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* itemMenu3 = new wxMenu;
    itemMenu3->Append(wxID_OPEN, _("Open"), _T(""), wxITEM_NORMAL);
    itemMenu3->AppendSeparator();
    itemMenu3->Append(wxID_EXIT, _("Exit"), _T(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu3, _("File"));
    wxMenu* itemMenu7 = new wxMenu;
    itemMenu7->Append(ID_CATALOG_VOLUME, _("Catalog volume"), _T(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu7, _("Volumes"));
    itemFrame1->SetMenuBar(menuBar);

    wxStatusBar* itemStatusBar9 = new wxStatusBar( itemFrame1, ID_STATUSBAR1, wxST_SIZEGRIP );
    itemStatusBar9->SetFieldsCount(2);
    itemFrame1->SetStatusBar(itemStatusBar9);

    wxSplitterWindow* itemSplitterWindow10 = new wxSplitterWindow( itemFrame1, ID_SPLITTERWINDOW1, wxDefaultPosition, wxSize(100, 100), wxSP_3DBORDER|wxSP_3DSASH|wxSP_NO_XP_THEME|wxNO_BORDER );
    itemSplitterWindow10->SetMinimumPaneSize(0);

    wxTreeCtrl* itemTreeCtrl11 = new wxTreeCtrl( itemSplitterWindow10, ID_TREE_CONTROL, wxDefaultPosition, wxSize(100, 100), wxTR_HAS_BUTTONS |wxTR_HIDE_ROOT|wxTR_SINGLE|wxNO_BORDER|wxTR_DEFAULT_STYLE );

    wxListCtrl* itemListCtrl12 = new wxListCtrl( itemSplitterWindow10, ID_LIST_CONTROL, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT|wxNO_BORDER );

    itemSplitterWindow10->SplitVertically(itemTreeCtrl11, itemListCtrl12, 50);

////@end CMainFrame content construction

	CreateListControlHeaders();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT
 */

void CMainFrame::OnEXITClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT in Prova.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT in Prova. 
}

/*!
 * Should we show tooltips?
 */

bool CMainFrame::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap CMainFrame::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin CMainFrame bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end CMainFrame bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon CMainFrame::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin CMainFrame icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end CMainFrame icon retrieval
}
/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_CATALOG_VOLUME
 */

void CMainFrame::OnCatalogVolumeClick( wxCommandEvent& event )
{
	event.Skip(false);	// to suppress a warning
////@begin wxEVT_COMMAND_MENU_SELECTED event handler for ID_CATALOG_VOLUME in CMainFrame.
    // Before editing this code, remove the block markers.
    CDialogCatalogVolume* window = new CDialogCatalogVolume(this, ID_DIALOG_CATALOG_VOLUME, _("Catalog volume"));
    window->Show(true);
////@end wxEVT_COMMAND_MENU_SELECTED event handler for ID_CATALOG_VOLUME in CMainFrame. 
}


void CMainFrame::LoadTreeControl(void) {

	wxTreeCtrl* tctl = (wxTreeCtrl*) FindWindow( ID_TREE_CONTROL );
	wxImageList* iml = new wxImageList( 16, 16 );
	iml->Add(wxIcon(removable_xpm));
	iml->Add(wxIcon(folder_closed_xpm));
	iml->Add(wxIcon(folder_opened_xpm));
	tctl->AssignImageList( iml );

	tctl->DeleteAllItems();

	// adds a root item that will not ba visible
	wxTreeItemId rootID = tctl->AddRoot( wxT("Root") );

	CVolumes vol;
	vol.DBStartQueryListVolumes();
	while( !vol.IsEOF() ) {
		LoadVolumeInTreeControl( vol, tctl, rootID );
		vol.DBNextRow();
	}
}


void CMainFrame::LoadVolumeInTreeControl( CVolumes vol, wxTreeCtrl* tctl, wxTreeItemId rootID ) {

	// first retrieves the id of the root folder
	long rootPathID = -1;
	CPaths pth;
	CNullableLong nl;
	nl.SetNull(true);
	pth.DBStartQueryListPaths( vol.VolumeID, nl );
	while( !pth.IsEOF() ) {
		// this query should return only one line
		rootPathID = pth.PathID;
		pth.DBNextRow();
	}

	// appends the volume item
	wxTreeItemId volumeID = tctl->AppendItem( rootID, vol.VolumeName, 0, 0, 
							new MyTreeItemData(vol.VolumeName, vol.VolumeID, rootPathID, true) );

	// appends the first level of subfolders

	// now retrieves the subfolders
	nl = rootPathID;
	pth.DBStartQueryListPaths( vol.VolumeID, nl );
	while( !pth.IsEOF() ) {
		wxString name = pth.PathName;
		name = name.AfterLast( wxFileName::GetPathSeparator() );
		// adds the folder to the tree
		wxTreeItemId itemID = tctl->AppendItem( volumeID, name, 1, 2, 
							new MyTreeItemData(name, vol.VolumeID, pth.PathID, false) );
		// sets the expanded images
		tctl->SetItemImage( itemID, 1, wxTreeItemIcon_Expanded );
		tctl->SetItemImage( itemID, 2, wxTreeItemIcon_SelectedExpanded );
		// adds the subfolders
		LoadFolderInTreeControl( vol.VolumeID, tctl, itemID, pth.PathID );

		pth.DBNextRow();
	}

}


void CMainFrame::LoadFolderInTreeControl( long VolumeID, wxTreeCtrl* tctl, wxTreeItemId fatherTreeID, long fatherID ) {

	CPaths pth;
	pth.DBStartQueryListPaths( VolumeID, fatherID );
	while( !pth.IsEOF() ) {
		wxString name = pth.PathName;
		name = name.AfterLast( wxFileName::GetPathSeparator() );
		// adds the folder to the tree
		wxTreeItemId itemID = tctl->AppendItem( fatherTreeID, name, 1, 2, 
							new MyTreeItemData(name, VolumeID, pth.PathID, false) );
		// sets the expanded images
		tctl->SetItemImage( itemID, 1, wxTreeItemIcon_Expanded );
		tctl->SetItemImage( itemID, 2, wxTreeItemIcon_SelectedExpanded );

		pth.DBNextRow();
	}
}
/*!
 * wxEVT_COMMAND_TREE_ITEM_EXPANDING event handler for ID_TREE_CONTROL
 */

void CMainFrame::OnTreeControlItemExpanding( wxTreeEvent& event )
{
	wxTreeCtrl* tctl = (wxTreeCtrl*) FindWindow( ID_TREE_CONTROL );
	wxTreeItemId itemID = event.GetItem();
    MyTreeItemData *itemData = (MyTreeItemData *) tctl->GetItemData(itemID);

	if( itemData->IsVolume() || itemData->AlreadyOpened() ) return;
		
	// if this item has not been yet opened it loads the children of its children
	itemData->SetAlreadyOpened();

	// loops over the children
	wxTreeItemIdValue cookie;
	wxTreeItemId childID = tctl->GetFirstChild( itemID, cookie );
	while( childID.IsOk() ) {
		// adds the children of this child
	    MyTreeItemData *childItemData = (MyTreeItemData *) tctl->GetItemData(childID);
		LoadFolderInTreeControl( childItemData->GetVolumeID(), tctl, childID, childItemData->GetPathID() );
		childID = tctl->GetNextChild( itemID, cookie );
	}
}


/*!
 * wxEVT_COMMAND_TREE_SEL_CHANGED event handler for ID_TREE_CONTROL
 */

void CMainFrame::OnTreeControlSelChanged( wxTreeEvent& event )
{

	wxTreeCtrl* tctl = (wxTreeCtrl*) FindWindow( ID_TREE_CONTROL );
	wxListCtrl* lctl = (wxListCtrl*) FindWindow( ID_LIST_CONTROL );
	
	// assigns the image list
	wxImageList* iml = new wxImageList( 16, 16 );
	iml->Add(wxIcon(folder_closed_xpm));
	iml->Add(wxIcon(deffile_xpm));
	lctl->AssignImageList( iml, wxIMAGE_LIST_SMALL );

	// retrieves info about the selected item
	wxTreeItemId itemID = event.GetItem();
    MyTreeItemData *itemData = (MyTreeItemData *) tctl->GetItemData(itemID);

	lctl->DeleteAllItems();

	// retrieves the files contained in the selected folder
	CFiles files;
	files.DBStartQueryListFiles( itemData->GetPathID() );
	int i = 0;
	while( !files.IsEOF() ) {
		// adds the file to the list control
		int imageIndex = (files.IsFolder ? 0 : 1 );
		lctl->InsertItem( i, files.FileName, imageIndex );
		lctl->SetItem( i, 1, files.FileSize.ToString() );
		lctl->SetItem( i, 2, files.FileExt );
		lctl->SetItem( i, 3, files.DateTime.FormatDate() + " " + files.DateTime.FormatTime() );

		files.DBNextRow();
		i++;
	}

	//lctl->SetColumnWidth( 0, wxLIST_AUTOSIZE );
	//lctl->SetColumnWidth( 1, wxLIST_AUTOSIZE );
	//lctl->SetColumnWidth( 2, wxLIST_AUTOSIZE );
	//lctl->SetColumnWidth( 3, wxLIST_AUTOSIZE );
	lctl->SetColumnWidth( 0, 200 );
	lctl->SetColumnWidth( 1, 200 );
	lctl->SetColumnWidth( 2, 200 );
	lctl->SetColumnWidth( 3, 200 );

}


void CMainFrame::CreateListControlHeaders(void) {

	wxListCtrl* lctl = (wxListCtrl*) FindWindow( ID_LIST_CONTROL );

	// adds the columns to the list control
	wxListItem itemCol;
	itemCol.SetText( _("Name") );
	itemCol.SetAlign( wxLIST_FORMAT_LEFT );
	itemCol.SetImage( -1 );
	lctl->InsertColumn( 0, itemCol );

	itemCol.SetText( _("Size") );
	itemCol.SetAlign( wxLIST_FORMAT_RIGHT );
	lctl->InsertColumn( 1, itemCol );

	itemCol.SetText( _("Ext") );
	itemCol.SetAlign( wxLIST_FORMAT_LEFT );
	lctl->InsertColumn( 2, itemCol );

	itemCol.SetText( _("Last modified") );
	itemCol.SetAlign( wxLIST_FORMAT_LEFT );
	lctl->InsertColumn( 3, itemCol );
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for wxID_OPEN
 */

void CMainFrame::OnOPENClick( wxCommandEvent& event )
{
    event.Skip();

	wxString caption = _("Open catalog");
	wxString wildcard = _("VVV  files (*.vvv)|*.vvv|All files (*.*)|*.*");
	wxFileDialog fd( this, caption, wxEmptyString, wxEmptyString, wildcard, wxOPEN );
	if( fd.ShowModal() == wxID_OK ) {
		wxString path = fd.GetPath();

		CBaseDB *db = CBaseDB::GetDatabase();
		if( db != NULL ) {
			CBaseDB::GetDatabase()->Disconnect();
			CBaseDB::DeleteFirebirdDatabase();
		}
		
		CBaseDB::CreateFirebirdDatabase( "", path, "SYSDBA", "masterkey" );
		wxString stmp = CBaseDB::GetDatabase()->Connect();

		LoadTreeControl();

		wxListCtrl* lctl = (wxListCtrl*) FindWindow( ID_LIST_CONTROL );
		lctl->DeleteAllItems();
	}
}


