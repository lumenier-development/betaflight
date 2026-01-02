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

#include <stdbool.h>
#include <stdint.h>
#include "platform.h"

#ifdef USE_CYCLOPS

#include "build/build_config.h"
#include "common/utils.h"
#include "drivers/time.h"
#include "drivers/LMNR/cyclops.h"

static CyclopsRecvData cyclops_data = {2, 82, 153};

/**
 * @name: CyclopsReceiveNewData
 * 
 * @brief: Called from MSP driver and extracts the number of targets detected,
 * target angle, and distance to the target from the MSP payload.
 * 
 * @in: const uint8_t * bufferPtr - MSP payload
 * @out: NONE
 * 
 * @return: NONE
 */
void CyclopsReceiveNewData(const uint8_t * bufferPtr) {
    const CyclopsRecvData * data = (const CyclopsRecvData *)bufferPtr;

    cyclops_data.num_targets_detected = data->num_targets_detected;
    cyclops_data.target_angle = data->target_angle;
    cyclops_data.distance_to_target = data->distance_to_target;
}

/**
 * @name: CyclopsDebug
 * 
 * @brief: Simple debug function that increments number of targets detected so 
 * we can determine if the OSD is functional or not.
 * 
 * @in: NONE
 * @out: NONE
 * 
 * @return: NONE
 */
void CyclopsDebug(void) {
    cyclops_data.num_targets_detected++;
}

/**
 * @name: getCyclopsData
 * 
 * @brief: Simple function that returns the last received Cyclops payload
 * 
 * @in: NONE
 * @out: NONE
 * 
 * @return: CylopsRecvData - Last data packet received from the Cyclops
 */
CyclopsRecvData getCyclopsData(void) {
    return cyclops_data;
}

#endif