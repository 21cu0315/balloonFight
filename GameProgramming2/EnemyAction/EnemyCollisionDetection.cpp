//----------------------------------------------------------
// �t�@�C����		�FEnemyCollisionDetection.cpp
// �T�v				�F�G�L�����̓����蔻��
// �쐬��			�F21CU0315 ���쌫
// �X�V���e			�F2022/03/10 21CU0315 ���쌫 �쐬
//					�F2022/03/15 21CU0315 ���쌫 �G�ƒn�ʂ̓����蔻����C���A
//												 �G�Ƒ��̓G���Ԃ������Ƃ��̏�����ǉ�
//					�F2022/04/05 21CU0315 ���쌫 �G�̓����蔻�莞�X�Ȃ��Ȃ�o�O���C�����܂���
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyCollisionDetection()
{
	//�u���b�N�̓����蔻��
	//g_pPlatFormL�ɓ������Ă���Ƃ��A�ȉ��̏������s�����W���X�V����
	for (int i = 0; i < PlatFormQuantityL; ++i)
	{
		for (int j = 0; j < EnemyQuantity; ++j)
		{
			if (g_pEnemy[j] != NULL)
			{
				//�G����ʂ̏�ɏo�Ȃ��悤�ɐݒ肷��
				if (g_pEnemy[j]->getPos().y > (WINDOW_HEIGHT / 2 - 48.0f))
				{
					if (j == EnemyType01_01 || j == EnemyType01_02)
					{
						g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, WINDOW_HEIGHT / 2 - 48.0f);
						ENEMY_SPEED_Y = -2.0f;
					}
					else if (j == EnemyType02_01 || j == EnemyType02_02)
					{
						g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, WINDOW_HEIGHT / 2 - 48.0f);
						ENEMY_SPEED_Y2 = -2.0f;
					}
					else if (j == EnemyType03_01 || j == EnemyType03_02)
					{
						g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, WINDOW_HEIGHT / 2 - 48.0f);
						ENEMY_SPEED_Y3 = -2.0f;
					}
				}

				if (g_pEnemy[j]->collision(g_pPlatFormL[i]) != false)
				{
					if (g_pEnemy[j]->getPos().y > g_pPlatFormL[i]->getPos().y)
					{

						//�ォ�瓖�����Ă�Ƃ��l��0�ɂ���
						if (j == EnemyType01_01 || j == EnemyType01_02)
						{
							if (enemyBalloonIsBroken[0] != true && enemyIsDead[0] != true)
							{
								//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pPlatFormL[i]->getPos().y + 64.0f);
								ENEMY_SPEED_Y = 2.0f;
							}
						}
						else if (j == EnemyType02_01 || j == EnemyType02_02)
						{
							if (enemyBalloonIsBroken[1] != true && enemyIsDead[1] != true)
							{
								//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pPlatFormL[i]->getPos().y + 64.0f);
								ENEMY_SPEED_Y2 = 2.0f;
							}
						}
						else if (j == EnemyType03_01 || j == EnemyType03_02)
						{
							if (enemyBalloonIsBroken[2] != true && enemyIsDead[2] != true)
							{
								//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pPlatFormL[i]->getPos().y + 64.0f);
								ENEMY_SPEED_Y3 = 2.0f;
							}
						}
					}
					else
					{
						if (j == EnemyType01_01 || j == EnemyType01_02)
						{
							if (enemyBalloonIsBroken[0] != true && enemyIsDead[0] != true)
							{
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, (g_pPlatFormL[i]->getPos().y - 16.0f - 48.0f));
								ENEMY_SPEED_Y = -2.0f;
							}
						}
						else if (j == EnemyType02_01 || j == EnemyType02_02)
						{
							if (enemyBalloonIsBroken[1] != true && enemyIsDead[1] != true)
							{
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, (g_pPlatFormL[i]->getPos().y - 16.0f - 48.0f));
								ENEMY_SPEED_Y2 = -2.0f;
							}
						}
						else if (j == EnemyType03_01 || j == EnemyType03_02)
						{
							if (enemyBalloonIsBroken[2] != true && enemyIsDead[2] != true)
							{
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, (g_pPlatFormL[i]->getPos().y - 16.0f - 48.0f));
								ENEMY_SPEED_Y3 = -2.0f;
							}
						}
					}

				}
			}


		}
	}

	//g_pPlatFormS�ɓ������Ă���Ƃ��A�ȉ��̏������s�����W���X�V����
	for (int i = 0; i < PlatFormQuantityS; ++i)
	{
		for (int j = 0; j < EnemyQuantity; ++j)
		{
			if (g_pEnemy[j] != NULL)
			{
				if (g_pEnemy[j]->collision(g_pPlatFormS[i]) != false)
				{
					//�����瓖����Ƃ�
					//�E����
					if (g_pEnemy[j]->getPos().x > g_pPlatFormS[i]->getPos().x && g_pEnemy[j]->getPos().y < g_pPlatFormS[i]->getPos().y + (64.0f + GravLimi) && g_pEnemy[j]->getPos().y > g_pPlatFormS[i]->getPos().y - (64.0f + GravLimi))
					{
						if (j == EnemyType01_01 || j == EnemyType01_02)
						{
							if (enemyBalloonIsBroken[0] != true && enemyIsDead[0] != true)
							{
								ENEMY_SPEED_X = 2.0f;
								g_pEnemy[j]->setPos(256.0f, g_pEnemy[j]->getPos().y);
							}
						}
						else if (j == EnemyType02_01 || j == EnemyType02_02)
						{
							if (enemyBalloonIsBroken[1] != true && enemyIsDead[1] != true)
							{
								ENEMY_SPEED_X2 = 2.0f;
								g_pEnemy[j]->setPos(256.0f, g_pEnemy[j]->getPos().y);
							}
						}
						else if (j == EnemyType03_01 || j == EnemyType03_02)
						{
							if (enemyBalloonIsBroken[2] != true && enemyIsDead[2] != true)
							{
								ENEMY_SPEED_X3 = 2.0f;
								g_pEnemy[j]->setPos(256.0f, g_pEnemy[j]->getPos().y);
							}
						}

					}
					//������
					else if (g_pEnemy[j]->getPos().x < g_pPlatFormS[i]->getPos().x && g_pEnemy[j]->getPos().y <  g_pPlatFormS[i]->getPos().y + (64.0f + GravLimi) && g_pEnemy[j]->getPos().y > g_pPlatFormS[i]->getPos().y - (64.0f + GravLimi))
					{
						if (j == EnemyType01_01 || j == EnemyType01_02)
						{
							if (enemyBalloonIsBroken[0] != true && enemyIsDead[0] != true)
							{
								ENEMY_SPEED_X = -2.0f;
								g_pEnemy[j]->setPos(-256.0f, g_pEnemy[j]->getPos().y);
							}
						}
						else if (j == EnemyType02_01 || j == EnemyType02_02)
						{
							if (enemyBalloonIsBroken[1] != true && enemyIsDead[1] != true)
							{
								ENEMY_SPEED_X2 = -2.0f;
								g_pEnemy[j]->setPos(-256.0f, g_pEnemy[j]->getPos().y);
							}
						}
						else if (j == EnemyType03_01 || j == EnemyType03_02)
						{
							if (enemyBalloonIsBroken[2] != true && enemyIsDead[2] != true)
							{
								ENEMY_SPEED_X3 = -2.0f;
								g_pEnemy[j]->setPos(-256.0f, g_pEnemy[j]->getPos().y);
							}
						}
					}

					//�ォ�瓖����Ƃ�
					else if (g_pEnemy[j]->getPos().y > g_pPlatFormS[i]->getPos().y)
					{

						//�ォ�瓖�����Ă�Ƃ��l��0�ɂ���
						if (j == EnemyType01_01 || j == EnemyType01_02)
						{
							if (enemyBalloonIsBroken[0] != true && enemyIsDead[0] != true)
							{
								//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pPlatFormS[i]->getPos().y + 64.0f);
								ENEMY_SPEED_Y = 2.0f;
							}
						}
						else if (j == EnemyType02_01 || j == EnemyType02_02)
						{
							if (enemyBalloonIsBroken[1] != true && enemyIsDead[1] != true)
							{
								//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pPlatFormS[i]->getPos().y + 64.0f);
								ENEMY_SPEED_Y2 = 2.0f;
							}
						}
						else if (j == EnemyType03_01 || j == EnemyType03_02)
						{
							if (enemyBalloonIsBroken[2] != true && enemyIsDead[2] != true)
							{
								//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pPlatFormS[i]->getPos().y + 64.0f);
								ENEMY_SPEED_Y3 = 2.0f;
							}
						}


					}
					else if (g_pEnemy[j]->getPos().y < g_pPlatFormS[i]->getPos().y)
					{
						g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, (g_pPlatFormS[i]->getPos().y - 16.0f - 48.0f));
						if (j == EnemyType01_01 || j == EnemyType01_02)
						{
							ENEMY_SPEED_Y = -2.0f;
						}
						else if (j == EnemyType02_01 || j == EnemyType02_02)
						{
							ENEMY_SPEED_Y2 = -2.0f;
						}
						else if (j == EnemyType03_01 || j == EnemyType03_02)
						{
							ENEMY_SPEED_Y3 = -2.0f;
						}
					}

				}
			}
		}
	}

	//g_pGround�ɓ������Ă��鎞�A�ȉ��̏������s�����W���X�V����
	for (int i = 0; i < GroundQuantity; ++i)
	{
		if (g_pGround[i] != NULL)
		{
			for (int j = 0; j < EnemyQuantity; ++j)
			{
				if (j == EnemyType01_01 || j == EnemyType01_02)
				{
					if (enemyBalloonIsBroken[0] != true && enemyIsDead[0] != true)
					{
						//�����瓖����Ƃ�
						if (g_pEnemy[j]->collision(g_pGround[3]) != false && ENEMY_SPEED_X > 0 && g_pEnemy[j]->getPos().y < -292.0f - 6.0f)
						{
							ENEMY_SPEED_X = -2.0f;
							g_pEnemy[j]->setPos(224.0f, g_pEnemy[j]->getPos().y);
						}
						else if (g_pEnemy[j]->collision(g_pGround[7]) != false && ENEMY_SPEED_X < 0 && g_pEnemy[j]->getPos().y < -292.0f - 6.0f)
						{
							ENEMY_SPEED_X = 2.0f;
							g_pEnemy[j]->setPos(-224.0f, g_pEnemy[j]->getPos().y);
						}
						//�ォ�瓖����Ƃ�
						else if (g_pEnemy[j]->collision(g_pGround[i]) != false)
						{
							if (g_pEnemy[j]->getPos().y > g_pGround[i]->getPos().y)
							{
								//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
								//�ォ�瓖�����Ă�Ƃ��l��0�ɂ���
								ENEMY_SPEED_Y = 2.0f;
							}
						}
					}
				}
				else if (j == EnemyType02_01 || j == EnemyType02_02)
				{
					if (enemyBalloonIsBroken[1] != true && enemyIsDead[1] != true)
					{
						//�����瓖����Ƃ�
						if (g_pEnemy[j]->collision(g_pGround[3]) != false && ENEMY_SPEED_X2 > 0 && g_pEnemy[j]->getPos().y < -292.0f - 6.0f)
						{
							ENEMY_SPEED_X2 = -2.0f;
							g_pEnemy[j]->setPos(224.0f, g_pEnemy[j]->getPos().y);
						}
						else if (g_pEnemy[j]->collision(g_pGround[7]) != false && ENEMY_SPEED_X2 < 0 && g_pEnemy[j]->getPos().y < -292.0f - 6.0f)
						{
							ENEMY_SPEED_X2 = 2.0f;
							g_pEnemy[j]->setPos(-224.0f, g_pEnemy[j]->getPos().y);
						}
						//�ォ�瓖����Ƃ�
						else if (g_pEnemy[j]->collision(g_pGround[i]) != false)
						{
							if (g_pEnemy[j]->getPos().y > g_pGround[i]->getPos().y)
							{
								//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
								//�ォ�瓖�����Ă�Ƃ��l��0�ɂ���
								ENEMY_SPEED_Y2 = 2.0f;
							}
						}
					}
				}
				else if (j == EnemyType03_01 || j == EnemyType03_02)
				{
					if (enemyBalloonIsBroken[2] != true && enemyIsDead[2] != true)
					{
						//�����瓖����Ƃ�
						if (g_pEnemy[j]->collision(g_pGround[3]) != false && ENEMY_SPEED_X3 > 0 && g_pEnemy[j]->getPos().y < -292.0f - 6.0f)
						{
							ENEMY_SPEED_X3 = -2.0f;
							g_pEnemy[j]->setPos(224.0f, g_pEnemy[j]->getPos().y);
						}
						else if (g_pEnemy[j]->collision(g_pGround[7]) != false && ENEMY_SPEED_X3 < 0 && g_pEnemy[j]->getPos().y < -292.0f - 6.0f)
						{
							ENEMY_SPEED_X3 = 2.0f;
							g_pEnemy[j]->setPos(-224.0f, g_pEnemy[j]->getPos().y);
						}
						//�ォ�瓖����Ƃ�
						else if (g_pEnemy[j]->collision(g_pGround[i]) != false)
						{
							if (g_pEnemy[j]->getPos().y > g_pGround[i]->getPos().y)
							{
								//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
								g_pEnemy[j]->setPos(g_pEnemy[j]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
								//�ォ�瓖�����Ă�Ƃ��l��0�ɂ���
								ENEMY_SPEED_Y3 = 2.0f;
							}
						}
					}
				}
			}
		}
	}
	//�G�Ƒ��̓G�̓����蔻��
	//g_pEnemy[0]��g_pEnemy[2]
	if (enemyIsDead[0] != true && enemyIsDead[1] != true && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
	{
		if (g_pEnemy[0]->collision(g_pEnemy[2]) != false)
		{
			//�㉺�̓����蔻��
			if (g_pEnemy[0]->getPos().x <= g_pEnemy[2]->getPos().x + 64.0f && g_pEnemy[0]->getPos().x >= g_pEnemy[2]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[0]->getPos().y > g_pEnemy[2]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y2 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().y < g_pEnemy[2]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y2 = 2.0f;
				}
			}
			//���E�̓����蔻��
			else if (g_pEnemy[0]->getPos().y <= g_pEnemy[2]->getPos().y + 96.0f && g_pEnemy[0]->getPos().y >= g_pEnemy[2]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[0]->getPos().x > g_pEnemy[2]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X2 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().x < g_pEnemy[2]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X2 = 2.0f;
				}

			}
		}
		else if (g_pEnemy[1]->collision(g_pEnemy[2]) != false)
		{
			//�㉺�̓����蔻��
			if (g_pEnemy[1]->getPos().x <= g_pEnemy[2]->getPos().x + 64.0f && g_pEnemy[1]->getPos().x >= g_pEnemy[2]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[1]->getPos().y > g_pEnemy[2]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y2 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().y < g_pEnemy[2]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y2 = 2.0f;
				}
			}
			//���E�̓����蔻��
			else if (g_pEnemy[1]->getPos().y <= g_pEnemy[2]->getPos().y + 96.0f && g_pEnemy[1]->getPos().y >= g_pEnemy[2]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[1]->getPos().x > g_pEnemy[2]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X2 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().x < g_pEnemy[2]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X2 = 2.0f;
				}

			}
		}
		else if (g_pEnemy[0]->collision(g_pEnemy[3]) != false)
		{
			//�㉺�̓����蔻��
			if (g_pEnemy[0]->getPos().x <= g_pEnemy[3]->getPos().x + 64.0f && g_pEnemy[0]->getPos().x >= g_pEnemy[3]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[0]->getPos().y > g_pEnemy[3]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y2 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().y < g_pEnemy[3]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y2 = 2.0f;
				}
			}
			//���E�̓����蔻��
			else if (g_pEnemy[0]->getPos().y <= g_pEnemy[3]->getPos().y + 96.0f && g_pEnemy[0]->getPos().y >= g_pEnemy[3]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[0]->getPos().x > g_pEnemy[3]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X2 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().x < g_pEnemy[3]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X2 = 2.0f;
				}

			}
		}
		else if (g_pEnemy[1]->collision(g_pEnemy[3]) != false)
		{
			//�㉺�̓����蔻��
			if (g_pEnemy[1]->getPos().x <= g_pEnemy[3]->getPos().x + 64.0f && g_pEnemy[1]->getPos().x >= g_pEnemy[3]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[1]->getPos().y > g_pEnemy[3]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y2 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().y < g_pEnemy[3]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y2 = 2.0f;
				}
			}
			//���E�̓����蔻��
			else if (g_pEnemy[1]->getPos().y <= g_pEnemy[3]->getPos().y + 96.0f && g_pEnemy[1]->getPos().y >= g_pEnemy[3]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[1]->getPos().x > g_pEnemy[3]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X2 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().x < g_pEnemy[3]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X2 = 2.0f;
				}

			}
		}
	}
	//g_pEnemy[0]��g_pEnemy[4]
	if (enemyIsDead[0] != true && enemyIsDead[2] != true && g_pEnemy[0] != NULL && g_pEnemy[4] != NULL)
	{
		if (g_pEnemy[0]->collision(g_pEnemy[4]) != false)
		{
			//�㉺�̓����蔻��
			if (g_pEnemy[0]->getPos().x <= g_pEnemy[4]->getPos().x + 64.0f && g_pEnemy[0]->getPos().x >= g_pEnemy[4]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[0]->getPos().y > g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().y < g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//���E�̓����蔻��
			else if (g_pEnemy[0]->getPos().y <= g_pEnemy[4]->getPos().y + 96.0f && g_pEnemy[0]->getPos().y >= g_pEnemy[4]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[0]->getPos().x > g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().x < g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
		else if (g_pEnemy[1]->collision(g_pEnemy[4]) != false)
		{
			//�㉺�̓����蔻��
			if (g_pEnemy[1]->getPos().x <= g_pEnemy[4]->getPos().x + 64.0f && g_pEnemy[1]->getPos().x >= g_pEnemy[4]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[1]->getPos().y > g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().y < g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//���E�̓����蔻��
			else if (g_pEnemy[1]->getPos().y <= g_pEnemy[4]->getPos().y + 96.0f && g_pEnemy[1]->getPos().y >= g_pEnemy[4]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[1]->getPos().x > g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().x < g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
		else if (g_pEnemy[0]->collision(g_pEnemy[5]) != false)
		{
			//�㉺�̓����蔻��
			if (g_pEnemy[0]->getPos().x <= g_pEnemy[5]->getPos().x + 64.0f && g_pEnemy[0]->getPos().x >= g_pEnemy[5]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[0]->getPos().y > g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().y < g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//���E�̓����蔻��
			else if (g_pEnemy[0]->getPos().y <= g_pEnemy[5]->getPos().y + 96.0f && g_pEnemy[0]->getPos().y >= g_pEnemy[5]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[0]->getPos().x > g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[0]->getPos().x < g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
		else if (g_pEnemy[1]->collision(g_pEnemy[5]) != false)
		{
			//�㉺�̓����蔻��
			if (g_pEnemy[1]->getPos().x <= g_pEnemy[5]->getPos().x + 64.0f && g_pEnemy[1]->getPos().x >= g_pEnemy[5]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[1]->getPos().y > g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().y < g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//���E�̓����蔻��
			else if (g_pEnemy[1]->getPos().y <= g_pEnemy[5]->getPos().y + 96.0f && g_pEnemy[1]->getPos().y >= g_pEnemy[5]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[1]->getPos().x > g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[1]->getPos().x < g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
	}
	//g_pEnemy[2]��g_pEnemy[4]
	if (enemyIsDead[1] != true && enemyIsDead[2] != true && g_pEnemy[2] != NULL && g_pEnemy[4] != NULL)
	{
		if (g_pEnemy[2]->collision(g_pEnemy[4]) != false)
		{
			//�㉺�̓����蔻��
			if (g_pEnemy[2]->getPos().x <= g_pEnemy[4]->getPos().x + 64.0f && g_pEnemy[2]->getPos().x >= g_pEnemy[4]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[2]->getPos().y > g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y2 = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[2]->getPos().y < g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y2 = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//���E�̓����蔻��
			else if (g_pEnemy[2]->getPos().y <= g_pEnemy[4]->getPos().y + 96.0f && g_pEnemy[2]->getPos().y >= g_pEnemy[4]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[2]->getPos().x > g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X2 = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[2]->getPos().x < g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X2 = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
		else if (g_pEnemy[3]->collision(g_pEnemy[4]) != false)
		{
			//�㉺�̓����蔻��
			if (g_pEnemy[3]->getPos().x <= g_pEnemy[4]->getPos().x + 64.0f && g_pEnemy[3]->getPos().x >= g_pEnemy[4]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[3]->getPos().y > g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y2 = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[3]->getPos().y < g_pEnemy[4]->getPos().y)
				{
					ENEMY_SPEED_Y2 = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//���E�̓����蔻��
			else if (g_pEnemy[3]->getPos().y <= g_pEnemy[4]->getPos().y + 96.0f && g_pEnemy[3]->getPos().y >= g_pEnemy[4]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[3]->getPos().x > g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X2 = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[3]->getPos().x < g_pEnemy[4]->getPos().x)
				{
					ENEMY_SPEED_X2 = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
		else if (g_pEnemy[2]->collision(g_pEnemy[5]) != false)
		{
			//�㉺�̓����蔻��
			if (g_pEnemy[2]->getPos().x <= g_pEnemy[5]->getPos().x + 64.0f && g_pEnemy[2]->getPos().x >= g_pEnemy[5]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[2]->getPos().y > g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y2 = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[2]->getPos().y < g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y2 = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//���E�̓����蔻��
			else if (g_pEnemy[2]->getPos().y <= g_pEnemy[5]->getPos().y + 96.0f && g_pEnemy[2]->getPos().y >= g_pEnemy[5]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[2]->getPos().x > g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X2 = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[2]->getPos().x < g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X2 = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
		else if (g_pEnemy[3]->collision(g_pEnemy[5]) != false)
		{
			//�㉺�̓����蔻��
			if (g_pEnemy[3]->getPos().x <= g_pEnemy[5]->getPos().x + 64.0f && g_pEnemy[3]->getPos().x >= g_pEnemy[5]->getPos().x - (64.0f - Enemy_Speed_Limit_X))
			{
				if (g_pEnemy[3]->getPos().y > g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y2 = 2.0f;
					ENEMY_SPEED_Y3 = -2.0f;
				}
				else if (g_pEnemy[3]->getPos().y < g_pEnemy[5]->getPos().y)
				{
					ENEMY_SPEED_Y2 = -2.0f;
					ENEMY_SPEED_Y3 = 2.0f;
				}
			}
			//���E�̓����蔻��
			else if (g_pEnemy[3]->getPos().y <= g_pEnemy[5]->getPos().y + 96.0f && g_pEnemy[3]->getPos().y >= g_pEnemy[5]->getPos().y - (96.0f - Enemy_Speed_Limit_Y))
			{
				if (g_pEnemy[3]->getPos().x > g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X2 = 2.0f;
					ENEMY_SPEED_X3 = -2.0f;
				}
				else if (g_pEnemy[3]->getPos().x < g_pEnemy[5]->getPos().x)
				{
					ENEMY_SPEED_X2 = -2.0f;
					ENEMY_SPEED_X3 = 2.0f;
				}
			}
		}
	}
}