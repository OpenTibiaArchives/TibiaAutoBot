// mod_cavebot.h : main header file for the MOD_CAVEBOT DLL
//

#if !defined(AFX_MOD_CAVEBOT_H__D1220A19_D7FC_4B51_900D_224C2CAC1CB8__INCLUDED_)
#define AFX_MOD_CAVEBOT_H__D1220A19_D7FC_4B51_900D_224C2CAC1CB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif // ifndef __AFXWIN_H__

#include "resource.h"           // main symbols
#include <IModuleInterface.h>
#include "ConfigDialog.h"

/////////////////////////////////////////////////////////////////////////////
// CMod_cavebotApp
// See mod_cavebot.cpp for the implementation of this class
//

struct Item {
	char name[40];
	int x, y, z;
	Item *prev;
	Item *nxt;
	Item()
	{
		prev    = this;
		nxt     = this;
		name[0] = 0;
		x       = y = z = 0;
	}

	int distance(int x, int y)
	{
		return max(abs(this->x - x), abs(this->y - y));
	}

	void InsertNodeAfter(Item *pred)
	{
		//remove node
		if (prev != NULL)
			prev->nxt = nxt;
		if (nxt != NULL)
			nxt->prev = prev;
		//insert node
		nxt       = pred->nxt;
		prev      = pred;
		pred->nxt = this;
		if (pred->nxt != NULL)
			pred->nxt->prev = this;
	}
};

struct Creature : public Item
{
	int failedAttacks;
	time_t isIgnoredUntil;
	int listPriority;//1 is lowest, 0 means not in attack list
	int hpPercLeft;
	int isAttacking;
	int isOnscreen;
	int isWithinMargins;
	int isInvisible;
	int isDead;
	int number;
	unsigned int tibiaId;
	time_t lastAttackTm;
	Creature()
	{
		lastAttackTm  = isIgnoredUntil = 0;
		failedAttacks = isInvisible = isOnscreen = isWithinMargins = isAttacking = listPriority = isDead = number = tibiaId = x = y = z = 0;
		hpPercLeft    = 100;
		memset(name, 0, 40);
	}
};


struct Corpse
{
	int tod;
	int x, y, z;
	Corpse()
	{
		tod = x = y = z = 0;
	}

	Corpse(int x, int y, int z, int tod)
	{
		this->tod = tod;
		this->x   = x;
		this->y   = y;
		this->z   = z;
	}
};

class CMod_cavebotApp : public IModuleInterface
{
public:
	CMod_cavebotApp();
	~CMod_cavebotApp();
public:
	void resetMultiParamAccess(const char *paramName);
	int isMultiParam(const char *paramName);
	int validateConfig(int showAlerts);
	// functions from IModuleInterface
	char * getName();
	int isStarted();
	void start();
	void stop();
	void getNewSkin(CSkin);
	void showConfigDialog();
	void configToControls();
	void controlsToConfig();
	void disableControls();
	void enableControls();
	char *getVersion();
	void resetConfig();
	void loadConfigParam(const char *paramName, char *paramValue);
	char *saveConfigParam(const char *paramName);
	const char **getConfigParamNames();
private:
	int m_started;
	CConfigDialog * m_configDialog;
	CConfigData *m_configData;
	int m_currentWaypointNr;
	int m_currentMonsterNr;
	int m_currentIgnoreNr;
	int m_currentDepotEntryNr;
	int m_currentDroplistEntryNr;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOD_CAVEBOT_H__D1220A19_D7FC_4B51_900D_224C2CAC1CB8__INCLUDED_)
