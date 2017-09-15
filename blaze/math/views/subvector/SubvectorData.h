//=================================================================================================
/*!
//  \file blaze/math/views/subvector/SubvectorData.h
//  \brief Header file for the implementation of the SubvectorData class template
//
//  Copyright (C) 2012-2017 Klaus Iglberger - All Rights Reserved
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

#ifndef _BLAZE_MATH_VIEWS_SUBVECTOR_SUBVECTORDATA_H_
#define _BLAZE_MATH_VIEWS_SUBVECTOR_SUBVECTORDATA_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/util/Types.h>


namespace blaze {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Auxiliary class template for the data members of the Subvector class.
// \ingroup subvector
//
// The auxiliary SubvectorData class template represents an abstraction of the data members of
// the Subvector class template. The necessary set of data members is selected depending on the
// number of compile time subvector arguments.
*/
template< size_t... CSAs >  // Compile time subvector arguments
struct SubvectorData
{};
//*************************************************************************************************




//=================================================================================================
//
//  CLASS TEMPLATE SPECIALIZATION FOR ZERO COMPILE TIME ARGUMENTS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Specialization of the SubvectorData class template for zero compile time subvector
//        arguments.
// \ingroup subvector
//
// This specialization of SubvectorData adapts the class template to the requirements of zero
// compile time subvector arguments.
*/
template<>
struct SubvectorData<>
{
 public:
   //**Constructors********************************************************************************
   /*!\name Constructors */
   //@{
   explicit inline constexpr SubvectorData( size_t index, size_t n );
   // No explicitly declared copy constructor.
   //@}
   //**********************************************************************************************

   //**Destructor**********************************************************************************
   // No explicitly declared destructor.
   //**********************************************************************************************

   //**Assignment operators************************************************************************
   SubvectorData& operator=( const SubvectorData& ) = delete;
   //**********************************************************************************************

   //**Utility functions***************************************************************************
   /*!\name Utility functions */
   //@{
   inline constexpr size_t offset() const noexcept;
   inline constexpr size_t size  () const noexcept;
   //@}
   //**********************************************************************************************

 private:
   //**Member variables****************************************************************************
   /*!\name Member variables */
   //@{
   const size_t offset_;  //!< The offset of the subvector within the vector.
   const size_t size_;    //!< The size of the subvector.
   //@}
   //**********************************************************************************************
};
//*************************************************************************************************


//*************************************************************************************************
/*!\brief The constructor for SubvectorData.
//
// \param index The offset of the subvector within the given vector.
// \param n The size of the subvector.
*/
inline constexpr SubvectorData<>::SubvectorData( size_t index, size_t n )
   : offset_( index )  // The offset of the subvector within the vector
   , size_  ( n     )  // The size of the subvector
{}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns the offset of the subvector within the underlying vector.
//
// \return The offset of the subvector.
*/
inline constexpr size_t SubvectorData<>::offset() const noexcept
{
   return offset_;
}
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Returns the current size/dimension of the subvector.
//
// \return The size of the subvector.
*/
inline constexpr size_t SubvectorData<>::size() const noexcept
{
   return size_;
}
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  CLASS TEMPLATE SPECIALIZATION FOR TWO COMPILE TIME ARGUMENTS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Specialization of the SubvectorData class template for two compile time subvector
//        arguments.
// \ingroup subvector
//
// This specialization of SubvectorData adapts the class template to the requirements of two
// compile time arguments.
*/
template< size_t I    // Index of the first element
        , size_t N >  // Number of elements
struct SubvectorData<I,N>
{
 public:
   //**Constructors********************************************************************************
   /*!\name Constructors */
   //@{
   explicit inline constexpr SubvectorData();
   // No explicitly declared copy constructor.
   //@}
   //**********************************************************************************************

   //**Destructor**********************************************************************************
   // No explicitly declared destructor.
   //**********************************************************************************************

   //**Assignment operators************************************************************************
   SubvectorData& operator=( const SubvectorData& ) = delete;
   //**********************************************************************************************

   //**Utility functions***************************************************************************
   /*!\name Utility functions */
   //@{
   inline constexpr size_t offset() const noexcept;
   inline constexpr size_t size  () const noexcept;
   //@}
   //**********************************************************************************************
};
//*************************************************************************************************


//*************************************************************************************************
/*!\brief The constructor for SubvectorData.
*/
template< size_t I    // Index of the first element
        , size_t N >  // Number of elements
inline constexpr SubvectorData<I,N>::SubvectorData()
{}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns the offset of the subvector within the underlying vector.
//
// \return The offset of the subvector.
*/
template< size_t I    // Index of the first element
        , size_t N >  // Number of elements
inline constexpr size_t SubvectorData<I,N>::offset() const noexcept
{
   return I;
}
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Returns the current size/dimension of the subvector.
//
// \return The size of the subvector.
*/
template< size_t I    // Index of the first element
        , size_t N >  // Number of elements
inline constexpr size_t SubvectorData<I,N>::size() const noexcept
{
   return N;
}
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif