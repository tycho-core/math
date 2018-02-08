//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 31 March 2008 7:47:18 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __MATRIX4X4_H_C43A0EF7_7126_4A1C_BE6F_6E8D94BB6E3B_
#define __MATRIX4X4_H_C43A0EF7_7126_4A1C_BE6F_6E8D94BB6E3B_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "math/math_abi.h"
#include "math/vector4.h"
#include "math/utilities.h"
#include "core/debug/assert.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace math
{

	/// 4x4 by matrix arranged as 4 row major vector 4's.
	template<class T>
    class matrix4x4
    {
    public:
		typedef T		     component_type;
		typedef matrix4x4<T> this_type;
		typedef vector4<T>	 vector_type;
		
		/// default constructor, does not initialise
		matrix4x4();
		
		/// constructor from 4 vector4's
		matrix4x4(const vector_type&, const vector_type&, const vector_type&, const vector_type&);
		
		/// copy constructor
		matrix4x4(const matrix4x4 &);
		
		/// create a zero initialised matrix
		static this_type create_zero();

		/// create an identity matrix
		static this_type create_identity();
		
		/// assignment operator
		this_type operator=(const matrix4x4 &);
		
		/// \returns the i'th row, i in [0, 3]. const version.
		const vector_type& row(int i) const;
		
		/// \returns the i'th row, i in [0, 3]
		vector_type& row(int i) ;

		/// sets the i'th row, i in [0, 3]
		vector_type& row(int i, const vector_type &) ;
		
		/// \returns a temporary containing the i'th column
		vector_type col(int i) const;
		
		/// sets the i'th column
		void col(int i, const vector_type &);		
		
		/// sets the translation components of the matrix
		this_type& set_translation(const math::vector3<T>&);

		/// sets the scale components of the matrix
		this_type& set_scale(const math::vector3<T>&);

		/// \returns the translation components of the matrix		
		math::vector3<T> get_translation() const;
		
		/// transposes the matrix
		this_type& transpose();				

		/// \returns a transposed copy the matrix
		this_type transposed() const;
		
		/// \name Operators
		//@{
		this_type operator*(const this_type &rhs) const;
		this_type& operator*=(const this_type &rhs);
		this_type operator+(const this_type &rhs) const;
		this_type& operator+=(const this_type &rhs);
		this_type operator-(const this_type &rhs) const;
		this_type& operator-=(const this_type &rhs);
		//@}
		
		/// \name Vector operators
		//@{
		vector4<T> operator*(const vector4<T>&) const;
		
		/// computes *this * vector4(x, y, z, 1)
		vector3<T> operator*(const vector3<T>&) const;
		//@}
		
    private:
		vector_type m_rows[4];
    };

	// non member functions
	template<class T> matrix4x4<T> make_look_at(const vector3<T> &eye, const vector3<T> &at, const vector3<T> &up);
	template<class T> matrix4x4<T> make_perspective_fov(T fov, T aspect_ratio, T near_plane, T far_plane);
	template<class T> matrix4x4<T> make_perspective(T width, T height, T near_plane, T far_plane);
		
	typedef matrix4x4<core::float32> matrix4x4f;
	typedef matrix4x4<core::float64> matrix4x4d;
	typedef matrix4x4<core::int32>   matrix4x4i;
	
#include "matrix4x4.inl"

} // end namespace
} // end namespace

#endif // __MATRIX4X4_H_C43A0EF7_7126_4A1C_BE6F_6E8D94BB6E3B_
