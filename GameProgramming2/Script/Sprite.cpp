//----------------------------------------------------------
// ファイル名		：Sprite.cpp
// 概要				：画像UV座標の配列を複数配列用意
// 作成者			：21CU0315 黄卓賢
// 更新内容			：2022/03/02 21CU0315 黄卓賢 作成
//					：2022/03/24 21cu0321 田中翔太　スコアのUV座標の配列を複数配列用意
//----------------------------------------------------------

#include "stdafx.h"
#include "CActionGameApp.h"
#include "GameResource.h"
#include "UV.h"

/**
 * 関数名 : createSprite()
 * 処理内容 : 指定されたパスにある画像を、指定されたサイズで作成する
 * 引数 :	path_		画像のあるパス
 *			width_		作成する画像の幅
 *			height_		作成する画像の高さ
 * 戻り値 : 作成した画像を管理するオブジェクト
 */
CPicture* CActionGameApp::createSprite (LPCWSTR path_, float width_, float height_)
{
	vector <QuadrangleTexel>  singleTexels = {
	QuadrangleTexel{ { 0, 1.0f },{ 0, 0.0f },{ 1, 1.0f },{ 1, 0.0f } }	// 指定するUV座標が一つの配列
	};
	XMFLOAT2 spriteSize = { width_, height_};
	CPicture* object = NULL;
	
	//Player1の場合、指定するUV座標の配列を複数配列用意
	if (path_ == Tex_Player1)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// スプライトの位置
			spriteSize,					// スプライトのサイズ
			kTexelPlayer1);				// 指定するUV座標の配列
	}
	//Enemyの場合、指定するUV座標の配列を複数配列用意
	else if (path_ == Tex_Enemy)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// スプライトの位置
			spriteSize,					// スプライトのサイズ
			kTexelEnemy);				// 指定するUV座標の配列
	}

	//GreenEnemyの場合、指定するUV座標の配列を複数配列用意
	//else if (path_ == Tex_GreenEnemy)
	//{
	//	object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
	//		{ 0.0f, 0.0f, 0.0f, 0.0f },	// スプライトの位置
	//		spriteSize,					// スプライトのサイズ
	//		kTexelGreenEnemy);				// 指定するUV座標の配列
	//}
	
	//WhiteEnemyの場合、指定するUV座標の配列を複数配列用意
	//else if (path_ == Tex_WhiteEnemy)
	//{
	//	object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
	//		{ 0.0f, 0.0f, 0.0f, 0.0f },	// スプライトの位置
	//		spriteSize,					// スプライトのサイズ
	//		kTexelWhiteEnemy);				// 指定するUV座標の配列
	//}
	

	//Fishの場合、指定するUV座標の配列を複数配列用意
	else if (path_ == Tex_Fish)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// スプライトの位置
			spriteSize,					// スプライトのサイズ
			kTexelFish);				// 指定するUV座標の配列
	}

	//Waterの場合、指定するUV座標の配列を複数配列用意
	//else if (path_ == Tex_Water)
	//{
	//	object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
	//		{ 0.0f, 0.0f, 0.0f, 0.0f },	// スプライトの位置
	//		spriteSize,					// スプライトのサイズ
	//		kTexelWater);				// 指定するUV座標の配列
	//}
	
	//Thunderの場合、指定するUV座標の配列を複数配列用意
	else if (path_ == Tex_Thunder)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// スプライトの位置
			spriteSize,					// スプライトのサイズ
			kTexelThunder);				// 指定するUV座標の配列
	}
	//Thunderの本体の場合、指定するUV座標の配列を複数配列用意
	else if (path_ == Tex_ThunderBody)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// スプライトの位置
			spriteSize,					// スプライトのサイズ
			kTexelThunderBody);				// 指定するUV座標の配列
	}
	//オープニングのバルーンの指定するUV座標の配列を複数配列用意
	else if (path_ == Tex_OpningBallon)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// スプライトの位置
			spriteSize,					// スプライトのサイズ
			kTexelOpningBalloon);				// 指定するUV座標の配列
	}

	else
	{
	object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
		{ 0.0f, 0.0f, 0.0f, 0.0f },	// スプライトの位置
		spriteSize,					// スプライトのサイズ
		singleTexels);				// 指定するUV座標の配列
	}
	return object;
}

//Scoreの場合、指定するUV座標の配列を複数配列用意
CFont* CActionGameApp::createFont(LPCWSTR path_, int digits_, float width_, float height_)
{
	XMFLOAT2 spriteSize = { width_, height_ };
	CFont* objects = NULL;
	


	// スコア
	objects = CFont::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
		{ 0.0f, 0.0f, 0.0f, 0.0f },	// スプライトの位置
		spriteSize,					// スプライトのサイズ
		kTexelIScore,			// 指定するUV座標の配列
		digits_);				//　桁数

	return objects;
}
