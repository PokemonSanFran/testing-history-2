#ifndef GUARD_UNION_ROOM_PLAYER_AVATAR_H
#define GUARD_UNION_ROOM_PLAYER_AVATAR_H

u8 sub_8019BA8(struct UnkStruct_8019BA8 * ptr);
void sub_8019E3C(void);
void CreateGroupMemberObjectsInvisible(u8 *arg0, s32 arg1);
void DestroyGroupMemberObjects(u8 *spriteIds);
void sub_8019F2C(void);
void ScheduleUnionRoomPlayerRefresh(struct WirelessLink_URoom *arg0);
void HandleUnionRoomPlayerRefresh(struct WirelessLink_URoom *arg0);
bool32 RfuUnionTool_GetGroupAndMemberInFrontOfPlayer(struct UnkStruct_Main0 *arg0, s16 *arg1, s16 *arg2, u8 *arg3);
void UpdateUnionGroupMemberFacing(u32 arg0, u32 arg1, struct UnkStruct_Main0 *arg2);

#endif //GUARD_UNION_ROOM_PLAYER_AVATAR_H
