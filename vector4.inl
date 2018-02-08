//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 31 March 2008 7:46:40 PM
//////////////////////////////////////////////////////////////////////////////



template<typename T>
vector4<T>::vector4() 
{
}

template<typename T>
vector4<T>::vector4(T x, T y, T z, T w) : 
	m_x(x), 
	m_y(y),
	m_z(z),
	m_w(w)
{}

template<typename T>
vector4<T>::vector4(const vector3<T> &v)
{
	x(v.x());
	y(v.y());
	z(v.z());
	w(0);
}

template<typename T>
vector4<T>::vector4(const vector3<T> &v, T w_)
{
	x(v.x());
	y(v.y());
	z(v.z());
	w(w_);
}

template<typename T>
T vector4<T>::x() 
{ 
	return m_x; 
}

template<typename T>
T vector4<T>::x() const 
{ 
	return m_x; 
}

template<typename T>
T vector4<T>::y() 
{ 
	return m_y; 
}

template<typename T>
T vector4<T>::y() const 
{ 
	return m_y; 
}

template<typename T>
T vector4<T>::z()
{ 
	return m_z; 
}

template<typename T>
T vector4<T>::z() const 
{ 
	return m_z; 
}

template<typename T>
T vector4<T>::w()
{ 
	return m_w; 
}

template<typename T>
T vector4<T>::w() const 
{ 
	return m_w; 
}

template<typename T>
void vector4<T>::x(T x) 
{ 
	m_x = x; 
}

template<typename T>
void vector4<T>::y(T y) 
{ 
	m_y = y; 
}

template<typename T>
void vector4<T>::z(T z) 
{ 
	m_z = z; 
}

template<typename T>
void vector4<T>::w(T w) 
{ 
	m_w = w; 
}

template<typename T>
T vector4<T>::dot(const this_type &v) const 
{ 
	return x() * v.x() + y() * v.y() + z() * v.z() + w() * v.w(); 
}

template<typename T>
vector4<T> vector4<T>::square(const this_type &v) const 
{ 
	return this_type(x() * v.x(), y() * v.y(), z() * v.z(), w() * v.w()); 
}

template<typename T>
vector4<T> vector4<T>::operator-() const
{
	return this_type(-x(), -y(), -z(), -w());
}

template<typename T>
vector4<T> vector4<T>::operator+(const this_type &v) const
{ 
	return this_type(x() + v.x(), y() + v.y(), z() + v.z(), v.w() + v.w()); 
}

template<typename T>
vector4<T> vector4<T>::operator-(const this_type &v) const
{ 
	return this_type(x() - v.x(), y() - v.y(), z() - v.z(), w() - v.w()); 
};

template<typename T>
vector4<T> vector4<T>::operator*(T t) const 
{ 
	return this_type(x() * t, y() * t, z() * t, w() * t); 
}

template<typename T>
vector4<T> vector4<T>::operator/(T t) const 
{ 
	return this_type(x() / t, y() / t, z() / t, w() / t); 
}

template<typename T>
vector4<T>& vector4<T>::operator +=(const this_type &v) 
{ 
	x(x() + v.x());
	y(y() + v.y()); 
	z(z() + v.z());
	w(w() + v.w());
	return *this; 
}

template<typename T>
vector4<T>& vector4<T>::operator -=(const this_type &v) 
{ 
	x(x() - v.x()); 
	y(y() - v.y()); 
	z(z() - v.z());
	w(w() - v.w());
	return *this; 
}

template<typename T>
vector4<T>& vector4<T>::operator *=(T t) 
{ 
	x(x() * t); 
	y(y() * t); 
	z(z() * t);
	w(w() * t);
	return *this; 
}

template<typename T>
vector4<T>& vector4<T>::operator /=(T t) 
{ 
	x(x() / t); 
	y(y() / t); 
	z(z() / t);
	w(w() / t);
	return *this; 
}

template<typename T>
T vector4<T>::length_squared() const 
{ 
	return math::square(y()) + math::square(x()) + math::square(z()) + math::square(w()); 
}

template<typename T>
T vector4<T>::length() const 
{ 
	return sqrt(length_squared()); 
}

template<typename T>
vector4<T> vector4<T>::normalized() const 
{ 
	return *this / length(); 
}

template<typename T>
vector4<T>& vector4<T>::normalize()
{ 
	return *this /= length(); 
} 
