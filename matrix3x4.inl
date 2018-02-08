//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 31 March 2008 7:47:07 PM
//////////////////////////////////////////////////////////////////////////////

template<class T>
matrix3x4<T>::matrix3x4()
{
	// no - op
}

/// copy constructor
template<class T>
matrix3x4<T>::matrix3x4(const matrix3x4 &other)
{
	row(0, other.row(0));
	row(1, other.row(1));
	row(2, other.row(2));
}

/// construct from 3 vector4's. 
template<class T>
matrix3x4<T>::matrix3x4(const vector4<T> &r0, const vector4<T> &r1, const vector4<T> &r2)
{
	row(0, r0);
	row(1, r1);
	row(2, r2);
}

/// construct from a 3x3 matrix and a translation vector
template<class T>
matrix3x4<T>::matrix3x4(const matrix3x3<T>& m, const vector3<T>& t)
{
	row(0, vector4<T>(m.row(0), t.x()));
	row(1, vector4<T>(m.row(1), t.y()));
	row(2, vector4<T>(m.row(2), t.z()));
}

/// create a zero initialised matrix
template<class T>
matrix3x4<T> matrix3x4<T>::create_zero()
{
	static matrix3x4 zero = {
		vector4<T>(0,0,0,0),
		vector4<T>(0,0,0,0),
		vector4<T>(0,0,0,0)
	};
	
	return zero;
}

/// assignment operator
template<class T>
matrix3x4<T>& matrix3x4<T>::operator=(const matrix3x4 &other)
{
	row(0, other.row(0));
	row(1, other.row(1));
	row(2, other.row(2));
	return *this;
}

/// get the i'th row, i in [0-3]
template<class T>
const vector4<T>& matrix3x4<T>::row(int i) const
{
	TYCHO_ASSERT(i >= 0 && i <= 3);
	return m_rows[i];
}

/// set the i'th row, i in [0-3]
template<class T>
void matrix3x4<T>::row(int i, const vector4<T> &v)
{
	TYCHO_ASSERT(i >= 0 && i <= 3);
	m_rows[i] = v;
}

