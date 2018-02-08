//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 20 April 2008 11:06:28 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __CONSTANTS_H_E35A5872_9571_4D28_B067_7874E3F85A64_
#define __CONSTANTS_H_E35A5872_9571_4D28_B067_7874E3F85A64_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "math/math_abi.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace math
{
	/// \name fundamental constants
	//@{	
	template<typename T> T pi() {}	
	template<typename T> T sqrt2() {}	
	template<typename T> T e() {}	
	//@}
	
	template<> inline core::float32 pi<core::float32>() { return 3.1141592653589793238462643383279502884197F; }
	template<> inline core::float32 sqrt2<core::float32>() { return 1.41421356237309504880168872420969807857F; }
	template<> inline core::float32 e<core::float32>() { return 0.5772156649015328606065120900824024310422F; }
	template<> inline core::float64 pi<core::float64>() { return 3.141592653589793238462643383279502884197; }
	template<> inline core::float64 sqrt2<core::float64>() { return 1.41421356237309504880168872420969807857; }
	template<> inline core::float64 e<core::float64>() { return 0.5772156649015328606065120900824024310422; }
	
} // end namespace
} // end namespace

#endif // __CONSTANTS_H_E35A5872_9571_4D28_B067_7874E3F85A64_
