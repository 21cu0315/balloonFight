//----------------------------------------------------------
// �t�@�C����		�FSprite.cpp
// �T�v				�F�摜UV���W�̔z��𕡐��z��p��
// �쐬��			�F21CU0315 ���쌫
// �X�V���e			�F2022/03/02 21CU0315 ���쌫 �쐬
//					�F2022/03/24 21cu0321 �c���đ��@�X�R�A��UV���W�̔z��𕡐��z��p��
//----------------------------------------------------------

#include "stdafx.h"
#include "CActionGameApp.h"
#include "GameResource.h"
#include "UV.h"

/**
 * �֐��� : createSprite()
 * �������e : �w�肳�ꂽ�p�X�ɂ���摜���A�w�肳�ꂽ�T�C�Y�ō쐬����
 * ���� :	path_		�摜�̂���p�X
 *			width_		�쐬����摜�̕�
 *			height_		�쐬����摜�̍���
 * �߂�l : �쐬�����摜���Ǘ�����I�u�W�F�N�g
 */
CPicture* CActionGameApp::createSprite (LPCWSTR path_, float width_, float height_)
{
	vector <QuadrangleTexel>  singleTexels = {
	QuadrangleTexel{ { 0, 1.0f },{ 0, 0.0f },{ 1, 1.0f },{ 1, 0.0f } }	// �w�肷��UV���W����̔z��
	};
	XMFLOAT2 spriteSize = { width_, height_};
	CPicture* object = NULL;
	
	//Player1�̏ꍇ�A�w�肷��UV���W�̔z��𕡐��z��p��
	if (path_ == Tex_Player1)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// �X�v���C�g�̈ʒu
			spriteSize,					// �X�v���C�g�̃T�C�Y
			kTexelPlayer1);				// �w�肷��UV���W�̔z��
	}
	//Enemy�̏ꍇ�A�w�肷��UV���W�̔z��𕡐��z��p��
	else if (path_ == Tex_Enemy)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// �X�v���C�g�̈ʒu
			spriteSize,					// �X�v���C�g�̃T�C�Y
			kTexelEnemy);				// �w�肷��UV���W�̔z��
	}

	//GreenEnemy�̏ꍇ�A�w�肷��UV���W�̔z��𕡐��z��p��
	//else if (path_ == Tex_GreenEnemy)
	//{
	//	object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
	//		{ 0.0f, 0.0f, 0.0f, 0.0f },	// �X�v���C�g�̈ʒu
	//		spriteSize,					// �X�v���C�g�̃T�C�Y
	//		kTexelGreenEnemy);				// �w�肷��UV���W�̔z��
	//}
	
	//WhiteEnemy�̏ꍇ�A�w�肷��UV���W�̔z��𕡐��z��p��
	//else if (path_ == Tex_WhiteEnemy)
	//{
	//	object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
	//		{ 0.0f, 0.0f, 0.0f, 0.0f },	// �X�v���C�g�̈ʒu
	//		spriteSize,					// �X�v���C�g�̃T�C�Y
	//		kTexelWhiteEnemy);				// �w�肷��UV���W�̔z��
	//}
	

	//Fish�̏ꍇ�A�w�肷��UV���W�̔z��𕡐��z��p��
	else if (path_ == Tex_Fish)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// �X�v���C�g�̈ʒu
			spriteSize,					// �X�v���C�g�̃T�C�Y
			kTexelFish);				// �w�肷��UV���W�̔z��
	}

	//Water�̏ꍇ�A�w�肷��UV���W�̔z��𕡐��z��p��
	//else if (path_ == Tex_Water)
	//{
	//	object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
	//		{ 0.0f, 0.0f, 0.0f, 0.0f },	// �X�v���C�g�̈ʒu
	//		spriteSize,					// �X�v���C�g�̃T�C�Y
	//		kTexelWater);				// �w�肷��UV���W�̔z��
	//}
	
	//Thunder�̏ꍇ�A�w�肷��UV���W�̔z��𕡐��z��p��
	else if (path_ == Tex_Thunder)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// �X�v���C�g�̈ʒu
			spriteSize,					// �X�v���C�g�̃T�C�Y
			kTexelThunder);				// �w�肷��UV���W�̔z��
	}
	//Thunder�̖{�̂̏ꍇ�A�w�肷��UV���W�̔z��𕡐��z��p��
	else if (path_ == Tex_ThunderBody)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// �X�v���C�g�̈ʒu
			spriteSize,					// �X�v���C�g�̃T�C�Y
			kTexelThunderBody);				// �w�肷��UV���W�̔z��
	}
	//�I�[�v�j���O�̃o���[���̎w�肷��UV���W�̔z��𕡐��z��p��
	else if (path_ == Tex_OpningBallon)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// �X�v���C�g�̈ʒu
			spriteSize,					// �X�v���C�g�̃T�C�Y
			kTexelOpningBalloon);				// �w�肷��UV���W�̔z��
	}

	else
	{
	object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
		{ 0.0f, 0.0f, 0.0f, 0.0f },	// �X�v���C�g�̈ʒu
		spriteSize,					// �X�v���C�g�̃T�C�Y
		singleTexels);				// �w�肷��UV���W�̔z��
	}
	return object;
}

//Score�̏ꍇ�A�w�肷��UV���W�̔z��𕡐��z��p��
CFont* CActionGameApp::createFont(LPCWSTR path_, int digits_, float width_, float height_)
{
	XMFLOAT2 spriteSize = { width_, height_ };
	CFont* objects = NULL;
	


	// �X�R�A
	objects = CFont::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
		{ 0.0f, 0.0f, 0.0f, 0.0f },	// �X�v���C�g�̈ʒu
		spriteSize,					// �X�v���C�g�̃T�C�Y
		kTexelIScore,			// �w�肷��UV���W�̔z��
		digits_);				//�@����

	return objects;
}
