//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Tuesday, 29 April 2008 7:23:41 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER

#ifndef __RECT_H_E57B8F15_31FF_4F8B_9B1E_F4AEE2654075_
#define __RECT_H_E57B8F15_31FF_4F8B_9B1E_F4AEE2654075_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "math/math_abi.h"
#include "math/vector2.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace math
{

    /// 2d rectangle
    template <class T>
    struct rect
    {
    public:
        typedef rect<T> this_type;

    public:
        /// constructor
        rect(T x, T y, T width, T height);

        /// constructor
        rect(const vector2<T>& pos, const vector2<T>& size);

        /// default constructor, zero initialises
        rect();

        T x() const { return m_x; }
        T y() const { return m_y; }
        T width() const { return m_width; }
        T height() const { return m_height; }

        /// \returns the width of the rectangle
        T get_width() const;

        /// \returns the height of the rectangle
        T get_height() const;

        T get_minx() const { return m_x; }

        T get_miny() const { return m_y; }

        T get_maxx() const { return m_x + m_width; }

        T get_maxy() const { return m_y + m_height; }

        /// \returns the top left corner of the rectangle
        vector2<T> get_top_left() const;

        /// \returns the top right corner of the rectangle
        vector2<T> get_top_right() const;

        /// \returns the bottom left corner of the rectangle
        vector2<T> get_bottom_left() const;

        /// \returns the top right corner of the rectangle
        vector2<T> get_bottom_right() const;

    private:
        T m_x, m_y;
        T m_width, m_height;
    };

#include "rect.inl"
    typedef rect<float>  rectf;
    typedef rect<double> rectd;
    typedef rect<int>    recti;

} // namespace math
} // namespace tycho

#endif // __RECT_H_E57B8F15_31FF_4F8B_9B1E_F4AEE2654075_
