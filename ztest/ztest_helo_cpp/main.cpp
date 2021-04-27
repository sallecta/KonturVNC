#include <iostream>

#include "../libkvnc_all_rfb/lkvnc_rfb_Defs.cpp"
#include "../libkvnc_all_logger/LogWriter.h"




using namespace std;

int main()
{
    cout << "Hello world!" << lkvnc_rfb_Defs__Client::BEGIN_NEG << endl;
    LogWriter preLog(0);


    return 0;
}
