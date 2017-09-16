//
// Created by scott on 9/16/2017.
//

#ifndef GUARD_FIELDMAP_H
#define GUARD_FIELDMAP_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
u8 MapGridGetMetatileBehaviorAt(s16, s16);
void GetCameraCoords(u16*, u16*);
bool8 MapGridIsImpassableAt(s16, s16);
s32 GetMapBorderIdAt(s16, s16);
bool32 CanCameraMoveInDirection(u8);

#endif //GUARD_FIELDMAP_H
