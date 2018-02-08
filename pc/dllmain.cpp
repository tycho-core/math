//----------------------------------------------------------------------------
// Tycho Library
// Copyright (C) 2018 Martin Slater
// Created : Thursday, 08 February 2018 09:58:28 AM
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------------
#include "core/pc/safe_windows.h"

#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE /*hModule*/,
                       DWORD  /*ul_reason_for_call*/,
                       LPVOID /*lpReserved*/
					 )
{
    return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif


