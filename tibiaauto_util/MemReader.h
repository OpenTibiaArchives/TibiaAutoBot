// MemReader.h: interface for the CMemReader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMREADER_H__520F2B59_0B82_4188_9DE0_9362EB4062E7__INCLUDED_)
#define AFX_MEMREADER_H__520F2B59_0B82_4188_9DE0_9362EB4062E7__INCLUDED_

#include "TibiaCharacter.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TibiaContainer.h"
#include "TibiaMapPoint.h"
#include "MemConstData.h"
#include "TibiaMiniMap.h"
#include "TibiaMiniMapPoint.h"
#include "TibiaMiniMapLabel.h"
#include "TibiaVIPEntry.h"

class CMemReader  : public CMemConstData
{
public:	
	CMemReader(); 
	virtual ~CMemReader();		
public:
	int getCreatureDeltaY(int creatureNr);
	int getCreatureDeltaX(int creatureNr);
	void setAttackedCreature(int tibiaId);
	void writeCreatureDeltaXY(int creatureNr, int deltaX, int deltaY);
	int getXRayValue2();
	int getXRayValue1();
	void setXRayValues(int v1, int v2);
	int getConnectionState();
	char * getOpenWindowName();
	int getPlayerModeAttackPlayers();
	int getPlayerModeFollow();
	int getPlayerModeAttackType();
	void setMainTrayText(char *text);
	void setMainWindowText(char *text);
	CTibiaMiniMapLabel * readMiniMapLabel(int mapNr,int pointNr);
	CTibiaMiniMapPoint * readMiniMapPoint(int x,int y,int z);
	CTibiaMiniMap * readMiniMap(int nr);
	void setRemainingTilesToGo(int val);
	void writeDisableRevealCName();
	void writeEnableRevealCName();
	long getCurrentTm();
	int mapGetPointItemExtraInfo(point p,int stackNr,int extraPos);
	int mapGetPointStackIndex(point p,int stackNr);
	void mapSetPointItemsCount(point p,int count);
	void mapSetPointItemId(point p, int stackNr, int tileId);
	int mapGetPointItemId(struct point p,int stackNr);
	int mapGetPointItemsCount(struct point p);
	void writeSelfLightColor(int value);
	void writeSelfLightPower(int value);
	int readSelfLightColor();
	int readSelfLightPower();
	int readCreatureLightPower(int creatureNr);
	int readCreatureLightColor(int creatureNr);
	void writeCreatureLightPower(int creatureNr,int value);
	void writeCreatureLightColor(int creatureNr,int value);
	void cancelAttackCoords();
	void writeGotoCoords(int x,int y,int z);
	int getLoggedCharNr();
	int getSelfEventFlags();
	void writeVisibleCreatureName(int chNr,char *name);
	CTibiaItem * getTradeItemPartner(int nr);
	CTibiaItem * getTradeItemSelf(int nr);
	int getTradeCountPartner();
	int getTradeCountSelf();
	int getAttackedCreature();
	char * GetLoggedChar(int processId);
	int readBattleListMax();
	int readBattleListMin();
	CTibiaCharacter * readVisibleCreature(int nr);
	CTibiaContainer *readContainer(int containerNr);
	CTibiaItem * readItem(int locationAddress);
	CTibiaCharacter *readSelfCharacter();
	CTibiaCharacter *getCharacterByTibiaId(int tibiaId);
	CTibiaVIPEntry *readVIPEntry(int nr);

private:
	int dereference(int addr);
	int mapConvertPointToCell(struct point p);
	struct point mapConvertRelPointToPoint(struct point p);
	struct point mapConvertPointToRelPoint(struct point p);
	struct point mapConvertCellToPoint(int cellNr);
	int mapGetSelfCellNr();
	
};

#endif // !defined(AFX_MEMREADER_H__520F2B59_0B82_4188_9DE0_9362EB4062E7__INCLUDED_)
