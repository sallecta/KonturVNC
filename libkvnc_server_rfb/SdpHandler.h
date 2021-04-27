
#ifndef __SDPHANDLER_H__
#define __SDPHANDLER_H__

#include "RfbDispatcherListener.h"
#include "RfbCodeRegistrator.h"

#include "../libkvnc_all_network/RfbInputGate.h"
#include "../libkvnc_all_network/RfbOutputGate.h"
#include "../libkvnc_all_logger/LogWriter.h"

#include "../libkvnc_all_thread/AutoLock.h"

#include "../libkvnc_all_p2p/p2ptransport.h"



class SdpHandler : public RfbDispatcherListener

{
public:
  SdpHandler(RfbCodeRegistrator *registrator,
                             RfbOutputGate *output,
                             LogWriter *log, P2pTransport * p2p);
  virtual ~SdpHandler();
    void sendSDPToClient();

protected:

  virtual void onRequest(UINT32 reqCode, RfbInputGate *input);
  RfbOutputGate *m_output;
  LogWriter *m_log;
  P2pTransport * m_p2p;
};

#endif // __SDPHANDLER_H__
