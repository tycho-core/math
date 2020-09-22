//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 31 March 2008 7:46:30 PM
//////////////////////////////////////////////////////////////////////////////

template <typename T>
vector3<T>::vector3()
{
}

template <typename T>
vector3<T>::vector3(T x, T y, T z)
    : m_x(x)
    , m_y(y)
    , m_z(z)
{
}

template <typename T>
T vector3<T>::x()
{
    return m_x;
}

template <typename T>
T vector3<T>::x() const
{
    return m_x;
}

template <typename T>
T vector3<T>::y()
{
    return m_y;
}

template <typename T>
T vector3<T>::y() const
{
    return m_y;
}

template <typename T>
T vector3<T>::z()
{
    return m_z;
}

template <typename T>
T vector3<T>::z() const
{
    return m_z;
}

template <typename T>
void vector3<T>::x(T x)
{
    m_x = x;
}

template <typename T>
void vector3<T>::y(T y)
{
    m_y = y;
}

template <typename T>
void vector3<T>::z(T z)
{
    m_z = z;
}

template <typename T>
T vector3<T>::dot(const this_type& v) const
{
    return x() * v.x() + y() * v.y() + z() * v.z();
}

template <typename T>
vector3<T> vector3<T>::cross(const this_type& v) const
{
    return vector3<T>(y() * v.z() - z() * v.y(), z() * v.x() - x() * v.z(),
                      x() * v.y() - y() * v.x());
}

template <typename T>
vector3<T> vector3<T>::square(const this_type& v) const
{
    return this_type(x() * v.x(), y() * v.y(), z() * v.z());
}

template <typename T>
vector3<T> vector3<T>::operator+(const this_type& v) const
{
    return this_type(x() + v.x(), y() + v.y(), z() + v.z());
}

template <typename T>
vector3<T> vector3<T>::operator-(const this_type& v) const
{
    return this_type(x() - v.x(), y() - v.y(), z() - v.z());
};

template <typename T>
vector3<T> vector3<T>::operator*(T t) const
{
    return this_type(x() * t, y() * t, z() * t);
}

template <typename T>
vector3<T> vector3<T>::operator/(T t) const
{
    return this_type(x() / t, y() / t, z() / t);
}

template <typename T>
vector3<T>& vector3<T>::operator+=(const this_type& v)
{
    x(x() + v.x());
    y(y() + v.y());
    z(z() + v.z());
    return *this;
}

template <typename T>
vector3<T>& vector3<T>::operator-=(const this_type& v)
{
    x(x() - v.x());
    y(y() - v.y());
    z(z() - v.z());
    return *this;
}

template <typename T>
vector3<T>& vector3<T>::operator*=(T t)
{
    x(x() * t);
    y(y() * t);
    z(z() * t);
    return *this;
}

template <typename T>
vector3<T>& vector3<T>::operator/=(T t)
{
    x(x() / t);
    y(y() / t);
    z(z() / t);
    return *this;
}

template <typename T>
T vector3<T>::length_squared() const
{
    return math::square(y()) + math::square(x()) + math::square(z());
}

template <typename T>
T vector3<T>::length() const
{
    return sqrt(length_squared());
}

template <typename T>
vector3<T> vector3<T>::normalized() const
{
    return *this / length();
}

template <typename T>
vector3<T>& vector3<T>::normalize()
{
    return *this /= length();
}

template <typename T>
vector3<T> vector3<T>::max(const vector3<T>& v) const
{
    return vector3<T>(math::max(m_x, v.m_x), math::max(m_y, v.m_y), math::max(m_z, v.m_z));
}

template <typename T>
vector3<T> vector3<T>::min(const vector3<T>& v) const
{
    return vector3<T>(math::min(m_x, v.m_x), math::min(m_y, v.m_y), math::min(m_z, v.m_z));
}

template <typename T>
vector3<T> vector3<T>::abs() const
{
    return vector3<T>(math::abs(m_x), math::abs(m_y), math::abs(m_z));
}

template <typename T>
bool operator==(const T& lhs, const T& rhs)
{
    return (lhs.x() == rhs.x()) && (lhs.y() == rhs.y()) && (lhs.z() == rhs.z());
}

template <typename T>
bool operator!=(const T& lhs, const T& rhs)
{
    return !(lhs == rhs);
}
