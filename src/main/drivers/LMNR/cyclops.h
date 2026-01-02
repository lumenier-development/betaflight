/*
 * This file is part of Betaflight and INAV
 *
 * Betaflight and INAV are free software. You can
 * redistribute this software and/or modify this software under
 * the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * Betaflight and INAV are distributed in the hope that
 * they will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "common/time.h"
#include "drivers/io_types.h"

typedef struct {
    uint8_t num_targets_detected;
    int16_t target_angle;
    int16_t distance_to_target;
} CyclopsRecvData;

typedef enum {
    NUM_TARGETS_DETECTED = 0,
    TARGET_ANGLE = 1,
    DISTANCE_TO_TARGET = 2,
    LIST_MAX = 3
} CYCLOPS_DATA_LIST;

void CyclopsReceiveNewData(const uint8_t * bufferPtr);
void CyclopsDebug(void) ;
CyclopsRecvData getCyclopsData(void);