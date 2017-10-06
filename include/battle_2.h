#ifndef GUARD_BATTLE_2_H
#define GUARD_BATTLE_2_H

void CB2_InitBattle(void);
void CB2_QuitRecordedBattle(void);
void FaintClearSetData(void);
void SwitchInClearSetData(void);
void sub_803BDA0(u8 bank);
void BattleMainCB2(void);
void VBlankCB_Battle(void);
bool8 TryRunFromBattle(u8 bank);
u8 IsRunningFromBattleImpossible(void);
u8 GetWhoStrikesFirst(u8 bank1, u8 bank2, bool8 ignoreChosenMoves);
void SwapTurnOrder(u8 id1, u8 id2);
void BattleTurnPassed(void);
void RunBattleScriptCommands_PopCallbacksStack(void);
void RunBattleScriptCommands(void);

#endif // GUARD_BATTLE_2_H
