#ifndef GUARD_FIELD_PLAYER_AVATAR_H
#define GUARD_FIELD_PLAYER_AVATAR_H

void PlayerStep(u8 direction, u16 newKeys, u16 heldKeys);
void ClearPlayerAvatarInfo(void);
void SetPlayerAvatarExtraStateTransition(u16, u8);
u8 GetPlayerAvatarGenderByGraphicsId(u16);
bool8 TestPlayerAvatarFlags(u8);
u8 GetPlayerAvatarSpriteId(void);
void PlayerGetDestCoords(s16 *, s16 *);
u8 GetPlayerFacingDirection(void);
u8 GetPlayerMovementDirection(void);
u8 PlayerGetCopyableMovement(void);
void PlayerWalkNormal(u8);
void PlayerWalkFast(u8);
void PlayerRideWaterCurrent(u8);
void PlayerWalkFaster(u8);
void PlayerOnBikeCollide(u8);
void PlayerFaceDirection(u8 a);
void PlayerTurnInPlace(u8 a);
void PlayerJumpLedge(u8 a);
void PlayerIdleWheelie(u8 a);
void PlayerStartWheelie(u8 a);
void PlayerEndWheelie(u8 a);
void PlayerStandingHoppingWheelie(u8 a);
void PlayerMovingHoppingWheelie(u8 a);
void PlayerLedgeHoppingWheelie(u8 a);
void PlayerAcroTurnJump(u8 a);
void PlayerSetAnimId(u8 a, u8 b);
bool8 IsPlayerCollidingWithFarawayIslandMew(u8 direction);
void PlayerOnBikeCollideWithFarawayIslandMew(u8 direction);
u8 CheckForObjectEventCollision(struct ObjectEvent *a, s16 b, s16 c, u8 d, u8 e);
u8 PlayerGetZCoord(void);
void SetPlayerAvatarTransitionFlags(u16 a);
void CancelPlayerForcedMovement(void);
void InitPlayerAvatar(s16 a, s16 b, u8 c, u8 d);
void PlayerFreeze(void);
void StopPlayerAvatar(void);
void SetSpinStartFacingDir(u8);
void GetXYCoordsOneStepInFrontOfPlayer(s16 *xPtr, s16 *yPtr);
u16 GetRivalAvatarGraphicsIdByStateIdAndGender(u8, u8);
void SetPlayerAvatarFieldMove(void);
u16 GetPlayerAvatarGraphicsIdByCurrentState(void);
void SetPlayerAvatarStateMask(u8 a);
u16 GetPlayerAvatarGraphicsIdByStateId(u8 a);
u8 GetJumpSpecialMovementAction(u32);
bool8 PartyHasMonWithSurf(void);
bool8 IsPlayerFacingSurfableFishableWater(void);
bool8 IsPlayerSurfingNorth(void);
void SetPlayerAvatarWatering(u8 direction);
u8 GetPlayerAvatarFlags(void);
void UpdatePlayerAvatarTransitionState(void);
u16 GetFRLGAvatarGraphicsIdByGender(u8);
u16 GetRSAvatarGraphicsIdByGender(u8);
void PlayerWheelieInPlace(u8 direction);
void PlayerWheelieMove(u8 direction);
void PlayerPopWheelieWhileMoving(u8 direction);
void PlayerUseAcroBikeOnBumpySlope(u8 direction);
void PlayerEndWheelieWhileMoving(u8 direction);
void DoPlayerSpinEntrance(void);
void DoPlayerSpinExit(void);
bool32 IsPlayerSpinEntranceActive(void);
bool32 IsPlayerSpinExitActive(void);
void SetPlayerInvisibility(bool8 invisible);
u8 player_get_pos_including_state_based_drift(s16 *x, s16 *y);
void StartFishing(u8 rod);
u16 GetPlayerAvatarGraphicsByGender(u8); //custom PSF function for showing the correct avatar on naming screen based on player's body choice

#endif // GUARD_FIELD_PLAYER_AVATAR_H
