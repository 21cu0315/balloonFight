//----------------------------------------------------------
// ファイル名		：EnemyBalloonCack()
// 概要				：敵のバルーンが破壊されているかの確認
// 作成者			：21CU0118　小池慎之介
// 更新内容			：2022/03/15　小池慎之介 作成 確認およびEnemyNotBallonへの接続
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyBalloonCeck()
{
	//for文を使用し、破壊されているかの確認
	for (int i = 0; i < EnemyBalloonCeckCnt; ++i)
	{
		//もし破壊されていたら
		//破壊されたときの関数へ移行
		if (enemyBalloonIsBroken[i] != false)
		{
			//関数の呼び出し
			EenemyNotBalune(i);
		}
	}
}
