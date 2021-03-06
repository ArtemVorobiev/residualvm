/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * Additional copyright for this file:
 * Copyright (C) 1999-2000 Revolution Software Ltd.
 * This code is based on source code created by Revolution Software,
 * used with permission.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "engines/icb/common/px_common.h"

#include "surface_manager.h"
#include "global_objects.h"
#include "graphic_prims.h"

namespace ICB {

int32 twabs(int32 val) {
	if (val >= 0)
		return (val);
	return (0 - val);
}

DXrect MakeRECTFromSpriteSizes(int32 nX, int32 nY, uint32 nWidth, uint32 nHeight) {
	DXrect sRetVal;

	sRetVal.left = nX;
	sRetVal.top = nY;
	sRetVal.right = nX + nWidth;
	sRetVal.bottom = nY + nHeight;

	return (sRetVal);
}

} // End of namespace ICB
