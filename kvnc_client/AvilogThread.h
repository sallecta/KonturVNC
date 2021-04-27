#pragma once
#include "../libkvnc_all_thread/Thread.h"
#include "../!external/lib_avilog/AVIGenerator.h"
#include "../libkvnc_all_Logger/LogWriter.h"
#include "../libkvnc_all_rfb/lkvnc_rfb_FrameBuffer.h"
#include "../libkvnc_all_thread/GlobalMutex.h"

class AvilogThread :
	public Thread
{
public:
	AvilogThread(const lkvnc_rfb_FrameBuffer *, bool isAutoStart);
	~AvilogThread();
	void UpdateAvilog();
	void SetCursorPos(Rect cursorpos);
	void setPort(int port);

	GlobalMutex m_mutex;
	bool m_isRecord;

protected:
	virtual void execute();

	const lkvnc_rfb_FrameBuffer * m_frame;
	void *m_buffer;
	BYTE *m_tempbuffer;
	size_t m_bufferLen;
	BITMAPINFOHEADER  bmiHeader;
	Rect crect;
	int m_port;
	CAVIGenerator *m_avilog;
};
