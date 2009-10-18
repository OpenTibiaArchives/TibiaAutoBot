// protocol.h : Defines the entry point for the DLL application.
//

#include <string>
#include <iostream>
#include <fstream>

#define NETWORKMESSAGE_MAXSIZE 15360



class NetworkMessage
{
public:
	NetworkMessage();
	NetworkMessage(char* rawMsg);
	virtual	~NetworkMessage(){};

	unsigned char GetByte();
	unsigned int GetInt();
	unsigned short GetShort();
	unsigned char PeekByte();
	unsigned int PeekInt();
	unsigned short PeekShort();
	bool canAdd(int size);
	void Refresh();
	std::string GetString(int stringLen=0);
	void AddByte(unsigned char c);
	void AddInt(unsigned int i);
	void AddShort(unsigned short s);
	void AddString(const char* value);
	void AddBytes(const char* bytes, int size);

	unsigned char msgBuf[NETWORKMESSAGE_MAXSIZE];
	int msgSize,readPos;
};

class Protocol
{
public:
	Protocol(){}
	virtual ~Protocol(){}

	static void Protocol::parsePacket(NetworkMessage &msg);
};
