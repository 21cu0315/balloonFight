//----------------------------------------------------------
// ファイル名		：PECollusionDetection.cpp
// 概要				：プレイヤーと敵キャラの当たり判定
// 作成者			：21CU0315 黄卓賢
// 更新内容			：2022/03/07 21CU0315 黄卓賢 作成
//					：2022/03/08 21CU0315 黄卓賢 プレイヤーと敵の位置によって、当たり判定を修正
//					：2022/03/15 21CU0315 黄卓賢 プレイヤーと敵の当たり判定を修正
//					：2022/03/15 21CU0118 小池慎之介 敵の処理判定を追加
//					：2022/03/15 21CU0118 小池慎之介 敵の処理判定の修正
//					：2022/03/25 21CU0118 小池慎之介 敵とプレイヤーの当たり判定に処理、敵のスピードの0、if文の追加
//					：2022/03/30 21CU0118 小池慎之介 敵が動いていない時の処理の追加
//					：2022/04/05 21CU0315 黄卓賢 プレイヤーと敵の当たり判定の範囲を改善しました
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::PECollusionDetection()
{
	//プレイヤーと敵の当たり判定
	for (int i = 0; i < EnemyQuantity; ++i)
	{
		for (int j = 0; j < PlayerQuantity; ++j)
		{
			if (g_pEnemy[i] != NULL)
			{
				if (PlayerInvincible != false && playerIsDead != true)
				{
					if (g_pPlayer1[j]->getPos().x < WINDOW_WIDTH / 2 + PLAYER_SIZE_X / 2 && g_pPlayer1[j]->getPos().x > -WINDOW_WIDTH / 2 - PLAYER_SIZE_X / 2
						&& g_pEnemy[i]->getPos().x < WINDOW_WIDTH / 2 + PLAYER_SIZE_X / 2 && g_pEnemy[i]->getPos().x > -WINDOW_WIDTH / 2 - PLAYER_SIZE_X / 2)
					{
						if (j == 0)
						{
							if (i == EnemyType01_01 || i == EnemyType01_02)
							{
								if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] != true)
								{
									//横から
									//プレイヤーが右、エネミーが左
									if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x  && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 64.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = 2.0f;
										ENEMY_SPEED_X = -2.0f;

									}
									//プレイヤーが左、エネミーが右
									else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x  && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 64.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = -2.0f;
										ENEMY_SPEED_X = 2.0f;
									}
									//プレイヤーが上から
									else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + (96.0f + GravLimi))
									{
										//プレイヤーの座標を敵に接する位置まで調整する
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
										moveY = 2.0f;
									}
									//プレイヤーが下から
									else if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										//プレイヤーの座標を敵に接する位置まで調整する
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y - 96.0f);
										moveY = -2.0f;
										ENEMY_SPEED_Y = 2.0f;
									}
									//プレイヤーのバルーンの当たり判定
									if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - 36.0f)
									{
										//プレイヤーの残機の調節
										/*
										* 最初にバルーンの残機の調節
										* バルーンの残機がなくなったらプレイヤーの残機
										*/
										if (enemyBalloonIsBroken[0] != true)
										{
											if (PlayerBalloon > 0)
											{
												//バルーンの残機の減少
												PlayerBalloon--;
												//ここでバルーンの残機の確認
												//バルーンの残機が0になっていたら
												//プレイヤーの残機の減少
												if (PlayerBalloon == 0)
												{
													PlayerDieBalloon = true;
												};
												return;
											}
										}
									}
									else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + 36.0f)
									{
										if (enemyBalloonIsBroken[0] == false)
										{
											g_score += 500;
											enemyBalloonIsBroken[0] = true;
											//スピードも0にする
											ENEMY_SPEED_X = 0.0f;
											//強さの変更
											if (iEnemyStrong[0] == 0)
											{
												iEnemyStrong[0] = 1;
											}
											else if (iEnemyStrong[0] == 1)
											{
												iEnemyStrong[0] = 2;
											}
										}
										//敵のバルーンが割れた時
										else if (enemyBalloonIsBroken[0] == true)
										{
											if (enemyIsDead[0] != true)
											{
												g_score += 1000;
												enemyIsDead[0] = true;
											}
										}
									}
								}
								else if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] == true && g_pPlayer1[j]->getPos().y <= g_pEnemy[i]->getPos().y + 60.0f)
								{
									if (enemyIsDead[0] != true)
									{
										g_score += 750;
										enemyIsDead[0] = true;

										if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 26.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 26.0f)
										{
											//プレイヤーの座標を敵に接する位置まで調整する
											g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 60.0f);
											moveY = 2.0f;
										}
										else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 26.0f)
										{
											g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 58.0f, g_pPlayer1[j]->getPos().y);
											playerHoriSpeed = 2.0f;
											ENEMY_SPEED_X = -2.0f;
										}
										else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 26.0f)
										{
											g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 58.0f, g_pPlayer1[j]->getPos().y);
											playerHoriSpeed = -2.0f;
											ENEMY_SPEED_X = 2.0f;
										}
									}
								}
							}
							else if (i == EnemyType02_01 || i == EnemyType02_02)
							{
								if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[1] != true)
								{
									//横から
									//プレイヤーが右、エネミーが左
									if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f))
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 64.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = 2.0f;
										ENEMY_SPEED_X2 = -2.0f;

									}
									//プレイヤーが左、エネミーが右
									else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 64.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = -2.0f;
										ENEMY_SPEED_X2 = 2.0f;

									}
									//プレイヤーが上から
									else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + (96.0f + GravLimi))
									{
										//プレイヤーの座標を敵に接する位置まで調整する
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
										moveY = 2.0f;
									}
									//プレイヤーが下から
									else if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										//プレイヤーの座標を敵に接する位置まで調整する
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y - 96.0f);
										moveY = -2.0f;
										ENEMY_SPEED_Y2 = 2.0f;
									}
									//プレイヤーのバルーンの当たり判定
									if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - 36.0f)
									{
										//プレイヤーの残機の調節
										/*
										* 最初にバルーンの残機の調節
										* バルーンの残機がなくなったらプレイヤーの残機
										*/
										if (enemyBalloonIsBroken[1] != true)
										{
											if (PlayerBalloon > 0)
											{
												//バルーンの残機の減少
												PlayerBalloon--;
												//ここでバルーンの残機の確認
												//バルーンの残機が0になっていたら
												//プレイヤーの残機の減少
												if (PlayerBalloon == 0)
												{
													PlayerDieBalloon = true;
												};
												return;
											}
										}
									}
									else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + 36.0f)
									{
										if (enemyBalloonIsBroken[1] == false)
										{
											g_score += 500;
											enemyBalloonIsBroken[1] = true;
											//スピードも0にする
											ENEMY_SPEED_X2 = 0.0f;
											//強さの変更
											if (iEnemyStrong[1] == 0)
											{
												iEnemyStrong[1] = 1;
											}
											else if (iEnemyStrong[1] == 1)
											{
												iEnemyStrong[1] = 2;
											}
										}
										//敵のバルーンが割れた時
										else if (enemyBalloonIsBroken[1] == true)
										{
											if (enemyIsDead[1] != true)
											{
												g_score += 1000;
												enemyIsDead[1] = true;
											}
										}
									}
								}
								else if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] == true && g_pPlayer1[j]->getPos().y <= g_pEnemy[i]->getPos().y + 60.0f)
								{
									if (enemyIsDead[1] != true)
									{
										g_score += 750;
										enemyIsDead[1] = true;

										if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 26.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 26.0f)
										{
											//プレイヤーの座標を敵に接する位置まで調整する
											g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 60.0f);
											moveY = 2.0f;
										}
										else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 26.0f)
										{
											g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 58.0f, g_pPlayer1[j]->getPos().y);
											playerHoriSpeed = 2.0f;
											ENEMY_SPEED_X2 = -2.0f;
										}
										else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 26.0f)
										{
											g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 58.0f, g_pPlayer1[j]->getPos().y);
											playerHoriSpeed = -2.0f;
											ENEMY_SPEED_X2 = 2.0f;
										}
									}
								}
							}
							else if (i == EnemyType03_01 || i == EnemyType03_02)
							{
								if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[2] != true)
								{
									//横から
									//プレイヤーが右、エネミーが左
									if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f))
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 64.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = 2.0f;
										ENEMY_SPEED_X3 = -2.0f;

									}
									//プレイヤーが左、エネミーが右
									else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 64.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = -2.0f;
										ENEMY_SPEED_X3 = 2.0f;

									}
									//プレイヤーが上から
									else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + (96.0f + GravLimi))
									{
										//プレイヤーの座標を敵に接する位置まで調整する
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
										moveY = 2.0f;
									}
									//プレイヤーが下から
									else if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										//プレイヤーの座標を敵に接する位置まで調整する
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y - 96.0f);
										moveY = -2.0f;
										ENEMY_SPEED_Y3 = 2.0f;
									}
									//プレイヤーのバルーンの当たり判定
									if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - 36.0f)
									{
										//プレイヤーの残機の調節
										/*
										* 最初にバルーンの残機の調節
										* バルーンの残機がなくなったらプレイヤーの残機
										*/
										if (enemyBalloonIsBroken[2] != true)
										{
											if (PlayerBalloon > 0)
											{
												//バルーンの残機の減少
												PlayerBalloon--;
												//ここでバルーンの残機の確認
												//バルーンの残機が0になっていたら
												//プレイヤーの残機の減少
												if (PlayerBalloon == 0)
												{
													PlayerDieBalloon = true;
												};
												return;
											}
										}
									}
									else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + 36.0f)
									{
										if (enemyBalloonIsBroken[2] == false)
										{
											g_score += 500;
											enemyBalloonIsBroken[2] = true;
											//スピードも0にする
											ENEMY_SPEED_X3 = 0.0f;
											//強さの変更
											if (iEnemyStrong[2] == 0)
											{
												iEnemyStrong[2] = 1;
											}
											else if (iEnemyStrong[2] == 1)
											{
												iEnemyStrong[2] = 2;
											}
										}
										//敵のバルーンが割れた時
										else if (enemyBalloonIsBroken[2] == true)
										{
											if (enemyIsDead[2] != true)
											{
												g_score += 1000;
												enemyIsDead[2] = true;
											}
										}
									}
								}
								else if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] == true && g_pPlayer1[j]->getPos().y <= g_pEnemy[i]->getPos().y + 60.0f)
								{
									if (enemyIsDead[2] != true)
									{
										g_score += 750;
										enemyIsDead[2] = true;

										if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 26.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 26.0f)
										{
											//プレイヤーの座標を敵に接する位置まで調整する
											g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 60.0f);
											moveY = 2.0f;
										}
										else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 26.0f)
										{
											g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 58.0f, g_pPlayer1[j]->getPos().y);
											playerHoriSpeed = 2.0f;
											ENEMY_SPEED_X3 = -2.0f;
										}
										else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 26.0f)
										{
											g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 58.0f, g_pPlayer1[j]->getPos().y);
											playerHoriSpeed = -2.0f;
											ENEMY_SPEED_X3 = 2.0f;
										}
									}
								}
							}
						}
						else if (j == 1)
						{
						if (i == EnemyType01_01 || i == EnemyType01_02)
						{

							if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] != true)
							{
								//横から
								//プレイヤーが右、エネミーが左
								if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f))
								{
									g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 64.0f, g_pPlayer1[j]->getPos().y);
									playerHoriSpeed = 2.0f;
									ENEMY_SPEED_X = -2.0f;

								}
								//プレイヤーが左、エネミーが右
								else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
								{
									g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 64.0f, g_pPlayer1[j]->getPos().y);
									playerHoriSpeed = -2.0f;
									ENEMY_SPEED_X = 2.0f;

								}
								//プレイヤーが上から
								else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y)
								{
									//プレイヤーの座標を敵に接する位置まで調整する
									g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
									moveY = 2.0f;
								}
								//プレイヤーが下から
								else if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y)
								{
									//プレイヤーの座標を敵に接する位置まで調整する
									g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y - 96.0f);
									moveY = -2.0f;
									ENEMY_SPEED_Y = 2.0f;
								}
								//プレイヤーのバルーンの当たり判定
								if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - 36.0f)
								{
									//プレイヤーの残機の調節
									/*
									* 最初にバルーンの残機の調節
									* バルーンの残機がなくなったらプレイヤーの残機
									*/
									if (enemyBalloonIsBroken[0] != true)
									{
										if (PlayerBalloon > 0)
										{
											//バルーンの残機の減少
											PlayerBalloon--;
											//ここでバルーンの残機の確認
											//バルーンの残機が0になっていたら
											//プレイヤーの残機の減少
											if (PlayerBalloon == 0)
											{
												PlayerDieBalloon = true;
											};
											return;
										}
									}
								}
								else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + 36.0f)
								{
									if (enemyBalloonIsBroken[0] == false)
									{
										g_score += 500;
										enemyBalloonIsBroken[0] = true;
										//スピードも0にする
										ENEMY_SPEED_X = 0.0f;
										//強さの変更
										if (iEnemyStrong[0] == 0)
										{
											iEnemyStrong[0] = 1;
										}
										else if (iEnemyStrong[0] == 1)
										{
											iEnemyStrong[0] = 2;
										}
									}
									//敵のバルーンが割れた時
									else if (enemyBalloonIsBroken[0] == true)
									{
										if (enemyIsDead[0] != true)
										{
											g_score += 1000;
											enemyIsDead[0] = true;
											//プレイヤーの座標を敵に接する位置まで調整する
											if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
												moveY = 2.0f;
											}
											else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x + 64.0f, g_pEnemy[i]->getPos().y);
											}
											else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x - 64.0f, g_pEnemy[i]->getPos().y);
											}
										}
									}
								}
							}
							else if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] == true && g_pPlayer1[j]->getPos().y <= g_pEnemy[i]->getPos().y + 60.0f)
							{
								if (enemyIsDead[0] != true)
								{
									g_score += 750;
									enemyIsDead[0] = true;

									if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 26.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 26.0f)
									{
										//プレイヤーの座標を敵に接する位置まで調整する
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 60.0f);
										moveY = 2.0f;
									}
									else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 26.0f)
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 58.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = 2.0f;
										ENEMY_SPEED_X = -2.0f;
									}
									else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 26.0f)
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 58.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = -2.0f;
										ENEMY_SPEED_X = 2.0f;
									}
								}
							}
						}
						else if (i == EnemyType02_01 || i == EnemyType02_02)
						{
							if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[1] != true)
							{
								//横から
								//プレイヤーが右、エネミーが左
								if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f))
								{
									g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 64.0f, g_pPlayer1[j]->getPos().y);
									playerHoriSpeed = 2.0f;
									ENEMY_SPEED_X2 = -2.0f;

								}
								//プレイヤーが左、エネミーが右
								else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
								{
									g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 64.0f, g_pPlayer1[j]->getPos().y);
									playerHoriSpeed = -2.0f;
									ENEMY_SPEED_X2 = 2.0f;

								}
								//プレイヤーが上から
								else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y)
								{
									//プレイヤーの座標を敵に接する位置まで調整する
									g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
									moveY = 2.0f;
								}
								//プレイヤーが下から
								else if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y)
								{
									//プレイヤーの座標を敵に接する位置まで調整する
									g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y - 96.0f);
									moveY = -2.0f;
									ENEMY_SPEED_Y2 = 2.0f;
								}
								//プレイヤーのバルーンの当たり判定
								if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - 36.0f)
								{
									//プレイヤーの残機の調節
									/*
									* 最初にバルーンの残機の調節
									* バルーンの残機がなくなったらプレイヤーの残機
									*/
									if (enemyBalloonIsBroken[1] != true)
									{
										if (PlayerBalloon > 0)
										{
											//バルーンの残機の減少
											PlayerBalloon--;
											//ここでバルーンの残機の確認
											//バルーンの残機が0になっていたら
											//プレイヤーの残機の減少
											if (PlayerBalloon == 0)
											{
												PlayerDieBalloon = true;
											};
											return;
										}
									}
								}
								else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + 36.0f)
								{
									if (enemyBalloonIsBroken[1] == false)
									{
										g_score += 500;
										enemyBalloonIsBroken[1] = true;
										//スピードも0にする
										ENEMY_SPEED_X2 = 0.0f;
										//強さの変更
										if (iEnemyStrong[1] == 0)
										{
											iEnemyStrong[1] = 1;
										}
										else if (iEnemyStrong[1] == 1)
										{
											iEnemyStrong[1] = 2;
										}
									}
									//敵のバルーンが割れた時
									else if (enemyBalloonIsBroken[1] == true)
									{
										if (enemyIsDead[1] != true)
										{
											g_score += 1000;
											enemyIsDead[1] = true;
											//プレイヤーの座標を敵に接する位置まで調整する
											if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
												moveY = 2.0f;
											}
											else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x + 64.0f, g_pEnemy[i]->getPos().y);
											}
											else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x - 64.0f, g_pEnemy[i]->getPos().y);
											}
										}
									}
								}
							}
							else if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] == true && g_pPlayer1[j]->getPos().y <= g_pEnemy[i]->getPos().y + 60.0f)
							{
								if (enemyIsDead[1] != true)
								{
									g_score += 750;
									enemyIsDead[1] = true;

									if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 26.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 26.0f)
									{
										//プレイヤーの座標を敵に接する位置まで調整する
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 60.0f);
										moveY = 2.0f;
									}
									else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 26.0f)
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 58.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = 2.0f;
										ENEMY_SPEED_X2 = -2.0f;
									}
									else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 26.0f)
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 58.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = -2.0f;
										ENEMY_SPEED_X2 = 2.0f;
									}
								}
							}
						}
						else if (i == EnemyType03_01 || i == EnemyType03_02)
						{
							if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[2] != true)
							{
								//横から
								//プレイヤーが右、エネミーが左
								if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f))
								{
									g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 64.0f, g_pPlayer1[j]->getPos().y);
									playerHoriSpeed = 2.0f;
									ENEMY_SPEED_X3 = -2.0f;

								}
								//プレイヤーが左、エネミーが右
								else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
								{
									g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 64.0f, g_pPlayer1[j]->getPos().y);
									playerHoriSpeed = -2.0f;
									ENEMY_SPEED_X3 = 2.0f;

								}
								//プレイヤーが上から
								else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y)
								{
									//プレイヤーの座標を敵に接する位置まで調整する
									g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
									moveY = 2.0f;
								}
								//プレイヤーが下から
								else if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y)
								{
									//プレイヤーの座標を敵に接する位置まで調整する
									g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y - 96.0f);
									moveY = -2.0f;
									ENEMY_SPEED_Y3 = 2.0f;
								}
								//プレイヤーのバルーンの当たり判定
								if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - 36.0f)
								{
									//プレイヤーの残機の調節
									/*
									* 最初にバルーンの残機の調節
									* バルーンの残機がなくなったらプレイヤーの残機
									*/
									if (enemyBalloonIsBroken[2] != true)
									{
										if (PlayerBalloon > 0)
										{
											//バルーンの残機の減少
											PlayerBalloon--;
											//ここでバルーンの残機の確認
											//バルーンの残機が0になっていたら
											//プレイヤーの残機の減少
											if (PlayerBalloon == 0)
											{
												PlayerDieBalloon = true;
											};
											return;
										}
									}
								}
								else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + 36.0f)
								{
									if (enemyBalloonIsBroken[2] == false)
									{
										g_score += 500;
										enemyBalloonIsBroken[2] = true;
										//スピードも0にする
										ENEMY_SPEED_X3 = 0.0f;
										//強さの変更
										if (iEnemyStrong[2] == 0)
										{
											iEnemyStrong[2] = 1;
										}
										else if (iEnemyStrong[2] == 1)
										{
											iEnemyStrong[2] = 2;
										}
									}
									//敵のバルーンが割れた時
									else if (enemyBalloonIsBroken[2] == true)
									{
										if (enemyIsDead[2] != true)
										{
											g_score += 1000;
											enemyIsDead[2] = true;
											//プレイヤーの座標を敵に接する位置まで調整する
											if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
												moveY = 2.0f;
											}
											else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x + 64.0f, g_pEnemy[i]->getPos().y);
											}
											else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x - 64.0f, g_pEnemy[i]->getPos().y);
											}
										}
									}
								}
							}
							else if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] == true && g_pPlayer1[j]->getPos().y <= g_pEnemy[i]->getPos().y + 60.0f)
							{
								if (enemyIsDead[2] != true)
								{
									g_score += 750;
									enemyIsDead[2] = true;

									if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 26.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 26.0f)
									{
										//プレイヤーの座標を敵に接する位置まで調整する
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 60.0f);
										moveY = 2.0f;
									}
									else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 26.0f)
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 58.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = 2.0f;
										ENEMY_SPEED_X3 = -2.0f;
									}
									else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 26.0f)
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 58.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = -2.0f;
										ENEMY_SPEED_X3 = 2.0f;
									}
								}
							}
						}
						}
					}
				}
			}
		}

	}
}