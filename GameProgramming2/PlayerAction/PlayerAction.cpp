#include "CActionGameApp.h"

/*
 * �v���C���[�̍s������������֐�
 *						:3��16���@���r�T�V�� �v���C���[�̎c�@�����̒ǉ� �v���C���[�������鎞�A��莞�ԑ���s�\�̏�Ԃ̍쐬
*/
void CActionGameApp::PlayerAction()
{
	/*
	* �֐��̌Ăяo��
	*/
	//������if���̒ǉ�
	//�v���C���[�������邩�ǂ����̔���p
	if (PlayerDieBalloon == false)
	{
		if (iPlayerResidue != 0)
		{
			//�v���C���[�̃W�����v�̊֐�
			PlayerJump();
			//�v���C���[�̉�ʊO�̏���
			PlayerOffScreen();
			//�v���C���[�̉��ړ��̏���
			PlayerMove();
			//�v���C���[�̓����蔻��
			PlayerCollusionDetection();
			//�v���C���[�̎c�@�̏���
			PlayerResidue();
		}
	}
	else 
	{
		//�v���C���[�̎��S���̏���
		PlayerDieActionActive();
	}
}