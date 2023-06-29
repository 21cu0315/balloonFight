//------------------------------------------
// ファイル名		:PlayerJump.cpp
// 概要				:プレイヤーの空中移動速度
// 作成日			:2022/03/09
// 作成者			:田中翔太
// 更新内容			:プレイヤーの空中横移動の処理を新たに加えました。
//					:2022/03/18 21CU0315 黄卓賢 プレイヤーがジャンプしたときのアニメーションを実装してみました。
//					:2022/03/28 21cu0118 小池慎之介　無敵判定解除追加
#include "CActionGameApp.h"



void CActionGameApp::PlayerJump()
{
	//ジャンプの処理
	//スペースキーでジャンプ
	if (startPlayerJumpAnimCounter == true)
	{
		playerJumpAnimIndex++;
		if (PlayerBalloon == 2)
		{
			g_pPlayer1[0]->setAnimationRange(19, 20);
			g_pPlayer1[1]->setAnimationRange(19, 20);

		}
		else if (PlayerBalloon == 1)
		{
			if (playerJumpAnimIndex < 15)
			{
				g_pPlayer1[0]->setAnimationRange(14, 15);
				g_pPlayer1[1]->setAnimationRange(14, 15);
			}
		}
		if (playerJumpAnimIndex % 5  == 0)
		{
			g_pPlayer1[0]->stepAnimation();
			g_pPlayer1[1]->stepAnimation();
		}
	}
	if (playerJumpAnimIndex > 15)
	{
		if (PlayerBalloon == 2)
		{
			g_pPlayer1[0]->setAnimation(21);
			g_pPlayer1[1]->setAnimation(21);
		}
		else if (PlayerBalloon == 1)
		{
			g_pPlayer1[0]->setAnimation(16);
			g_pPlayer1[1]->setAnimation(16);
		}
		playerJumpAnimIndex = 0;
		startPlayerJumpAnimCounter = false;
	}
	if (m_pDirectInput->isPressedOnce(DIK_SPACE))
	{
		playerJumpAnimIndex = 0;
		startPlayerJumpAnimCounter = true;
		//無敵判定解除
		PlayerInvincible = true;
		//特定の値まではジャンプ加算ができる
		if (g_jumpPowerMax > moveY)
		{
			moveY += 1.6;
		}
	}
	//プレイヤーが（足場、地面）から落ちた時のアニメーション
	else if (moveY < -0.1f && startPlayerJumpAnimCounter != true)
	{
		if (PlayerBalloon == 2)
		{
			g_pPlayer1[0]->setAnimation(21);
			g_pPlayer1[1]->setAnimation(21);
		}
		else if (PlayerBalloon == 1)
		{
			g_pPlayer1[0]->setAnimation(16);
			g_pPlayer1[1]->setAnimation(16);
		}
		playerJumpAnimIndex = 0;
		startPlayerJumpAnimCounter = false;
	}


//	//---------------------------------------------------------------
//// 右キーが押された時
//	if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
//	{
//		if (SpeedUpStart1 < 8)
//		{
//			SpeedUpStart1++;
//			playerHoriSpeed1 += 0.1;
//		}
//		else
//		{
//			//上限値まで加速
//			if (SpeedLimit > playerHoriSpeed1)
//			{
//				playerHoriSpeed1 += 0.1f; // 変更点
//			}
//		}
//		//無敵判定解除
//		PlayerInvincible = true;
//	}
//	// 左キーが押された時
//	else if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
//	{
//		if (SpeedUpStart1 < 8)
//		{
//			SpeedUpStart1++;
//			playerHoriSpeed1 -= 0.1;
//		}
//		else
//		{
//			//下限値まで減速
//			if (-SpeedLimit1 < playerHoriSpeed1)
//			{
//				playerHoriSpeed1 -= 0.1f; // 変更点
//			}
//		}
//		//無敵判定解除
//		PlayerInvincible = true;
//
//	}
//	//特定の値の間に入ったらスピードを0にする
//	else if (playerHoriSpeed1 > 0 && playerHoriSpeed1 < 0.2 || playerHoriSpeed1 < 0 && playerHoriSpeed1 > 0.8)
//	{
//		playerHoriSpeed1 = 0;
//	}
//	//ボタンを離したら減速する
//	else if (playerHoriSpeed1 > 0 || playerHoriSpeed1 < 0)
//	{
//		if (playerHoriSpeed1 > 0)
//		{
//			playerHoriSpeed1 -= 0.1f;
//		}
//		else if (playerHoriSpeed1 < 0)
//		{
//			playerHoriSpeed1 += 0.1f;
//		}
//	}
//	else
//	{
//		SpeedUpStart1 = 0;
//	}
	//---------------------------------------------------------
		//0.2秒に1回落下処理をする
	if (PlayerGravDownTime == 1)
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
}