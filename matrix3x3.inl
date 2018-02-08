//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 31 March 2008 7:46:49 PM
//////////////////////////////////////////////////////////////////////////////


template<class T>
matrix3x3<T>::matrix3x3()
{}

template<class T>
matrix3x3<T>::matrix3x3(const vector3<T>& v0, const vector3<T>& v1, const vector3<T>& v2)
{
	row(0, v0);
	row(1, v1);
	row(2, v2);
}

/// copy constructor
template<class T>
matrix3x3<T>::matrix3x3(const matrix3x3<T> &other)
{
	row(0, other.row(0));
	row(1, other.row(1));
	row(2, other.row(2));
}

/// create a zero initialised matrix
template<class T>
matrix3x3<T> matrix3x3<T>::create_zero()
{
	static matrix3x3<T> zero(vector3<T>(0,0,0),
							 vector3<T>(0,0,0),
							 vector3<T>(0,0,0));
							 
	return zero;							 
}

/// create an identity matrix
template<class T>
matrix3x3<T> matrix3x3<T>::create_identity()
{
	static matrix3x3<T> identity(vector3<T>(1,0,0),
								 vector3<T>(0,1,0),
								 vector3<T>(0,0,1));
							 
	return identity;							 
}


/// assignment operator
template<class T>
matrix3x3<T> matrix3x3<T>::operator=(const matrix3x3<T> &other)
{
	row(0, other.row(0));
	row(1, other.row(1));
	row(2, other.row(2));
	return *this;
}

/// \returns the i'th row, i in [0, 3]. const version.
template<class T>
const vector3<T>& matrix3x3<T>::row(int i) const
{
	TYCHO_ASSERT(i >= 0 && i < 4);
	return m_rows[i];
}


/// \returns the i'th row, i in [0, 3]
template<class T>
vector3<T>& matrix3x3<T>::row(int i)
{
	TYCHO_ASSERT(i >= 0 && i < 3);
	return m_rows[i];
}

/// sets the i'th row, i in [0, 3]
template<class T>
vector3<T>& matrix3x3<T>::row(int i, const vector3<T> &r)
{
	TYCHO_ASSERT(i >= 0 && i < 3);
	row(i) = r;
	return row(i);
}


/// \returns a temporary containing the i'th column
template<class T>
vector3<T> matrix3x3<T>::col(int i) const
{
	TYCHO_ASSERT(i < 3);
	switch(i)
	{
		case 0 : return vector3<T>(row(0).x(), row(1).x(), row(2).x());
		case 1 : return vector3<T>(row(0).y(), row(1).y(), row(2).y());
		case 2 : return vector3<T>(row(0).z(), row(1).z(), row(2).z());
	}
	// shouldn't get here
	return vector3<T>();	
}

/// sets the i'th column
template<class T>
void matrix3x3<T>::col(int i, const vector3<T> &v)
{
	TYCHO_ASSERT(i < 3);
	if(i == 0)
	{
		row(0).x(v.x());
		row(1).x(v.y());
		row(2).x(v.z());
	}
	else if(i == 0)
	{
		row(0).y(v.x());
		row(1).y(v.y());
		row(2).y(v.z());
	}
	else if(i == 0)
	{
		row(0).z(v.x());
		row(1).z(v.y());
		row(2).z(v.z());
	}	
}

/// transposes the matrix
template<class T>
matrix3x3<T>& matrix3x3<T>::transpose()
{
	vector3<T> c0 = col(0);
	vector3<T> c1 = col(1);
	vector3<T> c2 = col(2);
	row(0, c0);
	row(1, c1);
	row(2, c2);
	return *this;	
}

/// transposes the matrix
template<class T>
matrix3x3<T> matrix3x3<T>::transposed() const
{
	this_type tmp(*this);
	vector3<T> c0 = col(0);
	vector3<T> c1 = col(1);
	vector3<T> c2 = col(2);
	tmp.row(0, c0);
	tmp.row(1, c1);
	tmp.row(2, c2);
	return tmp;	
}

template<class T>
matrix3x3<T> matrix3x3<T>::operator*(const this_type &rhs) const
{
	vector3<T> c0(col(0));
	vector3<T> c1(col(1));
	vector3<T> c2(col(2));
	this_type tmp;
	tmp.row(0, vector3<T>(c0.dot(rhs.row(0)),
						   c1.dot(rhs.row(0)),
						   c2.dot(rhs.row(0))));

	tmp.row(1, vector3<T>(c0.dot(rhs.row(1)),
						   c1.dot(rhs.row(1)),
						   c2.dot(rhs.row(1))));

	tmp.row(2, vector3<T>(c0.dot(rhs.row(2)),
						   c1.dot(rhs.row(2)),
						   c2.dot(rhs.row(2))));

	return tmp;
}

template<class T>
matrix3x3<T>& matrix3x3<T>::operator*=(const this_type &rhs)
{
	return *this;
}

template<class T>
matrix3x3<T> matrix3x3<T>::operator+(const this_type &rhs) const
{
	this_type tmp;
	tmp.row(0, row(0) + rhs.row(0));
	tmp.row(1, row(1) + rhs.row(1));
	tmp.row(2, row(2) + rhs.row(2));
	return tmp;
}

template<class T>
matrix3x3<T>& matrix3x3<T>::operator+=(const this_type &rhs)
{
	row(0, row(0) + rhs.row(0));
	row(1, row(1) + rhs.row(1));
	row(2, row(2) + rhs.row(2));
	return *this;
}

template<class T>
matrix3x3<T> matrix3x3<T>::operator-(const this_type &rhs) const
{
	this_type tmp;
	tmp.row(0, row(0) - rhs.row(0));
	tmp.row(1, row(1) - rhs.row(1));
	tmp.row(2, row(2) - rhs.row(2));
	return tmp;

}
template<class T>
matrix3x3<T>& matrix3x3<T>::operator-=(const this_type &rhs)
{
	row(0, row(0) - rhs.row(0));
	row(1, row(1) - rhs.row(1));
	row(2, row(2) - rhs.row(2));
	return *this;
}
