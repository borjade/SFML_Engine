#include "XBOXController.h"

using namespace std;
XBOXController::XBOXController(int playerNumber)
{
    // Set the Controller Number
    _controllerNum = playerNumber - 1;
}

XBOXController::XBOXController(void)
{
    // Set the Controller Number
    _controllerNum = 0;
}

XBOXController::~XBOXController(void)
{
   
}

XINPUT_STATE XBOXController::GetState()
{
    // Zeroise the state
    ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

    // Get the state
    XInputGetState(_controllerNum, &_controllerState);

    return _controllerState;
}

bool XBOXController::IsConnected()
{
    // Zeroise the state
    ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

    // Get the state
    DWORD Result = XInputGetState(_controllerNum, &_controllerState);

    if(Result == ERROR_SUCCESS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void XBOXController::Vibrate(int leftVal, int rightVal)
{
    // Create a Vibraton State
    XINPUT_VIBRATION Vibration;

    // Zeroise the Vibration
    ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

    // Set the Vibration Values
    Vibration.wLeftMotorSpeed = leftVal;
    Vibration.wRightMotorSpeed = rightVal;

    // Vibrate the controller
    XInputSetState(_controllerNum, &Vibration);
}

float XBOXController::thumbStick()
	{
		XINPUT_STATE state = GetState();

		float LX = state.Gamepad.sThumbLX;

		float magnitude = sqrt(LX * LX);

		float normalizedLX = LX / magnitude;

		float normalizedMagnitude = 0;

		if (magnitude > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
			{
				if(magnitude > 32767) magnitude = 32767;

				magnitude -= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE;
			}

		return magnitude;
	}