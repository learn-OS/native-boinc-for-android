// This file is part of BOINC.
// http://boinc.berkeley.edu
// Copyright (C) 2008 University of California
//
// BOINC is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
//
// BOINC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with BOINC.  If not, see <http://www.gnu.org/licenses/>.

#ifndef _VIEWMESSAGESGRID_H_
#define _VIEWMESSAGESGRID_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "ViewMessagesGrid.cpp"
#endif


#include "BOINCBaseView.h"
#include "BOINCGridCtrl.h"

class CViewMessagesGrid : public CBOINCBaseView
{
    DECLARE_DYNAMIC_CLASS( CViewMessagesGrid )
    DECLARE_EVENT_TABLE()

public:
    CViewMessagesGrid();
    CViewMessagesGrid(wxNotebook* pNotebook);

    ~CViewMessagesGrid();

    virtual wxString&       GetViewName();
    virtual wxString&       GetViewDisplayName();
    virtual const char**    GetViewIcon();

    void                    OnMessagesCopyAll( wxCommandEvent& event );
    void                    OnMessagesCopySelected( wxCommandEvent& event );

protected:
    virtual bool            OnSaveState( wxConfigBase* pConfig );
    virtual bool            OnRestoreState( wxConfigBase* pConfig );
    virtual void            OnListRender( wxTimerEvent& event );

    virtual wxInt32         GetDocCount();

    virtual void            UpdateSelection();

    wxInt32                 FormatProjectName( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatTime( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatMessage( wxInt32 item, wxString& strBuffer ) const;
	wxInt32                 FormatSeqNo( wxInt32 item, wxString& strBuffer ) const;
	wxInt32                 FormatPriority( wxInt32 item, wxString& strBuffer ) const;

	CBOINCGridCtrl*			m_pGridPane;

#ifdef wxUSE_CLIPBOARD
    bool                    m_bClipboardOpen;
    wxString                m_strClipboardData;
    bool                    OpenClipboard();
    wxInt32                 CopyToClipboard( wxInt32 item );
    bool                    CloseClipboard();
#endif
};

#endif

