
#ifndef _STOCH_H
#define _STOCH_H

#define HIP_ID 1
#define HIP_MIN 6500
#define HIP_MAX 11500

#define KNEE_ID 0
#define KNEE_MIN 3500
#define KNEE_MAX 8400

#define SIT_HIP 9300
#define SIT_KNEE 5100 

#define STAND_HIP 8300
#define STAND_KNEE 5500 

#define DELAY 500 //ms
#define STEP_SIZE 10

void single_traj_write (byte id, unsigned int  start_pos, unsigned int end_pos);
void set_pos (byte id, unsigned int angle);

#endif
