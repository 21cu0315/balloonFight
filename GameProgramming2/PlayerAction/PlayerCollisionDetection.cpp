//----------------------------------------------------------
// �t�@�C����		�FPlayerCollisionDetection.cpp
// �T�v				�F�v���C���[�̓����蔻��
// �쐬��			�F21CU0315 ���쌫
// �X�V���e			�F2022/03/02 21CU0315 ���쌫 �쐬
//					�F2022/03/04 21CU0315 ���쌫 �v���C���[�ƒn�ʁA����S�̓����蔻���ǉ�
//					�F2022/03/08 21CU0315 ���쌫 �v���C���[�ƃM�~�b�N�̈ʒu�ɂ���āA�����蔻����C��
//					�F2022/03/28 21CU0118 ���r�T�V�� �A�Ƃ̓����蔻���ǉ�
//----------------------------------------------------------
#include "CActionGameApp.h"

int playerRunningCounter = 0;


void CActionGameApp::PlayerCollusionDetection()
{
	if (playerIsDead != true)
	{
		//�����x�̃J�E���^�[���n�߂�
		horiSpeedCounter++;
		//����Ƃ��p�̃J�E���^�[���n�߂�
		playerRunningCounter++;

		//�ړ��ʂ��v���C���[�ɐݒ肷��
		for (int i = 0; i < PlayerQuantity; ++i)
		{
			if (g_pPlayer1[i] != NULL)
			{
				if (g_pPlayer1[i]->getPos().y > (WINDOW_HEIGHT / 2 - 48.0f))
				{
					g_pPlayer1[i]->setPos(g_pPlayer1[i]->getPos().x, WINDOW_HEIGHT / 2 - 48.0f);
					moveY = -2.0f;
				}
				else
				{
					g_pPlayer1[i]->setPos(g_pPlayer1[i]->getPos().x, g_pPlayer1[i]->getPos().y + moveY);
				}
			}
		}
		//�u���b�N�̓����蔻��
		//g_pPlatFormL�ɓ������Ă���Ƃ��A�ȉ��̏������s�����W���X�V����
		for (int i = 0; i < PlatFormQuantityL; ++i)
		{
			for (int j = 0; j < PlayerQuantity; ++j)
			{
				if (g_pPlayer1[j] != NULL && g_pPlatFormL[i] != NULL)
				{
					if (g_pPlayer1[j]->collision(g_pPlatFormL[i]) != false)
					{
						if (g_pPlayer1[j]->getPos().y > g_pPlatFormL[i]->getPos().y)
						{
							//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
							g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pPlatFormL[i]->getPos().y + 64.0f);
							//�ォ�瓖�����Ă�Ƃ��l��0�ɂ���
							moveY = 0.0f;

							//�E�ɍs���Ƃ�
							if (playerHoriSpeed > 0)
							{
								if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
								{
									//���鎞�̃A�j���[�V����
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimationRange(10, 12);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimationRange(3, 5);
									}
									if (playerRunningCounter % 5 == 0)
									{
										g_pPlayer1[j]->stepAnimation();
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
								else
								{
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimation(13);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimation(6);
									}
								}
								//���C��
								if (horiSpeedCounter % 3 == 0)
								{
									playerHoriSpeed -= 0.1f;
									horiSpeedCounter = 0;
								}
							}
							//���ɍs���Ƃ�
							else if (playerHoriSpeed < 0)
							{
								if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
								{
									//���鎞�̃A�j���[�V����
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimationRange(10, 12);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimationRange(3, 5);
									}
									if (playerRunningCounter % 5 == 0)
									{
										g_pPlayer1[j]->stepAnimation();
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
								else
								{
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimation(13);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimation(6);
									}
								}
								//���C��
								if (horiSpeedCounter % 3 == 0)
								{
									playerHoriSpeed += 0.1f;
									horiSpeedCounter = 0;
								}
							}
							//�v���C���[��_�����ɂ���
							else if (playerHoriSpeed == 0)
							{
								SpeedUpStart = 0;
								if (PlayerBalloon == 2)
								{
									g_pPlayer1[j]->setAnimation(7);
								}
								else if (PlayerBalloon == 1)
								{
									g_pPlayer1[j]->setAnimation(0);
								}
							}
						}
						else
						{
							g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, (g_pPlatFormL[i]->getPos().y - 16.0f - 48.0f));
							moveY = -2.0f;
						}
					}
				}
			}
		}

		//g_pPlatFormS�ɓ������Ă���Ƃ��A�ȉ��̏������s�����W���X�V����
		for (int i = 0; i < PlatFormQuantityS; ++i)
		{
			for (int j = 0; j < PlayerQuantity; ++j)
			{
				if (g_pPlayer1[j] != NULL && g_pPlatFormS[i] != NULL)
				{
					if (g_pPlayer1[j]->collision(g_pPlatFormS[i]) != false)
					{
						//�����瓖����Ƃ�
						//�E����
						if (g_pPlayer1[j]->getPos().x > g_pPlatFormS[i]->getPos().x && g_pPlayer1[j]->getPos().y < g_pPlatFormS[i]->getPos().y + (64.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pPlatFormS[i]->getPos().y - (64.0f + GravLimi))
						{
							g_pPlayer1[j]->setPos(256.0f, g_pPlayer1[j]->getPos().y);
							playerHoriSpeed = 2.0f;
						}
						//������
						else if (g_pPlayer1[j]->getPos().x < g_pPlatFormS[i]->getPos().x && g_pPlayer1[j]->getPos().y <  g_pPlatFormS[i]->getPos().y + (64.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pPlatFormS[i]->getPos().y - (64.0f + GravLimi))
						{
							g_pPlayer1[j]->setPos(-256.0f, g_pPlayer1[j]->getPos().y);
							playerHoriSpeed = -2.0f;
						}

						//�ォ�瓖����Ƃ�

						else if (g_pPlayer1[j]->getPos().y > g_pPlatFormS[i]->getPos().y)
						{
							//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
							g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pPlatFormS[i]->getPos().y + 64.0f);
							//�ォ�瓖�����Ă�Ƃ��l��0�ɂ���
							moveY = 0.0f;

							//�E�ɍs���Ƃ�
							if (playerHoriSpeed > 0)
							{
								if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
								{
									//���鎞�̃A�j���[�V����
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimationRange(10, 12);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimationRange(3, 5);
									}
									if (playerRunningCounter % 5 == 0)
									{
										g_pPlayer1[j]->stepAnimation();
									}
								}
								else
								{
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimation(13);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimation(6);
									}
								}
								//���C��
								if (horiSpeedCounter % 3 == 0)
								{
									playerHoriSpeed -= 0.1f;
									horiSpeedCounter = 0;
								}
							}
							//���ɍs���Ƃ�
							else if (playerHoriSpeed < 0)
							{
								if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
								{
									//���鎞�̃A�j���[�V����
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimationRange(10, 12);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimationRange(3, 5);
									}
									if (playerRunningCounter % 5 == 0)
									{
										g_pPlayer1[j]->stepAnimation();
									}
								}
								else
								{
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimation(13);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimation(6);
									}
								}
								//���C��
								if (horiSpeedCounter % 3 == 0)
								{
									playerHoriSpeed += 0.1f;
									horiSpeedCounter = 0;
								}
							}
							//�v���C���[��_�����ɂ���
							else if (playerHoriSpeed == 0)
							{
								SpeedUpStart = 0;
								if (PlayerBalloon == 2)
								{
									g_pPlayer1[j]->setAnimation(7);
								}
								else if (PlayerBalloon == 1)
								{
									g_pPlayer1[j]->setAnimation(0);
								}
							}
						}
						else if (g_pPlayer1[j]->getPos().y < g_pPlatFormS[i]->getPos().y)
						{
							g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, (g_pPlatFormS[i]->getPos().y - 16.0f - 48.0f));
							moveY = -2.0f;
						}

					}
				}

			}
		}

		//g_pGround�ɓ������Ă��鎞�A�ȉ��̏������s�����W���X�V����
		for (int i = 0; i < GroundQuantity; ++i)
		{
			for (int j = 0; j < PlayerQuantity; ++j)
			{
				if (g_pGround[i] != NULL && g_pPlayer1[j] != NULL)
				{
					//�����瓖����Ƃ�
					if (g_pPlayer1[j]->collision(g_pGround[3]) != false && playerHoriSpeed > 0 && g_pPlayer1[j]->getPos().y < -292.0f - 6.0f)
					{
						g_pPlayer1[j]->setPos(224.0f, g_pPlayer1[j]->getPos().y);
						playerHoriSpeed = -2.0f;
					}
					else if (g_pPlayer1[j]->collision(g_pGround[7]) != false && playerHoriSpeed < 0 && g_pPlayer1[j]->getPos().y < -292.0f - 6.0f)
					{
						g_pPlayer1[j]->setPos(-224.0f, g_pPlayer1[j]->getPos().y);
						playerHoriSpeed = 2.0f;
					}
					//�ォ�瓖����Ƃ�
					else if (g_pPlayer1[j]->collision(g_pGround[i]) != false)
					{
						if (g_pPlayer1[j]->getPos().y > GroundPosY)
						{
							//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
							g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
							//�ォ�瓖�����Ă�Ƃ��l��0�ɂ���
							moveY = 0.0f;

							//�E�ɍs���Ƃ�
							if (playerHoriSpeed > 0)
							{
								if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
								{
									//���鎞�̃A�j���[�V����
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimationRange(10, 12);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimationRange(3, 5);
									}
									if (playerRunningCounter % 5 == 0)
									{
										g_pPlayer1[j]->stepAnimation();
									}
								}
								else
								{
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimation(13);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimation(6);
									}
								}
								//���C��
								if (horiSpeedCounter % 3 == 0)
								{
									playerHoriSpeed -= 0.1f;
									horiSpeedCounter = 0;
								}
							}
							//���ɍs���Ƃ�
							else if (playerHoriSpeed < 0)
							{
								if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
								{
									//���鎞�̃A�j���[�V����
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimationRange(10,12);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimationRange(3,5);
									}
									if (playerRunningCounter % 5 == 0)
									{
										g_pPlayer1[j]->stepAnimation();
									}
								}
								else
								{
									if (PlayerBalloon == 2)
									{
										g_pPlayer1[j]->setAnimation(13);
									}
									else if (PlayerBalloon == 1)
									{
										g_pPlayer1[j]->setAnimation(6);
									}
								}
								//���C��
								if (horiSpeedCounter % 3 == 0)
								{
									playerHoriSpeed += 0.1f;
									horiSpeedCounter = 0;
								}
							}
							//�v���C���[��_�����ɂ���
							else if (playerHoriSpeed == 0)
							{
								SpeedUpStart = 0;
								if (PlayerBalloon == 2)
								{
									g_pPlayer1[j]->setAnimation(7);
								}
								else if (PlayerBalloon == 1)
								{
									g_pPlayer1[j]->setAnimation(0);
								}
							}
						}
					}
				}
			}
		}

		//�v���C���[�ƖA�̓����蔻��
		for (int j = 0; j < FoamQuantity; ++j)
		{
			if (g_pPlayer1[0] != NULL)
			{
				if (g_pFoam[j] != NULL)
				{
					//�A�Ɠ���������
					if (g_pPlayer1[0]->collision(g_pFoam[j]) != false)
					{
						//���̎��ɃX�R�A�̉��Z
     						g_score += 500;
						//�܂��A�̉摜�̍폜
						disposeSprite(g_pFoam[j]);
						g_pFoam[j] = NULL;
						break;
					}
				}
			}
			if (g_pPlayer1[1] != NULL)
			{
				if (g_pFoam[j] != NULL)
				{
					//�A�Ɠ���������
					if (g_pPlayer1[1]->collision(g_pFoam[j]) != false)
					{
						//���̎��ɃX�R�A�̉��Z
						g_score += 500;
						//�܂��A�̉摜�̍폜
						disposeSprite(g_pFoam[j]);
						g_pFoam[j] = NULL;
						break;
					}
				}
			}
		}
	}
}