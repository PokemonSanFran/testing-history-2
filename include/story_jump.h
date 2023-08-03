#ifndef GUARD_STORYJUMP_H
#define GUARD_STORYJUMP_H

#define NO_WARP_ID 255
#define USE_WARP_ID -1

extern u8 ThereCanOnlyBeOne_Debug_Script[];

void JumpPlayerToStoryPoint(u8 chosenStoryPoint, u8 taskId);
void WarpPlayerAfterVarSet(void);

#endif // GUARD_STORYJUMP_H
