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

#ifndef wxADJUST_MINSIZE
#define wxADJUST_MINSIZE 0
#endif

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
#include "wx/mstream.h"
////@end includes

#include <wx/utils.h>
#include <wx/config.h>
#include "catalog_volume.h"
#include "vvv.h"
#include "utils.h"
#include "long_task_beep.h"
#include "catalog_volume_functions.h"
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
    EVT_BUTTON( ID_VOLUME_BROWSE, CDialogCatalogVolume::OnVolumeBrowseClick )
#if defined(__WXMSW__)
    EVT_BUTTON( ID_GET_VOLUME_NAME, CDialogCatalogVolume::OnGetVolumeNameClick )
#endif

    EVT_BUTTON( wxID_HELP, CDialogCatalogVolume::OnHelpClick )
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

	wxConfigBase *pConfig = wxConfigBase::Get();
	pConfig->SetPath(wxT("/CatalogVolume"));
	wxString catalogPath = pConfig->Read( wxT("CatalogPath"), wxT("") );
	m_VolumePath->SetValue( catalogPath );
	
	m_WindowPosition.SetWindow( this );
	m_WindowPosition.RestorePosition();

	return true;
}

/*!
 * Member initialisation 
 */

void CDialogCatalogVolume::Init()
{
////@begin CDialogCatalogVolume member initialisation
    m_VolumePath = NULL;
    m_VolumeBrowse = NULL;
    m_VolumeName = NULL;
#if defined(__WXMSW__)
    m_GetVolumeNameButton = NULL;
#endif
    m_HelpButton = NULL;
    m_CatalogButton = NULL;
    m_CloseButton = NULL;
    m_CurrentFolder = NULL;
    m_HistoryListBox = NULL;
////@end CDialogCatalogVolume member initialisation
	m_realVolumeName = wxEmptyString;
	m_CatalogAudioMetadata = true;
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

    wxStaticText* itemStaticText3 = new wxStaticText( itemDialog1, wxID_STATIC, _("Enter or select the volume to catalog"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_LEFT|wxALL|wxADJUST_MINSIZE, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer4, 0, wxGROW|wxBOTTOM, 5);

    m_VolumePath = new wxTextCtrl( itemDialog1, ID_VOLUME_PATH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(m_VolumePath, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_VolumeBrowse = new wxButton( itemDialog1, ID_VOLUME_BROWSE, _("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    itemBoxSizer4->Add(m_VolumeBrowse, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP|wxBOTTOM, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemDialog1, wxID_STATIC, _("Volume name"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText7, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP|wxADJUST_MINSIZE, 5);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer8, 0, wxGROW|wxBOTTOM, 5);

    m_VolumeName = new wxTextCtrl( itemDialog1, ID_VOLUME_NAME, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0 );
    itemBoxSizer8->Add(m_VolumeName, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

#if defined(__WXMSW__)
    m_GetVolumeNameButton = new wxButton( itemDialog1, ID_GET_VOLUME_NAME, _("Get volume name"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer8->Add(m_GetVolumeNameButton, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP|wxBOTTOM, 5);

#endif

    wxBoxSizer* itemBoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer11, 0, wxGROW|wxTOP|wxBOTTOM, 5);

    m_HelpButton = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer11->Add(m_HelpButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer11->Add(5, 5, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CatalogButton = new wxButton( itemDialog1, ID_BUTTON_CATALOG, _("Catalog"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer11->Add(m_CatalogButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CloseButton = new wxButton( itemDialog1, wxID_CANCEL, _("&Close"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer11->Add(m_CloseButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CurrentFolder = new wxStaticText( itemDialog1, ID_CURRENT_FOLDER, _("Current folder"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(m_CurrentFolder, 0, wxGROW|wxALL|wxADJUST_MINSIZE, 5);

    wxStaticText* itemStaticText17 = new wxStaticText( itemDialog1, wxID_STATIC, _("Previously cataloged volumes"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText17, 0, wxALIGN_LEFT|wxALL, 5);

    wxArrayString m_HistoryListBoxStrings;
    m_HistoryListBox = new wxListBox( itemDialog1, ID_LISTBOX_HISTORY, wxDefaultPosition, wxSize(-1, 80), m_HistoryListBoxStrings, wxLB_SINGLE );
    itemBoxSizer2->Add(m_HistoryListBox, 1, wxGROW|wxALL, 5);

////@end CDialogCatalogVolume content construction

	m_CurrentFolder->SetLabel( wxEmptyString );
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

#ifdef __WXMSW__
void CDialogCatalogVolume::OnGetVolumeNameClick( wxCommandEvent& WXUNUSED(event) ) {
	wxString path = m_VolumePath->GetValue();
	if( !path.EndsWith(wxT("\\")) )
		path += wxT("\\");
	wxString vn = GetVolumeName( path );
	m_VolumeName->SetValue( vn );
	m_realVolumeName = vn;
}
#endif


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CATALOG
 */

void CDialogCatalogVolume::OnButtonCatalogClick( wxCommandEvent& WXUNUSED(event) )
{
	wxString path = m_VolumePath->GetValue();
	if( path == wxEmptyString ) {
		CUtils::MsgErr( _("The volume path is missing") );
		return;
	}
	wxString vn = m_VolumeName->GetValue();
	if( vn == wxEmptyString ) {
		CUtils::MsgErr( _("The volume name is missing") );
		return;
	}

	wxBusyCursor bc;
	CLongTaskBeep ltb;

	EnableDisableControls( false );

	// creates an object that will be used to catalog data
	CCatalogVolumeFunctions cvf( m_CurrentFolder, m_CatalogAudioMetadata );
	try {
		cvf.CatalogVolume( path, vn );
	}
	catch( CDataErrorException& e ) {
		if( e.GetErrorCause() == CDataErrorException::ecUnique ) {
			EnableDisableControls( true );
			CUtils::MsgErr( _("This volume name is already present in the database") );
			return;
		}
		else
			throw;
	}

	EnableDisableControls( true );

	// adds this volume to the history listbox
	wxString s = m_VolumeName->GetValue();
	if( !m_realVolumeName.empty() )
		s += wxT(" - ") + m_realVolumeName;
	m_HistoryListBox->InsertItems( 1, &s, 0 );

	m_VolumeName->SetValue( wxEmptyString );
	m_CurrentFolder->SetLabel( wxEmptyString );
	m_realVolumeName = wxEmptyString;
}

CDialogCatalogVolume::~CDialogCatalogVolume() {

	wxConfigBase *pConfig = wxConfigBase::Get();
	pConfig->SetPath(wxT("/CatalogVolume"));
	wxString catalogPath = m_VolumePath->GetValue();
	pConfig->Write( wxT("CatalogPath"), catalogPath );

	m_WindowPosition.SavePosition();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void CDialogCatalogVolume::OnHelpClick( wxCommandEvent& WXUNUSED(event) )
{
	wxGetApp().GetHelpController()->DisplaySection( wxT("catalog_volume.htm") );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_VOLUME_BROWSE
 */

void CDialogCatalogVolume::OnVolumeBrowseClick( wxCommandEvent& WXUNUSED(event) )
{
	wxDirDialog dlg( this, _("Select the volume to catalog"), wxEmptyString, wxDD_DEFAULT_STYLE|wxDD_DIR_MUST_EXIST );
	if( dlg.ShowModal() == wxID_OK )
		m_VolumePath->SetValue( dlg.GetPath() );
}

void CDialogCatalogVolume::EnableDisableControls( bool enabled ) {

	m_VolumeBrowse->Enable( enabled );
	m_HelpButton->Enable( enabled );
	m_CatalogButton->Enable( enabled );
	m_CloseButton->Enable( enabled );
#ifdef __WXMSW__
	m_GetVolumeNameButton->Enable( enabled );
#endif
}

