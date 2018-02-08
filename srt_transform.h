//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Thursday, 8 May 2008 7:52:41 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __SRT_TRANSFORM_H_818F5BCF_9CA3_4D64_B52F_15708A74EA4F_
#define __SRT_TRANSFORM_H_818F5BCF_9CA3_4D64_B52F_15708A74EA4F_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "math/math_abi.h"
#include "math/matrix3x3.h"
#include "math/vector3.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace math
{

	/// This stores the scale, rotation and translation components separately
	/// so it is easy to modify and animate them without needing to decompose 
	/// a regular 3x4 matrix.
	template<class T>
    class srt_transform
    {
    public:
		typedef srt_transform<T> this_type;
		typedef T				 component_type;
		typedef vector3<T>		 vector_type;
		typedef matrix3x3<T>	 matrix_type;
		
    public:
		srt_transform(const vector3<T>& scale, const vector3<T>& trans, const matrix3x3<T>& rotation);
		srt_transform();
		srt_transform& set_translation(const vector3<T>&);
		srt_transform& set_scale(const vector3<T>&);
		srt_transform& set_rotation(const matrix3x3<T>&);
				
		static this_type create_identity();
		
		const matrix3x3<T>& get_rotation() const;
		const vector_type& get_translation() const;
		const vector_type& get_scale() const;		
		matrix4x4<T> get_matrix() const;
		
// 		/// transform vector to parent space. x = y * M
// 		vector_type transform(const vector_type&);
// 		
// 		/// transform vector to local space. x = y * M^-1
// 		vector_type inverse_transform(const vector_type&);
		
		/// \name Operators
		//@{
// 		this_type operator*(const this_type& rhs);
// 		this_type& operator*=(const this_type& rhs);
// 		this_type operator+(const this_type& rhs);
// 		this_type& operator+=(const this_type& rhs);
// 		this_type operator-(const this_type& rhs);
// 		this_type& operator-=(const this_type& rhs);		
// 		vector_type operator*(const vector_type&);
		//@}
		
    private:
 		vector_type m_scale;
 		matrix_type m_rotation; ///< \todo could be a quaternion when we get support in for them 
 		vector_type m_translation;
    };
    
    typedef srt_transform<float>  srt_transformf;
    typedef srt_transform<double> srt_transformd;
    
#include "math/srt_transform.inl"
    
} // end namespace
} // end namespace

#endif // __SRT_TRANSFORM_H_818F5BCF_9CA3_4D64_B52F_15708A74EA4F_
