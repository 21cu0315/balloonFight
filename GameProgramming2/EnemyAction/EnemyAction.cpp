//----------------------------------------------------------
// ファイル名		：EnemyAction
// 概要				：敵の行動を管理するCPP
// 作成者			：21CU0118　小池慎之介
// 更新内容			：2022/03/15　小池慎之介　敵の行動を管理するcpp追加、EnemyFly1の削除
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyAction()
{
	//バルーンがない時の処理
	EnemyNotBalloon();
	//バルーンが破壊されたときの処理
	EnemyBalloonBreak();
	//敵の行動を管理する関数
	EnemyFly1();
	//敵の画面外の行動
	EnemyOffScreen();
	//敵の当たり判定
	EnemyCollisionDetection();
	//敵が海に落ちたときの処理
	EnemySeaDrop();
	//敵が死んだ時の処理
	EnemyDead();
}