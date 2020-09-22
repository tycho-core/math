//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 31 March 2008 7:45:39 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER

#ifndef __VECTOR2_H_DAA2CD29_B1FA_4FA9_8FAD_175F197B787B_
#define __VECTOR2_H_DAA2CD29_B1FA_4FA9_8FAD_175F197B787B_

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

    /// 2d vector
    template <class T>
    class vector2
    {
    public:
        typedef vector2<T> this_type;

    public:
        vector2();
        vector2(T x, T y);

        T x();
        T x() const;
        T y();
        T y() const;

        void x(T x);
        void y(T y);

        T          dot(const this_type& v) const;
        this_type  square(const this_type& v) const;
        this_type  operator+(const this_type& v) const;
        this_type  operator-(const this_type& v) const;
        this_type  operator*(T t) const;
        this_type  operator/(T t) const;
        this_type& operator+=(const this_type& v);
        this_type& operator-=(const this_type& v);
        this_type& operator*=(T t);
        this_type& operator/=(T t);
        this_type  perp() const;
        T          length_squared() const;
        T          length() const;
        this_type  normalized() const;
        this_type& normalize();
        this_type  max(const this_type& v) const;
        this_type  min(const this_type& v) const;
        this_type  abs() const;

    private:
        T m_x;
        T m_y;
    };

    typedef vector2<core::int32>   vector2i;
    typedef vector2<core::float32> vector2f;
    typedef vector2<core::float64> vector2d;

#include "math/vector2.inl"

} // namespace math

} // namespace tycho

#endif // __VECTOR2_H_DAA2CD29_B1FA_4FA9_8FAD_175F197B787B_
