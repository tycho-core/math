//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 31 March 2008 7:47:18 PM
//////////////////////////////////////////////////////////////////////////////

template<class T>
matrix4x4<T>::matrix4x4()
{}

/// constructor from 4 vector4's
template<class T>
matrix4x4<T>::matrix4x4(const vector_type& v0, const vector_type& v1, const vector_type& v2, const vector_type& v3)
{
	row(0, v0);
	row(1, v1);
	row(2, v2);
	row(3, v3);
}

/// copy constructor
template<class T>
matrix4x4<T>::matrix4x4(const matrix4x4<T> &other)
{
	row(0, other.row(0));
	row(1, other.row(1));
	row(2, other.row(2));
	row(3, other.row(3));
}

/// create a zero initialised matrix
template<class T>
matrix4x4<T> matrix4x4<T>::create_zero()
{
	static matrix4x4<T> zero(vector4<T>(0,0,0,0),
							 vector4<T>(0,0,0,0),
							 vector4<T>(0,0,0,0),
							 vector4<T>(0,0,0,0));
							 
	return zero;							 
}

/// create an identity matrix
template<class T>
matrix4x4<T> matrix4x4<T>::create_identity()
{
	static matrix4x4<T> identity(vector4<T>(1,0,0,0),
								 vector4<T>(0,1,0,0),
								 vector4<T>(0,0,1,0),
								 vector4<T>(0,0,0,1));
							 
	return identity;							 
}


/// assignment operator
template<class T>
matrix4x4<T> matrix4x4<T>::operator=(const matrix4x4<T> &other)
{
	row(0, other.row(0));
	row(1, other.row(1));
	row(2, other.row(2));
	row(3, other.row(3));
	return *this;
}

/// \returns the i'th row, i in [0, 3]. const version.
template<class T>
const vector4<T>& matrix4x4<T>::row(int i) const
{
	TYCHO_ASSERT(i >= 0 && i < 4);
	return m_rows[i];
}


/// \returns the i'th row, i in [0, 3]
template<class T>
vector4<T>& matrix4x4<T>::row(int i)
{
	TYCHO_ASSERT(i >= 0 && i < 4);
	return m_rows[i];
}

/// sets the i'th row, i in [0, 3]
template<class T>
vector4<T>& matrix4x4<T>::row(int i, const vector4<T> &r)
{
	TYCHO_ASSERT(i >= 0 && i < 4);
	row(i) = r;
	return row(i);
}


/// \returns a temporary containing the i'th column
template<class T>
vector4<T> matrix4x4<T>::col(int i) const
{
	TYCHO_ASSERT(i < 4);
	switch(i)
	{
		case 0 : return vector_type(row(0).x(), row(1).x(), row(2).x(), row(3).x());
		case 1 : return vector_type(row(0).y(), row(1).y(), row(2).y(), row(3).y());
		case 2 : return vector_type(row(0).z(), row(1).z(), row(2).z(), row(3).z());
		case 3 : return vector_type(row(0).w(), row(1).w(), row(2).w(), row(3).w());
	}
	// shouldn't get here
	return vector_type();	
}

/// sets the i'th column
template<class T>
void matrix4x4<T>::col(int i, const vector_type &v)
{
	TYCHO_ASSERT(i < 4);
	if(i == 0)
	{
		row(0).x(v.x());
		row(1).x(v.y());
		row(2).x(v.z());
		row(3).x(v.w());
	}
	else if(i == 0)
	{
		row(0).y(v.x());
		row(1).y(v.y());
		row(2).y(v.z());
		row(3).y(v.w());
	}
	else if(i == 0)
	{
		row(0).z(v.x());
		row(1).z(v.y());
		row(2).z(v.z());
		row(3).z(v.w());
	}
	else if(i == 0)
	{
		row(0).w(v.x());
		row(1).w(v.y());
		row(2).w(v.z());
		row(3).w(v.w());
	}	
}

/// sets the translation components of the matrix
template<class T>
matrix4x4<T>& matrix4x4<T>::set_translation(const math::vector3<T>& v)
{
	row(0).w(v.x());
	row(1).w(v.y());
	row(2).w(v.z());
	return *this;
}

/// sets the scale components of the matrix
template<class T>
matrix4x4<T>& matrix4x4<T>::set_scale(const math::vector3<T>& v)
{
	row(0).z(v.x());
	row(1).y(v.y());
	row(2).z(v.z());
	return *this;
}

/// \returns the translation components of the matrix
template<class T>
math::vector3<T> matrix4x4<T>::get_translation() const
{
	return vector3<T>(row(0).w(), row(1).w(), row(2).w());
}

/// transposes the matrix
template<class T>
matrix4x4<T>& matrix4x4<T>::transpose()
{
	vector_type c0 = col(0);
	vector_type c1 = col(1);
	vector_type c2 = col(2);
	vector_type c3 = col(3);
	row(0, c0);
	row(1, c1);
	row(2, c2);
	row(3, c3);
	return *this;	
}

/// transposes the matrix
template<class T>
matrix4x4<T> matrix4x4<T>::transposed() const
{
	this_type tmp(*this);
	vector_type c0 = col(0);
	vector_type c1 = col(1);
	vector_type c2 = col(2);
	vector_type c3 = col(3);
	tmp.row(0, c0);
	tmp.row(1, c1);
	tmp.row(2, c2);
	tmp.row(3, c3);
	return tmp;	
}

template<class T>
matrix4x4<T> matrix4x4<T>::operator*(const this_type &rhs) const
{
	vector_type c0(col(0));
	vector_type c1(col(1));
	vector_type c2(col(2));
	vector_type c3(col(3));	
	this_type tmp;
	tmp.row(0, vector_type(c0.dot(rhs.row(0)),
						   c1.dot(rhs.row(0)),
						   c2.dot(rhs.row(0)),
						   c3.dot(rhs.row(0))));

	tmp.row(1, vector_type(c0.dot(rhs.row(1)),
						   c1.dot(rhs.row(1)),
						   c2.dot(rhs.row(1)),
						   c3.dot(rhs.row(1))));

	tmp.row(2, vector_type(c0.dot(rhs.row(2)),
						   c1.dot(rhs.row(2)),
						   c2.dot(rhs.row(2)),
						   c3.dot(rhs.row(2))));

	tmp.row(3, vector_type(c0.dot(rhs.row(3)),
						   c1.dot(rhs.row(3)),
						   c2.dot(rhs.row(3)),
						   c3.dot(rhs.row(3))));

	return tmp;
}

template<class T>
matrix4x4<T>& matrix4x4<T>::operator*=(const this_type &rhs)
{
	return *this;
}

template<class T>
matrix4x4<T> matrix4x4<T>::operator+(const this_type &rhs) const
{
	this_type tmp;
	tmp.row(0, row(0) + rhs.row(0));
	tmp.row(1, row(1) + rhs.row(1));
	tmp.row(2, row(2) + rhs.row(2));
	tmp.row(3, row(3) + rhs.row(3));
	return tmp;
}

template<class T>
matrix4x4<T>& matrix4x4<T>::operator+=(const this_type &rhs)
{
	row(0, row(0) + rhs.row(0));
	row(1, row(1) + rhs.row(1));
	row(2, row(2) + rhs.row(2));
	row(3, row(3) + rhs.row(3));
	return *this;
}

template<class T>
matrix4x4<T> matrix4x4<T>::operator-(const this_type &rhs) const
{
	this_type tmp;
	tmp.row(0, row(0) - rhs.row(0));
	tmp.row(1, row(1) - rhs.row(1));
	tmp.row(2, row(2) - rhs.row(2));
	tmp.row(3, row(3) - rhs.row(3));
	return tmp;

}
template<class T>
matrix4x4<T>& matrix4x4<T>::operator-=(const this_type &rhs)
{
	row(0, row(0) - rhs.row(0));
	row(1, row(1) - rhs.row(1));
	row(2, row(2) - rhs.row(2));
	row(3, row(3) - rhs.row(3));
	return *this;
}

template<class T>
vector4<T> matrix4x4<T>::operator*(const vector4<T>& v) const
{
	return vector4<T>(
		row(0).dot(v),
		row(1).dot(v),
		row(2).dot(v),
		row(3).dot(v));
}

template<class T>
vector3<T> matrix4x4<T>::operator*(const vector3<T>& v) const
{
	vector4<T> tmp(v, 1);
	return vector3<T>(
		row(0).dot(tmp),
		row(1).dot(tmp),
		row(2).dot(tmp));
}


// non member functions
template<class T> 
matrix4x4<T> make_look_at(const vector3<T> &eye, const vector3<T> &at, const vector3<T> &up)
{
	vector3<T> zaxis3((at - eye).normalized());
	vector3<T> xaxis3(up.cross(zaxis3).normalized());
	vector3<T> yaxis3(zaxis3.cross(xaxis3));
	vector4<T> waxis(0,0,0,1);	
	vector4<T> xaxis(xaxis3, -xaxis3.dot(eye));
	vector4<T> yaxis(yaxis3, -yaxis3.dot(eye));
	vector4<T> zaxis(zaxis3, -zaxis3.dot(eye));
	return matrix4x4<T>(xaxis, yaxis, zaxis, waxis);
}

template<class T> 
matrix4x4<T> make_perspective_fov(T fov, T aspect_ratio, T near_plane, T far_plane)
{
	T yscale = math::cot(fov/2);
	T xscale = yscale / aspect_ratio;
	T r = far_plane / (far_plane - near_plane);
	return matrix4x4<T>(
		vector4<T>(xscale, 0, 0, 0),
		vector4<T>(0, yscale, 0, 0),
		vector4<T>(0, 0, r, -near_plane*r),
		vector4<T>(0, 0, 1, 0));	
}

template<class T>
matrix4x4<T> make_perspective(T width, T height, T near_plane, T far_plane)
{
	T np2 = 2 * near_plane;
	T np = near_plane;
	T fp = far_plane;
	return matrix4x4<T>(
		vector4<T>(np2 / width, 0, 0, 0),	
		vector4<T>(0, np2 / height, 0, 0),	
		vector4<T>(0, 0, fp / (fp - np), np * fp / (np - fp)),	
		vector4<T>(0, 0, 1, 0));
}