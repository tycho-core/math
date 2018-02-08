//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 31 March 2008 7:46:49 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __MATRIX3X3_H_83452781_C065_48CC_8495_4227D793D7AF_
#define __MATRIX3X3_H_83452781_C065_48CC_8495_4227D793D7AF_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "math/math_abi.h"
#include "math/vector3.h"
#include "core/debug/assert.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace math
{

	template<class T>
    class matrix3x3
    {
    public:
		typedef matrix3x3<T> this_type;
		typedef T		     component_type;
		typedef vector3<T>	 vector_type;
		
    public:
		/// default constructor, does not initialise
		matrix3x3();
		
		/// matrix3x3 from 3 vector3's
		matrix3x3(const vector_type&, const vector_type&, const vector_type&);
		
		/// copy constructor
		matrix3x3(const matrix3x3 &);
		
		/// create a zero initialised matrix
		static this_type create_zero();

		/// create an identity matrix
		static this_type create_identity();
		
		/// assignment operator
		this_type operator=(const matrix3x3 &);
		
		/// \returns the i'th row, i in [0, 2]. const version.
		const vector_type& row(int i) const;
		
		/// \returns the i'th row, i in [0, 2]
		vector_type& row(int i) ;

		/// sets the i'th row, i in [0, 2]
		vector_type& row(int i, const vector_type &) ;
		
		/// \returns a temporary containing the i'th column
		vector_type col(int i) const;
		
		/// sets the i'th column
		void col(int i, const vector_type &);		
				
		/// transposes the matrix
		this_type& transpose();				

		/// \returns a transposed copy the matrix
		this_type transposed() const;
		
		/// \name Operators
		//@{
		this_type operator*(const this_type &rhs) const;
		this_type& operator*=(const this_type &rhs);
		this_type operator+(const this_type &rhs)const;
		this_type& operator+=(const this_type &rhs);
		this_type operator-(const this_type &rhs)const;
		this_type& operator-=(const this_type &rhs);
		//@}
    
    private:		
		vector_type m_rows[3]; ///< columns stored as row vectors
    };

	typedef matrix3x3<float> matrix3x3f;
	typedef matrix3x3<double> matrix3x3d;

#include "math/matrix3x3.inl"

} // end namespace
} // end namespace

#endif // __MATRIX3X3_H_83452781_C065_48CC_8495_4227D793D7AF_
