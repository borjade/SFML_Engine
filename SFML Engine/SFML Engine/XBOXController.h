#ifndef _XBOX_CONTROLLER_H_
#define _XBOX_CONTROLLER_H_

/*

		code for class online found at: http://www.codeproject.com/Articles/26949/Xbox-360-Controller-Input-in-C-with-XInput
*/

// No MFC
#define WIN32_LEAN_AND_MEAN

// We need the Windows Header and the XInput Header
#include <Windows.h>
#include <XInput.h>
#include <cmath>

// Now, the XInput Library
// NOTE: COMMENT THIS OUT IF YOU ARE NOT USING
// A COMPILER THAT SUPPORTS THIS METHOD OF LINKING LIBRARIES
#pragma comment(lib, "XInput.lib")

// XBOX Controller Class Definition
class XBOXController
{
private:
    XINPUT_STATE _controllerState;
    int _controllerNum;
public:
	XBOXController(void);
	~XBOXController(void);
    XBOXController(int playerNumber);
    XINPUT_STATE GetState();
    bool IsConnected();
    void Vibrate(int leftVal = 0, int rightVal = 0);
	float thumbStick();
};

#endif