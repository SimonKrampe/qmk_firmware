/*
Copyright 2019 I/O Keyboards <hello@iokeyboards.eu>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 17

// ROWS: Top to bottom, COLS: Left to right

#define MATRIX_ROW_PINS {D3,B5,D5,B7,C7}
#define MATRIX_COL_PINS {B0,F1,F0,B6,B2,B3,B1,F7,F6,F5,F4,B4,E6,D7,D6,D4,D2}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define encoder pads */
#define ENCODERS_PAD_A { D1 }
#define ENCODERS_PAD_B { D0 }

/* define encoder resolution */
#define ENCODER_RESOLUTION 4

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

