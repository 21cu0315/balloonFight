//----------------------------------------------------------
// ファイル名		：Fish.cpp
// 概要				：魚の処理
// 作成者			：21CU0315 黄卓賢
// 更新内容			：2022/03/11 21CU0315 黄卓賢 作成
//				  　 :2022/03/16 21CU0118 小池慎之介 resetPlayerFishPos = false　をPlayerDieActiveに移行
//					 :2022/03/16 21CU333 望月智広 敵が魚に食われる処理	    
//					：2022/03/2821cu0118 小池慎之介 無敵化を追加
//----------------------------------------------------------

#include "CActionGameApp.h"



void CActionGameApp::Fish()
{
	for (int i = 0; i < PlayerQuantity; ++i)
	{
		if (g_pPlayer1[i] != NULL)
		{


			//プレイヤーが指定された位置に入ったら、カウンターを回す
			if (g_pPlayer1[0]->getPos().x<(g_pGround[3]->getPos().x - GROUND_SIZE_X / 2 - PLAYER_SIZE_X / 2)
				&& g_pPlayer1[0]->getPos().x >(g_pGround[7]->getPos().x + GROUND_SIZE_X / 2 + PLAYER_SIZE_X / 2) &&
				g_pPlayer1[0]->getPos().y < (GroundPosY + GROUND_SIZE_Y / 2 + PLAYER_SIZE_Y))
			{
				fishCounter++;
			}
			else if (g_pPlayer1[1]->getPos().x<(g_pGround[3]->getPos().x - GROUND_SIZE_X / 2 - PLAYER_SIZE_X / 2)
				&& g_pPlayer1[1]->getPos().x >(g_pGround[7]->getPos().x + GROUND_SIZE_X / 2 + PLAYER_SIZE_X / 2) &&
				g_pPlayer1[1]->getPos().y < (GroundPosY + GROUND_SIZE_Y / 2 + PLAYER_SIZE_Y))
			{
				fishCounter++;
			}
			//プレイヤーと敵はそれ以外に位置にいたら、カウンターと魚の位置を補正
			else
			{
				fishCounter = 1;
				g_pFish->setPos(fishPos);
			}
			//カウンターが5*60になったら、魚が動く始める
			if (fishCounter % 300 == 0)
			{
				fishStartedMoving = true;
				//プレイヤー
				if (g_pPlayer1[0]->getPos().x > -WINDOW_WIDTH / 2 && g_pPlayer1[0]->getPos().x < WINDOW_WIDTH / 2)
				{
					g_pFish->setPos(g_pPlayer1[0]->getPos().x, g_pFish->getPos().y);
				}
				else if (g_pPlayer1[1]->getPos().x > -WINDOW_WIDTH / 2 && g_pPlayer1[1]->getPos().x < WINDOW_WIDTH / 2)
				{
					g_pFish->setPos(g_pPlayer1[1]->getPos().x, g_pFish->getPos().y);
				}
			}
			//魚が動く始めたら
			if (fishStartedMoving == true)
			{
				g_pFish->setPos(g_pFish->getPos().x, g_pFish->getPos().y + 3.0f);
				//プレイヤーが魚とぶつかった時
				if (g_pPlayer1[i]->collision(g_pFish) != false)
				{
					playerCaughtByFish = true;
					fishStartedMoving = false;
				}
			}
			//プレイヤーが魚に捕まれた時
			if (playerCaughtByFish == true)
			{
				g_pPlayer1[i]->setPos(g_pFish->getPos().x, g_pFish->getPos().y + 25.0f);
				g_pFish->setPos(g_pFish->getPos().x, g_pFish->getPos().y - 2.0f);
			}
			//魚が画面外に出た時
			if (g_pFish->getPos().y < -WINDOW_HEIGHT / 2 && iPlayerResidue >= 1)
			{
				//魚とプレイヤーの座標をリセットする変数をtrueにする
				resetPlayerFishPos = true;
			}
			//プレイヤーが画面の下に出た時
			if (g_pPlayer1[i]->getPos().y < -WINDOW_HEIGHT / 2 - PLAYER_SIZE_X / 2 && iPlayerResidue >= 1)
			{
				//魚とプレイヤーの座標をリセットする変数をtrueにする
				resetPlayerFishPos = true;
			}
			//魚とプレイヤーの座標をリセットする変数がtrueになったとき
			if (resetPlayerFishPos == true)
			{

				//無敵化
				PlayerInvincible = false;
				//残機の減少
				iPlayerResidue--;
				fishCounter = 1;
				//リセット関数
				AllReset();
			}
		}
	}

	////敵
	//for (int j = 0; j < EnemyQuantity; ++j)
	//{
	//	if (g_pEnemy[j] != NULL)
	//	{
	//		//敵が指定された位置に入っていたら、カウンターを回す
	//		if (g_pEnemy[j]->getPos().x < (g_pGround[3]->getPos().x - GROUND_SIZE_X / 2 - ENEMY_SIZE_X / 2)
	//			&& g_pEnemy[j]->getPos().x >(g_pGround[7]->getPos().x + GROUND_SIZE_X / 2 + ENEMY_SIZE_X / 2) &&
	//			g_pEnemy[j]->getPos().y < (GroundPosY + GROUND_SIZE_Y / 2 + ENEMY_SIZE_Y))
	//		{
	//			fishCounter++;
	//		}
	//		//プレイヤーと敵はそれ以外に位置にいたら、カウンターと魚の位置を補正
	//		else
	//		{
	//			fishCounter = 1;
	//			g_pFish->setPos(fishPos);
	//		}
	//		//カウンターが5*60になったら、魚が動く始める
	//		if (fishCounter % 300 == 0)
	//		{
	//			fishStartedMoving = true;
	//		}
	//		//魚が動き始めたら
	//		if (fishStartedMoving == true)
	//		{
	//			g_pFish->setPos(g_pFish->getPos().x, g_pFish->getPos().y + 3.0f);
	//			//敵が魚とぶつかった時
	//			if (g_pEnemy[j]->collision(g_pFish) != false)
	//			{
	//				enemyCaughtByFish = true;
	//				fishStartedMoving = false;
	//			}
	//		}
	//		//敵が魚に捕まれた時
	//		if (enemyCaughtByFish == true)
	//		{
	//			g_pEnemy[j]->setPos(g_pFish->getPos().x, g_pFish->getPos().y + 25.0f);
	//			g_pFish->setPos(g_pFish->getPos().x, g_pFish->getPos().y - 2.0f);
	//		}
	//		//敵が画面下に出た時
	//		if (g_pEnemy[j]->getPos().y < -WINDOW_HEIGHT / 2 - ENEMY_SIZE_X / 2)
	//		{
	//			//敵を表示させない様にするx
	//			enemyCaughtByFish = false;
	//		}
	//	}
	//}
}