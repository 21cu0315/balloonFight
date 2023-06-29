//----------------------------------------------------------
// ファイル名		：AllReset.cpp
// 概要				：プレイヤーの残機以外全てリセットする関数
// 作成者			：21CU0118　小池慎之介
// 更新内容			：2022/03/14　小池慎之介作成
//					：2022/03/18	 21CU0315 黄卓賢 プレイヤーのアニメーションとプレイヤーが死ぬときのカウンターをリセットする処理を追加
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::AllReset()
{
	playerCaughtByFish = false;
	if (iPlayerResidue != 0)
	{
		g_pPlayer1[0]->setPos(PlayerSet[0]);
		g_pPlayer1[1]->setPos(PlayerSet[1]);
	}
	g_pFish->setPos(fishPos);
	resetPlayerFishPos = false;
	PlayerBalloon = 2;
	PlayerDieBalloon = false;
	g_pPlayer1[0]->setAnimation(7);
	g_pPlayer1[1]->setAnimation(7);
	playerDeathGoUpCounter = 0;
	PlayerIsKilledByThunder = false;
}