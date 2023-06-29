//----------------------------------------------------------
// ファイル名		：EnemyFly1
// 概要				：敵キャラクター1段階目の行動
// 作成者			：21cu0118 小池慎之介
// 更新内容			：2022/03/07 21cu0118 小池慎之介 作成
//					：2022/03/08 21cu0118 小池慎之介
//					：2022/03/10 21cu0118 小池慎之介 キャラ分け
//					：2022/03/11 21cu0118 小池慎之介 キャラの挙動修正
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyFly1()
{
	//敵を一定時間行動を制限する
	if (bEnemyTimeUp == false)
	{
		//一定時間動かなくさせる用の関数の呼び出し
		bEnemyTimeUp = Enemy_Start_Time();
	}
	else
	{
		//プレイヤー1の行動
		if (g_pEnemy[0] != NULL && EnemyStateChange[0] == 0 && enemyBalloonIsBroken[0] == false)
		{
			//プレイヤーの座標を一度取得する
			if (Enemy1.EnemyMoveTrue == false)
			{
				Enemy1.PlayerPos.x = g_pPlayer1[0]->getPos().x;
				Enemy1.PlayerPos.y = g_pPlayer1[0]->getPos().y;
				//変数を変更する
				Enemy1.EnemyMoveTrue = true;
			}
			else
			{
				//初期状態の時
				if (iEnemyStrong[0] == 0)
				{
					//60*15秒間動かす
					Enemy1.EnemyMoveTime++;
					if (Enemy1.EnemyMoveTime == 60 * 3)
					{
						//タイムのリセット
						Enemy1.EnemyMoveTime = 0;
						//座標をもう一度取得
						Enemy1.EnemyMoveTrue = false;
					}
					//座標より右にいるとき
					if (Enemy1.PlayerPos.x < g_pEnemy[0]->getPos().x)
					{
						//時間を10で割ったとき、あまりが0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 10 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X)
							{
								ENEMY_SPEED_X -= 0.1f;
							}
						}
					}
					//座標より左にいるとき
					if (Enemy1.PlayerPos.x > g_pEnemy[0]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 10 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X)
							{
								ENEMY_SPEED_X += 0.1f;
							}
						}
					}
					//座標より上に居るとき
					if (Enemy1.PlayerPos.y < g_pEnemy[0]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 10 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y -= 0.1f;
							}
						}
					}
					//特定の位置よりも敵が下にいる時
					if (g_pEnemy[0]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y += 0.1f;
							}
						}
					}
					//座標より下に居るとき
					else if (Enemy1.PlayerPos.y > g_pEnemy[0]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 10 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y += 0.1f;
							}
						}
					}
				}

				//2段階目の時
				if (iEnemyStrong[0] == 1)
				{
					//60*15秒間動かす
					Enemy1.EnemyMoveTime++;
					if (Enemy1.EnemyMoveTime == 60 * 3)
					{
						//タイムのリセット
						Enemy1.EnemyMoveTime = 0;
						//座標をもう一度取得
						Enemy1.EnemyMoveTrue = false;
					}
					//座標より右にいるとき
					if (Enemy1.PlayerPos.x < g_pEnemy[0]->getPos().x)
					{
						//時間を10で割ったとき、あまりが0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 5 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X)
							{
								ENEMY_SPEED_X -= 0.1f;
							}
						}
					}
					//座標より左にいるとき
					if (Enemy1.PlayerPos.x > g_pEnemy[0]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 5 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X)
							{
								ENEMY_SPEED_X += 0.1f;
							}
						}
					}
					//座標より上に居るとき
					if (Enemy1.PlayerPos.y < g_pEnemy[0]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 5 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y -= 0.1f;
							}
						}
					}
					//特定の位置よりも敵が下にいる時
					if (g_pEnemy[0]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y += 0.3f;
							}
						}
					}
					//座標より下に居るとき
					else if (Enemy1.PlayerPos.y > g_pEnemy[0]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 5 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y += 0.1f;
							}
						}
					}
				}

				//3段階目の時
				if (iEnemyStrong[0] == 2)
				{
					//60*15秒間動かす
					Enemy1.EnemyMoveTime++;
					if (Enemy1.EnemyMoveTime == 60 * 3)
					{
						//タイムのリセット
						Enemy1.EnemyMoveTime = 0;
						//座標をもう一度取得
						Enemy1.EnemyMoveTrue = false;
					}
					//座標より右にいるとき
					if (Enemy1.PlayerPos.x < g_pEnemy[0]->getPos().x)
					{
						//時間を10で割ったとき、あまりが0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X)
							{
								ENEMY_SPEED_X -= 0.1f;
							}
						}
					}
					//座標より左にいるとき
					if (Enemy1.PlayerPos.x > g_pEnemy[0]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X)
							{
								ENEMY_SPEED_X += 0.1f;
							}
						}
					}
					//座標より上に居るとき
					if (Enemy1.PlayerPos.y < g_pEnemy[0]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y -= 0.1f;
							}
						}
					}
					//特定の位置よりも敵が下にいる時
					if (g_pEnemy[0]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y += 0.1f;
							}
						}
					}
					//座標より下に居るとき
					else if (Enemy1.PlayerPos.y > g_pEnemy[0]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y += 0.1f;
							}
						}
					}
				}
			}
		}
		//プレイヤー2の行動
		if (g_pEnemy[2] != NULL && EnemyStateChange[1] == 0 && enemyBalloonIsBroken[1] == false)
		{
			//プレイヤーの座標を一度取得する
			if (Enemy2.EnemyMoveTrue == false)
			{
				Enemy2.PlayerPos.x = g_pPlayer1[0]->getPos().x;
				Enemy2.PlayerPos.y = g_pPlayer1[0]->getPos().y;
				//変数を変更する
				Enemy2.EnemyMoveTrue = true;
			}
			else
			{
				//敵の強さ1段階目
				if (iEnemyStrong[1] == 0)
				{
					//60*2秒間動かす
					Enemy2.EnemyMoveTime++;
					if (Enemy2.EnemyMoveTime == 60 * 2)
					{
						//タイムのリセット
						Enemy2.EnemyMoveTime = 0;
						//座標をもう一度取得
						Enemy2.EnemyMoveTrue = false;
					}
					//座標より右にいるとき
					if (Enemy2.PlayerPos.x < g_pEnemy[2]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy2.EnemyMoveTime % 10 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X2)
							{
								ENEMY_SPEED_X2 -= 0.1f;
							}
						}
					}
					//座標より左にいるとき
					if (Enemy2.PlayerPos.x > g_pEnemy[2]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy2.EnemyMoveTime % 10 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X2)
							{
								ENEMY_SPEED_X2 += 0.1f;
							}
						}
					}
					//座標より上に居るとき
					if (Enemy2.PlayerPos.y < g_pEnemy[2]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 10 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 -= 0.1f;
							}
						}
					}
					//特定の位置よりも敵が下にいる時
					if (g_pEnemy[2]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 += 0.1f;
							}
						}
					}
					//座標より下に居るとき
					else if (Enemy2.PlayerPos.y > g_pEnemy[2]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy2.EnemyMoveTime % 10 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 += 0.1f;
							}
						}
					}
				}

				//敵の強さ2段階目
				if (iEnemyStrong[1] == 1)
				{
					//60*2秒間動かす
					Enemy2.EnemyMoveTime++;
					if (Enemy2.EnemyMoveTime == 60 * 2)
					{
						//タイムのリセット
						Enemy2.EnemyMoveTime = 0;
						//座標をもう一度取得
						Enemy2.EnemyMoveTrue = false;
					}
					//座標より右にいるとき
					if (Enemy2.PlayerPos.x < g_pEnemy[2]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy2.EnemyMoveTime % 5 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X2)
							{
								ENEMY_SPEED_X2 -= 0.1f;
							}
						}
					}
					//座標より左にいるとき
					if (Enemy2.PlayerPos.x > g_pEnemy[2]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy2.EnemyMoveTime % 5 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X2)
							{
								ENEMY_SPEED_X2 += 0.1f;
							}
						}
					}
					//座標より上に居るとき
					if (Enemy2.PlayerPos.y < g_pEnemy[2]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 5 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 -= 0.1f;
							}
						}
					}
					//特定の位置よりも敵が下にいる時
					if (g_pEnemy[2]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 += 0.1f;
							}
						}
					}
					//座標より下に居るとき
					else if (Enemy2.PlayerPos.y > g_pEnemy[2]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy2.EnemyMoveTime % 5 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 += 0.1f;
							}
						}
					}
				}

				//敵の強さ3段階目
				if (iEnemyStrong[1] == 2)
				{
					//60*2秒間動かす
					Enemy2.EnemyMoveTime++;
					if (Enemy2.EnemyMoveTime == 60 * 2)
					{
						//タイムのリセット
						Enemy2.EnemyMoveTime = 0;
						//座標をもう一度取得
						Enemy2.EnemyMoveTrue = false;
					}
					//座標より右にいるとき
					if (Enemy2.PlayerPos.x < g_pEnemy[2]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy2.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X2)
							{
								ENEMY_SPEED_X2 -= 0.1f;
							}
						}
					}
					//座標より左にいるとき
					if (Enemy2.PlayerPos.x > g_pEnemy[2]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy2.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X2)
							{
								ENEMY_SPEED_X2 += 0.1f;
							}
						}
					}
					//座標より上に居るとき
					if (Enemy2.PlayerPos.y < g_pEnemy[2]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 -= 0.1f;
							}
						}
					}
					//特定の位置よりも敵が下にいる時
					if (g_pEnemy[2]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 += 0.1f;
							}
						}
					}
					//座標より下に居るとき
					else if (Enemy2.PlayerPos.y > g_pEnemy[2]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy2.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 += 0.1f;
							}
						}
					}
				}
			}
		}
		//プレイヤー3の行動
		if (g_pEnemy[4] != NULL && EnemyStateChange[2] == 0 && enemyBalloonIsBroken[2] == false)
		{
			//プレイヤーの座標を一度取得する
			if (Enemy3.EnemyMoveTrue == false)
			{
				Enemy3.PlayerPos.x = g_pPlayer1[0]->getPos().x;
				Enemy3.PlayerPos.y = g_pPlayer1[0]->getPos().y;
				//変数を変更する
				Enemy3.EnemyMoveTrue = true;
			}
			else
			{
				//敵の強さ1段階目
				if (iEnemyStrong[2] == 0)
				{
					//60*15秒間動かす
					Enemy3.EnemyMoveTime++;
					if (Enemy3.EnemyMoveTime == 60 * 4)
					{
						//タイムのリセット
						Enemy3.EnemyMoveTime = 0;
						//座標をもう一度取得
						Enemy3.EnemyMoveTrue = false;
					}
					//座標より右にいるとき
					if (Enemy3.PlayerPos.x < g_pEnemy[4]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 10 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X3)
							{
								ENEMY_SPEED_X3 -= 0.1f;
							}
						}
					}
					//座標より左にいるとき
					if (Enemy3.PlayerPos.x > g_pEnemy[4]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 10 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X3)
							{
								ENEMY_SPEED_X3 += 0.1f;
							}
						}
					}
					//座標より上に居るとき
					if (Enemy3.PlayerPos.y < g_pEnemy[4]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 10 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 -= 0.1f;
							}
						}
					}
					//特定の位置よりも敵が下にいる時
					if (g_pEnemy[4]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 += 0.2f;
							}
						}
					}
					//座標より下に居るとき
					if (Enemy3.PlayerPos.y > g_pEnemy[4]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 10 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 += 0.1f;
							}
						}
					}
				}

				//敵の強さ2段階目
				if (iEnemyStrong[2] == 1)
				{
					//60*15秒間動かす
					Enemy3.EnemyMoveTime++;
					if (Enemy3.EnemyMoveTime == 60 * 4)
					{
						//タイムのリセット
						Enemy3.EnemyMoveTime = 0;
						//座標をもう一度取得
						Enemy3.EnemyMoveTrue = false;
					}
					//座標より右にいるとき
					if (Enemy3.PlayerPos.x < g_pEnemy[4]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 5 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X3)
							{
								ENEMY_SPEED_X3 -= 0.1f;
							}
						}
					}
					//座標より左にいるとき
					if (Enemy3.PlayerPos.x > g_pEnemy[4]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 5 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X3)
							{
								ENEMY_SPEED_X3 += 0.1f;
							}
						}
					}
					//座標より上に居るとき
					if (Enemy3.PlayerPos.y < g_pEnemy[4]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 5 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 -= 0.1f;
							}
						}
					}
					//特定の位置よりも敵が下にいる時
					if (g_pEnemy[4]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 += 0.2f;
							}
						}
					}
					//座標より下に居るとき
					if (Enemy3.PlayerPos.y > g_pEnemy[4]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 5 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 += 0.1f;
							}
						}
					}
				}
				//3段階目
				if (iEnemyStrong[2] == 2)
				{
					//60*15秒間動かす
					Enemy3.EnemyMoveTime++;
					if (Enemy3.EnemyMoveTime == 60 * 4)
					{
						//タイムのリセット
						Enemy3.EnemyMoveTime = 0;
						//座標をもう一度取得
						Enemy3.EnemyMoveTrue = false;
					}
					//座標より右にいるとき
					if (Enemy3.PlayerPos.x < g_pEnemy[4]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X3)
							{
								ENEMY_SPEED_X3 -= 0.1f;
							}
						}
					}
					//座標より左にいるとき
					if (Enemy3.PlayerPos.x > g_pEnemy[4]->getPos().x)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X3)
							{
								ENEMY_SPEED_X3 += 0.1f;
							}
						}
					}
					//座標より上に居るとき
					if (Enemy3.PlayerPos.y < g_pEnemy[4]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 -= 0.1f;
							}
						}
					}
					//特定の位置よりも敵が下にいる時
					if (g_pEnemy[4]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 += 0.2f;
							}
						}
					}
					//座標より下に居るとき
					if (Enemy3.PlayerPos.y > g_pEnemy[4]->getPos().y)
					{
						//時間を10で割ったとき、0になったら値を加算する
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//リミット基準
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 += 0.1f;
							}
						}
					}
				}
			}
		}
	}
}