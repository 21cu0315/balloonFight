//----------------------------------------------------------
// ファイル名		：EnemySeaDrop
// 概要				：敵が海に落ちたときの泡の位置の調整
// // 作成者		：21CU0118 小池慎之介
// 更新内容			：2022/03/28 21CU0118 小池慎之介　作製
//----------------------------------------------------------

#include "CActionGameApp.h"

void CActionGameApp::EnemySeaDrop()
{
	//敵が特定の位置に落ちたときの泡の位置の調整
	if (PosGetSea[0] == false)
	{
		if (g_pEnemy[0] != NULL)
		{
			//画面内に敵が入っていれば座標を取得する
			if (g_pEnemy[0]->getPos().x > WINDOW_LEFT && g_pEnemy[0]->getPos().x < WINDOW_RIGHT)
			{
				//海に落ちたかの判定
				if (g_pEnemy[0]->getPos().y < -WINDOW_HEIGHT/2)
				{
					g_pFoam[0]->setPos(g_pEnemy[0]->getPos().x, ((-WINDOW_HEIGHT / 2) - (80.0f)));
					//座標を取得したら変数の中身を替える
					PosGetSea[0] = true;
					//関数の終了
					return;
				}
			}
		}
		if (g_pEnemy[1] != NULL)
		{
			//画面内に敵が入っていれば座標を取得する
			if (g_pEnemy[1]->getPos().x > WINDOW_LEFT && g_pEnemy[1]->getPos().x < WINDOW_RIGHT)
			{
				//海に落ちたかの判定
				if (g_pEnemy[1]->getPos().y < -WINDOW_HEIGHT/2)
				{
					g_pFoam[0]->setPos(g_pEnemy[1]->getPos().x, ((-WINDOW_HEIGHT / 2) - (80.0f)));
					//座標を取得したら変数の中身を替える
					PosGetSea[0] = true;
					//関数の終了
					return;
				}
			}
		}
	}
	//敵が特定の位置に落ちたときの泡の位置の調整
	if (PosGetSea[1] == false)
	{
		if (g_pEnemy[2] != NULL)
		{
			//画面内に敵が入っていれば座標を取得する
			if (g_pEnemy[2]->getPos().x > WINDOW_LEFT && g_pEnemy[2]->getPos().x < WINDOW_RIGHT)
			{
				//海に落ちたかの判定
				if (g_pEnemy[2]->getPos().y < -WINDOW_HEIGHT/2)
				{
					g_pFoam[1]->setPos(g_pEnemy[2]->getPos().x, ((-WINDOW_HEIGHT / 2) - (80.0f)));
					//座標を取得したら変数の中身を替える
					PosGetSea[1] = true;
					//関数の終了
					return;
				}
			}
		}
		if (g_pEnemy[3] != NULL)
		{
		//画面内に敵が入っていれば座標を取得する
			if (g_pEnemy[3]->getPos().x > WINDOW_LEFT && g_pEnemy[3]->getPos().x < WINDOW_RIGHT)
			{

				//海に落ちたかの判定
				if (g_pEnemy[3]->getPos().y < -WINDOW_HEIGHT/2)
				{
					g_pFoam[1]->setPos(g_pEnemy[3]->getPos().x, ((-WINDOW_HEIGHT / 2) - (80.0f)));
					//座標を取得したら変数の中身を替える
					PosGetSea[1] = true;
					//関数の終了
					return;
				}
			}
		}
	}
	//敵が特定の位置に落ちたときの泡の位置の調整
	if (PosGetSea[2] == false)
	{
		if (g_pEnemy[4] != NULL)
		{
			//画面内に敵が入っていれば座標を取得する
			if (g_pEnemy[4]->getPos().x > WINDOW_LEFT && g_pEnemy[4]->getPos().x < WINDOW_RIGHT)
			{
				//海に落ちたかの判定
				if (g_pEnemy[4]->getPos().y < -WINDOW_HEIGHT/2)
				{
					g_pFoam[2]->setPos(g_pEnemy[4]->getPos().x, ((-WINDOW_HEIGHT / 2) - (80.0f)));
					//座標を取得したら変数の中身を替える
					PosGetSea[2] = true;
					//関数の終了
					return;
				}
			}
		}
		if (g_pEnemy[5] != NULL)
		{
			//画面内に敵が入っていれば座標を取得する
			if (g_pEnemy[5]->getPos().x > WINDOW_LEFT && g_pEnemy[5]->getPos().x < WINDOW_RIGHT)
			{

				//海に落ちたかの判定
				if (g_pEnemy[5]->getPos().y < -WINDOW_HEIGHT/2)
				{
					g_pFoam[2]->setPos(g_pEnemy[5]->getPos().x, ((-WINDOW_HEIGHT / 2) - (80.0f)));
					//座標を取得したら変数の中身を替える
					PosGetSea[2] = true;
					//関数の終了
					return;
				}
			}
		}
	}
}