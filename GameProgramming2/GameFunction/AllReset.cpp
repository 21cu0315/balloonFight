//----------------------------------------------------------
// �t�@�C����		�FAllReset.cpp
// �T�v				�F�v���C���[�̎c�@�ȊO�S�ă��Z�b�g����֐�
// �쐬��			�F21CU0118�@���r�T�V��
// �X�V���e			�F2022/03/14�@���r�T�V��쐬
//					�F2022/03/18	 21CU0315 ���쌫 �v���C���[�̃A�j���[�V�����ƃv���C���[�����ʂƂ��̃J�E���^�[�����Z�b�g���鏈����ǉ�
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::AllReset()
{
	playerCaughtByFish = false;
	if (iPlayerResidue != 0)
	{
		g_pPlayer1[0]->setPos(PlayerSet[0]);
		g_pPlayer1[1]->setPos(PlayerSet[1]);
	}
	g_pFish->setPos(fishPos);
	resetPlayerFishPos = false;
	PlayerBalloon = 2;
	PlayerDieBalloon = false;
	g_pPlayer1[0]->setAnimation(7);
	g_pPlayer1[1]->setAnimation(7);
	playerDeathGoUpCounter = 0;
	PlayerIsKilledByThunder = false;
}