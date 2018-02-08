//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 31 March 2008 7:47:07 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __MATRIX3X4_H_ED95C6A3_8F40_4E93_90BB_36F55E26C45B_
#define __MATRIX3X4_H_ED95C6A3_8F40_4E93_90BB_36F55E26C45B_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "math/math_abi.h"
#include "math/vector4.h"
#include "math/vector3.h"
#include "math/matrix3x4.h"
#include "math/matrix3x3.h"
#include "core/debug/assert.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace math
{

	/// templated 3x4 matrix class.
	template<class T>
    class matrix3x4
    {
    public:
		typedef matrix3x4<T> this_type;
		typedef vector4<T>	 vector_type;
		typedef T			 component_type;
		
    public:
		/// default constructor, does not initialise its components
		matrix3x4();
		
		/// copy constructor
		matrix3x4(const this_type &);
		
		/// construct from 3 vector4's. 
		matrix3x4(const vector_type &r0, const vector_type &r1, const vector_type &r2);
		
		/// construct from a 3x3 matrix and a translation vector
		matrix3x4(const matrix3x3<T>&, const vector3<T>&);
		
		/// create a zero initialised matrix
		static this_type create_zero();
		
		/// assignment operator
		this_type& operator=(const this_type &other);
		
		/// get the i'th row, i in [0-3]
		const vector_type& row(int) const;

		/// set the i'th row, i in [0-3]
		void row(int, const vector_type &);
		
    private:
		vector_type m_rows[3];
    };

#include "math/matrix3x4.inl"

	typedef matrix3x4<core::float32> matrix3x4f;
	typedef matrix3x4<core::float64> matrix3x4d;
	typedef matrix3x4<core::int32>  matrix3x4i;
	
} // end namespace

} // end namespace

#endif // __MATRIX3X4_H_ED95C6A3_8F40_4E93_90BB_36F55E26C45B_
