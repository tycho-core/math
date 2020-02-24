//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Tuesday, 29 April 2008 7:23:42 PM
//////////////////////////////////////////////////////////////////////////////

/// constructor
template <class T>
rect<T>::rect(T x, T y, T width, T height)
    : m_x(x)
    , m_y(y)
    , m_width(width)
    , m_height(height)

{
}

template <class T>
rect<T>::rect(const vector2<T>& pos, const vector2<T>& size)
    : m_x(pos.x())
    , m_y(pos.y())
    , m_width(size.x())
    , m_height(size.y())
{
}

/// default constructor, zero initialises
template <class T>
rect<T>::rect()
    : m_x(0)
    , m_y(0)
    , m_width(0)
    , m_height(0)
{
}

/// \returns the width of the rectangle
template <class T>
T rect<T>::get_width() const
{
    return m_width;
}

/// \returns the height of the rectangle
template <class T>
T rect<T>::get_height() const
{
    return m_height;
}

/// \returns the top left corner of the rectangle
template <class T>
vector2<T> rect<T>::get_top_left() const
{
    return vector2<T>(m_x, m_y);
}

/// \returns the top right corner of the rectangle
template <class T>
vector2<T> rect<T>::get_top_right() const
{
    return vector2<T>(m_x + m_width, m_y);
}

/// \returns the bottom left corner of the rectangle
template <class T>
vector2<T> rect<T>::get_bottom_left() const
{
    return vector2<T>(m_x, m_y + m_height);
}

/// \returns the top right corner of the rectangle
template <class T>
vector2<T> rect<T>::get_bottom_right() const
{
    return vector2<T>(m_x + m_width, m_y + m_height);
}
