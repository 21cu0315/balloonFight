//----------------------------------------------------------
// ファイル名		：GameClearSet.cpp
// 概要				：ゲームの終了判定
// 作成者			：21CU0118　小池慎之介
// 更新内容			：2022/03/31 小池慎之介　作成
//----------------------------------------------------------
#include "CactionGameApp.h"

void CActionGameApp::GameClearSet()
{
	//ゲームの終了判定
	//敵が全ていなくなったら
	for (int i = 0; i < EnemyQuantity; ++i)
	{
		if (g_pEnemy[i] != NULL)
		{
			//敵が1体でも生存していたら関数を終了する
			return;
		}
	}
	//プレイヤーをその場にとどめる
	bPlayerStop = true;

	//xキーでタイトルに戻る
	if (getInput()->isPressedOnce(DIK_X))
	{
		g_NextStatusFromGame = eOpening;
		g_GamePhase = eEnd;
		GameReset();
	}

}