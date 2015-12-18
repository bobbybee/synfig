/* === S Y N F I G ========================================================= */
/*!	\file synfig/rendering/software/function/fftw.h
**	\brief FFTW Header
**
**	$Id$
**
**	\legal
**	......... ... 2015 Ivan Mahonin
**
**	This package is free software; you can redistribute it and/or
**	modify it under the terms of the GNU General Public License as
**	published by the Free Software Foundation; either version 2 of
**	the License, or (at your option) any later version.
**
**	This package is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
**	General Public License for more details.
**	\endlegal
*/
/* ========================================================================= */

/* === S T A R T =========================================================== */

#ifndef __SYNFIG_RENDERING_SOFTWARE_FFTW_H
#define __SYNFIG_RENDERING_SOFTWARE_FFTW_H

/* === H E A D E R S ======================================================= */

#include <synfig/complex.h>

/* === M A C R O S ========================================================= */

/* === T Y P E D E F S ===================================================== */

/* === C L A S S E S & S T R U C T S ======================================= */

namespace synfig
{
namespace rendering
{
namespace software
{

class FFTW
{
private:
	class Internal;

public:
	static int get_valid_count(int x);
	static bool is_valid_count(int x);

	static void multiply(Complex *x, int count, int stride, Real y);

	//! Fast Furier Transform
	//! @count should be compatible, use get_valid_count()
	//! @stride - distance (in items) between two sequential items
	static void fft(Complex *x, int count, int stride, bool invert);

	//! Fast Furier Transform 2d
	//! @rows and @cols should be compatible, use get_valid_count()
	//! @col_stride - distance (in items) between two sequential items
	//! @row_stride - distance (in items) between two sequential rows of items
	static void fft2d(Complex *x, int rows, int row_stride, int cols, int col_stride, bool invert, bool do_rows = true, bool do_cols = true);

	static void initialize();
	static void deinitialize();
};

} /* end namespace software */
} /* end namespace rendering */
} /* end namespace synfig */

/* -- E N D ----------------------------------------------------------------- */

#endif
