//----------------------------------------------------------
// ファイル名		：PlayerDieAction()
// 概要				：プレイヤーが死んだときの処理
// 作成者			：21cu0118 小池慎之介
// 更新内容			：2022/03/16 21cu0118 小池慎之介 作成
//					：2022/03/18 21CU0315 黄卓賢 プレイヤーが死ぬときのアニメーションを追加
//----------------------------------------------------------
#include "CActionGameApp.h"



void CActionGameApp::PlayerDieActionActive()
{
	//プレイヤーの座標が特定の値よりも下だったら
	//プレイヤーを落とす
	if (resetPlayerFishPos != false)
	{
		//変数を戻すF
		PlayerDieBalloon = false;
		//バルーンの残機の復活
		PlayerBalloon = 3;
		//変数の変更
		resetPlayerFishPos = false;
	}
	else if (PlayerIsKilledByThunder == true)
	{
		playerDeathAnimeCounter++;
		playerDeathGoUpCounter++;
		for (int i = 0; i < PlayerQuantity; ++i)
		{
			g_pPlayer1[i]->setAnimationRange(31, 32);
			if (playerDeathAnimeCounter % 3 == 0)
			{
				g_pPlayer1[i]->stepAnimation();
				playerDeathAnimeCounter = 0;
			}
		}

		if (playerDeathGoUpCounter > 60)
		{
			g_pPlayer1[0]->setPos(g_pPlayer1[0]->getPos().x, g_pPlayer1[0]->getPos().y - 5.0f);
			g_pPlayer1[1]->setPos(g_pPlayer1[1]->getPos().x, g_pPlayer1[1]->getPos().y - 5.0f);
		}

	}
	else
	{
		playerDeathAnimeCounter++;
		playerDeathGoUpCounter++;
		for (int i = 0; i < PlayerQuantity; ++i)
		{
			if (g_pPlayer1[i] != NULL)
			{
				g_pPlayer1[i]->setAnimationRange(28, 30);
				if (playerDeathAnimeCounter % 3 == 0)
				{
					g_pPlayer1[i]->stepAnimation();
					playerDeathAnimeCounter = 0;
				}
			}
		}
		if (playerDeathGoUpCounter < 30)
		{
			g_pPlayer1[0]->setPos(g_pPlayer1[0]->getPos().x, g_pPlayer1[0]->getPos().y + 5.0f);
			g_pPlayer1[1]->setPos(g_pPlayer1[1]->getPos().x, g_pPlayer1[1]->getPos().y + 5.0f);
		}
		else
		{
			g_pPlayer1[0]->setPos(g_pPlayer1[0]->getPos().x, g_pPlayer1[0]->getPos().y - 5.0f);
			g_pPlayer1[1]->setPos(g_pPlayer1[1]->getPos().x, g_pPlayer1[1]->getPos().y - 5.0f);
		}
	}
}