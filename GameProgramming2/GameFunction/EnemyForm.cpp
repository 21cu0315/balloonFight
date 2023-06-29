//----------------------------------------------------------
// ファイル名		：EnemyForm
// 概要				：敵が海に落ちたときの泡の処理
// 作成者			：21CU0118　小池慎之介
// 更新内容			：2022/03/28　小池慎之介 作成 
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyFoam()
{
	if (PosGetSea[0] != false)
	{
		//1つ目
		if (g_pFoam[0] != NULL)
		{
			//フレーム増加
			iFoamFleam[0]++;
			//フレームが特定の値に付いたら画像を左右に揺らす
			if (iFoamFleam[0] == 2)
			{
				//関数の値がFalseなら
				//左に動かす
				if (FoamRL[0] == false)
				{
					//特定の値に到達したかの判定
					if (-FoamMove_X_Limit < FoamMove_X[0])
					{
						//値に到達してなければ値を加算する
						FoamMove_X[0] -= 0.05;
					}
					//特定の値に到達していれば値をtrueにする
					else
					{
						FoamRL[0] = true;
					}
				}
				else
				{
					//特定の値に到達したかの判定
					if (FoamMove_X_Limit > FoamMove_X[0])
					{
						//値に到達してなければ値を加算する
						FoamMove_X[0] += 0.05;
					}
					//特定の値に到達していれば値をfalseにする
					else
					{
						FoamRL[0] = false;
					}
				}
				//フレームを0にする
				iFoamFleam[0] = 0;
			}
			//総移動量を加算
			g_pFoam[0]->setPos(g_pFoam[0]->getPos().x + FoamMove_X[0], g_pFoam[0]->getPos().y + 1.0f);

			//特定の位置よりも上に到達したら画像の削除
			if (g_pFoam[0]->getPos().y > WINDOW_TOP)
			{
				disposeSprite(g_pFoam[0]);
				g_pFoam[0] = NULL;
			}
		}
	}

	if (PosGetSea[1] != false)
	{
		//2つ目
		if (g_pFoam[1] != NULL)
		{
			//フレーム増加
			iFoamFleam[1]++;
			//フレームが特定の値に付いたら画像を左右に揺らす
			if (iFoamFleam[1] == 2)
			{
				//関数の値がFalseなら
				//左に動かす
				if (FoamRL[1] == false)
				{
					//特定の値に到達したかの判定
					if (-FoamMove_X_Limit < FoamMove_X[1])
					{
						//値に到達してなければ値を加算する
						FoamMove_X[1] -= 0.05;
					}
					//特定の値に到達していれば値をtrueにする
					else
					{
						FoamRL[1] = true;
					}
				}
				else
				{
					//特定の値に到達したかの判定
					if (FoamMove_X_Limit > FoamMove_X[1])
					{
						//値に到達してなければ値を加算する
						FoamMove_X[1] += 0.05;
					}
					//特定の値に到達していれば値をfalseにする
					else
					{
						FoamRL[1] = false;
					}
				}
				//フレームを0にする
				iFoamFleam[1] = 0;
			}
			//総移動量を加算
			g_pFoam[1]->setPos(g_pFoam[1]->getPos().x + FoamMove_X[1], g_pFoam[1]->getPos().y + 1.0f);

			//特定の位置よりも上に到達したら画像の削除
			if (g_pFoam[1]->getPos().y > WINDOW_TOP)
			{
				disposeSprite(g_pFoam[1]);
				g_pFoam[1] = NULL;
			}
		}
	}

	if (PosGetSea[2] != false)
	{
		//3個目
		if (g_pFoam[2] != NULL)
		{
			//フレーム増加
			iFoamFleam[2]++;
			//フレームが特定の値に付いたら画像を左右に揺らす
			if (iFoamFleam[2] == 2)
			{
				//関数の値がFalseなら
				//左に動かす
				if (FoamRL[2] == false)
				{
					//特定の値に到達したかの判定
					if (-FoamMove_X_Limit < FoamMove_X[2])
					{
						//値に到達してなければ値を加算する
						FoamMove_X[2] -= 0.05;
					}
					//特定の値に到達していれば値をtrueにする
					else
					{
						FoamRL[2] = true;
					}
				}
				else
				{
					//特定の値に到達したかの判定
					if (FoamMove_X_Limit > FoamMove_X[2])
					{
						//値に到達してなければ値を加算する
						FoamMove_X[2] += 0.05;
					}
					//特定の値に到達していれば値をfalseにする
					else
					{
						FoamRL[2] = false;
					}
				}
				//フレームを0にする
				iFoamFleam[2] = 0;
			}
			//総移動量を加算
			g_pFoam[2]->setPos(g_pFoam[2]->getPos().x + FoamMove_X[2], g_pFoam[2]->getPos().y + 1.0f);

			//特定の位置よりも上に到達したら画像の削除
			if (g_pFoam[2]->getPos().y > WINDOW_TOP)
			{
				disposeSprite(g_pFoam[2]);
				g_pFoam[2] = NULL;
			}
		}
	}
}