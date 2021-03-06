//=================================================================================================
/*!
//  \file blaze/util/algorithms/UninitializedDefaultConstruct.h
//  \brief Headerfile for the generic uninitialized_default_construct algorithm
//
//  Copyright (C) 2012-2019 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================

#ifndef _BLAZE_UTIL_ALGORITHMS_UNINITIALIZEDDEFAULTCONSTRUCT_H_
#define _BLAZE_UTIL_ALGORITHMS_UNINITIALIZEDDEFAULTCONSTRUCT_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <iterator>
#include <memory>


namespace blaze {

//=================================================================================================
//
//  UNINITIALIZED_DEFAULT_CONSTRUCT ALGORITHM
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Default constructs elements in the given range.
// \ingroup algorithms
//
// \param first Iterator to the first element of the range.
// \param last Iterator to the element one past the last element of the range.
// \return void
//
// This function default constructs elements in the given range \f$ [first,last) \f$. The range
// is assumed to be uninitialized.
*/
template< class ForwardIt >
void uninitialized_default_construct( ForwardIt first, ForwardIt last )
{
   using Value = typename std::iterator_traits<ForwardIt>::value_type;

   ForwardIt current( first );

   try {
      for( ; current!=last; ++current ) {
         ::new ( std::addressof( *current ) ) Value;
      }
   }
   catch (...) {
      for( ; first!=current; ++first ) {
         first->~Value();
      }
      throw;
   }
}
//*************************************************************************************************

} // namespace blaze

#endif
