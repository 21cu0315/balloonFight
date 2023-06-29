#include "CActionGameApp.h"

/*
 * プレイヤーの行動を処理する関数
 */
void CActionGameApp::PlayerAction()
{
	for (int i = 0; i < 2; ++i)
	{
		g_pPlayer1[i]->setPos(g_pPlayer1[i]->getPos().x + playerHoriSpeed, g_pPlayer1[i]->getPos().y);
	}
	if (playerHoriSpeed > 0)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (g_pPlayer1[i]->getPos().x > (WINDOW_WIDTH / 2) + 64.0f)
			{
				g_pPlayer1[i]->setPos((g_pPlayer1[i]->getPos().x - WINDOW_WIDTH * 2), g_pPlayer1[i]->getPos().y);
			}
		}
	}
	else if (playerHoriSpeed < 0)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (g_pPlayer1[i]->getPos().x < (-WINDOW_WIDTH / 2) - 64.0f)
			{
				g_pPlayer1[i]->setPos((g_pPlayer1[i]->getPos().x + WINDOW_WIDTH * 2), g_pPlayer1[i]->getPos().y);
			}
		}
	}
	// 右キーが押された時
	if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
	{
		if (SpeedUpStart < 8)
		{
			SpeedUpStart++;
			playerHoriSpeed += 0.4;
		}
		else
		{
			//上限値まで加速
			if (SpeedLimit > playerHoriSpeed)
			{
				playerHoriSpeed += 0.9f;
			}
		}
	}
	// 左キーが押された時
	else if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
	{
		if (SpeedUpStart < 8)
		{
			SpeedUpStart++;
			playerHoriSpeed -= 0.4;
		}
		else
		{
			//下限値まで減速
			if (-SpeedLimit < playerHoriSpeed)
			{
				playerHoriSpeed -= 0.9f;
			}
		}
	}
	//特定の値の間に入ったらスピードを0にする
	else if (playerHoriSpeed > 0 && playerHoriSpeed < 0.2 || playerHoriSpeed < 0 && playerHoriSpeed > 0.8)
	{
		playerHoriSpeed = 0;
	}
	//ボタンを離したら減速する
	else if (playerHoriSpeed > 0 || playerHoriSpeed < 0)
	{
		if (playerHoriSpeed > 0)
		{
			playerHoriSpeed -= 0.1f;
		}
		else if (playerHoriSpeed < 0)
		{
			playerHoriSpeed += 0.1f;
		}
	}
	else
	{
		SpeedUpStart = 0;
	}


	//ジャンプの処理
	//スペースキーでジャンプ
	if (m_pDirectInput->isPressedOnce(DIK_SPACE))
	{
		if (g_jumpPowerMax > moveY)
		{
			//特定の値まではジャンプ加算ができる
			moveY += 1.0;
		}
	}
	
	//0.2秒に1回落下処理をする
	if (PlayerGravDownTime == 3)
	{
		if (GravLimi < moveY)
		{
			//特定の値まで減算されていく
			moveY -= 0.2;
		}
		PlayerGravDownTime = 0;
	}
	//時間の値に加算していく
	else
	{
		++PlayerGravDownTime;
	}




	//移動量をプレイヤーに設定する
	for (int i = 0; i <PlayerQuanitity; ++i)
	{
		if (g_pPlayer1[i]->getPos().y > (WINDOW_HEIGHT / 2 - 48.0f))
		{
			g_pPlayer1[i]->setPos(g_pPlayer1[i]->getPos().x, WINDOW_HEIGHT / 2 - 48.0f);
			g_changeGrav = -2.0f;
		}
		else
		{
			g_pPlayer1[i]->setPos(g_pPlayer1[i]->getPos().x, g_pPlayer1[i]->getPos().y + moveY);
		}
	}
	//ブロックの当たり判定
	//g_pPlatFormLに当たっているとき、以下の処理を行い座標を更新する
	for (int i = 0; i < PlatFormQuantityL; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{

			if (g_pPlayer1[j]->collision(g_pPlatFormL[i]) != false)
			{
				if (g_pPlayer1[j]->getPos().y > PlatFormPosY)
				{
					//プレイヤーの座標を床に接する位置まで調整する
					g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pPlatFormL[i]->getPos().y + 64.0f);
					g_changeGrav = 0.0f;

					//摩擦力
					if (playerHoriSpeed > 0)
					{
						if (horiSpeedCounter % 30 == 0)
						{
							playerHoriSpeed -= 1.0f;
							horiSpeedCounter = 0;
						}
					}
					else if (playerHoriSpeed < 0)
					{
						if (horiSpeedCounter % 30 == 0)
						{
							playerHoriSpeed += 1.0f;
							horiSpeedCounter = 0;
						}
					}
				}
				else
				{
					g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, (PlatFormPosY - 32.0f - 48.0f));
					g_changeGrav = -2.0f;
				}
				//上から当たってるとき値を0にする
				moveY = 0.0f;
			}
		}
	}

	//g_pPlatFormSに当たっているとき、以下の処理を行い座標を更新する
	for (int i = 0; i < PlatFormQuantityS; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			//横から当たるとき
			//右から
			if (g_pPlayer1[j]->collision(g_pPlatFormS[0]) != false && playerHoriSpeed < 0 && g_pPlayer1[j]->getPos().y < -49.0f)
			{
				g_pPlayer1[j]->setPos(256.0f, g_pPlayer1[j]->getPos().y);
				playerHoriSpeed = 2.0f;
			}
			//左から
			else if (g_pPlayer1[j]->collision(g_pPlatFormS[1]) != false && playerHoriSpeed > 0 && g_pPlayer1[j]->getPos().y < -49.0f)
			{
				g_pPlayer1[j]->setPos(-256.0f, g_pPlayer1[j]->getPos().y);
				playerHoriSpeed = -2.0f;
			}

			//上から当たるとき
			else if (g_pPlayer1[j]->collision(g_pPlatFormS[i]))
			{
				if (g_pPlayer1[j]->getPos().y > PlatFormPosY)
				{
					//プレイヤーの座標を床に接する位置まで調整する
					g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pPlatFormS[i]->getPos().y + 64.0f);
					g_changeGrav = 0.0f;

					//摩擦力
					if (playerHoriSpeed > 0)
					{
						if (horiSpeedCounter % 30 == 0)
						{
							playerHoriSpeed -= 1.0f;
							horiSpeedCounter = 0;
						}
					}
					else if (playerHoriSpeed < 0)
					{
						if (horiSpeedCounter % 30 == 0)
						{
							playerHoriSpeed += 1.0f;
							horiSpeedCounter = 0;
						}
					}
				}
				else
				{
					g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, (PlatFormPosY - 32.0f - 48.0f));
					g_changeGrav = -2.0f;
				}
				//上から当たってるとき値を0にする
				moveY = 0.0f;
			}

		}
	}

	//g_pGroundに当たっている時、以下の処理を行い座標を更新する
	for (int i = 0; i < GroundQuantity; ++i)
	{
		if (g_pGround[i] != NULL)
		{

			for (int j = 0; j < 2; ++j)
			{

				//横から当たるとき
				if (g_pPlayer1[j]->collision(g_pGround[3]) != false && playerHoriSpeed > 0 && g_pPlayer1[j]->getPos().y < -301.0f)
				{
					g_pPlayer1[j]->setPos(224.0f, g_pPlayer1[j]->getPos().y);
					playerHoriSpeed = -2.0f;
				}
				else if (g_pPlayer1[j]->collision(g_pGround[7]) != false && playerHoriSpeed < 0 && g_pPlayer1[j]->getPos().y < -301.0f)
				{
					g_pPlayer1[j]->setPos(-224.0f, g_pPlayer1[j]->getPos().y);
					playerHoriSpeed = 2.0f;
				}
				//上から当たるとき
				else if (g_pPlayer1[j]->collision(g_pGround[i]) != false)
				{

					//プレイヤーの座標を床に接する位置まで調整する
					g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					g_changeGrav = 0.0f;

					//摩擦力
					if (playerHoriSpeed > 0)
					{
						if (horiSpeedCounter % 30 == 0)
						{
							playerHoriSpeed -= 1.0f;
							horiSpeedCounter = 0;
						}
					}
					else if (playerHoriSpeed < 0)
					{
						if (horiSpeedCounter % 30 == 0)
						{
							playerHoriSpeed += 1.0f;
							horiSpeedCounter = 0;
						}
					}
					//上から当たってるとき値を0にする
					moveY = 0.0f;
				}
			}
		}
	}
}