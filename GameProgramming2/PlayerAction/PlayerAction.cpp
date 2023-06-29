#include "CActionGameApp.h"

/*
 * プレイヤーの行動を処理する関数
 *						:3月16日　小池慎之介 プレイヤーの残機処理の追加 プレイヤーが落ちる時、一定時間操作不能の状態の作成
*/
void CActionGameApp::PlayerAction()
{
	/*
	* 関数の呼び出し
	*/
	//ここにif文の追加
	//プレイヤーが動けるかどうかの判定用
	if (PlayerDieBalloon == false)
	{
		if (iPlayerResidue != 0)
		{
			//プレイヤーのジャンプの関数
			PlayerJump();
			//プレイヤーの画面外の処理
			PlayerOffScreen();
			//プレイヤーの横移動の処理
			PlayerMove();
			//プレイヤーの当たり判定
			PlayerCollusionDetection();
			//プレイヤーの残機の処理
			PlayerResidue();
		}
	}
	else 
	{
		//プレイヤーの死亡時の処理
		PlayerDieActionActive();
	}
}