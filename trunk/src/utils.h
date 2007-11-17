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

#ifndef __UTILS_H__
#define __UTILS_H__

#include <wx/string.h>
#include <wx/msgdlg.h>
#include <string>

class wxMBConv;

class CUtils
{
public:

	// functions used to convert between std::string e wxString.
	// idea "borrowed" from the FlameRobin source code
	static std::string wx2std(const wxString& input, wxMBConv* conv = wxConvCurrent);
	static wxString std2wx(const std::string& input, wxMBConv* conv = wxConvCurrent);

	// returns the size of a file in human readable format (KB, MB and so on...)
	static wxString HumanReadableFileSize( wxLongLong size );

	// displays an error message
	static void MsgErr( wxString errMsg );

	// displays an information message
	static void MsgInfo( wxString infoMsg );

	// ask a question to the user. possible answers: yes or no (default)
	// returns true if the user has chosen yes
	static bool MsgAskNo( wxString msg );

	// returns the application name
	static wxString GetApplicationName(void);

	// returns the application version
	static wxString GetApplicationVersion(void);

	// returns the expected database version
	static int GetExpectedDatabaseVersion(void);

	// converts a long to a string
	static wxString long2string( long val );

	// returns the name of the database containing the catalog structure changes, used to dynamically update a catalog
	static wxString GetStructUpdateDbName(void);

	// encrypts/decrypts a string with a simple XOR
	static wxString Encrypt( wxString s );

private:
	// name of the current application
	static wxString applicationName;

	// current application version
	static wxString applicationVersion;

	// the current version of the application expects this database version
	static int expectedDatabaseVersion;

	// name of the database that contains the database changes from version to version
	static wxString strucUpdateDbName;

};



#endif
