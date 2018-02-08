//----------------------------------------------------------------------------
// Tycho Library
// Copyright (C) 2018 Martin Slater
// Created : Thursday, 08 February 2018 09:58:28 AM
//----------------------------------------------------------------------------

#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef _MATH_ABI_H_4C7E8D07_188D_48D2_A9E5_F3188FE62FF8
#define _MATH_ABI_H_4C7E8D07_188D_48D2_A9E5_F3188FE62FF8

//----------------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------------


#if TYCHO_PC

// DLL interface
#ifdef TYCHO_MATH_EXPORTS
#define TYCHO_MATH_ABI __declspec(dllexport)
#else
#define TYCHO_MATH_ABI __declspec(dllimport)
#endif 

// disable a few warnings globally. should move these into specific cpp's to avoid polluting
// user header files
#pragma warning(disable : 4251) // class needs to have dll-interface to be used by clients of class ''
#pragma warning(disable : 4355) // 'this' : used in base member initializer list

#else // TYCHO_PC

#define TYCHO_MATH_ABI

#endif // TYCHO_PC


#endif // _MATH_ABI_H_4C7E8D07_188D_48D2_A9E5_F3188FE62FF8
