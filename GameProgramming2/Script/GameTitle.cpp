#include "CActionGameApp.h"
#include "GameResource.h"


/*
 * タイトルの処理を行う部分
 */
void CActionGameApp::procTitle()
{
	switch (g_GamePhase)
	{
		//画像の作成用のフェーズ
		case eBegin:
		{
			//背景画像の作成
			if (BackGround == NULL)
			{
				BackGround = createSprite(Tex_BackBack);
			}
			//タイトル画面のバルーンの作成
			if (g_pTitleBalloon == NULL)
			{
				g_pTitleBalloon = createSprite(Tex_OpningBallon ,31.0f,55.0f );
				g_pTitleBalloon->setPos(-280.0f, -120.0f);
			}
			//次のフェーズへ移行
			g_GamePhase = eMain;
		}
		break;
		//メインフェーズ
		case eMain:
		{

			//Xキーの入力で次のフェーズへ移行
			if (getInput()->isPressedOnce(DIK_X))
			{
				//eEndの代入
				g_GamePhase = eEnd;
				//Playのフローに進む
				//(GamePlay.cpp)
				g_NextStatusFromGame = ePlaying;
			}
			//下キー入力で下に移動
			if (getInput()->isPressedOnce(DIK_DOWNARROW))
			{
				if (bBalloonUPOrDOWN == false)
				{
					g_pTitleBalloon->setPos(g_pTitleBalloon->getPos().x, g_pTitleBalloon->getPos().y - 70.0f);
					++BalloonUPDOWN;
				}
				if (BalloonUPDOWN == 2)
				{
					bBalloonUPOrDOWN = true;
				}
			}
			//上キー入力で下に移動
			if (getInput()->isPressedOnce(DIK_UPARROW))
			{
				if (bBalloonUPOrDOWN == true)
				{
					g_pTitleBalloon->setPos(g_pTitleBalloon->getPos().x, g_pTitleBalloon->getPos().y + 70.0f);
					--BalloonUPDOWN;
				}
				if (BalloonUPDOWN == 0)
				{
					bBalloonUPOrDOWN = false;
				}
			}


			//アニメーション用の関数の加算
			++iBalloonAnimation;
			//アニメーションをされる
			if (iBalloonAnimation == 10)
			{
				g_pTitleBalloon->setAnimation(iBalloonAnmSet);
				//アニメーションの設定
				if (bBalloonAnm == false)
				{
					iBalloonAnmSet++;
					//アニメーションが3になったら変数を変更
					if (iBalloonAnmSet == 3)
					{
						bBalloonAnm = true;
					}
				}
				else
				{
					iBalloonAnmSet--;
					//アニメーションが0になったら変数を変更
					if (iBalloonAnmSet == 0)
					{
						bBalloonAnm = false;
					}
				}

				//変数のリセット
				iBalloonAnimation = 0;
			}

			//背景の画像を表示する
			if (BackGround != NULL)
			{
				renderSprite(BackGround);
			}
			//バルーンの画像を表示する
			if (g_pTitleBalloon != NULL)
			{
				renderSprite(g_pTitleBalloon);
			}
		}
		break;
		//画像の破棄及びフローの変更用フェーズ
		case eEnd:
		{
			//背景の画像を破棄し
			//NULLを代入する
			if (BackGround != NULL)
			{
				disposeSprite(BackGround);
				BackGround = NULL;
			}
			//バルーンの画像を破棄する
			if (g_pTitleBalloon != NULL)
			{
				disposeSprite(g_pTitleBalloon);
				g_pTitleBalloon = NULL;
			}

			//次のフローに進む
			SetNextGameStatus(g_NextStatusFromGame);

		}
		break;
	}
}