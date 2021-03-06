/*
    Legacy (trunk) - a portable emulator of the 8086-based IBM PC series of computers
    Copyright (C) 2005 Jonathan Thomas
    Contributions and fixes to CPU emulation by Jim Shaw

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#ifndef __VIDEO_DRIVER_PALETTE_5H
#define __VIDEO_DRIVER_PALETTE_5H

// video driver for CGA 640x200x2

#include "VideoDriverPalette.h"
#include "MemoryMap.h"
#include "cpu86.h"
#include "utilities.h"

extern Cpu86 *theCPU;

class CVideoDriverPalette5h:public CVideoDriverPalette {
private:
	// activePalette will point to either palette1 or palette 2, this can be set in the bios call
	uint8 *palette;
public:
	virtual uint8 getWidthInCharacters();
	virtual uint8 getHeightInCharacters();

	CVideoDriverPalette5h(uint8 *emulatedSourceAbsoluteAddres);
	virtual void convertFromEmulatedToIntermediate();
	virtual ~CVideoDriverPalette5h(); // needs to clean up stuff allocated in constructor

	virtual void writeCharacterAtScreenPosition(uint8 xpos,uint8 ypos,uint8 foregroundColour,uint8 backgroundColour,uint8 displayPage);
};

#endif
