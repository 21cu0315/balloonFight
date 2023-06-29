//----------------------------------------------------------
// ファイル名		：Enemy_Start_Time.cpp
// 概要				：敵が動き出すまでの時間
// 作成者			：21CU0118　小池慎之介
// 更新内容			：2022/03/14　小池慎之介作成
//----------------------------------------------------------
#include "CActionGameApp.h"

bool CActionGameApp::Enemy_Start_Time()
{
	//約3秒間敵を硬直させる
	++iEnemyTimeUp;
	//判定
	if (iEnemyTimeUp == 180)
	{
		return true;
	}
	//それ以外
	return false;
}