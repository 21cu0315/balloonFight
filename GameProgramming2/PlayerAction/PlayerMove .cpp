//----------------------------------------------------------
// ファイル名		：PlayerMove.cpp
// 概要				：プレイヤーの横移動の速度
// 作成日			：2022/03/08
// 作成者			：21cu0321 田中翔太
// 更新内容			：2022/03/09 21cu0321 田中翔太 上限値、下限値の変更
//					：2022/03/11 21CU0315 黄卓賢 プレイヤーの向きの処理を追加
//					：2022/03/18 21cu0321 田中翔太　上限値、下限値の変更
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::PlayerMove()
{
	// 右キーが押された時
	if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
	{
		for (int i = 0; i < PlayerQuantity; ++i)
		{
			g_pPlayer1[i]->setAngle(0.0f, 0.0f, 0.0f);

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
	// 左キーが押された時
	else if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
	{
		for (int i = 0; i < PlayerQuantity; ++i)
		{
			g_pPlayer1[i]->setAngle(0.0f, 180.0f, 0.0f);
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
		//地面にいる時のみスライディングする
		for (int j = 0; j < GroundQuantity; ++j)
		{
			for (int i = 0; i < PlayerQuantity; ++i)
			{
				if (g_pPlayer1[i]->collision(g_pGround[j]) != false)
				{
					g_pPlayer1[i]->setAnimation(3);
				}
			}
		}
	}
}