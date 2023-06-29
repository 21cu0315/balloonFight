//----------------------------------------------------------
// ファイル名		：EnemyBalloonBreak
// 概要				：敵のバルーンが破壊された時の処理
// // 作成者			：21CU0315 黄卓賢
// 更新内容			：2022/03/23 21CU0315 黄卓賢 作成
//					：2022/03/25 21CU0118 小池慎之介 落下時のスピードの変更
//----------------------------------------------------------
#include "CActionGameApp.h"

int enemyFallingCounter[3] = { 0,0,0 };

void CActionGameApp::EnemyBalloonBreak()
{
	//Enemy1のバルーンが割れた時
	if (enemyBalloonIsBroken[0] == true && enemyIsDead[0] != true)
	{
		//Enemy1の落下カウンターを回す
		enemyFallingCounter[0]++;
		for (int i = 0; i < GroundQuantity; ++i)
		{
			if (g_pGround[i] != NULL && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL)
			{
				//Enemy1が地面に当たったとき
				if (g_pEnemy[0]->collision(g_pGround[i]) == true || g_pEnemy[1]->collision(g_pGround[i]) == true)
				{
					//敵がバルーンを作っていない時だけ発動する
					if (enemyPumpBalloon[0] != true)
					{
						g_pEnemy[0]->setAnimation(2);
						g_pEnemy[1]->setAnimation(2);
					}
					//落下していない
					enemyDeadFalling[0] = false;
					//敵が地面と接している
					enemyOnGround[0] = true;
					ENEMY_SPEED_X = 0.0f;
					//プレイヤーの座標を床に接する位置まで調整する
					g_pEnemy[0]->setPos(g_pEnemy[0]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					g_pEnemy[1]->setPos(g_pEnemy[1]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					//地面に当たった後バルーンを作り直すまでの時間を計算する
					if (enemyPumpBalloonCDCounter[0] < 300)
					{
						enemyPumpBalloonCDCounter[0]++;
					}
					else if (enemyPumpBalloonCDCounter[0] == 300)
					{
						//敵がバルーンを作り始める
						enemyPumpBalloon[0] = true;
					}
				}
				//当たっていない時
				else
				{
					ENEMY_SPEED_Y = -0.5f;
					//落下のアニメーションを発動する
					enemyDeadFalling[0] = true;
				}
			}
			for (int j = 0; j < PlatFormQuantityL; ++j)
			{
				if (g_pPlatFormL[j] != NULL && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL)
				{
					//Enemy1が足場Lに当たったとき
					if (g_pEnemy[0]->collision(g_pPlatFormL[j]) == true || g_pEnemy[1]->collision(g_pPlatFormL[j]) == true)
					{
						//敵がバルーンを作っていない時だけ発動する
						if (enemyPumpBalloon[0] != true)
						{
							g_pEnemy[0]->setAnimation(2);
							g_pEnemy[1]->setAnimation(2);
						}
						//落下していない
						enemyDeadFalling[0] = false;
						//敵が地面と接している
						enemyOnGround[0] = true;
						ENEMY_SPEED_X = 0.0f;
						//プレイヤーの座標を床に接する位置まで調整する
						g_pEnemy[0]->setPos(g_pEnemy[0]->getPos().x, g_pPlatFormL[j]->getPos().y + 64.0f);
						g_pEnemy[1]->setPos(g_pEnemy[1]->getPos().x, g_pPlatFormL[j]->getPos().y + 64.0f);
						//地面に当たった後バルーンを作り直すまでの時間を計算する
						if (enemyPumpBalloonCDCounter[0] < 300)
						{
							enemyPumpBalloonCDCounter[0]++;
						}
						else if (enemyPumpBalloonCDCounter[0] == 300)
						{
							//敵がバルーンを作り始める
							enemyPumpBalloon[0] = true;
						}
					}
					//当たっていない時
					else
					{
						ENEMY_SPEED_Y = -0.5f;
						//落下のアニメーションを発動する
						enemyDeadFalling[0] = true;
					}
				}
			}

			for (int k = 0; k < PlatFormQuantityS; ++k)
			{
				if (g_pPlatFormS[k] != NULL && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL)
				{
					//Enemy1が足場Sに当たったとき
					if (g_pEnemy[0]->collision(g_pPlatFormS[k]) == true || g_pEnemy[1]->collision(g_pPlatFormS[k]) == true)
					{
						if (enemyPumpBalloon[0] != true)
						{
							g_pEnemy[0]->setAnimation(2);
							g_pEnemy[1]->setAnimation(2);
						}
						//落下していない
						enemyDeadFalling[0] = false;
						//敵が地面と接している
						enemyOnGround[0] = true;
						ENEMY_SPEED_X = 0.0f;
						//プレイヤーの座標を床に接する位置まで調整する
						g_pEnemy[0]->setPos(g_pEnemy[0]->getPos().x, g_pPlatFormS[k]->getPos().y + 64.0f);
						g_pEnemy[1]->setPos(g_pEnemy[1]->getPos().x, g_pPlatFormS[k]->getPos().y + 64.0f);
						//地面に当たった後バルーンを作り直すまでの時間を計算する
						if (enemyPumpBalloonCDCounter[0] < 300)
						{
							enemyPumpBalloonCDCounter[0]++;
						}
						if (enemyPumpBalloonCDCounter[0] == 300)
						{
							//敵がバルーンを作り始める
							enemyPumpBalloon[0] = true;
						}
					}
					//当たっていない時
					else
					{
						ENEMY_SPEED_Y = -0.5f;
						//落下のアニメーションを発動する
						enemyDeadFalling[0] = true;
					}
				}
			}
		}
		//落下している時、アニメーションの処理
		if (enemyDeadFalling[0] == true)
		{
			if (enemyFallingCounter[0] <= 10)
			{
				//アニメーションの範囲を設定
				g_pEnemy[0]->setAnimationRange(10, 12);
				g_pEnemy[1]->setAnimationRange(10, 12);
				//５フレームずつアニメーションを動く
				if (enemyFallingCounter[0] % 5 == 0)
				{
					g_pEnemy[0]->stepAnimation();
					g_pEnemy[1]->stepAnimation();
				}
			}
		}
		//敵がバルーンを作り始めたら
		if (enemyPumpBalloon[0] == true)
		{
			//敵がバルーンを作るアニメーションのカウンターを回す
			enemyPumpBalloonCounter[0]++;
			//アニメーションの範囲を設定
			g_pEnemy[0]->setAnimationRange(3, 9);
			g_pEnemy[1]->setAnimationRange(3, 9);
			//30フレームずつ、アニメーションを動く
			if (enemyPumpBalloonCounter[0] % 10 == 0)
			{
				g_pEnemy[0]->stepAnimation();
				g_pEnemy[1]->stepAnimation();
			}
			//アニメーションを一回だけ動くように設定する
			else if (enemyPumpBalloonCounter[0] > 70)
			{
				//敵の変数をリセットする
				enemyPumpBalloon[0] = false;
				enemyBalloonIsBroken[0] = false;
				g_pEnemy[0]->setAnimation(0);
				g_pEnemy[1]->setAnimation(0);
				enemyPumpBalloonCDCounter[0] = 0;
				enemyFallingCounter[0] = 0;
				enemyPumpBalloonCounter[0] = 0;
				enemyOnGround[0] = false;
			}
		}
	}
	//Enemy2のバルーンが割れた時
	if (enemyBalloonIsBroken[1] == true && enemyIsDead[1] != true)
	{
		//Enemy2の落下カウンター
		enemyFallingCounter[1]++;
		for (int i = 0; i < GroundQuantity; ++i)
		{
			if (g_pGround[i] != NULL && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
			{
				//Enemy2が地面と当たったとき
				if (g_pEnemy[2]->collision(g_pGround[i]) == true || g_pEnemy[3]->collision(g_pGround[i]) == true)
				{
					//敵がバルーンを作っていない時だけ発動する
					if (enemyPumpBalloon[1] != true)
					{
						g_pEnemy[2]->setAnimation(2);
						g_pEnemy[3]->setAnimation(2);
					}
					//落下していない
					enemyDeadFalling[1] = false;
					//敵が地面と接している
					enemyOnGround[1] = true;
					ENEMY_SPEED_X2 = 0.0f;
					//プレイヤーの座標を床に接する位置まで調整する
					g_pEnemy[2]->setPos(g_pEnemy[2]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					g_pEnemy[3]->setPos(g_pEnemy[3]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					//地面に当たった後バルーンを作り直すまでの時間を計算する
					if (enemyPumpBalloonCDCounter[1] < 300)
					{
						enemyPumpBalloonCDCounter[1]++;
					}
					else if (enemyPumpBalloonCDCounter[1] == 300)
					{
						//敵がバルーンを作り始める
						enemyPumpBalloon[1] = true;
					}
				}
				//当たっていない時
				else
				{
					ENEMY_SPEED_Y2 = -0.5f;
					//落下アニメーションを発動
					enemyDeadFalling[1] = true;
				}
			}
		}
		for (int j = 0; j < PlatFormQuantityL; ++j)
		{
			if (g_pPlatFormL[j] != NULL && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
			{
				//Enemy2が足場Lと当たったとき
				if (g_pEnemy[2]->collision(g_pPlatFormL[j]) == true || g_pEnemy[3]->collision(g_pPlatFormL[j]) == true)
				{
					//敵がバルーンを作っていない時だけ発動する
					if (enemyPumpBalloon[1] != true)
					{
						g_pEnemy[2]->setAnimation(2);
						g_pEnemy[3]->setAnimation(2);
					}
					//落下していない
					enemyDeadFalling[1] = false;
					//敵が地面と接している
					enemyOnGround[1] = true;
					ENEMY_SPEED_X2 = 0.0f;
					//プレイヤーの座標を床に接する位置まで調整する
					g_pEnemy[2]->setPos(g_pEnemy[2]->getPos().x, g_pPlatFormL[j]->getPos().y + 64.0f);
					g_pEnemy[3]->setPos(g_pEnemy[3]->getPos().x, g_pPlatFormL[j]->getPos().y + 64.0f);
					//地面に当たった後バルーンを作り直すまでの時間を計算する
					if (enemyPumpBalloonCDCounter[1] < 300)
					{
						enemyPumpBalloonCDCounter[1]++;
					}
					else if (enemyPumpBalloonCDCounter[1] == 300)
					{
						//敵がバルーンを作り始める
						enemyPumpBalloon[1] = true;
					}
				}
				else
				{
					ENEMY_SPEED_Y2 = -0.5f;
					//落下のアニメーションを発動する
					enemyDeadFalling[1] = true;
				}
			}
		}
		for (int k = 0; k < PlatFormQuantityS; ++k)
		{
			if (g_pPlatFormS[k] != NULL && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
			{
				//Enemy2が足場Sと当たったとき
				if (g_pEnemy[2]->collision(g_pPlatFormS[k]) == true || g_pEnemy[3]->collision(g_pPlatFormS[k]) == true)
				{
					//敵がバルーンを作っていない時だけ発動する
					if (enemyPumpBalloon[1] != true)
					{
						g_pEnemy[2]->setAnimation(2);
						g_pEnemy[3]->setAnimation(2);
					}
					//落下していない
					enemyDeadFalling[1] = false;
					//敵が地面と接している
					enemyOnGround[1] = true;
					ENEMY_SPEED_X2 = 0.0f;
					//プレイヤーの座標を床に接する位置まで調整する
					g_pEnemy[2]->setPos(g_pEnemy[2]->getPos().x, g_pPlatFormS[k]->getPos().y + 64.0f);
					g_pEnemy[3]->setPos(g_pEnemy[3]->getPos().x, g_pPlatFormS[k]->getPos().y + 64.0f);
					//地面に当たった後バルーンを作り直すまでの時間を計算する
					if (enemyPumpBalloonCDCounter[1] < 300)
					{
						enemyPumpBalloonCDCounter[1]++;
					}
					else if (enemyPumpBalloonCDCounter[1] == 300)
					{
						//敵がバルーンを作り始める
						enemyPumpBalloon[1] = true;
					}
				}
				else
				{
					ENEMY_SPEED_Y2 = -0.5f;
					//落下のアニメーションを発動する
					enemyDeadFalling[1] = true;
				}
			}
		}
		//落下している時、アニメーションの処理
		if (enemyDeadFalling[1] == true)
		{
			if (enemyFallingCounter[1] <= 10)
			{
				g_pEnemy[2]->setAnimationRange(10, 12);
				g_pEnemy[3]->setAnimationRange(10, 12);
				if (enemyFallingCounter[1] % 5 == 0)
				{
					g_pEnemy[2]->stepAnimation();
					g_pEnemy[3]->stepAnimation();
				}
			}
		}
		//敵がバルーンを作り始めたら
		if (enemyPumpBalloon[1] == true)
		{
			//敵がバルーンを作るアニメーションのカウンターを回す
			enemyPumpBalloonCounter[1]++;
			//アニメーションの範囲を設定
			g_pEnemy[2]->setAnimationRange(3, 9);
			g_pEnemy[3]->setAnimationRange(3, 9);
			//30フレームずつ、アニメーションを動く
			if (enemyPumpBalloonCounter[1] % 10 == 0)
			{
				g_pEnemy[2]->stepAnimation();
				g_pEnemy[3]->stepAnimation();
			}
			//アニメーションを一回だけ動くように設定する
			else if (enemyPumpBalloonCounter[1] > 70)
			{
				//敵の変数をリセットする
				enemyPumpBalloon[1] = false;
				enemyBalloonIsBroken[1] = false;
				g_pEnemy[2]->setAnimation(0);
				g_pEnemy[3]->setAnimation(0);
				enemyPumpBalloonCDCounter[1] = 0;
				enemyFallingCounter[1] = 0;
				enemyPumpBalloonCounter[1] = 0;
				enemyOnGround[1] = false;
			}
		}
	}
	//Enemy3のバルーンが割れた時
	if (enemyBalloonIsBroken[2] == true && enemyIsDead[2] != true)
	{
		//Enemy3の落下カウンターを回す
		enemyFallingCounter[2]++;
		for (int i = 0; i < GroundQuantity; ++i)
		{
			if (g_pGround[i] != NULL && g_pEnemy[4] != NULL && g_pEnemy[5] != NULL)
			{
				//Enemy3が地面と当たったとき
				if (g_pEnemy[4]->collision(g_pGround[i]) == true || g_pEnemy[5]->collision(g_pGround[i]) == true)
				{
					//敵がバルーンを作っていない時だけ発動する
					if (enemyPumpBalloon[2] != true)
					{
						g_pEnemy[4]->setAnimation(2);
						g_pEnemy[5]->setAnimation(2);
					}
					//落下していない
					enemyDeadFalling[2] = false;
					//敵が地面と接している
					enemyOnGround[2] = true;
					ENEMY_SPEED_X3 = 0.0f;
					//プレイヤーの座標を床に接する位置まで調整する
					g_pEnemy[4]->setPos(g_pEnemy[4]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					g_pEnemy[5]->setPos(g_pEnemy[5]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					//地面に当たった後バルーンを作り直すまでの時間を計算する
					if (enemyPumpBalloonCDCounter[2] < 300)
					{
						enemyPumpBalloonCDCounter[2]++;
					}
					else if (enemyPumpBalloonCDCounter[2] == 300)
					{
						//敵がバルーンを作り始める
						enemyPumpBalloon[2] = true;
					}
				}
				else
				{
					ENEMY_SPEED_Y3 = -0.5f;
					//落下のアニメーションを発動する
					enemyDeadFalling[2] = true;
				}
			}
		}
		for (int j = 0; j < PlatFormQuantityL; ++j)
		{
			if (g_pPlatFormL[j] != NULL && g_pEnemy[4] != NULL && g_pEnemy[5] != NULL)
			{
				//Enemy3が足場Lと当たったとき
				if (g_pEnemy[4]->collision(g_pPlatFormL[j]) == true || g_pEnemy[5]->collision(g_pPlatFormL[j]) == true)
				{
					//敵がバルーンを作っていない時だけ発動する
					if (enemyPumpBalloon[2] != true)
					{
						g_pEnemy[4]->setAnimation(2);
						g_pEnemy[5]->setAnimation(2);
					}
					//落下していない
					enemyDeadFalling[2] = false;
					//敵が地面と接している
					enemyOnGround[2] = true;
					ENEMY_SPEED_X3 = 0.0f;
					//プレイヤーの座標を床に接する位置まで調整する
					g_pEnemy[4]->setPos(g_pEnemy[4]->getPos().x, g_pPlatFormL[j]->getPos().y + 64.0f);
					g_pEnemy[5]->setPos(g_pEnemy[5]->getPos().x, g_pPlatFormL[j]->getPos().y + 64.0f);
					//地面に当たった後バルーンを作り直すまでの時間を計算する
					if (enemyPumpBalloonCDCounter[2] < 300)
					{
						enemyPumpBalloonCDCounter[2]++;
					}
					else if (enemyPumpBalloonCDCounter[2] == 300)
					{
						//敵がバルーンを作り始める
						enemyPumpBalloon[2] = true;
					}
				}
				else
				{
					ENEMY_SPEED_Y3 = -0.5f;
					//落下のアニメーションを発動する
					enemyDeadFalling[2] = true;
				}
			}
		}
		for (int k = 0; k < PlatFormQuantityS; ++k)
		{
			if (g_pPlatFormS[k] != NULL && g_pEnemy[4] != NULL && g_pEnemy[5] != NULL)
			{
				//Enemy3が足場Sと当たったとき
				if (g_pEnemy[4]->collision(g_pPlatFormS[k]) == true || g_pEnemy[5]->collision(g_pPlatFormS[k]) == true)
				{
					//敵がバルーンを作っていない時だけ発動する
					if (enemyPumpBalloon[2] != true)
					{
						g_pEnemy[4]->setAnimation(2);
						g_pEnemy[5]->setAnimation(2);
					}
					//落下していない
					enemyDeadFalling[2] = false;
					//敵が地面と接している
					enemyOnGround[2] = true;
					ENEMY_SPEED_X3 = 0.0f;
					//プレイヤーの座標を床に接する位置まで調整する
					g_pEnemy[4]->setPos(g_pEnemy[4]->getPos().x, g_pPlatFormS[k]->getPos().y + 64.0f);
					g_pEnemy[5]->setPos(g_pEnemy[5]->getPos().x, g_pPlatFormS[k]->getPos().y + 64.0f);
					//地面に当たった後バルーンを作り直すまでの時間を計算する
					if (enemyPumpBalloonCDCounter[2] < 300)
					{
						enemyPumpBalloonCDCounter[2]++;
					}
					else if (enemyPumpBalloonCDCounter[2] == 300)
					{
						//敵がバルーンを作り始める
						enemyPumpBalloon[2] = true;
					}
				}
				else
				{
					ENEMY_SPEED_Y3 = -0.5f;
					//落下のアニメーションを発動する
					enemyDeadFalling[2] = true;
				}
			}
		}
		//落下している時、アニメーションの処理
		if (enemyDeadFalling[2] == true)
		{
			if (enemyFallingCounter[2] <= 10)
			{
				g_pEnemy[4]->setAnimationRange(10, 12);
				g_pEnemy[5]->setAnimationRange(10, 12);
				if (enemyFallingCounter[2] % 5 == 0)
				{
					g_pEnemy[4]->stepAnimation();
					g_pEnemy[5]->stepAnimation();
				}
			}
		}
		//敵がバルーンを作り始めたら
		if (enemyPumpBalloon[2] == true)
		{
			//敵がバルーンを作るアニメーションのカウンターを回す
			enemyPumpBalloonCounter[2]++;
			//アニメーションの範囲を設定
			g_pEnemy[4]->setAnimationRange(3, 9);
			g_pEnemy[5]->setAnimationRange(3, 9);
			//30フレームずつ、アニメーションを動く
			if (enemyPumpBalloonCounter[2] % 10 == 0)
			{
				g_pEnemy[4]->stepAnimation();
				g_pEnemy[5]->stepAnimation();
			}
			//アニメーションを一回だけ動くように設定する
			else if (enemyPumpBalloonCounter[2] > 70)
			{
				//敵の変数をリセットする
				enemyPumpBalloon[2] = false;
				enemyBalloonIsBroken[2] = false;
				g_pEnemy[4]->setAnimation(0);
				g_pEnemy[5]->setAnimation(0);
				enemyPumpBalloonCDCounter[2] = 0;
				enemyFallingCounter[2] = 0;
				enemyPumpBalloonCounter[2] = 0;
				enemyOnGround[2] = false;
			}
		}
	}
}