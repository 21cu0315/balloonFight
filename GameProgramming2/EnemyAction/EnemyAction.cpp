//----------------------------------------------------------
// �t�@�C����		�FEnemyAction
// �T�v				�F�G�̍s�����Ǘ�����CPP
// �쐬��			�F21CU0118�@���r�T�V��
// �X�V���e			�F2022/03/15�@���r�T�V��@�G�̍s�����Ǘ�����cpp�ǉ��AEnemyFly1�̍폜
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyAction()
{
	//�o���[�����Ȃ����̏���
	EnemyNotBalloon();
	//�o���[�����j�󂳂ꂽ�Ƃ��̏���
	EnemyBalloonBreak();
	//�G�̍s�����Ǘ�����֐�
	EnemyFly1();
	//�G�̉�ʊO�̍s��
	EnemyOffScreen();
	//�G�̓����蔻��
	EnemyCollisionDetection();
	//�G���C�ɗ������Ƃ��̏���
	EnemySeaDrop();
	//�G�����񂾎��̏���
	EnemyDead();
}