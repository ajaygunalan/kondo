#define HIP_ID 1
#define HIP_MIN 6500
#define HIP_MAX 11500

#define KNEE_ID 0
#define KNEE_MIN 3500
#define KNEE_MAX 8400

#define SIT_HIP 9800
#define SIT_KNEE 5600 

#define STAND_HIP 8100
#define STAND_KNEE 5600 

#define DELAY 0 //ms
#define STEP_SIZE 10

void single_traj_write (int id, unsigned int  start_pos, unsigned int end_pos);
void set_pos (int id, unsigned int angle);
