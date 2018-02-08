//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Thursday, 17 April 2008 2:30:29 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __UTILITIES_H_7CEC46B3_51BC_4417_A9E2_C7BA2E7B6941_
#define __UTILITIES_H_7CEC46B3_51BC_4417_A9E2_C7BA2E7B6941_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "math/math_abi.h"
#include <math.h>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace math
{

	TYCHO_MATH_ABI void initialise();
	
	
	/////////////////////////////////////////////////////////////////////////
	// core::float32 overloads
	/////////////////////////////////////////////////////////////////////////
	
	/// \name trigonometric functions
	//@{	
	inline core::float32 asin(core::float32 v)	{ return ::asinf(v); }	
	inline core::float32 acos(core::float32 v)	{ return ::acosf(v); }
	inline core::float32 atan(core::float32 v)	{ return ::atanf(v);}
	inline core::float32 atan2(core::float32 x, core::float32 y) { return ::atan2f(x, y);}	
	inline core::float32 sin(core::float32 v)	{ return ::sinf(v);	}	
	inline core::float32 cos(core::float32 v)	{ return ::cosf(v);	}
	inline core::float32 tan(core::float32 v)	{ return ::tanf(v);	}
	//@}

	/// \name hyperbolic functions
	//@{	
	inline core::float32 cosh(core::float32 v)	{ return ::coshf(v);	}
	inline core::float32 sinh(core::float32 v)	{ return ::sinhf(v);	}
	inline core::float32 tanh(core::float32 v)	{ return ::tanhf(v);	}
	//@}
	
	/// \name power functions
	//@{	
	inline core::float32 pow(core::float32 x, core::float32 y) { return ::powf(x, y); }
	inline core::float32 sqrt(core::float32 v)	{ return ::sqrtf(v); }		
	//@}
	
	/// \name exponential and logarithmic functions
	//@{	
	inline core::float32 exp(core::float32 v)	{ return ::expf(v);	}
	inline core::float32 log(core::float32 v)	{ return ::logf(v);	}
	inline core::float32 log10(core::float32 v)	{ return ::log10f(v); }
	//@}
	
	/// \name nearest integer, absolute value, and remainder functions
	//@{	
	inline core::float32 ceil(core::float32 v) { return ::ceil(v); }
	inline core::float32 floor(core::float32 v) { return ::floorf(v); }
	inline core::float32 fmod(core::float32 x, core::float32 y) { return ::fmodf(x, y); }
	//@}
		
	/////////////////////////////////////////////////////////////////////////
	// core::float64 overloads
	/////////////////////////////////////////////////////////////////////////
		
	/// \name trigonometric functions
	//@{	
	inline core::float64 asin(core::float64 v)	{ return ::asin(v); }	
	inline core::float64 acos(core::float64 v)	{ return ::acos(v); }
	inline core::float64 atan(core::float64 v)	{ return ::atan(v);}
	inline core::float64 atan2(core::float64 x, core::float64 y)	{ return ::atan2(x, y);}	
	inline core::float64 sin(core::float64 v)	{ return ::sin(v);	}	
	inline core::float64 cos(core::float64 v)	{ return ::cos(v);	}
	inline core::float64 tan(core::float64 v)	{ return ::tan(v);	}
	//@}

	/// \name hyperbolic functions
	//@{	
	inline core::float64 cosh(core::float64 v)	{ return ::cosh(v);	}
	inline core::float64 sinh(core::float64 v)	{ return ::sinh(v);	}
	inline core::float64 tanh(core::float64 v)	{ return ::tanh(v);	}
	//@}
	
	/// \name power functions
	//@{	
	inline core::float64 pow(core::float64 x, core::float64 y) { return ::pow(x, y); }
	inline core::float64 sqrt(core::float64 v)	{ return ::sqrt(v); }		
	//@}
	
	/// \name exponential and logarithmic functions
	//@{	
	inline core::float64 exp(core::float64 v)	{ return ::exp(v);	}
	inline core::float64 log(core::float64 v)	{ return ::log(v);	}
	inline core::float64 log10(core::float64 v)	{ return ::log10(v); }
	//@}
	
	/// \name nearest integer, absolute value, and remainder functions
	//@{	
	inline core::float64 ceil(core::float64 v) { return ::ceil(v); }
	inline core::float64 floor(core::float64 v) { return ::floor(v); }
	inline core::float64 fmod(core::float64 x, core::float64 y) { return ::fmod(x, y); }
	//@}

	/////////////////////////////////////////////////////////////////////////
	// templated functions
	/////////////////////////////////////////////////////////////////////////

	/// \returns t * t
	template<class T> 
	inline T square(T t)
	{
		return t * t;
	}
	
	template<class T>
	inline void sincos(T v, T &out_sin, T &out_cos)	
	{
		/// \todo can do in single op in asm
		out_sin = math::sin(v);
		out_cos = math::cos(v);
	}

	/// \returns the cotangent of v.
	template<class T> 
	inline T cot(T v)	
	{
		T s, c;
		math::sincos(v, s, c);
		return c / s;
	}
	
	template<class T>
	inline T clamp(T val, T min, T max)
	{
		if(val < min) return min;
		if(val > max) return max;
		return val;
	}

	template<class T>
	inline T lerp(T val, T min, T max)
	{
		if(val >= 1.0f)
			return max;
		if(val <= 0.0f)
			return min;
		return min + (max - min) * val;
	}

	template<class T>
	inline T min(T v1, T v2)
	{
		if(v1 < v2)
			return v1;
		return v2;
	}

	template<class T>
	inline T max(T v1, T v2)
	{
		if(v1 > v2)
			return v1;
		return v2;
	}

	
} // end namespace
} // end namespace

#endif // __UTILITIES_H_7CEC46B3_51BC_4417_A9E2_C7BA2E7B6941_
