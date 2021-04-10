#ifndef __STATSENDER_H__
#define __STATSENDER_H__

#include "../libkvnc_thread/Thread.h"
#include "../libkvnc_win_system/WindowsEvent.h"
#include "../libkvnc_network/socket/SocketIPv4.h"
#include "../tvnviewer/ConnectionData.h"
#include "../libkvnc_util/AnsiStringStorage.h"



class StatSender : public Thread
{
public:
  StatSender(ConnectionData * condata, P2pTransport * p2p);
  void setComment(StringStorage * comment);
  virtual ~StatSender();


protected:
	virtual void execute();
	virtual void onTerminate();
private:
	WindowsEvent m_sleepTimer;
	ConnectionData * m_condata;
	AnsiStringStorage ausername;
	AnsiStringStorage avp;
	AnsiStringStorage acomment;
	P2pTransport * m_p2p;
};

#endif // __STATSENDER_H__
