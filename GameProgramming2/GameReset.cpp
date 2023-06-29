//----------------------------------------------------------
// ファイル名		：GameReset
// 概要				：ゲームが終了した後、再開するために変数をリセットする
// 作成者			：21CU0315
// 更新内容			：2022/03/31　黄卓賢 作成
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::GameReset()
{
	//バルーンのアニメーション用変数
	iBalloonAnimation = 0;
	//アニメーションのセットよう変数
	iBalloonAnmSet = 0;
	//アニメーションの上がり下がり
	bBalloonAnm = false;
	//バルーンの上がり下がり
	BalloonUPDOWN = 0;
	//バルーンが上に行くか下に行くか
	bBalloonUPOrDOWN = false;

	resetPlayerFishPos = false;

	//ゲームオーバーカウンター
	GameOvercounter = 0;

	
	// スコア値
	g_number = 0;
	// スコア(二つ目)------------------------------------------
	// 二つ目のスコアの変数はIScoreにしました。
	// スコア値
	g_score = 0;

	
	//---------------------------------------------------------------------------------
	// 	//プレイヤーの横移動の速度のカウンター
	horiSpeedCounter = 0;

	//加速の最初に遅延を入れるための変数
	SpeedUpStart = 0;
	//加速の最初の遅延を入れるための変数（空中横移動）
	SpeedUpStart1 = 0;

	//プレイヤーの横移動の速度
	playerHoriSpeed = 0.0f; //　右に行くときは+　、左に行くときは-
	//プレイヤーの空中横移動の速度
	playerHoriSpeed1 = 0.0f;  //　右に行くときは+　、左に行くときは-　　　

	//プレイヤーのジャンプ力
	g_jumpPower = 0.0f;
	//プレイヤーのジャンプ力の上限
	g_jumpPowerMax = 3.5f;
	//ジャンプの総移動量
	g_jumpMove = 0.0f;
	//ジャンプの上昇フラグ
	g_isJumpRise = false;

	//重力のカウンター
	g_gravCounter = 0;
	//ジャンプ、重力の計算用
	g_changeGrav = 0.0f;
	

	//重力の処理
	moveY = 0.0f;
	//重力がかかるまでの時間用変数
	PlayerGravDownTime = 0;

	//プレイヤーの残機
	iPlayerResidue = 3;
	//プレイヤーのバルーンの数
	PlayerBalloon = 2;
	//プレイヤーが操作可能かどうか
	PlayerDieBalloon = false;
	//プレイヤーの無敵判定
	PlayerInvincible = false;


	//-------------------------------------------------------------------------------
	
	for (int i = 0; i < 3; ++i)
	{
		//敵が撃破されたかどうかの判定用
		Enemy_Defeat[i] = false;
		//ステータスの変更用
		EnemyStateChange[i] = 0;
		//敵の行動の段階を指定する変数
		enemyMovementStage[i] = 1;
		//敵のバルーンが破壊されたかどうかを判定用
		enemyBalloonIsBroken[i] =  true;
		//敵が死んだかどうかを判定用
		enemyIsDead[i] =false;
		//敵が落下するときアニメーション用カウンター
		enemyFallingCounter[i] = 0;
		//敵が落下しているかどうかの判定用
		enemyDeadFalling[i] = false;
		//敵のバルーンが割れた時、地面に当たった後にバルーンを作り直すタイミングのカウンター
		enemyPumpBalloonCDCounter[i] = 0;
		//敵がバルーンを作るアニメーション用カウンター
		enemyPumpBalloonCounter[i] = 0;
		//敵がバルーンを作っているかどうかの判定用
		enemyPumpBalloon[i] = false;
		//敵が死んだときに上に上がる範囲用
		EnemyDeadUp[i] = 0;
		//敵が死んだときのアニメーション用カウンター
		EnemyDeadAnimeCounter[i] = 0;

		iEnemyStrong[i] = 0;

		//座標を取得したかの判定用
		PosGetSea[i] = false;
		//敵が着地しているかどうかの判定用
		enemyOnGround[i] = true;
	}
	
	
	iEnemy_Start_Time = 0;
	bEnemyTimeUp = false;
	iEnemyTimeUp = 0;
	
	
	


	

	//-----------------------------------------------------------------------------------
	//魚の処理
	//プレイヤーが魚に捕まれた
	playerCaughtByFish = false;
	//敵が魚に捕まった時
	enemyCaughtByFish = false;
	//魚が上がり始めた
	fishStartedMoving = false;
	//魚のカウンター
	fishCounter = 1;

	//プレイヤーが死ぬときアニメーション用
	playerDeathAnimeCounter = 0;
	playerDeathGoUpCounter = 0;
	//プレイヤーが死んだかどうかを判定する用カウンター
	playerIsDead = false;

	//プレイヤーがジャンプする時のアニメーション用
	playerJumpAnimIndex = 0;
	startPlayerJumpAnimCounter = false;
	//死んだ敵の数
	noOfDeadEnemy = 0;

	

	

	//-----------------------------------------------------------------------------
	//プレイヤーの残機の個数
	PlayerRMQuantity = 2;

	//雷ボールが生成し始める前の時間を計算する
	ThunderSpawnCounter = 0;
	//雷ボールが生成したら、trueを代入する
	ThunderSpawning = false;



	

	PlayerIsKilledByThunder = false;

	//ゲームクリア時にプレイヤーを止める関数
	bPlayerStop = false;
}