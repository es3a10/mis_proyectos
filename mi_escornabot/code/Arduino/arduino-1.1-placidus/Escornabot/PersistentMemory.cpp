// PersistentMemory.cpp
/*

Copyright (C) 2014 Bricolabs - http://bricolabs.cc

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
USA.

See LICENSE.txt for details

*/

#include "PersistentMemory.h"
#include <avr/eeprom.h>
#include <avr/crc16.h>


static PersistentMemory PERSISTENT_MEMORY_INSTANCE;
PersistentMemory* PERSISTENT_MEMORY = &PERSISTENT_MEMORY_INSTANCE;


size_t PersistentMemory::totalBytes()
{
    return E2END + 1;
}


bool PersistentMemory::save(size_t address, uint8_t* buffer, size_t length)
{
    eeprom_write_block(buffer, (uint8_t*) address, length);

    // ToDo: test CRC verification

    return true;
}


bool PersistentMemory::load(size_t address, uint8_t* buffer, size_t length)
{
    eeprom_read_block(buffer, (uint8_t*)address, length);

    // ToDo test CRC verification

    return true;
}


void PersistentMemory::clear()
{
	for (int a = 0; a < E2END; a++)
	{
		eeprom_write_byte((uint8_t*)a, 0);
	}
}


// EOF
