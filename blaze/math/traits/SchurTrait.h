//=================================================================================================
/*!
//  \file blaze/math/traits/SchurTrait.h
//  \brief Header file for the Schur product trait
//
//  Copyright (C) 2013 Klaus Iglberger - All Rights Reserved
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

#ifndef _BLAZE_MATH_TRAITS_SCHURTRAIT_H_
#define _BLAZE_MATH_TRAITS_SCHURTRAIT_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/util/InvalidType.h>
#include <blaze/util/mpl/If.h>
#include <blaze/util/mpl/Or.h>
#include <blaze/util/typetraits/Decay.h>
#include <blaze/util/typetraits/IsConst.h>
#include <blaze/util/typetraits/IsReference.h>
#include <blaze/util/typetraits/IsVolatile.h>


namespace blaze {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Base template for the SchurTrait class.
// \ingroup math_traits
//
// \section schurtrait_general General
//
// The SchurTrait class template offers the possibility to select the resulting data type of
// a generic Schur product operation between the two given types \a T1 and \a T2. SchurTrait
// defines the nested type \a Type, which represents the resulting data type of the Schur
// product. In case \a T1 and \a T2 cannot be combined in a Schur product, the resulting data
// type \a Type is set to \a INVALID_TYPE. Note that \a const and \a volatile qualifiers and
// reference modifiers are generally ignored.
//
// Since the Schur product is only defined for matrices, the SchurTrait template only supports
// the following matrix types:
//
// <ul>
//    <li>blaze::StaticMatrix</li>
//    <li>blaze::HybridMatrix</li>
//    <li>blaze::DynamicMatrix</li>
//    <li>blaze::CustomMatrix</li>
//    <li>blaze::CompressedMatrix</li>
//    <li>blaze::SymmetricMatrix</li>
//    <li>blaze::HermitianMatrix</li>
//    <li>blaze::LowerMatrix</li>
//    <li>blaze::UniLowerMatrix</li>
//    <li>blaze::StrictlyLowerMatrix</li>
//    <li>blaze::UpperMatrix</li>
//    <li>blaze::UniUpperMatrix</li>
//    <li>blaze::StrictlyUpperMatrix</li>
//    <li>blaze::DiagonalMatrix</li>
// </ul>
//
//
// \n \section schurtrait_specializations Creating custom specializations
//
// It is possible to specialize the SchurTrait template for additional user-defined data types.
// The following example shows the according specialization for the Schur product between two
// static matrices with equal storage order:

   \code
   template< typename T1, size_t M, size_t N, bool SO, typename T2 >
   struct SchurTrait< StaticMatrix<T1,M,N,SO>, StaticMatrix<T2,M,N,SO> >
   {
      using Type = StaticMatrix< MultTrait_<T1,T2>, M, N, SO >;
   };
   \endcode

// \n \section schurtrait_examples Examples
//
// The following example demonstrates the use of the SchurTrait template, where depending on
// the two given data types the resulting data type is selected:

   \code
   template< typename T1, typename T2 >  // The two generic types
   typename SchurTrait<T1,T2>::Type      // The resulting generic return type
   schur( T1 t1, T2 t2 )                 //
   {                                     // The function 'schur' returns the Schur
      return t1 % t2;                    // product of the two given values
   }                                     //
   \endcode
*/
template< typename T1    // Type of the left-hand side operand
        , typename T2 >  // Type of the right-hand side operand
struct SchurTrait
{
 private:
   //**********************************************************************************************
   /*! \cond BLAZE_INTERNAL */
   using Type1 = Decay_<T1>;
   using Type2 = Decay_<T2>;
   /*! \endcond */
   //**********************************************************************************************

   //**struct Failure******************************************************************************
   /*! \cond BLAZE_INTERNAL */
   struct Failure { using Type = INVALID_TYPE; };
   /*! \endcond */
   //**********************************************************************************************

 public:
   //**********************************************************************************************
   /*! \cond BLAZE_INTERNAL */
   using Type = typename If_< Or< IsConst<T1>, IsVolatile<T1>, IsReference<T1>
                                , IsConst<T2>, IsVolatile<T2>, IsReference<T2> >
                            , SchurTrait<Type1,Type2>
                            , Failure >::Type;
   /*! \endcond */
   //**********************************************************************************************
};
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Auxiliary alias declaration for the SchurTrait class template.
// \ingroup math_traits
//
// The SchurTrait_ alias declaration provides a convenient shortcut to access the nested \a Type
// of the SchurTrait class template. For instance, given the types \a T1 and \a T2 the following
// two type definitions are identical:

   \code
   using Type1 = typename SchurTrait<T1,T2>::Type;
   using Type2 = SchurTrait_<T1,T2>;
   \endcode
*/
template< typename T1, typename T2 >
using SchurTrait_ = typename SchurTrait<T1,T2>::Type;
//*************************************************************************************************

} // namespace blaze

#endif
