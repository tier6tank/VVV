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

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "settings.h"
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
#include "wx/bookctrl.h"
////@end includes

#include "settings.h"
#include "vvv.h"
#include "ibpp.h"
#include "chooselang.h"

////@begin XPM images
////@end XPM images


/*!
 * CDialogSettings type definition
 */

IMPLEMENT_DYNAMIC_CLASS( CDialogSettings, wxPropertySheetDialog )


/*!
 * CDialogSettings event table definition
 */

BEGIN_EVENT_TABLE( CDialogSettings, wxPropertySheetDialog )

////@begin CDialogSettings event table entries
    EVT_BUTTON( ID_BTN_CHANGE_LANGUAGE, CDialogSettings::OnBtnChangeLanguageClick )
    EVT_UPDATE_UI( ID_DS_SERVERNAME, CDialogSettings::OnDsServernameUpdate )
    EVT_UPDATE_UI( ID_DS_USERNAME, CDialogSettings::OnDsUsernameUpdate )
    EVT_UPDATE_UI( ID_DS_PASSWORD, CDialogSettings::OnDsPasswordUpdate )
    EVT_BUTTON( ID_DS_TEST_CONNECTION, CDialogSettings::OnDsTestConnectionClick )
    EVT_UPDATE_UI( ID_DS_TEST_CONNECTION, CDialogSettings::OnDsTestConnectionUpdate )
////@end CDialogSettings event table entries

    EVT_BUTTON( wxID_HELP, CDialogSettings::OnHelpClick )

END_EVENT_TABLE()


/*!
 * CDialogSettings constructors
 */

CDialogSettings::CDialogSettings()
{
    Init();
}

CDialogSettings::CDialogSettings( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * CDialogSettings creator
 */

bool CDialogSettings::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin CDialogSettings creation
    SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY|wxWS_EX_BLOCK_EVENTS);
    SetSheetStyle(wxPROPSHEET_DEFAULT);
    wxPropertySheetDialog::Create( parent, id, caption, pos, size, style );

    CreateButtons(wxOK|wxCANCEL|wxHELP);
    CreateControls();
    LayoutDialog();
    Centre();
////@end CDialogSettings creation

	m_WindowPosition.SetWindow( this );
	m_WindowPosition.RestorePosition();

    return true;
}


/*!
 * CDialogSettings destructor
 */

CDialogSettings::~CDialogSettings()
{
////@begin CDialogSettings destruction
////@end CDialogSettings destruction
	
	m_WindowPosition.SavePosition();
}


/*!
 * Member initialisation
 */

void CDialogSettings::Init()
{
////@begin CDialogSettings member initialisation
    m_BeepTimeCtrl = NULL;
    m_chkCatalogAudioMetadata = NULL;
    m_chkArtist = NULL;
    m_chkAlbum = NULL;
    m_chkTitle = NULL;
    m_chkYear = NULL;
    m_chkComment = NULL;
    m_chkTrackNumber = NULL;
    m_chkGenre = NULL;
    m_chkLength = NULL;
    m_chkBitrate = NULL;
    m_chkSampleRate = NULL;
    m_chkChannels = NULL;
    m_ConnectServerCtrl = NULL;
    m_ServerNameCtrl = NULL;
    m_UsernameCtrl = NULL;
    m_PasswordCtrl = NULL;
////@end CDialogSettings member initialisation
}


/*!
 * Control creation for CDialogSettings
 */

void CDialogSettings::CreateControls()
{    
////@begin CDialogSettings content construction
    CDialogSettings* itemPropertySheetDialog1 = this;

    wxPanel* itemPanel2 = new wxPanel( GetBookCtrl(), ID_DS_GENERAL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
    itemPanel2->SetSizer(itemBoxSizer3);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer3->Add(itemBoxSizer4, 0, wxGROW|wxALL, 5);
    wxCheckBox* itemCheckBox5 = new wxCheckBox( itemPanel2, ID_DS_REOPEN_CATALOG, _("Reopen the last used catalog at startup"), wxDefaultPosition, wxDefaultSize, 0 );
    itemCheckBox5->SetValue(false);
    itemBoxSizer4->Add(itemCheckBox5, 0, wxALIGN_LEFT|wxALL, 5);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer4->Add(itemBoxSizer6, 0, wxALIGN_LEFT|wxALL, 5);
    wxStaticText* itemStaticText7 = new wxStaticText( itemPanel2, wxID_STATIC, _("Beep for tasks longer than (seconds):"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer6->Add(itemStaticText7, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP|wxBOTTOM, 5);

    m_BeepTimeCtrl = new wxSpinCtrl( itemPanel2, ID_SPIN_BEEP_TIME, wxT("0"), wxDefaultPosition, wxSize(60, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemBoxSizer6->Add(m_BeepTimeCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer4->Add(5, 5, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton10 = new wxButton( itemPanel2, ID_BTN_CHANGE_LANGUAGE, _("Change language"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemButton10, 0, wxALIGN_LEFT|wxALL, 5);

    GetBookCtrl()->AddPage(itemPanel2, _("General"));

    wxPanel* itemPanel11 = new wxPanel( GetBookCtrl(), ID_DS_MP3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxVERTICAL);
    itemPanel11->SetSizer(itemBoxSizer12);

    wxBoxSizer* itemBoxSizer13 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer12->Add(itemBoxSizer13, 0, wxGROW|wxALL, 5);
    m_chkCatalogAudioMetadata = new wxCheckBox( itemPanel11, wxID_ANY, _("Catalog audio metadata"), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkCatalogAudioMetadata->SetValue(false);
    itemBoxSizer13->Add(m_chkCatalogAudioMetadata, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer13->Add(2, 2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    wxStaticText* itemStaticText16 = new wxStaticText( itemPanel11, wxID_STATIC, _("Show the following data for audio files:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer13->Add(itemStaticText16, 0, wxALIGN_LEFT|wxALL, 5);

    m_chkArtist = new wxCheckBox( itemPanel11, ID_DS_ARTIST, _("Artist"), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkArtist->SetValue(false);
    itemBoxSizer13->Add(m_chkArtist, 0, wxALIGN_LEFT|wxALL, 5);

    m_chkAlbum = new wxCheckBox( itemPanel11, ID_DS_ALBUM, _("Album"), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkAlbum->SetValue(false);
    itemBoxSizer13->Add(m_chkAlbum, 0, wxALIGN_LEFT|wxALL, 5);

    m_chkTitle = new wxCheckBox( itemPanel11, ID_DS_TITLE, _("Title"), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkTitle->SetValue(false);
    itemBoxSizer13->Add(m_chkTitle, 0, wxALIGN_LEFT|wxALL, 5);

    m_chkYear = new wxCheckBox( itemPanel11, ID_DS_YEAR, _("Year"), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkYear->SetValue(false);
    itemBoxSizer13->Add(m_chkYear, 0, wxALIGN_LEFT|wxALL, 5);

    m_chkComment = new wxCheckBox( itemPanel11, ID_DS_COMMENT, _("Comment"), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkComment->SetValue(false);
    itemBoxSizer13->Add(m_chkComment, 0, wxALIGN_LEFT|wxALL, 5);

    m_chkTrackNumber = new wxCheckBox( itemPanel11, ID_DS_TRACK_NUMBER, _("Track number"), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkTrackNumber->SetValue(false);
    itemBoxSizer13->Add(m_chkTrackNumber, 0, wxALIGN_LEFT|wxALL, 5);

    m_chkGenre = new wxCheckBox( itemPanel11, ID_DS_GENRE, _("Genre"), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkGenre->SetValue(false);
    itemBoxSizer13->Add(m_chkGenre, 0, wxALIGN_LEFT|wxALL, 5);

    m_chkLength = new wxCheckBox( itemPanel11, ID_DS_LENGTH, _("Length"), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkLength->SetValue(false);
    itemBoxSizer13->Add(m_chkLength, 0, wxALIGN_LEFT|wxALL, 5);

    m_chkBitrate = new wxCheckBox( itemPanel11, ID_DS_BITRATE, _("Bitrate"), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkBitrate->SetValue(false);
    itemBoxSizer13->Add(m_chkBitrate, 0, wxALIGN_LEFT|wxALL, 5);

    m_chkSampleRate = new wxCheckBox( itemPanel11, ID_DS_SAMPLE_RATE, _("Sample rate"), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkSampleRate->SetValue(false);
    itemBoxSizer13->Add(m_chkSampleRate, 0, wxALIGN_LEFT|wxALL, 5);

    m_chkChannels = new wxCheckBox( itemPanel11, ID_DS_CHANNELS, _("Channels"), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkChannels->SetValue(false);
    itemBoxSizer13->Add(m_chkChannels, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer13->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    GetBookCtrl()->AddPage(itemPanel11, _("Audio files"));

    wxPanel* itemPanel29 = new wxPanel( GetBookCtrl(), ID_DS_SERVER, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer30 = new wxBoxSizer(wxVERTICAL);
    itemPanel29->SetSizer(itemBoxSizer30);

    wxBoxSizer* itemBoxSizer31 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer30->Add(itemBoxSizer31, 0, wxGROW|wxALL, 5);
    wxStaticText* itemStaticText32 = new wxStaticText( itemPanel29, wxID_STATIC, _("Check the checkbox below if you want to access catalogs stored\nin a network server. Each computer in the network will be able to\naccess the same catalogs stored in the server.\nDO NOT check the checkbox if you only want to access catalogs\nstored in this computer and you do not want to share them\nwith other computers."), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
    itemBoxSizer31->Add(itemStaticText32, 0, wxGROW|wxALL, 5);

    itemBoxSizer31->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_ConnectServerCtrl = new wxCheckBox( itemPanel29, ID_DS_CONNECT_SERVER, _("Connect to a network server"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ConnectServerCtrl->SetValue(false);
    itemBoxSizer31->Add(m_ConnectServerCtrl, 0, wxALIGN_LEFT|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer35 = new wxFlexGridSizer(3, 2, 0, 0);
    itemBoxSizer31->Add(itemFlexGridSizer35, 0, wxGROW|wxALL, 5);
    wxStaticText* itemStaticText36 = new wxStaticText( itemPanel29, wxID_STATIC, _("Server"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer35->Add(itemStaticText36, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ServerNameCtrl = new wxTextCtrl( itemPanel29, ID_DS_SERVERNAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer35->Add(m_ServerNameCtrl, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText38 = new wxStaticText( itemPanel29, wxID_STATIC, _("Username"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer35->Add(itemStaticText38, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_UsernameCtrl = new wxTextCtrl( itemPanel29, ID_DS_USERNAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer35->Add(m_UsernameCtrl, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText40 = new wxStaticText( itemPanel29, wxID_STATIC, _("Password"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer35->Add(itemStaticText40, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PasswordCtrl = new wxTextCtrl( itemPanel29, ID_DS_PASSWORD, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
    itemFlexGridSizer35->Add(m_PasswordCtrl, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer35->AddGrowableCol(1);

    itemBoxSizer31->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton43 = new wxButton( itemPanel29, ID_DS_TEST_CONNECTION, _("Test server connection"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer31->Add(itemButton43, 0, wxALIGN_RIGHT|wxALL, 5);

    GetBookCtrl()->AddPage(itemPanel29, _("Server"));

    // Set validators
    itemCheckBox5->SetValidator( wxGenericValidator(& m_ReopenCatalog) );
    m_BeepTimeCtrl->SetValidator( wxGenericValidator(& m_BeepTime) );
    m_chkCatalogAudioMetadata->SetValidator( wxGenericValidator(& m_CatalogAudioMetadata) );
    m_ConnectServerCtrl->SetValidator( wxGenericValidator(& m_ConnectServer) );
    m_ServerNameCtrl->SetValidator( wxGenericValidator(& m_ServerName) );
    m_UsernameCtrl->SetValidator( wxGenericValidator(& m_Username) );
    m_PasswordCtrl->SetValidator( wxGenericValidator(& m_Password) );
////@end CDialogSettings content construction
}


/*!
 * Should we show tooltips?
 */

bool CDialogSettings::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap CDialogSettings::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin CDialogSettings bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end CDialogSettings bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon CDialogSettings::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin CDialogSettings icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end CDialogSettings icon retrieval
}


bool CDialogSettings::TransferDataToWindow() {

	m_chkArtist->SetValue( m_amdColumnsToShow[CMainFrame::amdArtist] );
	m_chkAlbum->SetValue( m_amdColumnsToShow[CMainFrame::amdAlbum] );
	m_chkTitle->SetValue( m_amdColumnsToShow[CMainFrame::amdTitle] );
	m_chkYear->SetValue( m_amdColumnsToShow[CMainFrame::amdYear] );
	m_chkGenre->SetValue( m_amdColumnsToShow[CMainFrame::amdGenre] );
	m_chkLength->SetValue( m_amdColumnsToShow[CMainFrame::amdLength] );
	m_chkComment->SetValue( m_amdColumnsToShow[CMainFrame::amdComment] );
	m_chkTrackNumber->SetValue( m_amdColumnsToShow[CMainFrame::amdNumber] );
	m_chkBitrate->SetValue( m_amdColumnsToShow[CMainFrame::amdBitrate] );
	m_chkSampleRate->SetValue( m_amdColumnsToShow[CMainFrame::amdSampleRate] );
	m_chkChannels->SetValue( m_amdColumnsToShow[CMainFrame::amdChannels] );

	return wxPropertySheetDialog::TransferDataToWindow();
}


bool CDialogSettings::TransferDataFromWindow() {

	wxPropertySheetDialog::TransferDataFromWindow();

	m_amdColumnsToShow[CMainFrame::amdArtist] = m_chkArtist->GetValue();
	m_amdColumnsToShow[CMainFrame::amdAlbum] = m_chkAlbum->GetValue();
	m_amdColumnsToShow[CMainFrame::amdTitle] = m_chkTitle->GetValue();
	m_amdColumnsToShow[CMainFrame::amdYear] = m_chkYear->GetValue();
	m_amdColumnsToShow[CMainFrame::amdComment] = m_chkComment->GetValue();
	m_amdColumnsToShow[CMainFrame::amdNumber] = m_chkTrackNumber->GetValue();
	m_amdColumnsToShow[CMainFrame::amdGenre] = m_chkGenre->GetValue();
	m_amdColumnsToShow[CMainFrame::amdLength] = m_chkLength->GetValue();
	m_amdColumnsToShow[CMainFrame::amdBitrate] = m_chkBitrate->GetValue();
	m_amdColumnsToShow[CMainFrame::amdSampleRate] = m_chkSampleRate->GetValue();
	m_amdColumnsToShow[CMainFrame::amdChannels] = m_chkChannels->GetValue();

	bool ok = true;
	if( m_ConnectServer ) {
		if( ok && m_ServerName.empty() ) {
			ok = false;
			CUtils::MsgErr( _("You must enter a server name or address") );
		}
		if( ok && m_Username.empty() ) {
			ok = false;
			CUtils::MsgErr( _("You must enter a username") );
		}
		if( ok && m_Password.empty() ) {
			ok = false;
			CUtils::MsgErr( _("You must enter a password") );
		}
	}

	return ok;
}






/*!
 * wxEVT_UPDATE_UI event handler for ID_DS_TEST_CONNECTION
 */

void CDialogSettings::OnDsTestConnectionUpdate( wxUpdateUIEvent& event )
{
	event.Enable( m_ConnectServerCtrl->IsChecked() );
}


/*!
 * wxEVT_UPDATE_UI event handler for ID_DS_SERVERNAME
 */

void CDialogSettings::OnDsServernameUpdate( wxUpdateUIEvent& event )
{
	event.Enable( m_ConnectServerCtrl->IsChecked() );
}


/*!
 * wxEVT_UPDATE_UI event handler for ID_DS_USERNAME
 */

void CDialogSettings::OnDsUsernameUpdate( wxUpdateUIEvent& event )
{
	event.Enable( m_ConnectServerCtrl->IsChecked() );
}


/*!
 * wxEVT_UPDATE_UI event handler for ID_DS_PASSWORD
 */

void CDialogSettings::OnDsPasswordUpdate( wxUpdateUIEvent& event )
{
	event.Enable( m_ConnectServerCtrl->IsChecked() );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DS_TEST_CONNECTION
 */

void CDialogSettings::OnDsTestConnectionClick( wxCommandEvent& WXUNUSED(event) )
{
	wxString sn;
	wxBusyCursor bc;

	sn = m_ServerNameCtrl->GetValue();
	if( sn.empty() ) {
		CUtils::MsgErr( _("You must enter the server name or address") );
		return;
	}

	if( !CBaseDB::GetDatabase()->TestServerConnection(sn) )
		CUtils::MsgErr( _("Unable to connect to the server" ) );
	else
		CUtils::MsgInfo( _("Server connection successful") );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void CDialogSettings::OnHelpClick( wxCommandEvent& WXUNUSED(event) )
{
	int nPageSelected = GetBookCtrl()->GetSelection();
	switch( nPageSelected ) {
		case 0:
			wxGetApp().GetHelpController()->DisplaySection( wxT("general_settings.htm") );
			break;
		case 1:
			wxGetApp().GetHelpController()->DisplaySection( wxT("mp3_settings.htm") );
			break;
		case 2:
			wxGetApp().GetHelpController()->DisplaySection( wxT("server_settings.htm") );
			break;
	}
}



/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_CHANGE_LANGUAGE
 */

void CDialogSettings::OnBtnChangeLanguageClick( wxCommandEvent& WXUNUSED(event) )
{
    ChangeUILanguage();
}

