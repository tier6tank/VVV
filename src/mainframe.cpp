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

#include "wx/textdlg.h"
#include "wx/filename.h"
#include "wx/config.h"
#include "mainframe.h"
#include "data_interface/data_error.h"
#include "mytreeitemdata.h"

////@begin XPM images
////@end XPM images

#include "graphics/folder_closed.xpm"
#include "graphics/folder_opened.xpm"
#include "graphics/removable.xpm"
#include "graphics/deffile.xpm"

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

    EVT_MENU( ID_ADD_VIRTUAL_FOLDER, CMainFrame::OnAddVirtualFolderClick )
    EVT_UPDATE_UI( ID_ADD_VIRTUAL_FOLDER, CMainFrame::OnAddVirtualFolderUpdate )

    EVT_MENU( ID_RENAME_VOLUME, CMainFrame::OnRenameVolumeClick )
    EVT_UPDATE_UI( ID_RENAME_VOLUME, CMainFrame::OnRenameVolumeUpdate )

    EVT_UPDATE_UI( ID_DELETE_VOLUME, CMainFrame::OnDeleteVolumeUpdate )

    EVT_MENU( ID_NEW_VIRTUAL_ROOT_FOLDER, CMainFrame::OnNewVirtualRootFolderClick )
    EVT_UPDATE_UI( ID_NEW_VIRTUAL_ROOT_FOLDER, CMainFrame::OnNewVirtualRootFolderUpdate )

    EVT_MENU( ID_NEW_VIRTUAL_SUBFOLDER, CMainFrame::OnNewVirtualSubfolderClick )
    EVT_UPDATE_UI( ID_NEW_VIRTUAL_SUBFOLDER, CMainFrame::OnNewVirtualSubfolderUpdate )

    EVT_MENU( ID_RENAME_VIRTUAL_FOLDER, CMainFrame::OnRenameVirtualFolderClick )
    EVT_UPDATE_UI( ID_RENAME_VIRTUAL_FOLDER, CMainFrame::OnRenameVirtualFolderUpdate )

    EVT_MENU( ID_DELETE_VIRTUAL_FOLDER, CMainFrame::OnDeleteVirtualFolderClick )
    EVT_UPDATE_UI( ID_DELETE_VIRTUAL_FOLDER, CMainFrame::OnDeleteVirtualFolderUpdate )

    EVT_MENU( ID_CATALOG_VOLUME, CMainFrame::OnCatalogVolumeClick )

    EVT_MENU( ID_VIEW_PHYSICAL, CMainFrame::OnViewPhysicalClick )

    EVT_MENU( ID_VIEW_VIRTUAL, CMainFrame::OnViewVirtualClick )

    EVT_TREE_SEL_CHANGED( ID_TREE_CONTROL, CMainFrame::OnTreeControlSelChanged )
    EVT_TREE_ITEM_EXPANDING( ID_TREE_CONTROL, CMainFrame::OnTreeControlItemExpanding )

////@end CMainFrame event table entries

    EVT_TREE_SEL_CHANGED( ID_TREE_CONTROL_VIRTUAL, CMainFrame::OnTreeControlVirtualSelChanged )
    EVT_TREE_ITEM_EXPANDING( ID_TREE_CONTROL_VIRTUAL, CMainFrame::OnTreeControlVirtualItemExpanding )

	EVT_MENU_RANGE( wxID_FILE1, wxID_FILE9, CMainFrame::OnMRUFile)

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

	// reads the frame position from the config object
	wxConfigBase *pConfig = wxConfigBase::Get();
	pConfig->SetPath(wxT("/Mainframe/Layout"));
	int x = pConfig->Read(wxT("x"), 50),
		y = pConfig->Read(wxT("y"), 50),
		w = pConfig->Read(wxT("w"), 600),
		h = pConfig->Read(wxT("h"), 400);
	Move(x, y);
	SetClientSize(w, h);
	bool FrameMaximized;
	pConfig->Read( wxT("Maximized"), &FrameMaximized, false );
	if( FrameMaximized ) Maximize(true);

	// reads the splitter sash position
	wxSplitterWindow* sw = GetSplitterWindow();
	sw->SetSashPosition( pConfig->Read(wxT("SashPosition"), 200) );

	// reads the MRU files list
	m_fileHistory->Load( *pConfig );

	return true;
}

/*!
 * Member initialisation 
 */

void CMainFrame::Init()
{
////@begin CMainFrame member initialisation
    m_fileMenu = NULL;
////@end CMainFrame member initialisation
	m_ChooseVirtualFolderDialog = NULL;

	m_fileHistory = new wxFileHistory();
	
	m_CurrentView = Physical;	// let's start with the physical view
}
/*!
 * Control creation for Prova
 */

void CMainFrame::CreateControls()
{    
////@begin CMainFrame content construction
    // Generated by DialogBlocks, 22/04/2007 22:42:13 (unregistered)

    CMainFrame* itemFrame1 = this;

    wxMenuBar* menuBar = new wxMenuBar;
    m_fileMenu = new wxMenu;
    m_fileMenu->Append(wxID_OPEN, _("Open"), _T(""), wxITEM_NORMAL);
    m_fileMenu->AppendSeparator();
    m_fileMenu->Append(wxID_EXIT, _("Exit"), _T(""), wxITEM_NORMAL);
    menuBar->Append(m_fileMenu, _("File"));
    wxMenu* itemMenu7 = new wxMenu;
    itemMenu7->Append(ID_ADD_VIRTUAL_FOLDER, _("Add To Virtual Folder"), _T(""), wxITEM_NORMAL);
    itemMenu7->AppendSeparator();
    itemMenu7->Append(ID_RENAME_VOLUME, _("Rename Volume"), _T(""), wxITEM_NORMAL);
    itemMenu7->Append(ID_DELETE_VOLUME, _("Delete Volume"), _T(""), wxITEM_NORMAL);
    itemMenu7->AppendSeparator();
    itemMenu7->Append(ID_NEW_VIRTUAL_ROOT_FOLDER, _("New Virtual Root Folder"), _T(""), wxITEM_NORMAL);
    itemMenu7->Append(ID_NEW_VIRTUAL_SUBFOLDER, _("New Virtual Subfolder"), _T(""), wxITEM_NORMAL);
    itemMenu7->Append(ID_RENAME_VIRTUAL_FOLDER, _("Rename Virtual Folder"), _T(""), wxITEM_NORMAL);
    itemMenu7->Append(ID_DELETE_VIRTUAL_FOLDER, _("Delete Virtual Folder"), _T(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu7, _("Edit"));
    wxMenu* itemMenu17 = new wxMenu;
    itemMenu17->Append(ID_CATALOG_VOLUME, _("Catalog Volume"), _T(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu17, _("Volumes"));
    wxMenu* itemMenu19 = new wxMenu;
    itemMenu19->Append(ID_VIEW_PHYSICAL, _("Physical View"), _T(""), wxITEM_RADIO);
    itemMenu19->Check(ID_VIEW_PHYSICAL, true);
    itemMenu19->Append(ID_VIEW_VIRTUAL, _("Virtual View"), _T(""), wxITEM_RADIO);
    menuBar->Append(itemMenu19, _("View"));
    itemFrame1->SetMenuBar(menuBar);

    wxStatusBar* itemStatusBar22 = new wxStatusBar( itemFrame1, ID_STATUSBAR1, wxST_SIZEGRIP );
    itemStatusBar22->SetFieldsCount(2);
    itemFrame1->SetStatusBar(itemStatusBar22);

    wxSplitterWindow* itemSplitterWindow23 = new wxSplitterWindow( itemFrame1, ID_SPLITTERWINDOW1, wxDefaultPosition, wxSize(100, 100), wxSP_3DBORDER|wxSP_3DSASH|wxSP_NO_XP_THEME|wxNO_BORDER );
    itemSplitterWindow23->SetMinimumPaneSize(0);

    wxTreeCtrl* itemTreeCtrl24 = new wxTreeCtrl( itemSplitterWindow23, ID_TREE_CONTROL, wxDefaultPosition, wxSize(100, 100), wxTR_HAS_BUTTONS |wxTR_HIDE_ROOT|wxTR_SINGLE|wxNO_BORDER|wxTR_DEFAULT_STYLE );

    wxListCtrl* itemListCtrl25 = new wxListCtrl( itemSplitterWindow23, ID_LIST_CONTROL, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT|wxNO_BORDER );

    itemSplitterWindow23->SplitVertically(itemTreeCtrl24, itemListCtrl25, 50);

    // Connect events and objects
    itemTreeCtrl24->Connect(ID_TREE_CONTROL, wxEVT_CONTEXT_MENU, wxContextMenuEventHandler(CMainFrame::OnTreeControlContextMenu), NULL, this);
////@end CMainFrame content construction

	// creates the tree control used to show virtual folders
	// this control must be created in the same way as the tree control created above
	wxSplitterWindow* sw = (wxSplitterWindow*) FindWindow( ID_SPLITTERWINDOW1 );
	wxTreeCtrl* itemTreeCtrlVirtual = new wxTreeCtrl( sw, ID_TREE_CONTROL_VIRTUAL, wxDefaultPosition, wxSize(100, 100), wxTR_HAS_BUTTONS |wxTR_HIDE_ROOT|wxTR_SINGLE|wxNO_BORDER|wxTR_DEFAULT_STYLE );
	itemTreeCtrlVirtual->Show( false );

	// stores a pointer to some window components for later use
	m_splitterWindow = sw;
	m_treePhysicalCtl = (wxTreeCtrl*) FindWindow( ID_TREE_CONTROL );
	m_treeVirtualCtl = (wxTreeCtrl*) FindWindow( ID_TREE_CONTROL_VIRTUAL );
	m_listCtl = (wxListCtrl*) FindWindow( ID_LIST_CONTROL );

    m_treeVirtualCtl->Connect(ID_TREE_CONTROL_VIRTUAL, wxEVT_CONTEXT_MENU, wxContextMenuEventHandler(CMainFrame::OnTreeControlVirtualContextMenu), NULL, this);

	CreateListControlHeaders();

	// associates the MRU files list
	m_fileHistory->UseMenu( m_fileMenu );

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
    CDialogCatalogVolume* window = new CDialogCatalogVolume(this, ID_DIALOG_CATALOG_VOLUME, _("Catalog volume"));
    window->Show(true);
}


void CMainFrame::LoadTreeControl(void) {

	wxTreeCtrl* tctl = GetTreePhysicalControl();
	wxImageList* iml = new wxImageList( 16, 16 );
	iml->Add(wxIcon(removable_xpm));
	iml->Add(wxIcon(folder_closed_xpm));
	iml->Add(wxIcon(folder_opened_xpm));
	tctl->AssignImageList( iml );

	tctl->DeleteAllItems();

	// adds a root item that will not be visible
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
		// this query should return only one row
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

void CMainFrame::LoadVirtualTreeControl(void) {

	wxTreeCtrl* tctl = GetTreeVirtualControl();
	wxImageList* iml = new wxImageList( 16, 16 );
	iml->Add(wxIcon(removable_xpm));
	iml->Add(wxIcon(folder_closed_xpm));
	iml->Add(wxIcon(folder_opened_xpm));
	tctl->AssignImageList( iml );

	tctl->DeleteAllItems();

	// adds a root item that will not be visible
	wxTreeItemId rootID = tctl->AddRoot( wxT("Root") );

	// appends subfolders
	CVirtualPaths pth;
	CNullableLong nl;
	nl.SetNull(true);
	pth.DBStartQueryListPaths( nl );
	while( !pth.IsEOF() ) {
		wxString name = pth.PathName;
		// adds the folder to the tree
		wxTreeItemId itemID = tctl->AppendItem( rootID, name, 1, 2, 
							new MyTreeItemData(name, pth.PathID, pth.PhysPathID) );
		if( pth.PhysPathID.IsNull() ) {
			// this vistual path has been created by the user: it is not a physical path assigned to a virtual path
			// show it in a different colour
			tctl->SetItemTextColour( itemID, *wxBLUE );
		}
		// sets the expanded images
		tctl->SetItemImage( itemID, 1, wxTreeItemIcon_Expanded );
		tctl->SetItemImage( itemID, 2, wxTreeItemIcon_SelectedExpanded );
		// adds the subfolders
		LoadVirtualFolderInTreeControl( tctl, itemID, pth.PathID );

		pth.DBNextRow();
	}
}

void CMainFrame::LoadVirtualFolderInTreeControl( wxTreeCtrl* tctl, wxTreeItemId fatherTreeID, long fatherID ) {

	CVirtualPaths pth;
	pth.DBStartQueryListPaths( fatherID );
	while( !pth.IsEOF() ) {
		wxString name = pth.PathName;
		name = name.AfterLast( wxFileName::GetPathSeparator() );
		// adds the folder to the tree
		wxTreeItemId itemID = tctl->AppendItem( fatherTreeID, name, 1, 2, 
							new MyTreeItemData(name, pth.PathID, pth.PhysPathID) );
		if( pth.PhysPathID.IsNull() ) {
			// this vistual path has been created by the user: it is not a physical path assigned to a virtual path
			// show it in a different colour
			tctl->SetItemTextColour( itemID, *wxBLUE );
		}
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
	wxTreeCtrl* tctl = GetTreePhysicalControl();
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
	if( m_CurrentView != Physical ) return;

	wxTreeItemId itemID = event.GetItem();
	ShowFolderFiles( itemID );
}


/*!
 * wxEVT_COMMAND_TREE_SEL_CHANGED event handler for ID_TREE_CONTROL_VIRTUAL
 */

void CMainFrame::OnTreeControlVirtualSelChanged( wxTreeEvent& event )
{
	if( m_CurrentView != Virtual ) return;
	
	wxTreeItemId itemID = event.GetItem();
	ShowVirtualFolderFiles( itemID );
}


void CMainFrame::CreateListControlHeaders(void) {

	wxListCtrl* lctl = GetListControl();

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
		if ( path.empty() ) return;
		OpenDatabase( path );
	}
}

CMainFrame::~CMainFrame() {

	wxConfigBase *pConfig = wxConfigBase::Get();
	if ( pConfig == NULL )
		return;

	// saves the frame position
	int x, y, w, h;
	GetClientSize(&w, &h);
	GetPosition(&x, &y);
	pConfig->SetPath(wxT("/Mainframe/Layout"));
	if( !IsMaximized() ) {
		pConfig->Write(wxT("x"), (long) x);
		pConfig->Write(wxT("y"), (long) y);
		pConfig->Write(wxT("w"), (long) w);
		pConfig->Write(wxT("h"), (long) h);
	}
	pConfig->Write(wxT("Maximized"), IsMaximized() );

	// saves the sash position
	wxSplitterWindow* sw = GetSplitterWindow();
	pConfig->Write(wxT("SashPosition"), (long) sw->GetSashPosition() );

	// delete the virtual folders window
	if( m_ChooseVirtualFolderDialog != NULL ) delete m_ChooseVirtualFolderDialog;

	m_fileHistory->Save( *pConfig );

	delete m_fileHistory;
}
/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_VIEW_PHYSICAL
 */

void CMainFrame::OnViewPhysicalClick( wxCommandEvent& event )
{
	if( !event.IsChecked() ) return;
	event.Skip();

	// shows the physical tree view
	wxTreeCtrl* tctlPhysical = GetTreePhysicalControl();
	if( !tctlPhysical->IsShown() ) {
		wxTreeCtrl* tctlVirtual = GetTreeVirtualControl();
		wxSplitterWindow* sw = GetSplitterWindow();
		long sp = sw->GetSashPosition();
		wxListCtrl* lctl = GetListControl();
		sw->Unsplit();
		tctlVirtual->Show( false );
		tctlPhysical->Show( true );
		sw->SplitVertically( tctlPhysical, lctl );
		sw->SetSashPosition( sp );
		ShowSelectedFolderFiles();
		m_CurrentView = Physical;
	}
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_VIEW_VIRTUAL
 */

void CMainFrame::OnViewVirtualClick( wxCommandEvent& event )
{
	if( !event.IsChecked() ) return;
	event.Skip();

	// shows the virtual tree view
	wxTreeCtrl* tctlVirtual = GetTreeVirtualControl();
	if( !tctlVirtual->IsShown() ) {
		wxTreeCtrl* tctlPhysical = GetTreePhysicalControl();
		wxSplitterWindow* sw = GetSplitterWindow();
		long sp = sw->GetSashPosition();
		wxListCtrl* lctl = GetListControl();
		sw->Unsplit();
		tctlVirtual->Show( true );
		tctlPhysical->Show( false );
		sw->SplitVertically( tctlVirtual, lctl );
		sw->SetSashPosition( sp );
		ShowSelectedVirtualFolderFiles();
		m_CurrentView = Virtual;
	}
}


/*!
 * wxEVT_COMMAND_TREE_ITEM_EXPANDING event handler for ID_TREE_CONTROL_VIRTUAL
 */

void CMainFrame::OnTreeControlVirtualItemExpanding( wxTreeEvent& event )
{
	wxTreeCtrl* tctl = GetTreeVirtualControl();
	wxTreeItemId itemID = event.GetItem();
    MyTreeItemData *itemData = (MyTreeItemData *) tctl->GetItemData(itemID);

	if( itemData->AlreadyOpened() ) return;
		
	// if this item has not been yet opened it loads the children of its children
	itemData->SetAlreadyOpened();

	// loops over the children
	wxTreeItemIdValue cookie;
	wxTreeItemId childID = tctl->GetFirstChild( itemID, cookie );
	while( childID.IsOk() ) {
		// adds the children of this child
	    MyTreeItemData *childItemData = (MyTreeItemData *) tctl->GetItemData(childID);
		LoadVirtualFolderInTreeControl( tctl, childID, childItemData->GetPathID() );
		childID = tctl->GetNextChild( itemID, cookie );
	}
}


// shows in the listview the files contained in the passed folder
void CMainFrame::ShowFolderFiles( wxTreeItemId itemID ) {

	wxTreeCtrl* tctl = GetTreePhysicalControl();
	wxListCtrl* lctl = GetListControl();
	
	// assigns the image list
	wxImageList* iml = new wxImageList( 16, 16 );
	iml->Add(wxIcon(folder_closed_xpm));
	iml->Add(wxIcon(deffile_xpm));
	lctl->AssignImageList( iml, wxIMAGE_LIST_SMALL );

    MyTreeItemData *itemData = (MyTreeItemData *) tctl->GetItemData(itemID);

	lctl->DeleteAllItems();

	// retrieves the files contained in the selected folder
	CFiles files;
	files.DBStartQueryListFiles( itemData->GetPathID() );
	int i = 0;
	while( !files.IsEOF() ) {
		// adds the file to the list control
		int imageIndex = (files.IsFolder() ? 0 : 1 );
		lctl->InsertItem( i, files.FileName, imageIndex );
		lctl->SetItem( i, 1, files.IsFolder() ? "" : CUtils::HumanReadableFileSize(files.FileSize) );
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

// shows in the listview the files contained in the currently selected folder
void CMainFrame::ShowSelectedFolderFiles(void ) {

	wxTreeCtrl* tctl = GetTreePhysicalControl();
    wxTreeItemId itemID = tctl->GetSelection();
	if( itemID.IsOk() ) {
		ShowFolderFiles( itemID );
	}
	else {
		wxListCtrl* lctl = GetListControl();
		lctl->DeleteAllItems();
	}
}

// shows in the listview the files contained in the passed virtual folder
void CMainFrame::ShowVirtualFolderFiles( wxTreeItemId itemID ) {

	wxTreeCtrl* tctl = GetTreeVirtualControl();
	wxListCtrl* lctl = GetListControl();
	
	// assigns the image list
	wxImageList* iml = new wxImageList( 16, 16 );
	iml->Add(wxIcon(folder_closed_xpm));
	iml->Add(wxIcon(deffile_xpm));
	lctl->AssignImageList( iml, wxIMAGE_LIST_SMALL );

	// retrieves info about the selected item
    MyTreeItemData *itemData = (MyTreeItemData *) tctl->GetItemData(itemID);

	lctl->DeleteAllItems();

	// retrieves the files contained in the selected folder
	CVirtualFiles files;
	files.DBStartQueryListFiles( itemData->GetPathID() );
	int i = 0;
	while( !files.IsEOF() ) {
		// adds the file to the list control
		int imageIndex = (files.IsFolder() ? 0 : 1 );
		lctl->InsertItem( i, files.FileName, imageIndex );
		lctl->SetItem( i, 1, files.IsFolder() ? "" : CUtils::HumanReadableFileSize(files.FileSize) );
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

// shows in the listview the files contained in the currently selected virtual folder
void CMainFrame::ShowSelectedVirtualFolderFiles(void ) {

	wxTreeCtrl* tctl = GetTreeVirtualControl();
    wxTreeItemId itemID = tctl->GetSelection();
	if( itemID.IsOk() ) {
		ShowVirtualFolderFiles( itemID );
	}
	else {
		wxListCtrl* lctl = GetListControl();
		lctl->DeleteAllItems();
	}
}


/*!
 * wxEVT_CONTEXT_MENU event handler for ID_TREE_CONTROL
 */

void CMainFrame::OnTreeControlContextMenu( wxContextMenuEvent& event )
{
    wxPoint pt = event.GetPosition();
    wxTreeItemId item;
	wxTreeCtrl *tctl = GetTreePhysicalControl();

    // check if event was generated by keyboard (MSW-specific?)
    if ( pt.x == -1 && pt.y == -1 ) //(this is how MSW indicates it)
    {
        if ( !HasFlag(wxTR_MULTIPLE) )
            item = tctl->GetSelection();

        // attempt to guess where to show the menu
        if ( item.IsOk() )
        {
            // if an item was clicked, show menu to the right of it
            wxRect rect;
            tctl->GetBoundingRect(item, rect, true /* only the label */);
            pt = wxPoint(rect.GetRight(), rect.GetTop());
        }
        else
        {
            pt = wxPoint(0, 0);
        }
    }
    else // event was generated by mouse, use supplied coords
    {
        pt = ScreenToClient(pt);
        item = tctl->HitTest(pt);
    }

	wxMenu menu;
	menu.Append( ID_ADD_VIRTUAL_FOLDER, _("Add To Virtual Folder") );
	if( tctl->GetItemParent(item) == tctl->GetRootItem() ) {
		// only for voume nodes, not for folders
	    menu.AppendSeparator();
		menu.Append( ID_RENAME_VOLUME, _("Rename") );
		menu.Append( ID_DELETE_VOLUME, _("Delete") );
	}
	
	PopupMenu( &menu, pt );
}


void CMainFrame::OnTreeControlVirtualContextMenu( wxContextMenuEvent& event )
{
    wxPoint pt = event.GetPosition();
    wxTreeItemId item;
	wxTreeCtrl *tctl = GetTreeVirtualControl();

    // check if event was generated by keyboard (MSW-specific?)
    if ( pt.x == -1 && pt.y == -1 ) //(this is how MSW indicates it)
    {
        if ( !HasFlag(wxTR_MULTIPLE) )
            item = tctl->GetSelection();

        // attempt to guess where to show the menu
        if ( item.IsOk() )
        {
            // if an item was clicked, show menu to the right of it
            wxRect rect;
            tctl->GetBoundingRect(item, rect, true /* only the label */);
            pt = wxPoint(rect.GetRight(), rect.GetTop());
        }
        else
        {
            pt = wxPoint(0, 0);
        }
    }
    else // event was generated by mouse, use supplied coords
    {
        pt = ScreenToClient(pt);
        item = tctl->HitTest(pt);
    }

	wxMenu menu;
	menu.Append( ID_NEW_VIRTUAL_ROOT_FOLDER, _("New Root Folder") );
	if( item.IsOk() ) {
		// only if we have a selected item
		menu.Append( ID_NEW_VIRTUAL_SUBFOLDER, _("New Subfolder") );
	    MyTreeItemData *itemData = (MyTreeItemData *) tctl->GetItemData(item);
		if( itemData->GetPhysPathID().IsNull() ) menu.Append( ID_RENAME_VIRTUAL_FOLDER, _("Rename") );
		menu.Append( ID_DELETE_VIRTUAL_FOLDER, _("Delete") );
	}
	
	PopupMenu( &menu, pt );
}



/*!
 * wxEVT_UPDATE_UI event handler for ID_RENAME_VOLUME
 */

void CMainFrame::OnRenameVolumeUpdate( wxUpdateUIEvent& event )
{
	bool hideElement = false;
	wxTreeCtrl *tctl = GetTreePhysicalControl();
	wxTreeItemId item = tctl->GetSelection();
	if( item.IsOk() ) {
		if( tctl->GetItemParent(item) != tctl->GetRootItem() ) hideElement = true;
	}
	else {
		hideElement = true;
	}
	event.Enable( !hideElement );
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_DELETE_VOLUME
 */

void CMainFrame::OnDeleteVolumeUpdate( wxUpdateUIEvent& event )
{
	bool hideElement = false;
	wxTreeCtrl *tctl = GetTreePhysicalControl();
	wxTreeItemId item = tctl->GetSelection();
	if( item.IsOk() ) {
		if( tctl->GetItemParent(item) != tctl->GetRootItem() ) hideElement = true;
	}
	else {
		hideElement = true;
	}
	event.Enable( !hideElement );
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_RENAME_VOLUME
 */

void CMainFrame::OnRenameVolumeClick( wxCommandEvent& event )
{
	wxTreeCtrl *tctl = GetTreePhysicalControl();
	wxTreeItemId item = tctl->GetSelection();
	wxString oldName = tctl->GetItemText(item);

	// asks for the new volume name
	wxTextEntryDialog ted( this, _("Enter the new volume name"), _("Rename volume"), oldName, wxOK | wxCANCEL );
	if( ted.ShowModal() != wxID_OK ) return;
	wxString newName = ted.GetValue();
	if( newName == oldName || newName.empty() ) return;

	// changes the volume name in the database
    MyTreeItemData *itemData = (MyTreeItemData *) tctl->GetItemData(item);
	CVolumes vol( itemData->GetVolumeID() );	// loads the current data
	vol.VolumeName = newName;
	try {
		vol.DbUpdate();
	}
	catch( CDataErrorException& e ) {
		if( e.GetErrorCause() == CDataErrorException::Unique ) {
			CUtils::MsgErr( _("The new volume name is already present in the database") );
			return;
		}
		else
			throw;
	}

	// changes the volume name in the tree control
	tctl->SetItemText( item, newName );

	event.Skip(false);	// to suppress a warning
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_ADD_VIRTUAL_FOLDER
 */

void CMainFrame::OnAddVirtualFolderClick( wxCommandEvent& event )
{
	event.Skip(false);	// to suppress a warning

	if( m_ChooseVirtualFolderDialog->ShowModal() != wxID_OK ) return;
	long virtualFolderId = m_ChooseVirtualFolderDialog->GetVirtualFolderID();

	bool isVolumeItem = false;	// true if the user has selected a volume (not a folder)
	wxTreeCtrl *tctl = GetTreePhysicalControl();
	wxTreeItemId item = tctl->GetSelection();
	if( tctl->GetItemParent(item) == tctl->GetRootItem() ) isVolumeItem = true;

    MyTreeItemData *itemData = (MyTreeItemData *) tctl->GetItemData(item);
	long physicalFolderId = itemData->GetPathID();

	if( isVolumeItem )
		CVirtualPaths::CopyPhysicalPath( physicalFolderId, virtualFolderId );
	else
		CVirtualPaths::AppendPhysicalPath( physicalFolderId, virtualFolderId );

	// updates the tree controls
	m_ChooseVirtualFolderDialog->Refresh();
	LoadVirtualTreeControl();
}


/*!
 * wxEVT_UPDATE_UI event handler for ID_ADD_VIRTUAL_FOLDER
 */

void CMainFrame::OnAddVirtualFolderUpdate( wxUpdateUIEvent& event )
{
	event.Enable( m_CurrentView == Physical );
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_NEW_VIRTUAL_ROOT_FOLDER
 */

void CMainFrame::OnNewVirtualRootFolderClick( wxCommandEvent& event )
{
	CNullableLong nl;
	nl.SetNull( true );

	CreateNewVirtualFolder( nl, _("New virtual root folder") );

	event.Skip(false);	// to suppress a warning
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_NEW_VIRTUAL_ROOT_FOLDER
 */

void CMainFrame::OnNewVirtualRootFolderUpdate( wxUpdateUIEvent& event )
{
	event.Enable( m_CurrentView == Virtual );
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_NEW_VIRTUAL_SUBFOLDER
 */

void CMainFrame::OnNewVirtualSubfolderClick( wxCommandEvent& event )
{
	wxTreeCtrl *tctl = GetTreeVirtualControl();
	wxTreeItemId item = tctl->GetSelection();
    MyTreeItemData *itemData = (MyTreeItemData *) tctl->GetItemData(item);
	long FatherID = itemData->GetPathID();

	CreateNewVirtualFolder( FatherID, _("New virtual subfolder") );

	event.Skip(false);	// to suppress a warning
}

void CMainFrame::CreateNewVirtualFolder( CNullableLong FatherID, wxString windowTitle ) {
	wxTreeCtrl *tctl = GetTreeVirtualControl();
	wxTreeItemId fatherItem;
	wxString folderName = "";

	if( FatherID.IsNull() ) {
		// this is a root folder
		fatherItem = tctl->GetRootItem();
	}
	else {
		// this is a subfolder
		fatherItem = tctl->GetSelection();
	}

	// asks for the new folder name
	wxTextEntryDialog ted( this, _("Enter the new folder name"), windowTitle, folderName, wxOK | wxCANCEL );
	if( ted.ShowModal() != wxID_OK ) return;
	folderName = ted.GetValue();
	if( folderName == "" ) return;

	// adds the new folder to the database
	CVirtualPaths pth;
	pth.PathName = folderName;
	pth.PhysPathID.SetNull( true );
	pth.FatherID = FatherID;
	try {
		pth.DbInsert();
	}
	catch( CDataErrorException& e ) {
		if( e.GetErrorCause() == CDataErrorException::Unique ) {
			CUtils::MsgErr( _("The new folder name is already present in the database") );
			return;
		}
		else
			throw;
	}

	// adds the folder to the tree control
	wxTreeItemId newItem = tctl->AppendItem( fatherItem, pth.PathName, 1, 2, 
						new MyTreeItemData(pth.PathName, 0, pth.PathID, false) );
	tctl->SetItemTextColour( newItem, *wxBLUE );
	// sets the expanded images
	tctl->SetItemImage( newItem, 1, wxTreeItemIcon_Expanded );
	tctl->SetItemImage( newItem, 2, wxTreeItemIcon_SelectedExpanded );

	// updates the listview
	if( !FatherID.IsNull() ) 
		ShowVirtualFolderFiles( fatherItem );

	m_ChooseVirtualFolderDialog->Refresh();
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_NEW_VIRTUAL_SUBFOLDER
 */

void CMainFrame::OnNewVirtualSubfolderUpdate( wxUpdateUIEvent& event )
{
	event.Enable( m_CurrentView == Virtual );
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_RENAME_VIRTUAL_FOLDER
 */

void CMainFrame::OnRenameVirtualFolderClick( wxCommandEvent& event )
{
	wxTreeCtrl *tctl = GetTreeVirtualControl();
	wxTreeItemId item = tctl->GetSelection();
	wxString oldName = tctl->GetItemText(item);

	// asks for the new volume name
	wxTextEntryDialog ted( this, _("Enter the new forder name"), _("Rename virtual folder"), oldName, wxOK | wxCANCEL );
	if( ted.ShowModal() != wxID_OK ) return;
	wxString newName = ted.GetValue();
	if( newName == oldName || newName.empty() ) return;

	// changes the folder name in the database
    MyTreeItemData *itemData = (MyTreeItemData *) tctl->GetItemData(item);
	try {
		CVirtualPaths::Rename( itemData->GetPathID(), newName );
	}
	catch( CDataErrorException& e ) {
		if( e.GetErrorCause() == CDataErrorException::Unique ) {
			CUtils::MsgErr( _("The new folder name is already present in the database") );
			return;
		}
		else
			throw;
	}

	// changes the volume name in the tree control
	tctl->SetItemText( item, newName );

	event.Skip(false);	// to suppress a warning
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_RENAME_VIRTUAL_FOLDER
 */

void CMainFrame::OnRenameVirtualFolderUpdate( wxUpdateUIEvent& event )
{
	bool isEnabled = m_CurrentView == Virtual;
	if( isEnabled ) {
		wxTreeCtrl* tctl = GetTreeVirtualControl();
		wxTreeItemId item = tctl->GetSelection();
		if( item.IsOk() ) {
			MyTreeItemData *itemData = (MyTreeItemData *) tctl->GetItemData(item);
			isEnabled = itemData->GetPhysPathID().IsNull();
		}
	}
	event.Enable( isEnabled );
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_DELETE_VIRTUAL_FOLDER
 */

void CMainFrame::OnDeleteVirtualFolderClick( wxCommandEvent& event )
{
	if( !CUtils::MsgAskNo( _("This command will delete the selected virtual foder, but it will not change the folders in the physical view.\n\nDo you really want to delete the selected virtual folder?") ) )
		return;
	
	wxTreeCtrl *tctl = GetTreeVirtualControl();
	wxTreeItemId item = tctl->GetSelection();
    MyTreeItemData *itemData = (MyTreeItemData *) tctl->GetItemData(item);

	// deletes from the database
	CVirtualPaths vp;
	vp.PathID = itemData->GetPathID();
	vp.DbDelete();

	// deletes from the tree control
	tctl->DeleteChildren(item);
	tctl->Delete(item);

	event.Skip(false);	// to suppress a warning
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_DELETE_VIRTUAL_FOLDER
 */

void CMainFrame::OnDeleteVirtualFolderUpdate( wxUpdateUIEvent& event )
{
	event.Enable( m_CurrentView == Virtual );
}


void CMainFrame::OnMRUFile( wxCommandEvent& event ) {
	
	int i = event.GetId() - wxID_FILE1;
	wxString fileName = m_fileHistory->GetHistoryFile( i );
	if( fileName.empty() ) return;
	if( !wxFileName::FileExists(fileName) ) {
		CUtils::MsgErr( "This catalog file does not exist any more" );
		m_fileHistory->RemoveFileFromHistory( i );
		return;
	}
	OpenDatabase( fileName );

}


void CMainFrame::OpenDatabase( wxString fileName ) {

	CBaseDB *db = CBaseDB::GetDatabase();
	if( db != NULL ) {
		CBaseDB::GetDatabase()->Disconnect();
		CBaseDB::DeleteFirebirdDatabase();
	}
	
	CBaseDB::CreateFirebirdDatabase( "", fileName, "SYSDBA", "masterkey" );
	wxString stmp = CBaseDB::GetDatabase()->Connect();

	LoadTreeControl();
	LoadVirtualTreeControl();

	wxListCtrl* lctl = GetListControl();
	lctl->DeleteAllItems();

	// creates the dialog used to choose a virtual folder
	// we use a global object to keep folders selection between dialog calls
	if( m_ChooseVirtualFolderDialog != NULL ) delete m_ChooseVirtualFolderDialog;
	m_ChooseVirtualFolderDialog = new CDialogChooseVirtualFolder(this, ID_DIALOG_CHOOSE_VIRTUAL_FOLDER, _("Choose virual folder"));

	// stores the file in the MRU list
	m_fileHistory->AddFileToHistory( fileName );

}
