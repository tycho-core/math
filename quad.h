//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Friday, 4 July 2008 8:41:37 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __QUAD_H_C82E528D_6D65_46F8_AACB_86040CC60E87_
#define __QUAD_H_C82E528D_6D65_46F8_AACB_86040CC60E87_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "math/math_abi.h"
#include "core/debug/assert.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace math
{

	template<class T>
    class quad
    {
    public:
		quad() {}
		
		quad(const T& v0, const T& v1, const T& v2, const T& v3)
		{
			set(0, v0);
			set(1, v1);
			set(2, v2);
			set(3, v3);
		}
		
		void set(int v, const T& val)
		{
			TYCHO_ASSERT(v >= 0 && v < 4);
			m_vals[v] = val;
		}
		
		const T& get(int v) const
		{
			TYCHO_ASSERT(v >= 0 && v < 4);
			return m_vals[v];			
		}			

		T& get(int v)
		{
			TYCHO_ASSERT(v >= 0 && v < 4);
			return m_vals[v];			
		}			
			
    private:
		T m_vals[4];
    };

} // end namespace
} // end namespace

#endif // __QUAD_H_C82E528D_6D65_46F8_AACB_86040CC60E87_
