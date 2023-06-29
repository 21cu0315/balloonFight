//----------------------------------------------------------
// ファイル名		：PlayerRedisiue()
// 概要				：プレイヤーの残機の処理
// 作成者			：21cu0118 小池慎之介
// 更新内容			：2022/03/28 21cu0118 小池慎之介 作成
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::PlayerResidue()
{
	//プレイヤーの残機の減少によって画像を削除する
	if (g_pPlayer_RM[1] != NULL)
	{
		if (iPlayerResidue == 2)
		{
			//残機の画像を一つ消す
			disposeSprite(g_pPlayer_RM[1]);
			g_pPlayer_RM[1] = NULL;
		}
	}
	if (g_pPlayer_RM[0] != NULL)
	{
		if (iPlayerResidue == 1)
		{
			//残機の画像を一つ消す
			disposeSprite(g_pPlayer_RM[0]);
			g_pPlayer_RM[0] = NULL;
		}
	}
}