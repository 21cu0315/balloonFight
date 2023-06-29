//----------------------------------------------------------
// ファイル名		：PlayerOffScreen.cpp
// 概要				：プレイヤーの画面外の処理
// 作成者			：21CU0315 黄卓賢
// 更新内容			：2022/03/03 21CU0315 黄卓賢 作成
//					：2022/03/07 21CU0315 黄卓賢 プレイヤーの画像の位置を補正する処理を修正
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::PlayerOffScreen()
{
	if (g_pPlayer1[0] != NULL && g_pPlayer1[1] != NULL)
	{
		//プレイヤーの画像の縦位置を修正する
		if (g_pPlayer1[0]->getPos().x > -WINDOW_WIDTH / 2 && g_pPlayer1[0]->getPos().x < WINDOW_WIDTH / 2)
		{
			g_pPlayer1[1]->setPos(g_pPlayer1[1]->getPos().x, g_pPlayer1[0]->getPos().y);
		}
		else if (g_pPlayer1[1]->getPos().x > -WINDOW_WIDTH / 2 && g_pPlayer1[1]->getPos().x < WINDOW_WIDTH / 2)
		{
			g_pPlayer1[0]->setPos(g_pPlayer1[0]->getPos().x, g_pPlayer1[1]->getPos().y);
		}

		//プレイヤーの画像の横速度を一致する
		for (int i = 0; i < 2; ++i)
		{
			g_pPlayer1[i]->setPos(g_pPlayer1[i]->getPos().x + playerHoriSpeed * 1.0f, g_pPlayer1[i]->getPos().y);
		}
		//プレイヤーが横に移動する時、画像がループできるように配置する
		if (playerHoriSpeed > 0)
		{
			if (g_pPlayer1[0]->getPos().x > (WINDOW_WIDTH / 2) + 64.0f)
			{
				g_pPlayer1[0]->setPos((g_pPlayer1[1]->getPos().x - WINDOW_WIDTH), g_pPlayer1[1]->getPos().y);
			}
			else if (g_pPlayer1[1]->getPos().x > (WINDOW_WIDTH / 2) + 64.0f)
			{
				g_pPlayer1[1]->setPos((g_pPlayer1[0]->getPos().x - WINDOW_WIDTH), g_pPlayer1[0]->getPos().y);
			}
		}
		else if (playerHoriSpeed < 0)
		{
			if (g_pPlayer1[0]->getPos().x < (-WINDOW_WIDTH / 2) - 64.0f)
			{
				g_pPlayer1[0]->setPos((g_pPlayer1[1]->getPos().x + WINDOW_WIDTH), g_pPlayer1[1]->getPos().y);
			}
			else if (g_pPlayer1[1]->getPos().x < (-WINDOW_WIDTH / 2) - 64.0f)
			{
				g_pPlayer1[1]->setPos((g_pPlayer1[0]->getPos().x + WINDOW_WIDTH), g_pPlayer1[0]->getPos().y);
			}
		}
	}
}