//------------------------------------------
// �t�@�C����		:PlayerJump.cpp
// �T�v				:�v���C���[�̋󒆈ړ����x
// �쐬��			:2022/03/09
// �쐬��			:�c���đ�
// �X�V���e			:�v���C���[�̋󒆉��ړ��̏�����V���ɉ����܂����B
//					:2022/03/18 21CU0315 ���쌫 �v���C���[���W�����v�����Ƃ��̃A�j���[�V�������������Ă݂܂����B
//					:2022/03/28 21cu0118 ���r�T�V��@���G��������ǉ�
#include "CActionGameApp.h"



void CActionGameApp::PlayerJump()
{
	//�W�����v�̏���
	//�X�y�[�X�L�[�ŃW�����v
	if (startPlayerJumpAnimCounter == true)
	{
		playerJumpAnimIndex++;
		if (PlayerBalloon == 2)
		{
			g_pPlayer1[0]->setAnimationRange(19, 20);
			g_pPlayer1[1]->setAnimationRange(19, 20);

		}
		else if (PlayerBalloon == 1)
		{
			if (playerJumpAnimIndex < 15)
			{
				g_pPlayer1[0]->setAnimationRange(14, 15);
				g_pPlayer1[1]->setAnimationRange(14, 15);
			}
		}
		if (playerJumpAnimIndex % 5  == 0)
		{
			g_pPlayer1[0]->stepAnimation();
			g_pPlayer1[1]->stepAnimation();
		}
	}
	if (playerJumpAnimIndex > 15)
	{
		if (PlayerBalloon == 2)
		{
			g_pPlayer1[0]->setAnimation(21);
			g_pPlayer1[1]->setAnimation(21);
		}
		else if (PlayerBalloon == 1)
		{
			g_pPlayer1[0]->setAnimation(16);
			g_pPlayer1[1]->setAnimation(16);
		}
		playerJumpAnimIndex = 0;
		startPlayerJumpAnimCounter = false;
	}
	if (m_pDirectInput->isPressedOnce(DIK_SPACE))
	{
		playerJumpAnimIndex = 0;
		startPlayerJumpAnimCounter = true;
		//���G�������
		PlayerInvincible = true;
		//����̒l�܂ł̓W�����v���Z���ł���
		if (g_jumpPowerMax > moveY)
		{
			moveY += 1.6;
		}
	}
	//�v���C���[���i����A�n�ʁj���痎�������̃A�j���[�V����
	else if (moveY < -0.1f && startPlayerJumpAnimCounter != true)
	{
		if (PlayerBalloon == 2)
		{
			g_pPlayer1[0]->setAnimation(21);
			g_pPlayer1[1]->setAnimation(21);
		}
		else if (PlayerBalloon == 1)
		{
			g_pPlayer1[0]->setAnimation(16);
			g_pPlayer1[1]->setAnimation(16);
		}
		playerJumpAnimIndex = 0;
		startPlayerJumpAnimCounter = false;
	}


//	//---------------------------------------------------------------
//// �E�L�[�������ꂽ��
//	if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
//	{
//		if (SpeedUpStart1 < 8)
//		{
//			SpeedUpStart1++;
//			playerHoriSpeed1 += 0.1;
//		}
//		else
//		{
//			//����l�܂ŉ���
//			if (SpeedLimit > playerHoriSpeed1)
//			{
//				playerHoriSpeed1 += 0.1f; // �ύX�_
//			}
//		}
//		//���G�������
//		PlayerInvincible = true;
//	}
//	// ���L�[�������ꂽ��
//	else if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
//	{
//		if (SpeedUpStart1 < 8)
//		{
//			SpeedUpStart1++;
//			playerHoriSpeed1 -= 0.1;
//		}
//		else
//		{
//			//�����l�܂Ō���
//			if (-SpeedLimit1 < playerHoriSpeed1)
//			{
//				playerHoriSpeed1 -= 0.1f; // �ύX�_
//			}
//		}
//		//���G�������
//		PlayerInvincible = true;
//
//	}
//	//����̒l�̊Ԃɓ�������X�s�[�h��0�ɂ���
//	else if (playerHoriSpeed1 > 0 && playerHoriSpeed1 < 0.2 || playerHoriSpeed1 < 0 && playerHoriSpeed1 > 0.8)
//	{
//		playerHoriSpeed1 = 0;
//	}
//	//�{�^���𗣂����猸������
//	else if (playerHoriSpeed1 > 0 || playerHoriSpeed1 < 0)
//	{
//		if (playerHoriSpeed1 > 0)
//		{
//			playerHoriSpeed1 -= 0.1f;
//		}
//		else if (playerHoriSpeed1 < 0)
//		{
//			playerHoriSpeed1 += 0.1f;
//		}
//	}
//	else
//	{
//		SpeedUpStart1 = 0;
//	}
	//---------------------------------------------------------
		//0.2�b��1�񗎉�����������
	if (PlayerGravDownTime == 1)
	{
		if (GravLimi < moveY)
		{
			//����̒l�܂Ō��Z����Ă���
			moveY -= 0.2;
		}
		PlayerGravDownTime = 0;
	}
	//���Ԃ̒l�ɉ��Z���Ă���
	else
	{
		++PlayerGravDownTime;
	}
}