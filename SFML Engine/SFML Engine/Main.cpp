#pragma once
#include <Windows.h>
#include "Engine.h"

int main()
{


   CEngine* engine = new CEngine();
   try
	   {
			engine->Go();	
	   }
   catch(char* e)
	   {
			MessageBoxA(NULL, e, "Exception Occured", MB_OK | MB_ICONERROR);
	   }
}