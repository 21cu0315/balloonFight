//----------------------------------------------------------
// �t�@�C����		�FPlayerRedisiue()
// �T�v				�F�v���C���[�̎c�@�̏���
// �쐬��			�F21cu0118 ���r�T�V��
// �X�V���e			�F2022/03/28 21cu0118 ���r�T�V�� �쐬
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::PlayerResidue()
{
	//�v���C���[�̎c�@�̌����ɂ���ĉ摜���폜����
	if (g_pPlayer_RM[1] != NULL)
	{
		if (iPlayerResidue == 2)
		{
			//�c�@�̉摜�������
			disposeSprite(g_pPlayer_RM[1]);
			g_pPlayer_RM[1] = NULL;
		}
	}
	if (g_pPlayer_RM[0] != NULL)
	{
		if (iPlayerResidue == 1)
		{
			//�c�@�̉摜�������
			disposeSprite(g_pPlayer_RM[0]);
			g_pPlayer_RM[0] = NULL;
		}
	}
}