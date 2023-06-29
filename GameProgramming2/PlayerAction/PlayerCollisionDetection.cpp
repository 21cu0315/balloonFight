//----------------------------------------------------------
// ファイル名		：PlayerCollisionDetection.cpp
// 概要				：プレイヤーの当たり判定
// 作成者			：21CU0315 黄卓賢
// 更新内容			：2022/03/02 21CU0315 黄卓賢 作成
//					：2022/03/04 21CU0315 黄卓賢 プレイヤーと地面、足場Sの当たり判定を追加
//					：2022/03/08 21CU0315 黄卓賢 プレイヤーとギミックの位置によって、当たり判定を修正
//					：2022/03/28 21CU0118 小池慎之介 泡との当たり判定を追加
//----------------------------------------------------------
#include "CActionGameApp.h"

int playerRunningCounter = 0;


void CActionGameApp::PlayerCollusionDetection()
{
	if (playerIsDead != true)
	{
		//横速度のカウンターを始める
		horiSpeedCounter++;
		//走るとき用のカウンターを始める
		playerRunningCounter++;

		//移動量をプレイヤーに設定する
		for (int i = 0; i < PlayerQuantity; ++i)
		{
			if (g_pPlayer1[i] != NULL)
			{
				if (g_pPlayer1[i]->getPos().y > (WINDOW_HEIGHT / 2 - 48.0f))
				{
					g_pPlayer1[i]->setPos(g_pPlayer1[i]->getPos().x, WINDOW_HEIGHT / 2 - 48.0f);
					moveY = -2.0f;
				}
				else
				{
					g_pPlayer1[i]->setPos(g_pPlayer1[i]->getPos().x, g_pPlayer1[i]->getPos().y + moveY);
				}
			}
		}
		//ブロックの当たり判定
		//g_pPlatFormLに当たっているとき、以下の処理を行い座標を更新する
		for (int i = 0; i < PlatFormQuantityL; ++i)
		{
			for (int j = 0; j < PlayerQuantity; ++j)
			{
				if (g_pPlayer1[j] != NULL && g_pPlatFormL[i] != NULL)
				{
					if (g_pPlayer1[j]->collision(g_pPlatFormL[i]) != false)
					{
						if (g_pPlayer1[j]->getPos().y > g_pPlatFormL[i]->getPos().y)
						{
							//プレイヤーの座標を床に接する位置まで調整する
							g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pPlatFormL[i]->getPos().y + 64.0f);
							//上から当たってるとき値を0にする
							moveY = 0.0f;

							//右に行くとき
							if (playerHoriSpeed > 0)
							{
								if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
								{
									//走る時のアニメーション
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimationRange(10, 12);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimationRange(3, 5);
									}
									if (playerRunningCounter % 5 == 0)
									{
										g_pPlayer1[j]->stepAnimation();
									}
									if (SpeedUpStart < 8)
									{
										SpeedUpStart++;
										playerHoriSpeed += 0.1;
									}
									else
									{
										//上限値まで加速
										if (SpeedLimit > playerHoriSpeed)
										{
											playerHoriSpeed += 0.6f; // 変更点
										}
									}
								}
								else
								{
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimation(13);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimation(6);
									}
								}
								//摩擦力
								if (horiSpeedCounter % 3 == 0)
								{
									playerHoriSpeed -= 0.1f;
									horiSpeedCounter = 0;
								}
							}
							//左に行くとき
							else if (playerHoriSpeed < 0)
							{
								if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
								{
									//走る時のアニメーション
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimationRange(10, 12);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimationRange(3, 5);
									}
									if (playerRunningCounter % 5 == 0)
									{
										g_pPlayer1[j]->stepAnimation();
									}
									if (SpeedUpStart < 8)
									{
										SpeedUpStart++;
										playerHoriSpeed -= 0.1;
									}
									else
									{
										//下限値まで減速
										if (-SpeedLimit < playerHoriSpeed)
										{
											playerHoriSpeed -= 0.6f; // 変更点
										}
									}
								}
								else
								{
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimation(13);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimation(6);
									}
								}
								//摩擦力
								if (horiSpeedCounter % 3 == 0)
								{
									playerHoriSpeed += 0.1f;
									horiSpeedCounter = 0;
								}
							}
							//プレイヤーを棒立ちにする
							else if (playerHoriSpeed == 0)
							{
								SpeedUpStart = 0;
								if (PlayerBalloon == 2)
								{
									g_pPlayer1[j]->setAnimation(7);
								}
								else if (PlayerBalloon == 1)
								{
									g_pPlayer1[j]->setAnimation(0);
								}
							}
						}
						else
						{
							g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, (g_pPlatFormL[i]->getPos().y - 16.0f - 48.0f));
							moveY = -2.0f;
						}
					}
				}
			}
		}

		//g_pPlatFormSに当たっているとき、以下の処理を行い座標を更新する
		for (int i = 0; i < PlatFormQuantityS; ++i)
		{
			for (int j = 0; j < PlayerQuantity; ++j)
			{
				if (g_pPlayer1[j] != NULL && g_pPlatFormS[i] != NULL)
				{
					if (g_pPlayer1[j]->collision(g_pPlatFormS[i]) != false)
					{
						//横から当たるとき
						//右から
						if (g_pPlayer1[j]->getPos().x > g_pPlatFormS[i]->getPos().x && g_pPlayer1[j]->getPos().y < g_pPlatFormS[i]->getPos().y + (64.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pPlatFormS[i]->getPos().y - (64.0f + GravLimi))
						{
							g_pPlayer1[j]->setPos(256.0f, g_pPlayer1[j]->getPos().y);
							playerHoriSpeed = 2.0f;
						}
						//左から
						else if (g_pPlayer1[j]->getPos().x < g_pPlatFormS[i]->getPos().x && g_pPlayer1[j]->getPos().y <  g_pPlatFormS[i]->getPos().y + (64.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pPlatFormS[i]->getPos().y - (64.0f + GravLimi))
						{
							g_pPlayer1[j]->setPos(-256.0f, g_pPlayer1[j]->getPos().y);
							playerHoriSpeed = -2.0f;
						}

						//上から当たるとき

						else if (g_pPlayer1[j]->getPos().y > g_pPlatFormS[i]->getPos().y)
						{
							//プレイヤーの座標を床に接する位置まで調整する
							g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pPlatFormS[i]->getPos().y + 64.0f);
							//上から当たってるとき値を0にする
							moveY = 0.0f;

							//右に行くとき
							if (playerHoriSpeed > 0)
							{
								if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
								{
									//走る時のアニメーション
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimationRange(10, 12);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimationRange(3, 5);
									}
									if (playerRunningCounter % 5 == 0)
									{
										g_pPlayer1[j]->stepAnimation();
									}
								}
								else
								{
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimation(13);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimation(6);
									}
								}
								//摩擦力
								if (horiSpeedCounter % 3 == 0)
								{
									playerHoriSpeed -= 0.1f;
									horiSpeedCounter = 0;
								}
							}
							//左に行くとき
							else if (playerHoriSpeed < 0)
							{
								if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
								{
									//走る時のアニメーション
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimationRange(10, 12);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimationRange(3, 5);
									}
									if (playerRunningCounter % 5 == 0)
									{
										g_pPlayer1[j]->stepAnimation();
									}
								}
								else
								{
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimation(13);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimation(6);
									}
								}
								//摩擦力
								if (horiSpeedCounter % 3 == 0)
								{
									playerHoriSpeed += 0.1f;
									horiSpeedCounter = 0;
								}
							}
							//プレイヤーを棒立ちにする
							else if (playerHoriSpeed == 0)
							{
								SpeedUpStart = 0;
								if (PlayerBalloon == 2)
								{
									g_pPlayer1[j]->setAnimation(7);
								}
								else if (PlayerBalloon == 1)
								{
									g_pPlayer1[j]->setAnimation(0);
								}
							}
						}
						else if (g_pPlayer1[j]->getPos().y < g_pPlatFormS[i]->getPos().y)
						{
							g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, (g_pPlatFormS[i]->getPos().y - 16.0f - 48.0f));
							moveY = -2.0f;
						}

					}
				}

			}
		}

		//g_pGroundに当たっている時、以下の処理を行い座標を更新する
		for (int i = 0; i < GroundQuantity; ++i)
		{
			for (int j = 0; j < PlayerQuantity; ++j)
			{
				if (g_pGround[i] != NULL && g_pPlayer1[j] != NULL)
				{
					//横から当たるとき
					if (g_pPlayer1[j]->collision(g_pGround[3]) != false && playerHoriSpeed > 0 && g_pPlayer1[j]->getPos().y < -292.0f - 6.0f)
					{
						g_pPlayer1[j]->setPos(224.0f, g_pPlayer1[j]->getPos().y);
						playerHoriSpeed = -2.0f;
					}
					else if (g_pPlayer1[j]->collision(g_pGround[7]) != false && playerHoriSpeed < 0 && g_pPlayer1[j]->getPos().y < -292.0f - 6.0f)
					{
						g_pPlayer1[j]->setPos(-224.0f, g_pPlayer1[j]->getPos().y);
						playerHoriSpeed = 2.0f;
					}
					//上から当たるとき
					else if (g_pPlayer1[j]->collision(g_pGround[i]) != false)
					{
						if (g_pPlayer1[j]->getPos().y > GroundPosY)
						{
							//プレイヤーの座標を床に接する位置まで調整する
							g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
							//上から当たってるとき値を0にする
							moveY = 0.0f;

							//右に行くとき
							if (playerHoriSpeed > 0)
							{
								if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
								{
									//走る時のアニメーション
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimationRange(10, 12);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimationRange(3, 5);
									}
									if (playerRunningCounter % 5 == 0)
									{
										g_pPlayer1[j]->stepAnimation();
									}
								}
								else
								{
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimation(13);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimation(6);
									}
								}
								//摩擦力
								if (horiSpeedCounter % 3 == 0)
								{
									playerHoriSpeed -= 0.1f;
									horiSpeedCounter = 0;
								}
							}
							//左に行くとき
							else if (playerHoriSpeed < 0)
							{
								if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
								{
									//走る時のアニメーション
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimationRange(10,12);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimationRange(3,5);
									}
									if (playerRunningCounter % 5 == 0)
									{
										g_pPlayer1[j]->stepAnimation();
									}
								}
								else
								{
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimation(13);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimation(6);
									}
								}
								//摩擦力
								if (horiSpeedCounter % 3 == 0)
								{
									playerHoriSpeed += 0.1f;
									horiSpeedCounter = 0;
								}
							}
							//プレイヤーを棒立ちにする
							else if (playerHoriSpeed == 0)
							{
								SpeedUpStart = 0;
								if (PlayerBalloon == 2)
								{
									g_pPlayer1[j]->setAnimation(7);
								}
								else if (PlayerBalloon == 1)
								{
									g_pPlayer1[j]->setAnimation(0);
								}
							}
						}
					}
				}
			}
		}

		//プレイヤーと泡の当たり判定
		for (int j = 0; j < FoamQuantity; ++j)
		{
			if (g_pPlayer1[0] != NULL)
			{
				if (g_pFoam[j] != NULL)
				{
					//泡と当たったら
					if (g_pPlayer1[0]->collision(g_pFoam[j]) != false)
					{
						//その次にスコアの加算
     						g_score += 500;
						//まず泡の画像の削除
						disposeSprite(g_pFoam[j]);
						g_pFoam[j] = NULL;
						break;
					}
				}
			}
			if (g_pPlayer1[1] != NULL)
			{
				if (g_pFoam[j] != NULL)
				{
					//泡と当たったら
					if (g_pPlayer1[1]->collision(g_pFoam[j]) != false)
					{
						//その次にスコアの加算
						g_score += 500;
						//まず泡の画像の削除
						disposeSprite(g_pFoam[j]);
						g_pFoam[j] = NULL;
						break;
					}
				}
			}
		}
	}
}