#ifndef _MFloatPoint
#define _MFloatPoint
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MFloatPoint
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFloatPoint)
//
//	This class provides an implementation of a point in float.  Numerous 
//	convienence operators are provided to help with the manipulation of 
//	points. This includes operators that work with the MFloatVector and 
//	MFloatMatrix classes.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MTypes.h>
#include <maya/MIOStreamFwd.h>

// *****************************************************************************

// DECLARATIONS

class MFloatMatrix;
class MFloatVector;

#define MFloatPoint_kTol	1.0e-10

// *****************************************************************************

// CLASS DECLARATION (MFloatPoint)

/// Implementation of a point. (OpenMaya) (OpenMaya.py)
/**
  This class implements the Maya representation of a point in floats
*/
#if defined(_WIN32)
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFloatPoint  
{
public:
	///
						MFloatPoint();	// defaults to 0,0,0,1
	///
						MFloatPoint( const MFloatPoint & srcpt );  
	///
						MFloatPoint( float xx, float yy,
									 float zz = 0.0, float ww = 1.0 );
	///
						MFloatPoint( const float[4] );
	///
						~MFloatPoint();
	///
	MStatus				get( float[4] ) const;
	///
	MFloatPoint &		operator=( const MFloatPoint & src );
	///
	float				operator()(unsigned int i) const;
	///
	float				operator[](unsigned int i) const;
	///
	MFloatVector		operator-( const MFloatPoint & other ) const;
	///
	MFloatPoint			operator+( const MFloatVector & other ) const;
	///
	MFloatPoint			operator-( const MFloatVector & other ) const;
	///
	MFloatPoint &		operator+=( const MFloatVector & vector );
	///
	MFloatPoint &		operator-=( const MFloatVector & vector );
	///
	MFloatPoint			operator*(const float scale) const;
	///
	MFloatPoint			operator/(const float scale) const;
	///
	MFloatPoint			operator*(const MFloatMatrix &) const;
	///
	MFloatPoint &		operator*=(const MFloatMatrix &);
	///
	bool				operator==( const MFloatPoint & other ) const;
	///
	bool				operator!=( const MFloatPoint & other ) const;
	///
	MFloatPoint &		cartesianize();
	///
	MFloatPoint &		rationalize();
	///
	MFloatPoint &		homogenize();
	///
	float				distanceTo( const MFloatPoint & other ) const;
	///
	bool				isEquivalent( const MFloatPoint & other,
									  float tolerance = MFloatPoint_kTol)
									const;

BEGIN_NO_SCRIPT_SUPPORT:

	///	NO SCRIPT SUPPORT
	float &         	operator()(unsigned int i);

	///	NO SCRIPT SUPPORT
	float &         	operator[](unsigned int i);

	///	NO SCRIPT SUPPORT
	friend OPENMAYA_EXPORT MFloatPoint operator*( const MFloatMatrix &,
												  const MFloatPoint & );
	///	NO SCRIPT SUPPORT
	friend OPENMAYA_EXPORT std::ostream& operator<< ( std::ostream& os,
												 const MFloatPoint& p );

END_NO_SCRIPT_SUPPORT:

	///
	static const MFloatPoint origin;
	/// the x component of the point
	float				x;
	/// the y component of the point
	float				y;
	/// the z component of the point
	float				z;
	/// the w component of the point
	float				w;

protected:
// No protected members

private:
// No private members

};

#if defined(_WIN32)
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFloatPoint */
