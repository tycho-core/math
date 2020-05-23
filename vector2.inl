//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 31 March 2008 7:45:39 PM
//////////////////////////////////////////////////////////////////////////////

template<typename T>
vector2<T>::vector2() 
{
}

template<typename T>
vector2<T>::vector2(T x, T y) : 
	m_x(x), m_y(y) 
{}

template<typename T>
T vector2<T>::x() 
{ 
	return m_x; 
}

template<typename T>
T vector2<T>::x() const 
{ 
	return m_x; 
}

template<typename T>
T vector2<T>::y() 
{ 
	return m_y; 
}

template<typename T>
T vector2<T>::y() const 
{ 
	return m_y; 
}

template<typename T>
void vector2<T>::x(T x) 
{ 
	m_x = x; 
}

template<typename T>
void vector2<T>::y(T y) 
{ 
	m_y = y; 
}

template<typename T>
T vector2<T>::dot(const this_type &v) const 
{ 
	return x() * v.x() + y() * v.y(); 
}

template<typename T>
vector2<T> vector2<T>::square(const this_type &v) const 
{ 
	return this_type(x() * v.x(), y() * v.y()); 
}

template<typename T>
vector2<T> vector2<T>::operator+(const this_type &v) const
{ 
	return this_type(x() + v.x(), y() + v.y()); 
}

template<typename T>
vector2<T> vector2<T>::operator-(const this_type &v) const
{ 
	return this_type(x() - v.x(), y() - v.y()); 
};

template<typename T>
vector2<T> vector2<T>::operator*(T t) const 
{ 
	return this_type(x() * t, y() * t); 
}

template<typename T>
vector2<T> vector2<T>::operator/(T t) const 
{ 
	return this_type(x() / t, y() / t); 
}

template<typename T>
vector2<T>& vector2<T>::operator +=(const this_type &v) 
{ 
	x(x() + v.x()); y(y() + v.y()); 
	return *this; 
}

template<typename T>
vector2<T>& vector2<T>::operator -=(const this_type &v) 
{ 
	x(x() - v.x()); y(y() - v.y()); 
	return *this; 
}

template<typename T>
vector2<T>& vector2<T>::operator *=(T t) 
{ 
	x(x() * t); 
	y(y() * t); 
	return *this; 
}

template<typename T>
vector2<T>& vector2<T>::operator /=(T t) 
{ 
	x(x() / t); y(y() / t); 
	return *this; 
}

template<typename T>
vector2<T> vector2<T>::perp() const 
{ 
	return this_type(y(), -x()); 
}

template<typename T>
T vector2<T>::length_squared() const 
{ 
	return square(y()) + square(x()); 
}

template<typename T>
T vector2<T>::length() const 
{ 
	return sqrt(length_squared()); 
}

template<typename T>
vector2<T> vector2<T>::normalized() const 
{ 
	return *this / length(); 
}

template<typename T>
vector2<T>& vector2<T>::normalize()
{ 
	return *this /= length(); 
}

template <typename T>
vector2<T> vector2<T>::max(const vector2<T>& v) const
{
    return vector2<T>(math::max(m_x, v.m_x), math::max(m_y, v.m_y));
}

template <typename T>
vector2<T> vector2<T>::min(const vector2<T>& v) const
{
    return vector2<T>(math::min(m_x, v.m_x), math::min(m_y, v.m_y));
}

template <typename T>
vector2<T> vector2<T>::abs() const
{
    return vector2<T>(math::abs(m_x), math::abs(m_y));
}
