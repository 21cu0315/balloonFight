#include "CActionGameApp.h"

/*
 * �v���C���[�̍s������������֐�
 */
void CActionGameApp::PlayerAction()
{
	for (int i = 0; i < 2; ++i)
	{
		g_pPlayer1[i]->setPos(g_pPlayer1[i]->getPos().x + playerHoriSpeed, g_pPlayer1[i]->getPos().y);
	}
	if (playerHoriSpeed > 0)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (g_pPlayer1[i]->getPos().x > (WINDOW_WIDTH / 2) + 64.0f)
			{
				g_pPlayer1[i]->setPos((g_pPlayer1[i]->getPos().x - WINDOW_WIDTH * 2), g_pPlayer1[i]->getPos().y);
			}
		}
	}
	else if (playerHoriSpeed < 0)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (g_pPlayer1[i]->getPos().x < (-WINDOW_WIDTH / 2) - 64.0f)
			{
				g_pPlayer1[i]->setPos((g_pPlayer1[i]->getPos().x + WINDOW_WIDTH * 2), g_pPlayer1[i]->getPos().y);
			}
		}
	}
	// �E�L�[�������ꂽ��
	if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
	{
		if (SpeedUpStart < 8)
		{
			SpeedUpStart++;
			playerHoriSpeed += 0.4;
		}
		else
		{
			//����l�܂ŉ���
			if (SpeedLimit > playerHoriSpeed)
			{
				playerHoriSpeed += 0.9f;
			}
		}
	}
	// ���L�[�������ꂽ��
	else if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
	{
		if (SpeedUpStart < 8)
		{
			SpeedUpStart++;
			playerHoriSpeed -= 0.4;
		}
		else
		{
			//�����l�܂Ō���
			if (-SpeedLimit < playerHoriSpeed)
			{
				playerHoriSpeed -= 0.9f;
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
	}
	else
	{
		SpeedUpStart = 0;
	}


	//�W�����v�̏���
	//�X�y�[�X�L�[�ŃW�����v
	if (m_pDirectInput->isPressedOnce(DIK_SPACE))
	{
		if (g_jumpPowerMax > moveY)
		{
			//����̒l�܂ł̓W�����v���Z���ł���
			moveY += 1.0;
		}
	}
	
	//0.2�b��1�񗎉�����������
	if (PlayerGravDownTime == 3)
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




	//�ړ��ʂ��v���C���[�ɐݒ肷��
	for (int i = 0; i <PlayerQuanitity; ++i)
	{
		if (g_pPlayer1[i]->getPos().y > (WINDOW_HEIGHT / 2 - 48.0f))
		{
			g_pPlayer1[i]->setPos(g_pPlayer1[i]->getPos().x, WINDOW_HEIGHT / 2 - 48.0f);
			g_changeGrav = -2.0f;
		}
		else
		{
			g_pPlayer1[i]->setPos(g_pPlayer1[i]->getPos().x, g_pPlayer1[i]->getPos().y + moveY);
		}
	}
	//�u���b�N�̓����蔻��
	//g_pPlatFormL�ɓ������Ă���Ƃ��A�ȉ��̏������s�����W���X�V����
	for (int i = 0; i < PlatFormQuantityL; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{

			if (g_pPlayer1[j]->collision(g_pPlatFormL[i]) != false)
			{
				if (g_pPlayer1[j]->getPos().y > PlatFormPosY)
				{
					//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
					g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pPlatFormL[i]->getPos().y + 64.0f);
					g_changeGrav = 0.0f;

					//���C��
					if (playerHoriSpeed > 0)
					{
						if (horiSpeedCounter % 30 == 0)
						{
							playerHoriSpeed -= 1.0f;
							horiSpeedCounter = 0;
						}
					}
					else if (playerHoriSpeed < 0)
					{
						if (horiSpeedCounter % 30 == 0)
						{
							playerHoriSpeed += 1.0f;
							horiSpeedCounter = 0;
						}
					}
				}
				else
				{
					g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, (PlatFormPosY - 32.0f - 48.0f));
					g_changeGrav = -2.0f;
				}
				//�ォ�瓖�����Ă�Ƃ��l��0�ɂ���
				moveY = 0.0f;
			}
		}
	}

	//g_pPlatFormS�ɓ������Ă���Ƃ��A�ȉ��̏������s�����W���X�V����
	for (int i = 0; i < PlatFormQuantityS; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			//�����瓖����Ƃ�
			//�E����
			if (g_pPlayer1[j]->collision(g_pPlatFormS[0]) != false && playerHoriSpeed < 0 && g_pPlayer1[j]->getPos().y < -49.0f)
			{
				g_pPlayer1[j]->setPos(256.0f, g_pPlayer1[j]->getPos().y);
				playerHoriSpeed = 2.0f;
			}
			//������
			else if (g_pPlayer1[j]->collision(g_pPlatFormS[1]) != false && playerHoriSpeed > 0 && g_pPlayer1[j]->getPos().y < -49.0f)
			{
				g_pPlayer1[j]->setPos(-256.0f, g_pPlayer1[j]->getPos().y);
				playerHoriSpeed = -2.0f;
			}

			//�ォ�瓖����Ƃ�
			else if (g_pPlayer1[j]->collision(g_pPlatFormS[i]))
			{
				if (g_pPlayer1[j]->getPos().y > PlatFormPosY)
				{
					//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
					g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pPlatFormS[i]->getPos().y + 64.0f);
					g_changeGrav = 0.0f;

					//���C��
					if (playerHoriSpeed > 0)
					{
						if (horiSpeedCounter % 30 == 0)
						{
							playerHoriSpeed -= 1.0f;
							horiSpeedCounter = 0;
						}
					}
					else if (playerHoriSpeed < 0)
					{
						if (horiSpeedCounter % 30 == 0)
						{
							playerHoriSpeed += 1.0f;
							horiSpeedCounter = 0;
						}
					}
				}
				else
				{
					g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, (PlatFormPosY - 32.0f - 48.0f));
					g_changeGrav = -2.0f;
				}
				//�ォ�瓖�����Ă�Ƃ��l��0�ɂ���
				moveY = 0.0f;
			}

		}
	}

	//g_pGround�ɓ������Ă��鎞�A�ȉ��̏������s�����W���X�V����
	for (int i = 0; i < GroundQuantity; ++i)
	{
		if (g_pGround[i] != NULL)
		{

			for (int j = 0; j < 2; ++j)
			{

				//�����瓖����Ƃ�
				if (g_pPlayer1[j]->collision(g_pGround[3]) != false && playerHoriSpeed > 0 && g_pPlayer1[j]->getPos().y < -301.0f)
				{
					g_pPlayer1[j]->setPos(224.0f, g_pPlayer1[j]->getPos().y);
					playerHoriSpeed = -2.0f;
				}
				else if (g_pPlayer1[j]->collision(g_pGround[7]) != false && playerHoriSpeed < 0 && g_pPlayer1[j]->getPos().y < -301.0f)
				{
					g_pPlayer1[j]->setPos(-224.0f, g_pPlayer1[j]->getPos().y);
					playerHoriSpeed = 2.0f;
				}
				//�ォ�瓖����Ƃ�
				else if (g_pPlayer1[j]->collision(g_pGround[i]) != false)
				{

					//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
					g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					g_changeGrav = 0.0f;

					//���C��
					if (playerHoriSpeed > 0)
					{
						if (horiSpeedCounter % 30 == 0)
						{
							playerHoriSpeed -= 1.0f;
							horiSpeedCounter = 0;
						}
					}
					else if (playerHoriSpeed < 0)
					{
						if (horiSpeedCounter % 30 == 0)
						{
							playerHoriSpeed += 1.0f;
							horiSpeedCounter = 0;
						}
					}
					//�ォ�瓖�����Ă�Ƃ��l��0�ɂ���
					moveY = 0.0f;
				}
			}
		}
	}
}