//----------------------------------------------------------
// �t�@�C����		�FGameClearSet.cpp
// �T�v				�F�Q�[���̏I������
// �쐬��			�F21CU0118�@���r�T�V��
// �X�V���e			�F2022/03/31 ���r�T�V��@�쐬
//----------------------------------------------------------
#include "CactionGameApp.h"

void CActionGameApp::GameClearSet()
{
	//�Q�[���̏I������
	//�G���S�Ă��Ȃ��Ȃ�����
	for (int i = 0; i < EnemyQuantity; ++i)
	{
		if (g_pEnemy[i] != NULL)
		{
			//�G��1�̂ł��������Ă�����֐����I������
			return;
		}
	}
	//�v���C���[�����̏�ɂƂǂ߂�
	bPlayerStop = true;

	//x�L�[�Ń^�C�g���ɖ߂�
	if (getInput()->isPressedOnce(DIK_X))
	{
		g_NextStatusFromGame = eOpening;
		g_GamePhase = eEnd;
		GameReset();
	}

}