/**
* @file CActionGameApp.h
* @author 織戸　喜隆
* @date 日付（2017.02.14）
*/
#pragma once

#include "stdafx.h"
#include "CApplication.h"
#include "CPicture.h"
#include "MediaResource.h"
#include "UVAnimation.h"
#include "CFont.h"
// --------------------------------------------
// 枠内は細田弥卯が記述（2021_09_29）
#include "CSound.h"
// --------------------------------------------

#define SeaPosY -(WINDOW_HEIGHT / 2.0) + 40.0f
#define GroundPosY -(WINDOW_HEIGHT / 2.0) + 104.0f
#define PlatFormPosY -112.0f
#define EnemyType01_01 0 
#define EnemyType01_02 1
#define EnemyType02_01 2
#define EnemyType02_02 3
#define EnemyType03_01 4 
#define EnemyType03_02 5

#define PlayerAnimation 0

#define EnemyOutLine 20.0f
#define EnemyBalloonCeckCnt 3

#define EnemyStage1 1
#define EnemyStage2 2
#define EnemyStage3 3

class CActionGameApp :
	public CApplication
{
	typedef CApplication super;
private:
	int m_activeEnemies = 0;

	CPicture* createSprite(LPCWSTR path_, float width_ = WINDOW_WIDTH, float height_ = WINDOW_HEIGHT);
	void renderSprite(CPicture* object);
	void renderSprite(CPicture* object, XMFLOAT3 color);
	void renderSprite(CPicture* object, float r, float g, float b);
	void renderSprite(CPicture* object, XMFLOAT4 color);
	void disposeSprite(CPicture* object);
	CFont* createFont(LPCWSTR path_, int digits_, float width_, float height_);
	void renderFont(CFont* object, int num_);
	void disposeFont(CFont* object);
	bool createSpaceship(void);
	void initCameraInfo();
	void doOpenning();
	void doPlaying();
	void doGameClear();
	void doGameOver();
	void doEnding();

	void procTitle();
	void procGame();
	void procClear();
	void procGameOver();

	// --------------------------------------------
	// 枠内は細田弥卯が記述（2021_09_29）

	CSound* createSound(const char* filePath_, const bool loop_ = false);
	void PlaySourceSound(CSound* const objects);
	void disposeSound(CSound* const objects);
	// --------------------------------------------

	// 課題用関数
	void procTitleBegin();
	void procTitleMain();
	void procTitleEnd();
	void procPlayBegin();
	void procPlayMain();
	void procPlayEnd();
	void procClearBegin();
	void procClearMain();
	void procClearEnd();
	void procOverBegin();
	void procOverMain();
	void procOverEnd();


	//プレイヤーの行動処理用変数
	void PlayerAction();
	//プレイヤーのジャンプの処理
	void PlayerJump();
	//プレイヤーの画面外の処理
	void PlayerOffScreen();
	//プレイヤーの横移動の処理
	void PlayerMove();
	//プレイヤーの当たり判定
	void PlayerCollusionDetection();
	//プレイヤーが死んだときの落下処理
	void PlayerDieActionActive();
	//プレイヤーの残機の処理
	void PlayerResidue();

	//敵の行動処理用
	void EnemyAction();
	//敵の動き(1段階目)
	void EnemyFly1();
	//敵が動き出す時間の測定のための関数
	bool Enemy_Start_Time();
	//敵とプレイヤーの当たり判定
	void PECollusionDetection();
	//敵の画面外の行動
	void EnemyOffScreen();
	//敵の当たり判定
	void EnemyCollisionDetection();
	//敵のバルーンを破壊したか
	void EnemyBalloonBreak();
	//敵のバルーンを破壊した後の行動
	void EnemyNotBalloon();
	//敵が死んだときの処理
	void EnemyDead();
	//敵が海に落ちたときの泡の位置を調整する関数
	void EnemySeaDrop();
	//敵が落下および海に落ちたときに出てくる泡の処理
	void EnemyFoam();


	//雷ボールの処理
	void Thunder();
	//雷ボールの方向
	void ThunderDirection(int noOfThunder);
	//魚の処理
	void Fish();

	//呼び出すだけで残機以外の全ての値をリセットする関数
	void AllReset();

	//ゲームの終了用関数
	void GameClearSet();

	//ゲームが終了した後、再開するために変数をリセットする
	void GameReset();


public:
	CActionGameApp();
	~CActionGameApp();
	void render(XMFLOAT4X4 matView, XMFLOAT4X4 matProj);
	void release();


private:

	//タイトル画面を管理する変数
	CPicture* BackGround = NULL;
	//タイトル画面のバルーンを管理する変数
	CPicture* g_pTitleBalloon = NULL;
	//バルーンのアニメーション用変数
	int iBalloonAnimation = 0;
	//アニメーションのセットよう変数
	int iBalloonAnmSet = 0;
	//アニメーションの上がり下がり
	bool bBalloonAnm = false;
	//バルーンの上がり下がり
	int BalloonUPDOWN = 0;
	//バルーンが上に行くか下に行くか
	bool bBalloonUPOrDOWN = false;




	//ゲーム画面のフェーズを管理する変数
	ePhase g_GamePhase = eBegin;
	//ゲーム画面から次へ進むときのフローを管理する変数
	eGameStatus g_NextStatusFromGame = eNone;




	//----------------------------------------------------------------------------------
		//背景の画像を管理する変数
	CPicture* g_pBackground = NULL;


	//プレイヤーの画像の個数
	int PlayerQuantity = 2;
	//プレイヤー①の画像を管理する変数
	CPicture* g_pPlayer1[2] = { NULL,NULL };
	//プレイヤーの表示サイズ
	const float PLAYER_SIZE_X = 64.0f;
	const float PLAYER_SIZE_Y = 96.0f;
	//プレイヤーの初期座標
	XMFLOAT2 PlayerSet[2] =
	{
		{-400.0f, -300.0f},
		{-400.0f + WINDOW_WIDTH,-300.0f},
	};

	//敵の画像の個数
	int EnemyQuantity = 6;
	//敵の画像を管理する変数
	CPicture* g_pEnemy[6] = { NULL,NULL };
	//敵の画像の表示サイズ
	const float ENEMY_SIZE_X = 64.0f;
	const float ENEMY_SIZE_Y = 96.0f;
	XMFLOAT2 EnemySet[6] =
	{
		{-150.0f,-36.0f},
		{-150.0f + WINDOW_WIDTH,-36.0f},
		{0.0f,-36.0f},
		{0.0f + WINDOW_WIDTH,-36.0f},
		{150.0f,-36.0f},
		{150.0f + WINDOW_WIDTH,-36.0f},
	};
	//敵がゲームに存在している数
	int Enemy_Number = 3; //基本3体


	//海の画像の個数
	int SeaQuantity = 9;
	//海の画像を管理する変数
	CPicture* g_pSea[9] = { NULL, NULL };
	//海の画像の大きさの管理
	const float SEA_SIZE_X = 124.0f;
	const float SEA_SIZE_Y = 80.0f;
	//海の画像の座標
	XMFLOAT2 SeaSet[9] =
	{
		{0.0f,SeaPosY},
		{SEA_SIZE_X,SeaPosY},
		{SEA_SIZE_X * 2,SeaPosY},
		{SEA_SIZE_X * 3,SeaPosY},
		{SEA_SIZE_X * 4,SeaPosY},
		{-SEA_SIZE_X,SeaPosY},
		{-SEA_SIZE_X * 2,SeaPosY},
		{-SEA_SIZE_X * 3,SeaPosY},
		{-SEA_SIZE_X * 4,SeaPosY},
	};

	//足場の個数
	int PlatFormQuantityL = 6;
	//足場(L)の画像を管理する変数
	CPicture* g_pPlatFormL[6] = { NULL,NULL };
	//足場(L)の大きさの管理
	const float PLATFORML_SIZE_X = 64.0f;
	const float PLATFORML_SIZE_Y = 32.0f;
	//足場(L)の座標
	XMFLOAT2 PlatFormSetL[6] =
	{
		{PLATFORML_SIZE_X / 2,-100.0f},
		{(PLATFORML_SIZE_X / 2) + PLATFORML_SIZE_X,-100.0f},
		{(PLATFORML_SIZE_X / 2) + (PLATFORML_SIZE_X * 2),-100.0f},
		{-PLATFORML_SIZE_X / 2,-100.0f},
		{-(PLATFORML_SIZE_X / 2) - PLATFORML_SIZE_X,-100.0f},
		{-(PLATFORML_SIZE_X / 2) - (PLATFORML_SIZE_X * 2),-100.0f},
	};

	//足場Sの個数
	int PlatFormQuantityS = 2;
	//足場(S)の画像を管理する変数
	CPicture* g_pPlatFormS[2] = { NULL, NULL };
	//足場(S)の大きさの管理
	const float PLATFORMS_SIZE_ALL = 32.0f;
	//足場(S)の座標の管理
	XMFLOAT2 PlatFormSetS[2] =
	{
		{PLATFORML_SIZE_X * 3.0f + PLATFORMS_SIZE_ALL / 2 , -100.0f},
		{-PLATFORML_SIZE_X * 3.0f - PLATFORMS_SIZE_ALL / 2, -100.0f},
	};

	//地面の画像の個数
	int GroundQuantity = 8;
	//地面の画像を管理する変数
	CPicture* g_pGround[8] = { NULL,NULL };
	//地面の大きさの管理
	const float GROUND_SIZE_X = 64.0f;
	const float GROUND_SIZE_Y = 72.0f;
	//地面の座標の管理
	XMFLOAT2 GroundSet[8] =
	{
		{(WINDOW_WIDTH / 2) - 32.0f,GroundPosY},
		{(WINDOW_WIDTH / 2) - (24.0f + GROUND_SIZE_Y),GroundPosY},
		{(WINDOW_WIDTH / 2) - (16.0f + (GROUND_SIZE_Y * 2)),GroundPosY},
		{(WINDOW_WIDTH / 2) - (8.0f + (GROUND_SIZE_Y * 3)),GroundPosY},
		{-(WINDOW_WIDTH / 2) + 32.0f,GroundPosY},
		{-(WINDOW_WIDTH / 2) + (24.0f + GROUND_SIZE_Y),GroundPosY},
		{-(WINDOW_WIDTH / 2) + (16.0f + (GROUND_SIZE_Y * 2)),GroundPosY},
		{-(WINDOW_WIDTH / 2) + (8.0f + (GROUND_SIZE_Y * 3)),GroundPosY},
	};

	//雲の画像を管理する変数
	CPicture* g_pCloud = NULL;
	//雲の画像の大きさの管理
	const float CLOUD_SIZE_X = 124.0f;
	const float CLOUD_SIZE_Y = 120.0f;
	//雲の座標
	XMFLOAT2 CloudSet = { 90.0f,200.0f };

	//雷ボールを管理する構造体
	struct ThunderData
	{
		CPicture* obj;		//画像管理用
		XMFLOAT2 beginPos;			//初期座標
		float thunderMoveX;			//横移動の値
		float thunderMoveY;			//縦移動の値
		int thunderDirRand;			//方向を決める乱数の変数
		bool isMoving;		//雷ボールが動いているかを判断する変数
	};

	//雷ボールの画像の数
	int ThunderQuantity = 2;
	//雷ボールの画像の大きさの管理
	const float THUNDER_SIZE_X = 40.0f;
	const float THUNDER_SIZE_Y = 40.0f;
	//雷ボールの座標
	ThunderData g_pThunder[2] =
	{
		{NULL,{90.0f,200.0f},0.0f,0.0f,0,false},
		{NULL,{90.0f,200.0f},0.0f,0.0f,0,false},
	};
	//雷本体の画像用の変数
	CPicture* g_pThunderBody = NULL;
	//雷本体の保存用の位置用の変数
	XMFLOAT2 ThunderBodyPos = { 0.0f,800.0f };

	//魚の画像の管理用変数
	CPicture* g_pFish = NULL;
	//魚の画像の大きさの管理
	const float FISH_SIZE_X = 80.0f;
	const float FISH_SIZE_Y = 80.0f;
	//魚の座標
	XMFLOAT2 fishPos = { 0.0f,-440.0f };

	bool resetPlayerFishPos = false;

	// ゲームオーバー --------------------------------
	//フェーズ
	ePhase g_GameOverPhase = eBegin;
	//画像
	CPicture* g_pGameOver = NULL;
	//フロー
	eGameStatus g_NextStatusFromOver = eNone;
	//サイズ
	float GAMEOVER_SIZE_X;
	float GAMEOVER_SIZE_Y;
	//ゲームオーバーカウンター
	int GameOvercounter;

	// スコア------------------------------------------
	// スコアの画像を管理する変数
	CFont* g_pNumber = NULL;
	// スコア値
	int g_number = 0;
	// スコアの表示サイズ
	const float NUMBER_SIZE_X = 25.0f;
	const float NUMBER_SIZE_Y = 25.0f;

	// スコア(二つ目)------------------------------------------
	// 二つ目のスコアの変数はIScoreにしました。

	// スコアの画像を管理する変数
	CFont* g_pScore = NULL;
	// スコア値
	int g_score = 0;
	// スコアの表示サイズ
	const float SCORE_SIZE_X = 25.0f;
	const float SCORE_SIZE_Y = 25.0f;

	// Top-------------------------------------------------
	//Topの画像を管理する変数
	CPicture* g_pTop = NULL;
	// I-------------------------------------------------
	//I-の画像を管理する変数
	CPicture* g_pI = NULL;

	//---------------------------------------------------------------------------------
	// 	//プレイヤーの横移動の速度のカウンター
	int horiSpeedCounter = 0;
	///プレイヤーの横移動速度の上限値
	float SpeedLimit = 3.0f;
	//プレイヤーの空中横移動速度の上限値
	float SpeedLimit1 = 0.8f;

	//加速の最初に遅延を入れるための変数
	int SpeedUpStart = 0;
	//加速の最初の遅延を入れるための変数（空中横移動）
	int SpeedUpStart1 = 0;

	//プレイヤーの横移動の速度
	float playerHoriSpeed = 0.0f; //　右に行くときは+　、左に行くときは-
	//プレイヤーの空中横移動の速度
	float playerHoriSpeed1 = 0.0f;  //　右に行くときは+　、左に行くときは-　　　

	//プレイヤーのジャンプ力
	float g_jumpPower = 0.0f;
	//プレイヤーのジャンプ力の上限
	float g_jumpPowerMax = 3.5f;
	//ジャンプの総移動量
	float g_jumpMove = 0.0f;
	//ジャンプの上昇フラグ
	bool g_isJumpRise = false;

	//重力のカウンター
	int g_gravCounter = 0;
	//ジャンプ、重力の計算用
	float g_changeGrav = 0.0f;
	//下方向重力の処理
	const float GravLimi = -4.0f;

	//重力の処理
	float moveY = 0.0f;
	//重力がかかるまでの時間用変数
	int PlayerGravDownTime = 0;

	//プレイヤーの残機
	int iPlayerResidue = 3;
	//プレイヤーのバルーンの数
	int PlayerBalloon = 2;
	//プレイヤーが操作可能かどうか
	bool PlayerDieBalloon = false;
	//プレイヤーの無敵判定
	bool PlayerInvincible = false;


	//--------------------------------------------------------------------------------
	//敵の総移動速度代入(縦と横)
	float ENEMY_SPEED_X = 0.0f;
	float ENEMY_SPEED_Y = 0.0f;
	float ENEMY_SPEED_X2 = 0.0f;
	float ENEMY_SPEED_Y2 = 0.0f;
	float ENEMY_SPEED_X3 = 0.0f;
	float ENEMY_SPEED_Y3 = 0.0f;
	//敵の移動の最大値
	const float Enemy_Speed_Limit_X = 3.0f;
	const float Enemy_Speed_Limit_Y = 2.0f;
	const float Enemy_Speed_Limit_Balloon_X = 0.2f;
	//敵の行動を管理する構造体
	struct Enemy_Move
	{
		XMFLOAT2 PlayerPos; //プレイヤーの初期座標取得
		bool EnemyMoveTrue; //座標取得下かどうかの判定
		int EnemyMoveTime;	//取得までの時間
		int EnemyMove_2_3; //2段階目以降の一定時間敵が動かない時間
	};
	//敵1の行動用
	Enemy_Move Enemy1 = { {0.0f,0.0f},false,0,0 };
	Enemy_Move Enemy2 = { {0.0f,0.0f},false,0,0 };
	Enemy_Move Enemy3 = { {0.0f,0.0f},false,0,0 };
	//敵が撃破されたかどうかの判定用
	bool Enemy_Defeat[3] = { false,false,false };
	//ステータスの変更用
	int EnemyStateChange[3] = { 0,0,0 };
	//敵が動き出すまでの時間用の変数
	int iEnemy_Start_Time = 0;
	//一定時間が過ぎたかの判定用変数
	bool bEnemyTimeUp = false;
	//時間測定用の変数
	int iEnemyTimeUp = 0;
	//敵のバルーンが破壊された時に破壊された場所の座標を保存する変数
	XMFLOAT2 EnemyBreakBalloon[3] = { {0,0},{0,0},{0,0} };
	//座標を取得したかの判定用変数
	bool getPos_Enemy[3] = { false,false };
	//右に行くか左に行くかの判定
	//false = 左
	//true  = 右
	bool RightorLeft[3] = { false,false };


	//敵の行動の段階を指定する変数
	int enemyMovementStage[3] = { 1,1,1 };

	//-----------------------------------------------------------------------------------
	//魚の処理
	//プレイヤーが魚に捕まれた
	bool playerCaughtByFish = false;
	//敵が魚に捕まった時
	bool enemyCaughtByFish = false;
	//魚が上がり始めた
	bool fishStartedMoving = false;
	//魚のカウンター
	int fishCounter = 1;

	//プレイヤーが死ぬときアニメーション用
	int playerDeathAnimeCounter = 0;
	int playerDeathGoUpCounter = 0;
	//プレイヤーが死んだかどうかを判定する用カウンター
	bool playerIsDead = false;

	//プレイヤーがジャンプする時のアニメーション用
	int playerJumpAnimIndex = 0;
	bool startPlayerJumpAnimCounter = false;

	//敵のバルーンが破壊されたかどうかを判定用
	bool enemyBalloonIsBroken[3] = { true, true, true };
	//敵が死んだかどうかを判定用
	bool enemyIsDead[3] = { false,false, false };

	//敵が落下するときアニメーション用カウンター
	int enemyFallingCounter[3] = { 0,0,0 };
	//敵が落下しているかどうかの判定用
	bool enemyDeadFalling[3] = { false,false,false };
	//敵のバルーンが割れた時、地面に当たった後にバルーンを作り直すタイミングのカウンター
	int enemyPumpBalloonCDCounter[3] = { 0,0,0 };
	//敵がバルーンを作るアニメーション用カウンター
	int enemyPumpBalloonCounter[3] = { 0,0,0 };
	//敵がバルーンを作っているかどうかの判定用
	bool enemyPumpBalloon[3] = { false,false,false };

	//敵が死んだときに上に上がる範囲用
	int EnemyDeadUp[3] = { 0,0,0 };
	//敵が死んだときのアニメーション用カウンター
	int EnemyDeadAnimeCounter[3] = { 0,0,0 };
	//死んだ敵の数
	int noOfDeadEnemy = 0;
	
	int iEnemyStrong[3] = { 0,0 };

//-----------------------------------------------------------------------------
	//泡の画像の作成
	//泡の画像用の変数の作成
	CPicture* g_pFoam[3] = { NULL,NULL };
	//泡の画像用の座標管理用変数
	XMFLOAT2 FoamPos[3] = { {0,0},{0,0} };
	//泡の画像の個数の変数
	int FoamQuantity = 3;
	//泡のフレーム管理用変数
	int iFoamFleam[3] = { 0,0 };
	//左右のどちらに動くのかの決定用変数
	bool FoamRL[3] = { false,false };
	//泡の左右の揺れの代入用変数と
	//限界地
	float FoamMove_X[3] = { 0.0f,0.0f };
	float FoamMove_X_Limit = 1.0f;

//-----------------------------------------------------------------------------
	//座標を取得したかの判定用
	bool PosGetSea[3] = { false,false,false };



	//プレイヤーの残機の画像用の変数
	CPicture* g_pPlayer_RM[2] = { NULL , NULL };
	//プレイヤーの残機の個数
	int PlayerRMQuantity = 2;
	//プレイヤーの残機の座標
	XMFLOAT2 g_PlayerRM[2] = {
		{-170.0f , 420.0f},
		{-150.0f , 420.0f},
	};

	//雷ボールが生成し始める前の時間を計算する
	int ThunderSpawnCounter = 0;
	//雷ボールが生成したら、trueを代入する
	bool ThunderSpawning = false;
	//雷ボールの生成速度を管理するカウンター
	int ThunderSpawnCD = NULL;


	bool enemyOnGround[3] = { true,true,true };

	bool PlayerIsKilledByThunder = false;

	//ゲームクリア時にプレイヤーを止める関数
	bool bPlayerStop = false;
};