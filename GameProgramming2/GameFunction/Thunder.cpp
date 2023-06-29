//----------------------------------------------------------
// ファイル名		：Thunder.cpp
// 概要				：雷ボールの処理
// 作成者			：21CU0315 黄卓賢
// 更新内容			：2022/03/09 21CU0315 黄卓賢 作成
//					：2022/03/10 21CU0315 黄卓賢 雷ボールとプレイヤーの当たり判定
//----------------------------------------------------------


#include "CActionGameApp.h"
#include <time.h>
#include <cstdlib>

void CActionGameApp::Thunder()
{
	//30秒が経ったら、雷ボールが生成し始める
	ThunderSpawnCounter++;

	if (ThunderSpawnCounter == 60 * 30)
	{
		ThunderSpawning = true;
	}
	
	
	//雷ボールが生成されている時
	if (ThunderSpawning == true)
	{
		for (int i = 0; i < ThunderQuantity; ++i)
		{
			//縦移動の処理
			if (g_pThunder[i].obj->getPos().y > (WINDOW_HEIGHT / 2 - THUNDER_SIZE_Y / 2))
			{
				g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, WINDOW_HEIGHT / 2 - THUNDER_SIZE_Y / 2);
				g_pThunder[i].thunderMoveY *= -1.0f;
			}
			else
			{
				g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, g_pThunder[i].obj->getPos().y + g_pThunder[i].thunderMoveY);
			}
			//横移動の処理
			if (g_pThunder[i].obj->getPos().x > (WINDOW_WIDTH / 2 - THUNDER_SIZE_Y / 2))
			{
				g_pThunder[i].obj->setPos(WINDOW_WIDTH / 2 - THUNDER_SIZE_Y / 2, g_pThunder[i].obj->getPos().y);
				g_pThunder[i].thunderMoveX *= -1.0f;
			}
			else if (g_pThunder[i].obj->getPos().x < (-WINDOW_WIDTH / 2 + THUNDER_SIZE_Y / 2))
			{
				g_pThunder[i].obj->setPos(-WINDOW_WIDTH / 2 + THUNDER_SIZE_Y / 2, g_pThunder[i].obj->getPos().y);
				g_pThunder[i].thunderMoveX *= -1.0f;
			}
			else
			{
				g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x + g_pThunder[i].thunderMoveX, g_pThunder[i].obj->getPos().y);
			}
			//画面の下に出た時、リセットする
			if (g_pThunder[i].obj->getPos().y < -WINDOW_HEIGHT / 2)
			{
				g_pThunder[i].obj->setPos(90.0f, 200.0f);
				g_pThunder[i].thunderMoveX = 0.0f;
				g_pThunder[i].thunderMoveY = 0.0f;
				g_pThunder[i].isMoving = false;
			}




			//雷ボールが複数生成された時の処理
			ThunderSpawnCD++;
		
		

			if (g_pThunder[0].isMoving == false && g_pThunder[1].isMoving == false)
			{
				if (ThunderSpawnCD % 300 == 0)
				{
					ThunderDirection(0);
					g_pThunder[0].isMoving = true;
					ThunderSpawnCD = 1;
				}
			}
			else if (g_pThunder[0].isMoving != false && g_pThunder[1].isMoving == false)
			{
				if (ThunderSpawnCD % 300 == 0)
				{
					ThunderDirection(1);
					g_pThunder[1].isMoving = true;
					ThunderSpawnCD = 1;
				}
			}
			else if (g_pThunder[0].isMoving == false && g_pThunder[1].isMoving != false)
			{
				if (ThunderSpawnCD % 300 == 0)
				{
					ThunderDirection(0);
					g_pThunder[0].isMoving = true;
					ThunderSpawnCD = 1;
				}
			}
			
			//地面との当たり判定
			for (int i = 0; i < ThunderQuantity; ++i)
			{
				for (int j = 0; j < GroundQuantity; ++j)
				{
					if (g_pThunder[i].obj->collision(g_pGround[j]))
					{
						g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, g_pGround[j]->getPos().y + GROUND_SIZE_Y / 2 + THUNDER_SIZE_Y / 2);
						g_pThunder[i].thunderMoveY *= -1.0f;
					}
				}
			}
			//足場Sとの当たり判定
			for (int i = 0; i < ThunderQuantity; ++i)
			{
				for (int j = 0; j < PlatFormQuantityS; ++j)
				{
					if (g_pThunder[i].obj->getPos().y > g_pPlatFormS[j]->getPos().y)
					{
						if (g_pThunder[i].obj->collision(g_pPlatFormS[j]))
						{
							g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, g_pPlatFormS[j]->getPos().y + PLATFORMS_SIZE_ALL / 2 + THUNDER_SIZE_Y / 2);
							g_pThunder[i].thunderMoveY *= -1.0f;
						}
					}
					else if (g_pThunder[i].obj->getPos().y < g_pPlatFormS[j]->getPos().y)
					{
						if (g_pThunder[i].obj->collision(g_pPlatFormS[j]))
						{
							g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, g_pPlatFormS[j]->getPos().y - PLATFORMS_SIZE_ALL / 2 - THUNDER_SIZE_Y / 2);
							g_pThunder[i].thunderMoveY *= -1.0f;
						}
					}
				}
			}
			//足場Lとの当たり判定
			for (int i = 0; i < ThunderQuantity; ++i)
			{
				for (int j = 0; j < PlatFormQuantityL; ++j)
				{
					if (g_pThunder[i].obj->getPos().y > g_pPlatFormL[j]->getPos().y)
					{
						if (g_pThunder[i].obj->collision(g_pPlatFormL[j]))
						{
							g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, g_pPlatFormL[j]->getPos().y + PLATFORMS_SIZE_ALL / 2 + THUNDER_SIZE_Y / 2);
							g_pThunder[i].thunderMoveY *= -1.0f;
						}
					}
					else if (g_pThunder[i].obj->getPos().y < g_pPlatFormL[j]->getPos().y)
					{
						if (g_pThunder[i].obj->collision(g_pPlatFormL[j]))
						{
							g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, g_pPlatFormL[j]->getPos().y - PLATFORMS_SIZE_ALL / 2 - THUNDER_SIZE_Y / 2);
							g_pThunder[i].thunderMoveY *= -1.0f;
						}
					}
				}
			}

			//プレイヤーとの当たり判定
			for (int i = 0; i < ThunderQuantity; ++i)
			{
				for (int j = 0; j < PlayerQuantity; ++j)
				{
					if (g_pPlayer1[j]->collision(g_pThunder[i].obj) && g_pThunder[i].isMoving == true && PlayerInvincible != false)
					{
						g_pThunder[i].obj->setPos(90.0f, 200.0f);
						g_pThunder[i].thunderMoveX = 0.0f;
						g_pThunder[i].thunderMoveY = 0.0f;
						g_pThunder[i].isMoving = false;
						PlayerDieBalloon = true;
						PlayerIsKilledByThunder = true;
					}
				}
			}
		}
	}
	//アニメーションをさせる
	for (int i = 0; i < ThunderQuantity; ++i)
	{
		g_pThunder[i].obj->stepAnimation();
	}
}

void CActionGameApp::ThunderDirection(int noOfThunder)
{
	//乱数表の種を設定
	srand((unsigned)time(NULL));
	g_pThunder[noOfThunder].thunderDirRand = rand() % 4;

	if (g_pThunder[noOfThunder].thunderDirRand == 0)
	{
		g_pThunder[noOfThunder].thunderMoveX = 1.5f;
		g_pThunder[noOfThunder].thunderMoveY = 4.0f;
	}
	else if (g_pThunder[noOfThunder].thunderDirRand == 1)
	{
		g_pThunder[noOfThunder].thunderMoveX = -1.5f;
		g_pThunder[noOfThunder].thunderMoveY = 4.0f;
	}
	else if (g_pThunder[noOfThunder].thunderDirRand == 2)
	{
		g_pThunder[noOfThunder].thunderMoveX = 1.5f;
		g_pThunder[noOfThunder].thunderMoveY = -4.0f;
	}
	else if (g_pThunder[noOfThunder].thunderDirRand == 3)
	{
		g_pThunder[noOfThunder].thunderMoveX = -1.5f;
		g_pThunder[noOfThunder].thunderMoveY = -4.0f;
	}
}