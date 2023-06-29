//----------------------------------------------------------
// �t�@�C����		�FPlayerMove.cpp
// �T�v				�F�v���C���[�̉��ړ��̑��x
// �쐬��			�F2022/03/08
// �쐬��			�F21cu0321 �c���đ�
// �X�V���e			�F2022/03/09 21cu0321 �c���đ� ����l�A�����l�̕ύX
//					�F2022/03/11 21CU0315 ���쌫 �v���C���[�̌����̏�����ǉ�
//					�F2022/03/18 21cu0321 �c���đ��@����l�A�����l�̕ύX
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::PlayerMove()
{
	// �E�L�[�������ꂽ��
	if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
	{
		for (int i = 0; i < PlayerQuantity; ++i)
		{
			g_pPlayer1[i]->setAngle(0.0f, 0.0f, 0.0f);

		}
		if (SpeedUpStart < 8)
		{
			SpeedUpStart++;
			playerHoriSpeed += 0.1;
		}
		else
		{
			//����l�܂ŉ���
			if (SpeedLimit > playerHoriSpeed)
			{
				playerHoriSpeed += 0.6f; // �ύX�_
			}
		}
	}
	// ���L�[�������ꂽ��
	else if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
	{
		for (int i = 0; i < PlayerQuantity; ++i)
		{
			g_pPlayer1[i]->setAngle(0.0f, 180.0f, 0.0f);
		}
		if (SpeedUpStart < 8)
		{
			SpeedUpStart++;
			playerHoriSpeed -= 0.1;
		}
		else
		{
			//�����l�܂Ō���
			if (-SpeedLimit < playerHoriSpeed)
			{
				playerHoriSpeed -= 0.6f; // �ύX�_
			}
		}

	}
	//����̒l�̊Ԃɓ�������X�s�[�h��0�ɂ���
	else if (playerHoriSpeed > 0 && playerHoriSpeed < 0.2 || playerHoriSpeed < 0 && playerHoriSpeed > 0.8)
	{
		playerHoriSpeed = 0;
	}
	//�{�^���𗣂����猸������
	else if (playerHoriSpeed > 0 || playerHoriSpeed < 0)
	{
		if (playerHoriSpeed > 0)
		{
			playerHoriSpeed -= 0.1f;
		}
		else if (playerHoriSpeed < 0)
		{
			playerHoriSpeed += 0.1f;
		}
		//�n�ʂɂ��鎞�̂݃X���C�f�B���O����
		for (int j = 0; j < GroundQuantity; ++j)
		{
			for (int i = 0; i < PlayerQuantity; ++i)
			{
				if (g_pPlayer1[i]->collision(g_pGround[j]) != false)
				{
					g_pPlayer1[i]->setAnimation(3);
				}
			}
		}
	}
}