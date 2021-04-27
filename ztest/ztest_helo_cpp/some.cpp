#include <iostream>

#include "../../libkvnc_all_rfb/lkvnc_rfb_Defs.cpp"

// A function adding two integers and returning the result
int SampleAddInt(int i1, int i2)
{
    int ee = lkvnc_rfb_Defs__Client::SERVER_SDP;
     std::cout <<lkvnc_rfb_Defs__Client::SERVER_SDP;
    switch (i1) {
        case (lkvnc_rfb_Defs__Client::SERVER_SDP):
            break;
        case lkvnc_rfb_Defs__Client::P2P_OK:
            break;
    }



    return ee;
}

// A function doing nothing ;)
void SampleFunction1()
{
    // insert code here
}

// A function always returning zero
int SampleFunction2()
{
    // insert code here

    return 0;
}
