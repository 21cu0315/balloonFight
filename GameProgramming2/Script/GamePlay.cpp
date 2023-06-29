//----------------------------------------------------------
// ファイル名		：GamePlay.cpp
// 概要				：プレイ画面の基本な処理
// 作成者			：21CU0315 黄卓賢
// 更新内容			：2022/03/02 21CU0315 黄卓賢 作成
//					：2022/03/24 21cu0321 田中翔太　　　スコア処理を追加
//					：2022/03/25 21cu0321 田中翔太　　　スコア位置の修正
//					：2022/03/31 21cu0118 小池慎之介　　終了判定の追加

#include "CActionGameApp.h"
#include "GameResource.h"

/*
 * ゲーム本編の処理を行う部分
 */
 /*
 * (ゲーム本編の大まかな処理)
 *  1.画像の作成
 *	eBegin内の処理
		 画像の作成->procPlayBegin
 *
 *　2.画像の表示およびゲーム本編の処理
 *	eMain内の処理
 *		画像の表示->procPlayMain
 *
 *　3.画像の破棄およびフローの変更
 *	eEnd内の処理
 *		画像の破棄->procPlayEnd
 *
 */

 /*
 * *注意*
 * 画像に関わることは必ずnullチェックを入れる
 * 画像の破棄後は必ず初期化
 */


void CActionGameApp::procGame()
{

	//フェーズの進行状態によって処理を切り替える
	switch (g_GamePhase)
	{
			//画像の作成
		case eBegin:
		{

			//ゲーム画面の開始処理
			//画像の作成
			procPlayBegin();
			//進行状態をメインに切り替える
			g_GamePhase = eMain;
		}
		break;
		//画像の表示
		//ゲーム本編の処理
		case eMain:
		{
			//終了判定用関数
			GameClearSet();
			//プレイヤーの残機がなくなった時の判定
			if (iPlayerResidue == 0)
			{
				//xキーでタイトルへ
				if (getInput()->isPressedOnce(DIK_X))
				{
					g_NextStatusFromGame = eOpening;
					g_GamePhase = eEnd;
				}
			}


			if (iPlayerResidue != 0 && bPlayerStop == false)
			{
				//敵の行動処理
				EnemyAction();
				//雷ボールの処理
				Thunder();
				//魚の処理
				Fish();
				//泡の処理
				EnemyFoam();
				//プレイヤーと敵の当たり判定
				if (PlayerDieBalloon != true && PlayerIsKilledByThunder != true && playerIsDead != true)
				{
					PECollusionDetection();
				}
			}
			else
			{
				for (int i = 0; i < PlayerQuantity; ++i)
				{
					disposeSprite(g_pPlayer1[i]);
					g_pPlayer1[i] = NULL;
				}
			}
			if (bPlayerStop == false)
			{
				//プレイヤーの行動の処理
				PlayerAction();
			}
			
			
		
			
			//ゲーム画面の表示の処理
			procPlayMain();
		}
		break;
		//終了時
		case eEnd:
		{
			//ゲーム画面の終了処理
			procPlayEnd();
			//再度ゲーム画面に来た時に開始から処理を行うために
			//フェーズを戻しておく
			g_GamePhase = eBegin;
			//次のステータスを設定する
			SetNextGameStatus(g_NextStatusFromGame);
		}
		break;
	}
}

/*
* 関数名：procPlayBegin()
* 処理内容：ゲーム画面の開始時に行う処理
* 引数：なし
* 戻り値：なし
*/
void CActionGameApp::procPlayBegin()
{
	//g_pBackground が NULL の時のみ画像を作成する
	if (g_pBackground == NULL)
	{
		//背景の画像を作成・配置する
		g_pBackground = createSprite(Tex_BackGround, WINDOW_WIDTH, WINDOW_HEIGHT);
		g_pBackground->setPos(0.0f, 0.0f);
	}
	//g_pPlayer が NULL の時のみ画像を作成する
	//for文で2枚作る
	for (int i = 0; i < PlayerQuantity; i++)
	{
		if (g_pPlayer1[i] == NULL)
		{
			//プレイヤーの画像を作成・配置する
			g_pPlayer1[i] = createSprite(Tex_Player1, PLAYER_SIZE_X, PLAYER_SIZE_Y);
			g_pPlayer1[i]->setPos(PlayerSet[i]);
		}
	}
	//g_pPlatFormがnullの時画像を作成する
	//for文で11個作成
	for (int i = 0; i < PlatFormQuantityL; ++i)
	{
		if (g_pPlatFormL[i] == NULL)
		{
			g_pPlatFormL[i] = createSprite(Tex_PlatFormL, PLATFORML_SIZE_X, PLATFORML_SIZE_Y);
			g_pPlatFormL[i]->setPos(PlatFormSetL[i]);
		}
	}
	//g_pPaltformSがNULLの時画像を作成する
	//for文で4個作成
	for (int i = 0; i < PlatFormQuantityS; ++i)
	{
		if (g_pPlatFormS[i] == NULL)
		{
			g_pPlatFormS[i] = createSprite(Tex_PlatFromS, PLATFORMS_SIZE_ALL, PLATFORMS_SIZE_ALL);
			g_pPlatFormS[i]->setPos(PlatFormSetS[i]);
		}
	}
	//g_pPaltformS[0]を反転させる
	if(g_pPlatFormS[0] != NULL)
	{
		g_pPlatFormS[0]->setAngle(0, 180, 0);
	}
	//g_pSeaがNULLの時のみ画像を作成する
	//for文で8個作成
	for (int i = 0; i < SeaQuantity; ++i)
	{
		if (g_pSea[i] == NULL)
		{
			g_pSea[i] = createSprite(Tex_Sea, SEA_SIZE_X, SEA_SIZE_Y);
			g_pSea[i]->setPos(SeaSet[i]);
		}
	}
	//g_pCloudがNULLの時のみ画像を作成する
	//1個
	if (g_pCloud == NULL)
	{
		g_pCloud = createSprite(Tex_Cloud, CLOUD_SIZE_X, CLOUD_SIZE_Y);
		g_pCloud->setPos(CloudSet);
	}
	//g_pGroundがNULLの時画像を作成する
	//for文で6個生成
	for (int i = 0; i < GroundQuantity; ++i)
	{
		if (g_pGround[i] == NULL)
		{
			g_pGround[i] = createSprite(Tex_Ground, GROUND_SIZE_X, GROUND_SIZE_Y);
			g_pGround[i]->setPos(GroundSet[i]);
		}
	}
	//敵の画像がNULLの時画像を作成する
	//for文で6個生成
	for (int i = 0; i < EnemyQuantity; ++i)
	{
		if (g_pEnemy[i] == NULL)
		{
			g_pEnemy[i] = createSprite(Tex_Enemy, ENEMY_SIZE_X, ENEMY_SIZE_Y);
			g_pEnemy[i]->setPos(EnemySet[i]);
		}
	}
	//雷ボールの画像がNULLの時画像を作成する
	//for文で2個生成
	for (int i = 0; i < ThunderQuantity; ++i)
	{
		if (g_pThunder[i].obj == NULL)
		{
			g_pThunder[i].obj = createSprite(Tex_Thunder, THUNDER_SIZE_X, THUNDER_SIZE_Y);
			g_pThunder[i].obj->setPos(g_pThunder[i].beginPos);
		}
	}
	//魚の画像がNULLの時画像を作成する
	if (g_pFish == NULL)
	{
		g_pFish = createSprite(Tex_Fish, FISH_SIZE_X, FISH_SIZE_Y);
		g_pFish->setPos(fishPos);
	}
	//数字用の画像を作成・配置する
	if (g_pNumber == NULL)
	{
		g_pNumber = createFont(Tex_Score, 6, NUMBER_SIZE_X, NUMBER_SIZE_Y);
		g_pNumber->setPos(-10.0f, 450.0f);
	}
	//スコア用の画像を作成・配置する
	if (g_pScore == NULL)
	{
		g_pScore = createFont(Tex_Score, 6, SCORE_SIZE_X, SCORE_SIZE_Y);
		g_pScore->setPos(-270.0f, 450.0f);
	}
	// Topの画像がNULLの時画像を作成する
	if (g_pTop == NULL)
	{
		g_pTop = createSprite(Tex_Top, 32.0f, 32.0f);
		g_pTop->setPos(-18.0f, 450.0f);
	}
	// Iの画像がNULLの時画像を作成する
	if (g_pI == NULL)
	{
		g_pI = createSprite(Tex_I, 32.0f, 32.0f);
		g_pI->setPos(-278.0f, 450.0f);
	}

	//g_pFoamの画像がnillのときだけ画像を作成する
	for (int i = 0; i < FoamQuantity; ++i)
	{
		if (g_pFoam[i] == NULL)
		{
			g_pFoam[i] = createSprite(Tex_foam, 56.0f, 64.0f);
			g_pFoam[i]->setPos(0.0f, ((-WINDOW_HEIGHT / 2) - (800.0f)));
		}
	}

	//プレイヤーの残機の画像を作成する
	for (int i = 0; i < PlayerRMQuantity; ++i)
	{
		if (g_pPlayer_RM[i] == NULL)
		{
			g_pPlayer_RM[i] = createSprite(Tex_PlayerRM, 16.0f, 24.0f);
			g_pPlayer_RM[i]->setPos(g_PlayerRM[i]);
		}
	}
	// g_pGameOverがNULLの時のみ画像を作成する
	if (g_pGameOver == NULL)
	{
		// ゲームオーバーの画像を作成する
		g_pGameOver = createSprite(Tex_Over, 400, 28);
	}

}



/*
* 関数名：procPlayMain()
* 処理内容：ゲーム画面のメイン処理
* 引数：なし
* 戻り値：なし
*/
void CActionGameApp::procPlayMain()
{
	//背景の画像が作成されていたら描画する
	if (g_pBackground != NULL)
	{
		renderSprite(g_pBackground);
	}
	//雷ボールの画像が作成されていたら描画する
	for (int i = 0; i < ThunderQuantity; ++i)
	{
		if (g_pThunder[i].obj != NULL)
		{
			renderSprite(g_pThunder[i].obj);
		}
	}
	//魚の画像が作成されていたら描画する
	if (g_pFish != NULL)
	{
		renderSprite(g_pFish);
		g_pFish->setAnimation(3);
	}

	//雲が存在している時だけ描画する
	if (g_pCloud != NULL)
	{
		renderSprite(g_pCloud);
	}
	//足場(L)が存在しているときだけ描画する
	//for文で11個表示
	for (int i = 0; i < PlatFormQuantityL; ++i)
	{
		if (g_pPlatFormL[i] != NULL)
		{
			renderSprite(g_pPlatFormL[i]);
		}
	}
	//足場(S)が存在しているときだけ描画する
	//for文で4個表示
	for (int i = 0; i < PlatFormQuantityS; ++i)
	{
		if (g_pPlatFormS[i] != NULL)
		{
			renderSprite(g_pPlatFormS[i]);
		}
	}
	//地面の画像が存在しているときだけ描画する
	//for文で6個表示
	for (int i = 0; i < GroundQuantity; ++i)
	{
		if (g_pGround[i] != NULL)
		{
			renderSprite(g_pGround[i]);
		}
	}



	//プレイヤー画像が作成されていたら描画する
	for (int i = 0; i < PlayerQuantity; i++)
	{
		if (g_pPlayer1[i] != NULL)
		{
			renderSprite(g_pPlayer1[i]);
		}
	}
	//海の画像が存在しているときだけ描画する
	//for文で8個表示
	for (int i = 0; i < SeaQuantity; ++i)
	{
		if (g_pSea[i] != NULL)
		{
			renderSprite(g_pSea[i]);
		}
	}
	//てきの画像が作成されていたら描画する
	for (int i = 0; i < EnemyQuantity; ++i)
	{
		if (g_pEnemy[i] != NULL)
		{
			renderSprite(g_pEnemy[i]);
		}
	}
	//数字用の画像を作成・配置する
	if (g_pNumber != NULL)
	{
		renderFont(g_pNumber, g_number);
	}
	//スコア用の画像を作成・配置する
	if (g_pScore != NULL)
	{
		renderFont(g_pScore, g_score);
	}
	// Topの画像がNULLの時画像を作成する
	if (g_pTop != NULL)
	{
		renderSprite(g_pTop);
	}
	// Iの画像がNULLの時画像を作成する
	if (g_pI != NULL)
	{
		renderSprite(g_pI);
	}

	
	//プレイヤーの残機の画像が作成されていたら表示する
	for (int i = 0; i < PlayerRMQuantity; ++i)
	{
		if (g_pPlayer_RM[i] != NULL)
		{
			renderSprite(g_pPlayer_RM[i]);
		}
	}
	// 残機が０になった時ゲームオーバー画像を描画する
	if (iPlayerResidue == 0)
	{
		// ゲームオーバー画面の画像が作成されていたら描画する
		if (g_pGameOver != NULL)
		{
			renderSprite(g_pGameOver);
		}
	}
	//g_pFoamの画像が作成されているときのみ画像を表示する
	for (int i = 0; i < FoamQuantity; ++i)
	{
		if (g_pFoam[i] != NULL)
		{
			renderSprite(g_pFoam[i]);
		}
	}
}

/*
* 関数名：procPlayEnd()
* 処理内容：ゲーム画面の終了時に行う処理
* 引数：なし
* 戻り値：なし
*/
void CActionGameApp::procPlayEnd()
{
	//g_pPlayer1 が作成されているときのみ破棄する
	for (int i = 0; i < PlayerQuantity; i++)
	{
		if (g_pPlayer1 != NULL)
		{
			disposeSprite(g_pPlayer1[i]);
			g_pPlayer1[i] = NULL;
		}
	}
	//背景の画像が作成されていたら描画する
	if (g_pBackground != NULL)
	{
		disposeSprite(g_pBackground);
		g_pBackground = NULL;
	}
	//雲が存在している時だけ描画する
	if (g_pCloud != NULL)
	{
		disposeSprite(g_pCloud);
		g_pCloud = NULL;
	}
	//足場(S)が存在しているときだけ描画する
	for (int i = 0; i < PlatFormQuantityS; ++i)
	{
		if (g_pPlatFormS[i] != NULL)
		{
			disposeSprite(g_pPlatFormS[i]);
			g_pPlatFormS[i] = NULL;
		}
	}
	//足場(L)が存在しているときだけ削除する
	for (int i = 0; i < PlatFormQuantityL; ++i)
	{
		if (g_pPlatFormL[i] != NULL)
		{
			disposeSprite(g_pPlatFormL[i]);
			g_pPlatFormL[i] = NULL;
		}
	}
	//地面の画像が存在しているときだけ描画する
	for (int i = 0; i < GroundQuantity; ++i)
	{
		if (g_pGround[i] != NULL)
		{
			disposeSprite(g_pGround[i]);
			g_pGround[i] = NULL;
		}
	}
	//海の画像が存在しているときだけ描画する
	for (int i = 0; i < SeaQuantity; ++i)
	{
		if (g_pSea[i] != NULL)
		{
			disposeSprite(g_pSea[i]);
			g_pSea[i] = NULL;
		}
	}
	//敵の画像が存在しているときだけ破棄する
	for (int i = 0; i < EnemyQuantity; ++i)
	{
		if (g_pEnemy[i] != NULL)
		{
			disposeSprite(g_pEnemy[i]);
			g_pEnemy[i] = NULL;
		}
	}

	//魚の画像が存在している時だけ破棄する
	if (g_pFish != NULL)
	{
		disposeSprite(g_pFish);
		g_pFish = NULL;
	}

	//雷ボールが存在している時だけ破棄する
	for (int i = 0; i < ThunderQuantity; ++i)
	{
		if (g_pThunder != NULL)
		{
			disposeSprite(g_pThunder[i].obj);
			g_pThunder[i].obj = NULL;
		}
	}
	//数字の画像が存在している時だけ破棄する
	if (g_pNumber != NULL)
	{
		disposeFont(g_pNumber);
		g_pNumber = NULL;
	}
	//スコアの画像が存在している時だけ破棄する
	if (g_pScore != NULL)
	{
		disposeFont(g_pScore);
		g_pScore = NULL;
	}
	// Topの画像がNULLの時画像を破棄する
	if (g_pTop != NULL)
	{
		disposeSprite(g_pTop);
		g_pTop = NULL;
	}
	// Iの画像がNULLの時画像を破棄する
	if (g_pI != NULL)
	{
		disposeSprite(g_pI);
		g_pI = NULL;
	}

	//g_pFoamの画像が作成されているときのみ画像を破棄する
	for (int i = 0; i < FoamQuantity; ++i)
	{
		if (g_pFoam[i] != NULL)
		{
			disposeSprite(g_pFoam[i]);
			g_pFoam[i] = NULL;
		}
	}
	//プレイヤーの残機の画像が作成されていたら削除する
	for (int i = 0; i < PlayerRMQuantity; ++i)
	{
		if (g_pPlayer_RM[i] != NULL)
		{
			disposeSprite(g_pPlayer_RM[i]);
			g_pPlayer_RM[i] = NULL;
		}
	}
	// g_pGameOverが作成されている場合のみ破棄する
	if (g_pGameOver != NULL)
	{
		// ゲームオーバー画面の画像を破棄する
		disposeSprite(g_pGameOver);
		g_pGameOver = NULL;
	}
	//各値のリセット
	//プレイヤーを止める関数のリセット
	bPlayerStop = false;
	//プレイヤーの変数のリセット
	iPlayerResidue = 3;
	PlayerBalloon = 2;

	//敵の関数のリセット
	for (int i = 0; i < EnemyType02_02; ++i)
	{
		enemyBalloonIsBroken[i] = true;
		enemyIsDead[i] = false;
		enemyPumpBalloon[i] = false;
		enemyPumpBalloonCDCounter[i] = 0;
		enemyPumpBalloonCounter[i] = 0;
		EnemyDeadAnimeCounter[i] = 0;
		enemyDeadFalling[i] = false;
		Enemy_Defeat[i] = false;
		iEnemyStrong[i] = 0;
		EnemyDeadUp[i] = 0;
		PosGetSea[i] = false;
	}
	Enemy1 = { {0.0f,0.0f},false,0,0 };
	Enemy2 = { {0.0f,0.0f},false,0,0 };
	Enemy3 = { {0.0f,0.0f},false,0,0 };
	//雷の値のリセット
	ThunderSpawnCounter = 0;
	ThunderSpawning = false;
	ThunderSpawnCD = NULL;
}