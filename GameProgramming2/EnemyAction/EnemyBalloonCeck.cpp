//----------------------------------------------------------
// �t�@�C����		�FEnemyBalloonCack()
// �T�v				�F�G�̃o���[�����j�󂳂�Ă��邩�̊m�F
// �쐬��			�F21CU0118�@���r�T�V��
// �X�V���e			�F2022/03/15�@���r�T�V�� �쐬 �m�F�����EnemyNotBallon�ւ̐ڑ�
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyBalloonCeck()
{
	//for�����g�p���A�j�󂳂�Ă��邩�̊m�F
	for (int i = 0; i < EnemyBalloonCeckCnt; ++i)
	{
		//�����j�󂳂�Ă�����
		//�j�󂳂ꂽ�Ƃ��̊֐��ֈڍs
		if (enemyBalloonIsBroken[i] != false)
		{
			//�֐��̌Ăяo��
			EenemyNotBalune(i);
		}
	}
}
