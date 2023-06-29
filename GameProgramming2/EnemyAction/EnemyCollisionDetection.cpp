//----------------------------------------------------------
// ファイル名		：EnemyCollisionDetection.cpp
// 概要				：敵キャラの当たり判定
// 作成者			：21CU0315 黄卓賢
// 更新内容			：2022/03/10 21CU0315 黄卓賢 作成
//					：2022/03/15 21CU0315 黄卓賢 敵と地面の当たり判定を修正、
//												 敵と他の敵をぶつかったときの処理を追加
//					：2022/04/05 21CU0315 黄卓賢 敵の当たり判定時々なくなるバグを修正しました
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyCollisionDetection()
{
	//ブロックの当たり判定
	//g_pPlatFormLに当たっているとき、以下の処理を行い座標を更新する
	for (int i = 0; i < PlatFormQuantityL; ++i)
	{
		for (int j = 0; j < EnemyQuantity; ++j)
		{
			if (g_pEnemy[j] != NULL)
			{
				//敵が画面の上に出ないように設定する
				if (g_pEnemy[j]->getPos().y > (WINDOW_HEIGHT / 2 - 48.0f))
				{
					if (j == EnemyType01_01 || j == EnemyType01_02)
					{
						g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, WINDOW_HEIGHT / 2 - 48.0f);
						ENEMY_SPEED_Y = -2.0f;
					}
					else if (j == EnemyType02_01 || j == EnemyType02_02)
					{
						g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, WINDOW_HEIGHT / 2 - 48.0f);
						ENEMY_SPEED_Y2 = -2.0f;
					}
					else if (j == EnemyType03_01 || j == EnemyType03_02)
					{
						g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, WINDOW_HEIGHT / 2 - 48.0f);
						ENEMY_SPEED_Y3 = -2.0f;
					}
				}

				if (g_pEnemy[j]->collision(g_pPlatFormL[i]) != false)
				{
					if (g_pEnemy[j]->getPos().y > g_pPlatFormL[i]->getPos().y)
					{

						//上から当たってるとき値を0にする
						if (j == EnemyType01_01 || j == EnemyType01_02)
						{
							if (enemyBalloonIsBroken[0] != true && enemyIsDead[0] != true)
							{
								//プレイヤーの座標を床に接する位置まで調整する
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pPlatFormL[i]->getPos().y + 64.0f);
								ENEMY_SPEED_Y = 2.0f;
							}
						}
						else if (j == EnemyType02_01 || j == EnemyType02_02)
						{
							if (enemyBalloonIsBroken[1] != true && enemyIsDead[1] != true)
							{
								//プレイヤーの座標を床に接する位置まで調整する
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pPlatFormL[i]->getPos().y + 64.0f);
								ENEMY_SPEED_Y2 = 2.0f;
							}
						}
						else if (j == EnemyType03_01 || j == EnemyType03_02)
						{
							if (enemyBalloonIsBroken[2] != true && enemyIsDead[2] != true)
							{
								//プレイヤーの座標を床に接する位置まで調整する
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pPlatFormL[i]->getPos().y + 64.0f);
								ENEMY_SPEED_Y3 = 2.0f;
							}
						}
					}
					else
					{
						if (j == EnemyType01_01 || j == EnemyType01_02)
						{
							if (enemyBalloonIsBroken[0] != true && enemyIsDead[0] != true)
							{
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, (g_pPlatFormL[i]->getPos().y - 16.0f - 48.0f));
								ENEMY_SPEED_Y = -2.0f;
							}
						}
						else if (j == EnemyType02_01 || j == EnemyType02_02)
						{
							if (enemyBalloonIsBroken[1] != true && enemyIsDead[1] != true)
							{
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, (g_pPlatFormL[i]->getPos().y - 16.0f - 48.0f));
								ENEMY_SPEED_Y2 = -2.0f;
							}
						}
						else if (j == EnemyType03_01 || j == EnemyType03_02)
						{
							if (enemyBalloonIsBroken[2] != true && enemyIsDead[2] != true)
							{
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, (g_pPlatFormL[i]->getPos().y - 16.0f - 48.0f));
								ENEMY_SPEED_Y3 = -2.0f;
							}
						}
					}

				}
			}


		}
	}

	//g_pPlatFormSに当たっているとき、以下の処理を行い座標を更新する
	for (int i = 0; i < PlatFormQuantityS; ++i)
	{
		for (int j = 0; j < EnemyQuantity; ++j)
		{
			if (g_pEnemy[j] != NULL)
			{
				if (g_pEnemy[j]->collision(g_pPlatFormS[i]) != false)
				{
					//横から当たるとき
					//右から
					if (g_pEnemy[j]->getPos().x > g_pPlatFormS[i]->getPos().x && g_pEnemy[j]->getPos().y < g_pPlatFormS[i]->getPos().y + (64.0f + GravLimi) && g_pEnemy[j]->getPos().y > g_pPlatFormS[i]->getPos().y - (64.0f + GravLimi))
					{
						if (j == EnemyType01_01 || j == EnemyType01_02)
						{
							if (enemyBalloonIsBroken[0] != true && enemyIsDead[0] != true)
							{
								ENEMY_SPEED_X = 2.0f;
								g_pEnemy[j]->setPos(256.0f, g_pEnemy[j]->getPos().y);
							}
						}
						else if (j == EnemyType02_01 || j == EnemyType02_02)
						{
							if (enemyBalloonIsBroken[1] != true && enemyIsDead[1] != true)
							{
								ENEMY_SPEED_X2 = 2.0f;
								g_pEnemy[j]->setPos(256.0f, g_pEnemy[j]->getPos().y);
							}
						}
						else if (j == EnemyType03_01 || j == EnemyType03_02)
						{
							if (enemyBalloonIsBroken[2] != true && enemyIsDead[2] != true)
							{
								ENEMY_SPEED_X3 = 2.0f;
								g_pEnemy[j]->setPos(256.0f, g_pEnemy[j]->getPos().y);
							}
						}

					}
					//左から
					else if (g_pEnemy[j]->getPos().x < g_pPlatFormS[i]->getPos().x && g_pEnemy[j]->getPos().y <  g_pPlatFormS[i]->getPos().y + (64.0f + GravLimi) && g_pEnemy[j]->getPos().y > g_pPlatFormS[i]->getPos().y - (64.0f + GravLimi))
					{
						if (j == EnemyType01_01 || j == EnemyType01_02)
						{
							if (enemyBalloonIsBroken[0] != true && enemyIsDead[0] != true)
							{
								ENEMY_SPEED_X = -2.0f;
								g_pEnemy[j]->setPos(-256.0f, g_pEnemy[j]->getPos().y);
							}
						}
						else if (j == EnemyType02_01 || j == EnemyType02_02)
						{
							if (enemyBalloonIsBroken[1] != true && enemyIsDead[1] != true)
							{
								ENEMY_SPEED_X2 = -2.0f;
								g_pEnemy[j]->setPos(-256.0f, g_pEnemy[j]->getPos().y);
							}
						}
						else if (j == EnemyType03_01 || j == EnemyType03_02)
						{
							if (enemyBalloonIsBroken[2] != true && enemyIsDead[2] != true)
							{
								ENEMY_SPEED_X3 = -2.0f;
								g_pEnemy[j]->setPos(-256.0f, g_pEnemy[j]->getPos().y);
							}
						}
					}

					//上から当たるとき
					else if (g_pEnemy[j]->getPos().y > g_pPlatFormS[i]->getPos().y)
					{

						//上から当たってるとき値を0にする
						if (j == EnemyType01_01 || j == EnemyType01_02)
						{
							if (enemyBalloonIsBroken[0] != true && enemyIsDead[0] != true)
							{
								//プレイヤーの座標を床に接する位置まで調整する
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pPlatFormS[i]->getPos().y + 64.0f);
								ENEMY_SPEED_Y = 2.0f;
							}
						}
						else if (j == EnemyType02_01 || j == EnemyType02_02)
						{
							if (enemyBalloonIsBroken[1] != true && enemyIsDead[1] != true)
							{
								//プレイヤーの座標を床に接する位置まで調整する
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pPlatFormS[i]->getPos().y + 64.0f);
								ENEMY_SPEED_Y2 = 2.0f;
							}
						}
						else if (j == EnemyType03_01 || j == EnemyType03_02)
						{
							if (enemyBalloonIsBroken[2] != true && enemyIsDead[2] != true)
							{
								//プレイヤーの座標を床に接する位置まで調整する
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pPlatFormS[i]->getPos().y + 64.0f);
								ENEMY_SPEED_Y3 = 2.0f;
							}
						}


					}
					else if (g_pEnemy[j]->getPos().y < g_pPlatFormS[i]->getPos().y)
					{
						g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, (g_pPlatFormS[i]->getPos().y - 16.0f - 48.0f));
						if (j == EnemyType01_01 || j == EnemyType01_02)
						{
							ENEMY_SPEED_Y = -2.0f;
						}
						else if (j == EnemyType02_01 || j == EnemyType02_02)
						{
							ENEMY_SPEED_Y2 = -2.0f;
						}
						else if (j == EnemyType03_01 || j == EnemyType03_02)
						{
							ENEMY_SPEED_Y3 = -2.0f;
						}
					}

				}
			}
		}
	}

	//g_pGroundに当たっている時、以下の処理を行い座標を更新する
	for (int i = 0; i < GroundQuantity; ++i)
	{
		if (g_pGround[i] != NULL)
		{
			for (int j = 0; j < EnemyQuantity; ++j)
			{
				if (j == EnemyType01_01 || j == EnemyType01_02)
				{
					if (enemyBalloonIsBroken[0] != true && enemyIsDead[0] != true)
					{
						//横から当たるとき
						if (g_pEnemy[j]->collision(g_pGround[3]) != false && ENEMY_SPEED_X > 0 && g_pEnemy[j]->getPos().y < -292.0f - 6.0f)
						{
							ENEMY_SPEED_X = -2.0f;
							g_pEnemy[j]->setPos(224.0f, g_pEnemy[j]->getPos().y);
						}
						else if (g_pEnemy[j]->collision(g_pGround[7]) != false && ENEMY_SPEED_X < 0 && g_pEnemy[j]->getPos().y < -292.0f - 6.0f)
						{
							ENEMY_SPEED_X = 2.0f;
							g_pEnemy[j]->setPos(-224.0f, g_pEnemy[j]->getPos().y);
						}
						//上から当たるとき
						else if (g_pEnemy[j]->collision(g_pGround[i]) != false)
						{
							if (g_pEnemy[j]->getPos().y > g_pGround[i]->getPos().y)
							{
								//プレイヤーの座標を床に接する位置まで調整する
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
								//上から当たってるとき値を0にする
								ENEMY_SPEED_Y = 2.0f;
							}
						}
					}
				}
				else if (j == EnemyType02_01 || j == EnemyType02_02)
				{
					if (enemyBalloonIsBroken[1] != true && enemyIsDead[1] != true)
					{
						//横から当たるとき
						if (g_pEnemy[j]->collision(g_pGround[3]) != false && ENEMY_SPEED_X2 > 0 && g_pEnemy[j]->getPos().y < -292.0f - 6.0f)
						{
							ENEMY_SPEED_X2 = -2.0f;
							g_pEnemy[j]->setPos(224.0f, g_pEnemy[j]->getPos().y);
						}
						else if (g_pEnemy[j]->collision(g_pGround[7]) != false && ENEMY_SPEED_X2 < 0 && g_pEnemy[j]->getPos().y < -292.0f - 6.0f)
						{
							ENEMY_SPEED_X2 = 2.0f;
							g_pEnemy[j]->setPos(-224.0f, g_pEnemy[j]->getPos().y);
						}
						//上から当たるとき
						else if (g_pEnemy[j]->collision(g_pGround[i]) != false)
						{
							if (g_pEnemy[j]->getPos().y > g_pGround[i]->getPos().y)
							{
								//プレイヤーの座標を床に接する位置まで調整する
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
								//上から当たってるとき値を0にする
								ENEMY_SPEED_Y2 = 2.0f;
							}
						}
					}
				}
				else if (j == EnemyType03_01 || j == EnemyType03_02)
				{
					if (enemyBalloonIsBroken[2] != true && enemyIsDead[2] != true)
					{
						//横から当たるとき
						if (g_pEnemy[j]->collision(g_pGround[3]) != false && ENEMY_SPEED_X3 > 0 && g_pEnemy[j]->getPos().y < -292.0f - 6.0f)
						{
							ENEMY_SPEED_X3 = -2.0f;
							g_pEnemy[j]->setPos(224.0f, g_pEnemy[j]->getPos().y);
						}
						else if (g_pEnemy[j]->collision(g_pGround[7]) != false && ENEMY_SPEED_X3 < 0 && g_pEnemy[j]->getPos().y < -292.0f - 6.0f)
						{
							ENEMY_SPEED_X3 = 2.0f;
							g_pEnemy[j]->setPos(-224.0f, g_pEnemy[j]->getPos().y);
						}
						//上から当たるとき
						else if (g_pEnemy[j]->collision(g_pGround[i]) != false)
						{
							if (g_pEnemy[j]->getPos().y > g_pGround[i]->getPos().y)
							{
								//プレイヤーの座標を床に接する位置まで調整する
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
								//上から当たってるとき値を0にする
								ENEMY_SPEED_Y3 = 2.0f;
							}
						}
					}
				}
			}
		}
	}
	//敵と他の敵の当たり判定
	//g_pEnemy[0]とg_pEnemy[2]
	if (enemyIsDead[0] != true && enemyIsDead[1] != true && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
	{
		if (g_pEnemy[0]->collision(g_pEnemy[2]) != false)
		{
			//上下の当たり判定
			if (g_pEnemy[0]->getPos().x <= g_pEnemy[2]->getPos().x + 64.0f && g_pEnemy[0]->getPos().x >= g_pEnemy[2]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[0]->getPos().y > g_pEnemy[2]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y2 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().y < g_pEnemy[2]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y2 = 2.0f;
				}
			}
			//左右の当たり判定
			else if (g_pEnemy[0]->getPos().y <= g_pEnemy[2]->getPos().y + 96.0f && g_pEnemy[0]->getPos().y >= g_pEnemy[2]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[0]->getPos().x > g_pEnemy[2]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X2 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().x < g_pEnemy[2]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X2 = 2.0f;
				}

			}
		}
		else if (g_pEnemy[1]->collision(g_pEnemy[2]) != false)
		{
			//上下の当たり判定
			if (g_pEnemy[1]->getPos().x <= g_pEnemy[2]->getPos().x + 64.0f && g_pEnemy[1]->getPos().x >= g_pEnemy[2]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[1]->getPos().y > g_pEnemy[2]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y2 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().y < g_pEnemy[2]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y2 = 2.0f;
				}
			}
			//左右の当たり判定
			else if (g_pEnemy[1]->getPos().y <= g_pEnemy[2]->getPos().y + 96.0f && g_pEnemy[1]->getPos().y >= g_pEnemy[2]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[1]->getPos().x > g_pEnemy[2]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X2 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().x < g_pEnemy[2]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X2 = 2.0f;
				}

			}
		}
		else if (g_pEnemy[0]->collision(g_pEnemy[3]) != false)
		{
			//上下の当たり判定
			if (g_pEnemy[0]->getPos().x <= g_pEnemy[3]->getPos().x + 64.0f && g_pEnemy[0]->getPos().x >= g_pEnemy[3]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[0]->getPos().y > g_pEnemy[3]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y2 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().y < g_pEnemy[3]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y2 = 2.0f;
				}
			}
			//左右の当たり判定
			else if (g_pEnemy[0]->getPos().y <= g_pEnemy[3]->getPos().y + 96.0f && g_pEnemy[0]->getPos().y >= g_pEnemy[3]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[0]->getPos().x > g_pEnemy[3]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X2 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().x < g_pEnemy[3]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X2 = 2.0f;
				}

			}
		}
		else if (g_pEnemy[1]->collision(g_pEnemy[3]) != false)
		{
			//上下の当たり判定
			if (g_pEnemy[1]->getPos().x <= g_pEnemy[3]->getPos().x + 64.0f && g_pEnemy[1]->getPos().x >= g_pEnemy[3]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[1]->getPos().y > g_pEnemy[3]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y2 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().y < g_pEnemy[3]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y2 = 2.0f;
				}
			}
			//左右の当たり判定
			else if (g_pEnemy[1]->getPos().y <= g_pEnemy[3]->getPos().y + 96.0f && g_pEnemy[1]->getPos().y >= g_pEnemy[3]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[1]->getPos().x > g_pEnemy[3]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X2 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().x < g_pEnemy[3]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X2 = 2.0f;
				}

			}
		}
	}
	//g_pEnemy[0]とg_pEnemy[4]
	if (enemyIsDead[0] != true && enemyIsDead[2] != true && g_pEnemy[0] != NULL && g_pEnemy[4] != NULL)
	{
		if (g_pEnemy[0]->collision(g_pEnemy[4]) != false)
		{
			//上下の当たり判定
			if (g_pEnemy[0]->getPos().x <= g_pEnemy[4]->getPos().x + 64.0f && g_pEnemy[0]->getPos().x >= g_pEnemy[4]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[0]->getPos().y > g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().y < g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//左右の当たり判定
			else if (g_pEnemy[0]->getPos().y <= g_pEnemy[4]->getPos().y + 96.0f && g_pEnemy[0]->getPos().y >= g_pEnemy[4]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[0]->getPos().x > g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().x < g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
		else if (g_pEnemy[1]->collision(g_pEnemy[4]) != false)
		{
			//上下の当たり判定
			if (g_pEnemy[1]->getPos().x <= g_pEnemy[4]->getPos().x + 64.0f && g_pEnemy[1]->getPos().x >= g_pEnemy[4]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[1]->getPos().y > g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().y < g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//左右の当たり判定
			else if (g_pEnemy[1]->getPos().y <= g_pEnemy[4]->getPos().y + 96.0f && g_pEnemy[1]->getPos().y >= g_pEnemy[4]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[1]->getPos().x > g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().x < g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
		else if (g_pEnemy[0]->collision(g_pEnemy[5]) != false)
		{
			//上下の当たり判定
			if (g_pEnemy[0]->getPos().x <= g_pEnemy[5]->getPos().x + 64.0f && g_pEnemy[0]->getPos().x >= g_pEnemy[5]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[0]->getPos().y > g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().y < g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//左右の当たり判定
			else if (g_pEnemy[0]->getPos().y <= g_pEnemy[5]->getPos().y + 96.0f && g_pEnemy[0]->getPos().y >= g_pEnemy[5]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[0]->getPos().x > g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().x < g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
		else if (g_pEnemy[1]->collision(g_pEnemy[5]) != false)
		{
			//上下の当たり判定
			if (g_pEnemy[1]->getPos().x <= g_pEnemy[5]->getPos().x + 64.0f && g_pEnemy[1]->getPos().x >= g_pEnemy[5]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[1]->getPos().y > g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().y < g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//左右の当たり判定
			else if (g_pEnemy[1]->getPos().y <= g_pEnemy[5]->getPos().y + 96.0f && g_pEnemy[1]->getPos().y >= g_pEnemy[5]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[1]->getPos().x > g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().x < g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
	}
	//g_pEnemy[2]とg_pEnemy[4]
	if (enemyIsDead[1] != true && enemyIsDead[2] != true && g_pEnemy[2] != NULL && g_pEnemy[4] != NULL)
	{
		if (g_pEnemy[2]->collision(g_pEnemy[4]) != false)
		{
			//上下の当たり判定
			if (g_pEnemy[2]->getPos().x <= g_pEnemy[4]->getPos().x + 64.0f && g_pEnemy[2]->getPos().x >= g_pEnemy[4]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[2]->getPos().y > g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y2 = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[2]->getPos().y < g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y2 = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//左右の当たり判定
			else if (g_pEnemy[2]->getPos().y <= g_pEnemy[4]->getPos().y + 96.0f && g_pEnemy[2]->getPos().y >= g_pEnemy[4]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[2]->getPos().x > g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X2 = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[2]->getPos().x < g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X2 = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
		else if (g_pEnemy[3]->collision(g_pEnemy[4]) != false)
		{
			//上下の当たり判定
			if (g_pEnemy[3]->getPos().x <= g_pEnemy[4]->getPos().x + 64.0f && g_pEnemy[3]->getPos().x >= g_pEnemy[4]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[3]->getPos().y > g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y2 = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[3]->getPos().y < g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y2 = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//左右の当たり判定
			else if (g_pEnemy[3]->getPos().y <= g_pEnemy[4]->getPos().y + 96.0f && g_pEnemy[3]->getPos().y >= g_pEnemy[4]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[3]->getPos().x > g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X2 = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[3]->getPos().x < g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X2 = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
		else if (g_pEnemy[2]->collision(g_pEnemy[5]) != false)
		{
			//上下の当たり判定
			if (g_pEnemy[2]->getPos().x <= g_pEnemy[5]->getPos().x + 64.0f && g_pEnemy[2]->getPos().x >= g_pEnemy[5]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[2]->getPos().y > g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y2 = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[2]->getPos().y < g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y2 = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//左右の当たり判定
			else if (g_pEnemy[2]->getPos().y <= g_pEnemy[5]->getPos().y + 96.0f && g_pEnemy[2]->getPos().y >= g_pEnemy[5]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[2]->getPos().x > g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X2 = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[2]->getPos().x < g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X2 = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
		else if (g_pEnemy[3]->collision(g_pEnemy[5]) != false)
		{
			//上下の当たり判定
			if (g_pEnemy[3]->getPos().x <= g_pEnemy[5]->getPos().x + 64.0f && g_pEnemy[3]->getPos().x >= g_pEnemy[5]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[3]->getPos().y > g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y2 = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[3]->getPos().y < g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y2 = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//左右の当たり判定
			else if (g_pEnemy[3]->getPos().y <= g_pEnemy[5]->getPos().y + 96.0f && g_pEnemy[3]->getPos().y >= g_pEnemy[5]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[3]->getPos().x > g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X2 = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[3]->getPos().x < g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X2 = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
	}
}