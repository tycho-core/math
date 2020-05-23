//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 31 March 2008 7:46:30 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __VECTOR3_H_D7CEAB51_AD2C_4D3B_83B1_62EBE79D8A86_
#define __VECTOR3_H_D7CEAB51_AD2C_4D3B_83B1_62EBE79D8A86_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "math/math_abi.h"
#include "math/utilities.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace math
{

	/// 3 dimensional vector.
	template<class T> class vector3
	{
	public:
		typedef vector3<T> this_type;

	public:
		vector3();
		vector3(T x, T y, T z);

		T x();
		T x() const;
		T y();
		T y() const;
		T z();
		T z() const;

		void x(T x);
		void y(T y);
		void z(T z);

		T dot(const this_type &v) const;
		this_type cross(const this_type &v) const;
		this_type square(const this_type &v) const;
		this_type operator+(const this_type &v) const;
		this_type operator-(const this_type &v) const; 
		this_type operator*(T t) const;
		this_type operator/(T t) const;
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

	private:
		T m_x;
		T m_y;        
		T m_z;        
	};

	typedef vector3<float>	vector3f;
	typedef vector3<double> vector3d;
	typedef vector3<int>	vector3i;
	
#include "vector3.inl"


} // end namespace

} // end namespace

#endif // __VECTOR3_H_D7CEAB51_AD2C_4D3B_83B1_62EBE79D8A86_
