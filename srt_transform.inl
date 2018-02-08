//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Thursday, 8 May 2008 7:52:41 PM
//////////////////////////////////////////////////////////////////////////////

template<class T>
srt_transform<T>::srt_transform(const vector3<T>& scale, const vector3<T>& trans, const matrix3x3<T>& rotation) :
	m_scale(scale),
    m_rotation(rotation),
    m_translation(trans)
{}

template<class T>
srt_transform<T>::srt_transform() 
{}

template<class T>
srt_transform<T> srt_transform<T>::create_identity()
{
	static srt_transform<T> identity(vector3<T>(1,1,1), vector3<T>(0,0,0), matrix3x3<T>::create_identity());
	return identity;
}

template<class T>
srt_transform<T>& srt_transform<T>::set_translation(const vector3<T>& t)
{
	m_translation = t;
	return *this;
}

template<class T>
srt_transform<T>& srt_transform<T>::set_scale(const vector3<T>& s)
{
	m_scale = s;
	return *this;
}

template<class T>
srt_transform<T>& srt_transform<T>::set_rotation(const matrix3x3<T>& r)
{
	m_rotation = r;
	return *this;
}
		
template<class T>
const matrix3x3<T>& srt_transform<T>::get_rotation() const
{
	return m_rotation;
}

template<class T>
const vector3<T>& srt_transform<T>::get_translation() const
{
	return m_translation;
}

template<class T>
const vector3<T>& srt_transform<T>::get_scale() const
{
	return m_scale;
}

template<class T>
matrix4x4<T> srt_transform<T>::get_matrix() const
{	
	matrix3x3<T> mat(matrix3x3<T>::create_identity());
	mat.row(0).x(m_scale.x());
	mat.row(1).y(m_scale.y());
	mat.row(2).z(m_scale.z());
	mat = mat * m_rotation;	
	matrix4x4<T> res;
	res.row(0, vector4<T>(mat.row(0), m_translation.x()));
	res.row(1, vector4<T>(mat.row(1), m_translation.y()));
	res.row(2, vector4<T>(mat.row(2), m_translation.z()));
	res.row(3, vector4<T>(0, 0, 0, 1));
	return res;
}

// vector_type srt_transform::transform(const vector_type&)
// {
// 	TYCHO_NOT_IMPLEMENTED;
// 	return vector_type();
// }
// 
// vector_type srt_transform::inverse_transform(const vector_type&)
// {
// 	TYCHO_NOT_IMPLEMENTED;
// 	return vector_type();
// }	
