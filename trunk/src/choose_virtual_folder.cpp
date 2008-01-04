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
// Name:        choose_virtual_folder.cpp
// Purpose:     
// Author:      
// Modified by: 
// Created:     16/04/2007 12:35:50
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 16/04/2007 12:35:50

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "choose_virtual_folder.h"
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

#include "wx/filename.h"

#include "choose_virtual_folder.h"
#include "mytreeitemdata.h"
#include "data_interface/virtual_paths.h"

////@begin XPM images
////@end XPM images

#include "graphics/folder_closed.xpm"
#include "graphics/folder_opened.xpm"
#include "graphics/removable.xpm"
#include "graphics/deffile.xpm"

/*!
 * CDialogChooseVirtualFolder type definition
 */

IMPLEMENT_DYNAMIC_CLASS( CDialogChooseVirtualFolder, wxDialog )

/*!
 * CDialogChooseVirtualFolder event table definition
 */

BEGIN_EVENT_TABLE( CDialogChooseVirtualFolder, wxDialog )

////@begin CDialogChooseVirtualFolder event table entries
    EVT_TREE_ITEM_EXPANDING( ID_TREECTRL_CHOOSE, CDialogChooseVirtualFolder::OnTreectrlChooseItemExpanding )

#if defined(__WXMSW__)
    EVT_BUTTON( wxID_OK, CDialogChooseVirtualFolder::OnOKClick )
#endif

#if defined(__WXMAC__) || defined(__WXGTK__)
    EVT_BUTTON( wxID_OK, CDialogChooseVirtualFolder::OnOKClick )
#endif

////@end CDialogChooseVirtualFolder event table entries

END_EVENT_TABLE()

/*!
 * CDialogChooseVirtualFolder constructors
 */

CDialogChooseVirtualFolder::CDialogChooseVirtualFolder( )
{
    Init();
}

CDialogChooseVirtualFolder::CDialogChooseVirtualFolder( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}

/*!
 * Dialog creator
 */

bool CDialogChooseVirtualFolder::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin CDialogChooseVirtualFolder creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end CDialogChooseVirtualFolder creation

	m_WindowPosition.SetWindow( this );
	m_WindowPosition.RestorePosition();
	
	return true;
}

/*!
 * Member initialisation 
 */

void CDialogChooseVirtualFolder::Init()
{
////@begin CDialogChooseVirtualFolder member initialisation
    m_TreeCtrl = NULL;
////@end CDialogChooseVirtualFolder member initialisation
	m_VirtualFolderID = -1;
}
/*!
 * Control creation for Dialog
 */

void CDialogChooseVirtualFolder::CreateControls()
{    
////@begin CDialogChooseVirtualFolder content construction
    CDialogChooseVirtualFolder* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemDialog1, wxID_STATIC, _("Please select the virtual folder that will receive the selected files and/or folders:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_LEFT|wxALL, 5);

    m_TreeCtrl = new wxTreeCtrl( itemDialog1, ID_TREECTRL_CHOOSE, wxDefaultPosition, wxSize(-1, 300), wxTR_NO_BUTTONS|wxTR_HIDE_ROOT|wxTR_SINGLE|wxTR_DEFAULT_STYLE );
    itemBoxSizer2->Add(m_TreeCtrl, 1, wxGROW|wxALL, 5);

#if defined(__WXMSW__)
    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer5, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemBoxSizer5->Add(5, 5, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton7 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton7->SetDefault();
    itemBoxSizer5->Add(itemButton7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton8 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemButton8, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

#endif

#if defined(__WXMAC__) || defined(__WXGTK__)
    wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer9, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemBoxSizer9->Add(5, 5, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton11 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer9->Add(itemButton11, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    wxButton* itemButton12 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton12->SetDefault();
    itemBoxSizer9->Add(itemButton12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

#endif

////@end CDialogChooseVirtualFolder content construction

	LoadVirtualTreeControl();
}

/*!
 * Should we show tooltips?
 */

bool CDialogChooseVirtualFolder::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap CDialogChooseVirtualFolder::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin CDialogChooseVirtualFolder bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end CDialogChooseVirtualFolder bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon CDialogChooseVirtualFolder::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin CDialogChooseVirtualFolder icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end CDialogChooseVirtualFolder icon retrieval
}


void CDialogChooseVirtualFolder::LoadVirtualTreeControl(void) {

	wxTreeCtrl* tctl = m_TreeCtrl;
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

void CDialogChooseVirtualFolder::LoadVirtualFolderInTreeControl( wxTreeCtrl* tctl, wxTreeItemId fatherTreeID, long fatherID ) {

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
 * wxEVT_COMMAND_TREE_ITEM_EXPANDING event handler for ID_TREECTRL_CHOOSE
 */

void CDialogChooseVirtualFolder::OnTreectrlChooseItemExpanding( wxTreeEvent& event )
{
	wxTreeCtrl* tctl = m_TreeCtrl;
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




/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void CDialogChooseVirtualFolder::OnOKClick( wxCommandEvent& WXUNUSED(event) )
{
	wxTreeItemId itemID = m_TreeCtrl->GetSelection();
	if( itemID.IsOk() ) {
		MyTreeItemData *itemData = (MyTreeItemData *) m_TreeCtrl->GetItemData(itemID);
		if( itemData != NULL )
			m_VirtualFolderID = itemData->GetPathID();
		else
			m_VirtualFolderID = -1;
	}
	else {
		m_VirtualFolderID = -1;
	}

	EndModal( wxID_OK );
}



void CDialogChooseVirtualFolder::GetCurrentPathArray( wxArrayString& as ) {

	as.Empty();
	wxTreeItemId itemID = m_TreeCtrl->GetSelection();
	
	if( !itemID.IsOk() ) return;		// empty array

	while( itemID != m_TreeCtrl->GetRootItem() ) {
		as.Add( m_TreeCtrl->GetItemText(itemID) );
		itemID = m_TreeCtrl->GetItemParent( itemID );
	}
}

void CDialogChooseVirtualFolder::SetCurrentPathArray( wxArrayString& as ) {
	int i;

	if( as.GetCount() == 0 ) return;

	wxTreeItemId fatherID = m_TreeCtrl->GetRootItem();
	i = as.GetCount() - 1;
	while( i >= 0 ) {
		// selects the right child of the current item
		wxTreeItemIdValue cookie;
		wxTreeItemId childID = m_TreeCtrl->GetFirstChild( fatherID, cookie );
		while( childID.IsOk() ) {
			wxString aa = m_TreeCtrl->GetItemText(childID);
			wxString bb = as[i];
			if( m_TreeCtrl->GetItemText(childID) == as[i] ) {
				// found! select this item
				m_TreeCtrl->SelectItem( childID );
				fatherID = childID;
				wxSafeYield();
				break;
			}

			childID = m_TreeCtrl->GetNextChild( fatherID, cookie );
			if( !childID.IsOk() )
				return;		// we did not find the folder
		}

		i--;
	}


}





CDialogChooseVirtualFolder::~CDialogChooseVirtualFolder() {
	m_WindowPosition.SavePosition();
}

