//----------------------------------------------------------
// ファイル名		：EnemyOffScreen.cpp
// 概要				：敵の画面外の処理
// 作成者			：21CU0315 黄卓賢
// 更新内容			：2022/03/03 21CU0315 黄卓賢 作成
//					：2022/03/10 21CU0315 黄卓賢 横移動の値を修正
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyOffScreen()
{
	if (enemyIsDead[0] != true && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL)
	{
		//プレイヤーの画像の縦位置を修正する
		if (g_pEnemy[0]->getPos().x > -WINDOW_WIDTH / 2 && g_pEnemy[0]->getPos().x < WINDOW_WIDTH / 2)
		{
			g_pEnemy[1]->setPos(g_pEnemy[1]->getPos().x, g_pEnemy[0]->getPos().y);
		}
		else if (g_pEnemy[1]->getPos().x > -WINDOW_WIDTH / 2 && g_pEnemy[1]->getPos().x < WINDOW_WIDTH / 2)
		{
			g_pEnemy[0]->setPos(g_pEnemy[0]->getPos().x, g_pEnemy[1]->getPos().y);
		}
	}
	if (enemyIsDead[1] != true && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
	{
		if (g_pEnemy[2]->getPos().x > -WINDOW_WIDTH / 2 && g_pEnemy[2]->getPos().x < WINDOW_WIDTH / 2)
		{
			g_pEnemy[3]->setPos(g_pEnemy[3]->getPos().x, g_pEnemy[2]->getPos().y);
		}
		else if (g_pEnemy[3]->getPos().x > -WINDOW_WIDTH / 2 && g_pEnemy[3]->getPos().x < WINDOW_WIDTH / 2)
		{
			g_pEnemy[2]->setPos(g_pEnemy[2]->getPos().x, g_pEnemy[3]->getPos().y);
		}
	}
	if (enemyIsDead[2] != true && g_pEnemy[4] != NULL && g_pEnemy[5] != NULL)
	{
		if (g_pEnemy[4]->getPos().x > -WINDOW_WIDTH / 2 && g_pEnemy[4]->getPos().x < WINDOW_WIDTH / 2)
		{
			g_pEnemy[5]->setPos(g_pEnemy[5]->getPos().x, g_pEnemy[4]->getPos().y);
		}
		else if (g_pEnemy[5]->getPos().x > -WINDOW_WIDTH / 2 && g_pEnemy[5]->getPos().x < WINDOW_WIDTH / 2)
		{
			g_pEnemy[4]->setPos(g_pEnemy[4]->getPos().x, g_pEnemy[5]->getPos().y);
		}
	}

	//プレイヤーの画像の横速度を一致する
	for (int i = 0; i < EnemyQuantity; ++i)
	{
		if (i == 0 || i == 1)
		{
			if (enemyIsDead[0] != true && g_pEnemy[i] != NULL)
			{
				g_pEnemy[i]->setPos(g_pEnemy[i]->getPos().x + ENEMY_SPEED_X, g_pEnemy[i]->getPos().y + ENEMY_SPEED_Y);
			}
		}
		if (i == 2 || i == 3)
		{
			if (enemyIsDead[1] != true && g_pEnemy[i] != NULL)
			{
				g_pEnemy[i]->setPos(g_pEnemy[i]->getPos().x + ENEMY_SPEED_X2, g_pEnemy[i]->getPos().y + ENEMY_SPEED_Y2);
			}
		}
		if (i == 4 || i == 5)
		{
			if (enemyIsDead[2] != true && g_pEnemy[i] != NULL)
			{
				g_pEnemy[i]->setPos(g_pEnemy[i]->getPos().x + ENEMY_SPEED_X3, g_pEnemy[i]->getPos().y + ENEMY_SPEED_Y3);
			}
		}
	}

	//プレイヤーが横に移動する時、画像がループできるように配置する
	if (ENEMY_SPEED_X > 0 && enemyIsDead[0] != true && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL)
	{
		if (g_pEnemy[0]->getPos().x > (WINDOW_WIDTH / 2) + 64.0f)
		{
			g_pEnemy[0]->setPos((g_pEnemy[1]->getPos().x - WINDOW_WIDTH), g_pEnemy[1]->getPos().y);
		}
		else if (g_pEnemy[1]->getPos().x > (WINDOW_WIDTH / 2) + 64.0f)
		{
			g_pEnemy[1]->setPos((g_pEnemy[0]->getPos().x - WINDOW_WIDTH), g_pEnemy[0]->getPos().y);
		}
	}
	else if (ENEMY_SPEED_X < 0 && enemyIsDead[0] != true && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL)
	{
		if (g_pEnemy[0]->getPos().x < (-WINDOW_WIDTH / 2) - 64.0f)
		{
			g_pEnemy[0]->setPos((g_pEnemy[1]->getPos().x + WINDOW_WIDTH), g_pEnemy[1]->getPos().y);
		}
		else if (g_pEnemy[1]->getPos().x < (-WINDOW_WIDTH / 2) - 64.0f)
		{
			g_pEnemy[1]->setPos((g_pEnemy[0]->getPos().x + WINDOW_WIDTH), g_pEnemy[0]->getPos().y);
		}
	}
	if (ENEMY_SPEED_X2 > 0 && enemyIsDead[1] != true && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
	{
		if (g_pEnemy[2]->getPos().x > (WINDOW_WIDTH / 2) + 64.0f)
		{
			g_pEnemy[2]->setPos((g_pEnemy[3]->getPos().x - WINDOW_WIDTH), g_pEnemy[3]->getPos().y);
		}
		else if (g_pEnemy[3]->getPos().x > (WINDOW_WIDTH / 2) + 64.0f)
		{
			g_pEnemy[3]->setPos((g_pEnemy[2]->getPos().x - WINDOW_WIDTH), g_pEnemy[2]->getPos().y);
		}
	}
	else if (ENEMY_SPEED_X2 < 0 && enemyIsDead[1] != true && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
	{
		if (g_pEnemy[2]->getPos().x < (-WINDOW_WIDTH / 2) - 64.0f)
		{
			g_pEnemy[2]->setPos((g_pEnemy[3]->getPos().x + WINDOW_WIDTH), g_pEnemy[3]->getPos().y);
		}
		else if (g_pEnemy[3]->getPos().x < (-WINDOW_WIDTH / 2) - 64.0f)
		{
			g_pEnemy[3]->setPos((g_pEnemy[2]->getPos().x + WINDOW_WIDTH), g_pEnemy[2]->getPos().y);
		}
	}
	if (ENEMY_SPEED_X3 > 0 && enemyIsDead[2] != true && g_pEnemy[4] != NULL && g_pEnemy[5] != NULL)
	{
		if (g_pEnemy[4]->getPos().x > (WINDOW_WIDTH / 2) + 64.0f)
		{
			g_pEnemy[4]->setPos((g_pEnemy[5]->getPos().x - WINDOW_WIDTH), g_pEnemy[5]->getPos().y);
		}
		else if (g_pEnemy[5]->getPos().x > (WINDOW_WIDTH / 2) + 64.0f)
		{
			g_pEnemy[5]->setPos((g_pEnemy[4]->getPos().x - WINDOW_WIDTH), g_pEnemy[4]->getPos().y);
		}

	}
	else if (ENEMY_SPEED_X3 < 0 && enemyIsDead[2] != true && g_pEnemy[4] != NULL && g_pEnemy[5] != NULL)
	{
		if (g_pEnemy[4]->getPos().x < (-WINDOW_WIDTH / 2) - 64.0f)
		{
			g_pEnemy[4]->setPos((g_pEnemy[5]->getPos().x + WINDOW_WIDTH), g_pEnemy[5]->getPos().y);
		}
		else if (g_pEnemy[5]->getPos().x < (-WINDOW_WIDTH / 2) - 64.0f)
		{
			g_pEnemy[5]->setPos((g_pEnemy[4]->getPos().x + WINDOW_WIDTH), g_pEnemy[4]->getPos().y);
		}
	}
}