//----------------------------------------------------------
// ファイル名		：EnemyDead.cpp
// 概要				：敵キャラが死んだときの処理
// 作成者			：21CU0315 黄卓賢
// 更新内容			：2022/03/23 21CU0315 黄卓賢 作成
//----------------------------------------------------------

#include "CActionGameApp.h"

void CActionGameApp::EnemyDead()
{
	//敵1が死んだとき
	if (enemyIsDead[0] == true && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL)
	{
		//死んだときのアニメーションカウンターを回す
		EnemyDeadAnimeCounter[0]++;
		//アニメーションの範囲を設定する
		g_pEnemy[0]->setAnimationRange(13, 14);
		g_pEnemy[1]->setAnimationRange(13, 14);
		//アニメーションを動く
		g_pEnemy[0]->stepAnimation();
		g_pEnemy[1]->stepAnimation();

		//敵が死んだとき、10フレームに上に移動する
		if (EnemyDeadUp[0] < 10)
		{
			EnemyDeadUp[0]++;
			g_pEnemy[0]->setPos(g_pEnemy[0]->getPos().x, g_pEnemy[0]->getPos().y + 5.0f);
			g_pEnemy[1]->setPos(g_pEnemy[1]->getPos().x, g_pEnemy[1]->getPos().y + 5.0f);
		}
		//10フレームが過ぎたら、下に移動する
		else if (EnemyDeadUp[0] == 10)
		{
			g_pEnemy[0]->setPos(g_pEnemy[0]->getPos().x, g_pEnemy[0]->getPos().y - 5.0f);
			g_pEnemy[1]->setPos(g_pEnemy[1]->getPos().x, g_pEnemy[1]->getPos().y - 5.0f);

		}
	}
	//敵2が死んだとき
	if (enemyIsDead[1] == true && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
	{
		EnemyDeadAnimeCounter[1]++;
		g_pEnemy[2]->setAnimationRange(13, 14);
		g_pEnemy[3]->setAnimationRange(13, 14);
		g_pEnemy[2]->stepAnimation();
		g_pEnemy[3]->stepAnimation();
		if (EnemyDeadUp[1] < 10)
		{
			EnemyDeadUp[1]++;
			g_pEnemy[2]->setPos(g_pEnemy[2]->getPos().x, g_pEnemy[2]->getPos().y + 5.0f);
			g_pEnemy[3]->setPos(g_pEnemy[3]->getPos().x, g_pEnemy[3]->getPos().y + 5.0f);
		}
		else if (EnemyDeadUp[1] == 10)
		{
			g_pEnemy[2]->setPos(g_pEnemy[2]->getPos().x, g_pEnemy[2]->getPos().y - 5.0f);
			g_pEnemy[3]->setPos(g_pEnemy[3]->getPos().x, g_pEnemy[3]->getPos().y - 5.0f);

		}
	}
	//敵3が死んだとき
	if (enemyIsDead[2] == true && g_pEnemy[4] != NULL && g_pEnemy[5] != NULL)
	{
		EnemyDeadAnimeCounter[2]++;
		g_pEnemy[4]->setAnimationRange(13, 14);
		g_pEnemy[5]->setAnimationRange(13, 14);
		g_pEnemy[4]->stepAnimation();
		g_pEnemy[5]->stepAnimation();
		if (EnemyDeadUp[2] < 10)
		{
			EnemyDeadUp[2]++;
			g_pEnemy[4]->setPos(g_pEnemy[4]->getPos().x, g_pEnemy[4]->getPos().y + 5.0f);
			g_pEnemy[5]->setPos(g_pEnemy[5]->getPos().x, g_pEnemy[5]->getPos().y + 5.0f);
		}
		else if (EnemyDeadUp[2] == 10)
		{
			g_pEnemy[4]->setPos(g_pEnemy[4]->getPos().x, g_pEnemy[4]->getPos().y - 5.0f);
			g_pEnemy[5]->setPos(g_pEnemy[5]->getPos().x, g_pEnemy[5]->getPos().y - 5.0f);
		}
	}
	//敵が画面外に出た時、破棄する
	for (int i = 0; i < EnemyQuantity; ++i)
	{
		if (g_pEnemy[i] != NULL)
		{
			if (g_pEnemy[i]->getPos().y < -WINDOW_HEIGHT / 2 - ENEMY_SIZE_Y / 2)
			{
				disposeSprite(g_pEnemy[i]);
				g_pEnemy[i] = NULL;
			}
		}
	}
	if (g_pEnemy[0] == NULL && g_pEnemy[1] != NULL)
	{
		disposeSprite(g_pEnemy[1]);
		g_pEnemy[1] = NULL;
	}
	if (g_pEnemy[1] == NULL && g_pEnemy[0] != NULL)
	{
		disposeSprite(g_pEnemy[0]);
		g_pEnemy[0] = NULL;
	}
	if (g_pEnemy[2] == NULL && g_pEnemy[3] != NULL)
	{
		disposeSprite(g_pEnemy[3]);
		g_pEnemy[3] = NULL;
	}
	if (g_pEnemy[3] == NULL && g_pEnemy[2] != NULL)
	{
		disposeSprite(g_pEnemy[2]);
		g_pEnemy[2] = NULL;
	}
	if (g_pEnemy[4] == NULL && g_pEnemy[5] != NULL)
	{
		disposeSprite(g_pEnemy[5]);
		g_pEnemy[5] = NULL;
	}
	if (g_pEnemy[5] == NULL && g_pEnemy[4] != NULL)
	{
		disposeSprite(g_pEnemy[4]);
		g_pEnemy[4] = NULL;
	}
}