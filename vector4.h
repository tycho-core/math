//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 31 March 2008 7:46:40 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __VECTOR4_H_5E7151BC_A6DE_476F_8560_39FB2E2D4E3A_
#define __VECTOR4_H_5E7151BC_A6DE_476F_8560_39FB2E2D4E3A_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "math/math_abi.h"
#include "math/utilities.h"
#include "math/vector3.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace math
{
	
	/// 4 dimensional vector.
	template<class T> class vector4
	{
	public:
		typedef vector4<T> this_type;

	public:
		vector4();
		vector4(T x, T y, T z, T w);
		vector4(const vector3<T> &);
		vector4(const vector3<T> &, T);
		
		T x();
		T x() const;
		T y();
		T y() const;
		T z();
		T z() const;
		T w();
		T w() const;

		void x(T x);
		void y(T y);
		void z(T z);
		void w(T w);

		/// compute dot product
		T dot(const this_type &v) const;
		
		/// multiply each component by itself
		this_type square(const this_type &v) const;
		
		/// unary minus operator
		this_type operator-() const;
		
		/// plus operator
		this_type operator+(const this_type &v) const;
		
		/// minus operator
		this_type operator-(const this_type &v) const; 
		
		/// multiply each component by a scalar
		this_type operator*(T t) const;

		/// dived each component by a scalar
		this_type operator/(T t) const;
		
		/// 
		this_type& operator +=(const this_type &v);
		this_type& operator -=(const this_type &v);
		this_type& operator *=(T t);
		this_type& operator /=(T t);
		T    length_squared() const;
		T    length() const;
		this_type normalized() const;
		this_type& normalize();
        this_type  max(const this_type& v) const;
        this_type  min(const this_type& v) const;
        this_type  abs() const;

		template<typename Y>
		vector4<Y> cast_to()
		{
			return vector4<Y>((Y)x(), (Y)y(), (Y)z(), (Y)w());
		}


	private:
		T m_x;
		T m_y;        
		T m_z;        
		T m_w;
	};

	typedef vector4<float>	vector4f;
	typedef vector4<double> vector4d;
	typedef vector4<int>	vector4i;
	
#include "vector4.inl"


} // end namespace

} // end namespace

#endif // __VECTOR4_H_5E7151BC_A6DE_476F_8560_39FB2E2D4E3A_
