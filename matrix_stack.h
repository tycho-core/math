//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 19 May 2008 8:53:32 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __MATRIX_STACK_H_3B8316D3_14E0_4F85_8A9F_46002E89185D_
#define __MATRIX_STACK_H_3B8316D3_14E0_4F85_8A9F_46002E89185D_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "math/math_abi.h"
#include "math/matrix4x4.h"
#include "core/debug/assert.h"
#include <stack>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace math
{

	template<class T>
    class matrix_stack
    {
    public:
		/// push a matrix on the stack
		const math::matrix4x4<T>& push(const math::matrix4x4<T>& mat)
		{
			m_stack.push(mat);
			return head();
		}
				
		/// push a matrix on the stack after multiplying it with the current head
		const math::matrix4x4<T>& push_mul(const math::matrix4x4<T>& mat)
		{
			if(m_stack.empty())
			{
				m_stack.push(mat);
			}
			else
			{
				const math::matrix4x4<T>& cur = head();
				m_stack.push(mat * cur);				
			}
			return head();
		}
		
		/// pop a matrix off the stack
		void pop()
		{
			TYCHO_ASSERT(!m_stack.empty());
			m_stack.pop();
		}
					
		/// get the matrix at the head of the stack
		const math::matrix4x4<T>& head() const
		{
			TYCHO_ASSERT(!m_stack.empty());
			return m_stack.top();			
		}
		
		/// \returns true if the matrix stack is empty
		bool empty() const { return m_stack.empty(); }

	private:
		std::stack<math::matrix4x4<T> > m_stack;    
    };

} // end namespace
} // end namespace

#endif // __MATRIX_STACK_H_3B8316D3_14E0_4F85_8A9F_46002E89185D_
