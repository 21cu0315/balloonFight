//----------------------------------------------------------
// �t�@�C����		�FEnemyFly1
// �T�v				�F�G�L�����N�^�[1�i�K�ڂ̍s��
// �쐬��			�F21cu0118 ���r�T�V��
// �X�V���e			�F2022/03/07 21cu0118 ���r�T�V�� �쐬
//					�F2022/03/08 21cu0118 ���r�T�V��
//					�F2022/03/10 21cu0118 ���r�T�V�� �L��������
//					�F2022/03/11 21cu0118 ���r�T�V�� �L�����̋����C��
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyFly1()
{
	//�G����莞�ԍs���𐧌�����
	if (bEnemyTimeUp == false)
	{
		//��莞�ԓ����Ȃ�������p�̊֐��̌Ăяo��
		bEnemyTimeUp = Enemy_Start_Time();
	}
	else
	{
		//�v���C���[1�̍s��
		if (g_pEnemy[0] != NULL && EnemyStateChange[0] == 0 && enemyBalloonIsBroken[0] == false)
		{
			//�v���C���[�̍��W����x�擾����
			if (Enemy1.EnemyMoveTrue == false)
			{
				Enemy1.PlayerPos.x = g_pPlayer1[0]->getPos().x;
				Enemy1.PlayerPos.y = g_pPlayer1[0]->getPos().y;
				//�ϐ���ύX����
				Enemy1.EnemyMoveTrue = true;
			}
			else
			{
				//������Ԃ̎�
				if (iEnemyStrong[0] == 0)
				{
					//60*15�b�ԓ�����
					Enemy1.EnemyMoveTime++;
					if (Enemy1.EnemyMoveTime == 60 * 3)
					{
						//�^�C���̃��Z�b�g
						Enemy1.EnemyMoveTime = 0;
						//���W��������x�擾
						Enemy1.EnemyMoveTrue = false;
					}
					//���W���E�ɂ���Ƃ�
					if (Enemy1.PlayerPos.x < g_pEnemy[0]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A���܂肪0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 10 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X)
							{
								ENEMY_SPEED_X -= 0.1f;
							}
						}
					}
					//���W��荶�ɂ���Ƃ�
					if (Enemy1.PlayerPos.x > g_pEnemy[0]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 10 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X)
							{
								ENEMY_SPEED_X += 0.1f;
							}
						}
					}
					//���W����ɋ���Ƃ�
					if (Enemy1.PlayerPos.y < g_pEnemy[0]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 10 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y -= 0.1f;
							}
						}
					}
					//����̈ʒu�����G�����ɂ��鎞
					if (g_pEnemy[0]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y += 0.1f;
							}
						}
					}
					//���W��艺�ɋ���Ƃ�
					else if (Enemy1.PlayerPos.y > g_pEnemy[0]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 10 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y += 0.1f;
							}
						}
					}
				}

				//2�i�K�ڂ̎�
				if (iEnemyStrong[0] == 1)
				{
					//60*15�b�ԓ�����
					Enemy1.EnemyMoveTime++;
					if (Enemy1.EnemyMoveTime == 60 * 3)
					{
						//�^�C���̃��Z�b�g
						Enemy1.EnemyMoveTime = 0;
						//���W��������x�擾
						Enemy1.EnemyMoveTrue = false;
					}
					//���W���E�ɂ���Ƃ�
					if (Enemy1.PlayerPos.x < g_pEnemy[0]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A���܂肪0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 5 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X)
							{
								ENEMY_SPEED_X -= 0.1f;
							}
						}
					}
					//���W��荶�ɂ���Ƃ�
					if (Enemy1.PlayerPos.x > g_pEnemy[0]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 5 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X)
							{
								ENEMY_SPEED_X += 0.1f;
							}
						}
					}
					//���W����ɋ���Ƃ�
					if (Enemy1.PlayerPos.y < g_pEnemy[0]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 5 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y -= 0.1f;
							}
						}
					}
					//����̈ʒu�����G�����ɂ��鎞
					if (g_pEnemy[0]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y += 0.3f;
							}
						}
					}
					//���W��艺�ɋ���Ƃ�
					else if (Enemy1.PlayerPos.y > g_pEnemy[0]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 5 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y += 0.1f;
							}
						}
					}
				}

				//3�i�K�ڂ̎�
				if (iEnemyStrong[0] == 2)
				{
					//60*15�b�ԓ�����
					Enemy1.EnemyMoveTime++;
					if (Enemy1.EnemyMoveTime == 60 * 3)
					{
						//�^�C���̃��Z�b�g
						Enemy1.EnemyMoveTime = 0;
						//���W��������x�擾
						Enemy1.EnemyMoveTrue = false;
					}
					//���W���E�ɂ���Ƃ�
					if (Enemy1.PlayerPos.x < g_pEnemy[0]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A���܂肪0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X)
							{
								ENEMY_SPEED_X -= 0.1f;
							}
						}
					}
					//���W��荶�ɂ���Ƃ�
					if (Enemy1.PlayerPos.x > g_pEnemy[0]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X)
							{
								ENEMY_SPEED_X += 0.1f;
							}
						}
					}
					//���W����ɋ���Ƃ�
					if (Enemy1.PlayerPos.y < g_pEnemy[0]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y -= 0.1f;
							}
						}
					}
					//����̈ʒu�����G�����ɂ��鎞
					if (g_pEnemy[0]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y += 0.1f;
							}
						}
					}
					//���W��艺�ɋ���Ƃ�
					else if (Enemy1.PlayerPos.y > g_pEnemy[0]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y)
							{
								ENEMY_SPEED_Y += 0.1f;
							}
						}
					}
				}
			}
		}
		//�v���C���[2�̍s��
		if (g_pEnemy[2] != NULL && EnemyStateChange[1] == 0 && enemyBalloonIsBroken[1] == false)
		{
			//�v���C���[�̍��W����x�擾����
			if (Enemy2.EnemyMoveTrue == false)
			{
				Enemy2.PlayerPos.x = g_pPlayer1[0]->getPos().x;
				Enemy2.PlayerPos.y = g_pPlayer1[0]->getPos().y;
				//�ϐ���ύX����
				Enemy2.EnemyMoveTrue = true;
			}
			else
			{
				//�G�̋���1�i�K��
				if (iEnemyStrong[1] == 0)
				{
					//60*2�b�ԓ�����
					Enemy2.EnemyMoveTime++;
					if (Enemy2.EnemyMoveTime == 60 * 2)
					{
						//�^�C���̃��Z�b�g
						Enemy2.EnemyMoveTime = 0;
						//���W��������x�擾
						Enemy2.EnemyMoveTrue = false;
					}
					//���W���E�ɂ���Ƃ�
					if (Enemy2.PlayerPos.x < g_pEnemy[2]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy2.EnemyMoveTime % 10 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X2)
							{
								ENEMY_SPEED_X2 -= 0.1f;
							}
						}
					}
					//���W��荶�ɂ���Ƃ�
					if (Enemy2.PlayerPos.x > g_pEnemy[2]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy2.EnemyMoveTime % 10 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X2)
							{
								ENEMY_SPEED_X2 += 0.1f;
							}
						}
					}
					//���W����ɋ���Ƃ�
					if (Enemy2.PlayerPos.y < g_pEnemy[2]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 10 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 -= 0.1f;
							}
						}
					}
					//����̈ʒu�����G�����ɂ��鎞
					if (g_pEnemy[2]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 += 0.1f;
							}
						}
					}
					//���W��艺�ɋ���Ƃ�
					else if (Enemy2.PlayerPos.y > g_pEnemy[2]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy2.EnemyMoveTime % 10 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 += 0.1f;
							}
						}
					}
				}

				//�G�̋���2�i�K��
				if (iEnemyStrong[1] == 1)
				{
					//60*2�b�ԓ�����
					Enemy2.EnemyMoveTime++;
					if (Enemy2.EnemyMoveTime == 60 * 2)
					{
						//�^�C���̃��Z�b�g
						Enemy2.EnemyMoveTime = 0;
						//���W��������x�擾
						Enemy2.EnemyMoveTrue = false;
					}
					//���W���E�ɂ���Ƃ�
					if (Enemy2.PlayerPos.x < g_pEnemy[2]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy2.EnemyMoveTime % 5 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X2)
							{
								ENEMY_SPEED_X2 -= 0.1f;
							}
						}
					}
					//���W��荶�ɂ���Ƃ�
					if (Enemy2.PlayerPos.x > g_pEnemy[2]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy2.EnemyMoveTime % 5 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X2)
							{
								ENEMY_SPEED_X2 += 0.1f;
							}
						}
					}
					//���W����ɋ���Ƃ�
					if (Enemy2.PlayerPos.y < g_pEnemy[2]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 5 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 -= 0.1f;
							}
						}
					}
					//����̈ʒu�����G�����ɂ��鎞
					if (g_pEnemy[2]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 += 0.1f;
							}
						}
					}
					//���W��艺�ɋ���Ƃ�
					else if (Enemy2.PlayerPos.y > g_pEnemy[2]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy2.EnemyMoveTime % 5 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 += 0.1f;
							}
						}
					}
				}

				//�G�̋���3�i�K��
				if (iEnemyStrong[1] == 2)
				{
					//60*2�b�ԓ�����
					Enemy2.EnemyMoveTime++;
					if (Enemy2.EnemyMoveTime == 60 * 2)
					{
						//�^�C���̃��Z�b�g
						Enemy2.EnemyMoveTime = 0;
						//���W��������x�擾
						Enemy2.EnemyMoveTrue = false;
					}
					//���W���E�ɂ���Ƃ�
					if (Enemy2.PlayerPos.x < g_pEnemy[2]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy2.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X2)
							{
								ENEMY_SPEED_X2 -= 0.1f;
							}
						}
					}
					//���W��荶�ɂ���Ƃ�
					if (Enemy2.PlayerPos.x > g_pEnemy[2]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy2.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X2)
							{
								ENEMY_SPEED_X2 += 0.1f;
							}
						}
					}
					//���W����ɋ���Ƃ�
					if (Enemy2.PlayerPos.y < g_pEnemy[2]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 -= 0.1f;
							}
						}
					}
					//����̈ʒu�����G�����ɂ��鎞
					if (g_pEnemy[2]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy1.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 += 0.1f;
							}
						}
					}
					//���W��艺�ɋ���Ƃ�
					else if (Enemy2.PlayerPos.y > g_pEnemy[2]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy2.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y2)
							{
								ENEMY_SPEED_Y2 += 0.1f;
							}
						}
					}
				}
			}
		}
		//�v���C���[3�̍s��
		if (g_pEnemy[4] != NULL && EnemyStateChange[2] == 0 && enemyBalloonIsBroken[2] == false)
		{
			//�v���C���[�̍��W����x�擾����
			if (Enemy3.EnemyMoveTrue == false)
			{
				Enemy3.PlayerPos.x = g_pPlayer1[0]->getPos().x;
				Enemy3.PlayerPos.y = g_pPlayer1[0]->getPos().y;
				//�ϐ���ύX����
				Enemy3.EnemyMoveTrue = true;
			}
			else
			{
				//�G�̋���1�i�K��
				if (iEnemyStrong[2] == 0)
				{
					//60*15�b�ԓ�����
					Enemy3.EnemyMoveTime++;
					if (Enemy3.EnemyMoveTime == 60 * 4)
					{
						//�^�C���̃��Z�b�g
						Enemy3.EnemyMoveTime = 0;
						//���W��������x�擾
						Enemy3.EnemyMoveTrue = false;
					}
					//���W���E�ɂ���Ƃ�
					if (Enemy3.PlayerPos.x < g_pEnemy[4]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 10 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X3)
							{
								ENEMY_SPEED_X3 -= 0.1f;
							}
						}
					}
					//���W��荶�ɂ���Ƃ�
					if (Enemy3.PlayerPos.x > g_pEnemy[4]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 10 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X3)
							{
								ENEMY_SPEED_X3 += 0.1f;
							}
						}
					}
					//���W����ɋ���Ƃ�
					if (Enemy3.PlayerPos.y < g_pEnemy[4]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 10 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 -= 0.1f;
							}
						}
					}
					//����̈ʒu�����G�����ɂ��鎞
					if (g_pEnemy[4]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 += 0.2f;
							}
						}
					}
					//���W��艺�ɋ���Ƃ�
					if (Enemy3.PlayerPos.y > g_pEnemy[4]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 10 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 += 0.1f;
							}
						}
					}
				}

				//�G�̋���2�i�K��
				if (iEnemyStrong[2] == 1)
				{
					//60*15�b�ԓ�����
					Enemy3.EnemyMoveTime++;
					if (Enemy3.EnemyMoveTime == 60 * 4)
					{
						//�^�C���̃��Z�b�g
						Enemy3.EnemyMoveTime = 0;
						//���W��������x�擾
						Enemy3.EnemyMoveTrue = false;
					}
					//���W���E�ɂ���Ƃ�
					if (Enemy3.PlayerPos.x < g_pEnemy[4]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 5 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X3)
							{
								ENEMY_SPEED_X3 -= 0.1f;
							}
						}
					}
					//���W��荶�ɂ���Ƃ�
					if (Enemy3.PlayerPos.x > g_pEnemy[4]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 5 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X3)
							{
								ENEMY_SPEED_X3 += 0.1f;
							}
						}
					}
					//���W����ɋ���Ƃ�
					if (Enemy3.PlayerPos.y < g_pEnemy[4]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 5 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 -= 0.1f;
							}
						}
					}
					//����̈ʒu�����G�����ɂ��鎞
					if (g_pEnemy[4]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 += 0.2f;
							}
						}
					}
					//���W��艺�ɋ���Ƃ�
					if (Enemy3.PlayerPos.y > g_pEnemy[4]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 5 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 += 0.1f;
							}
						}
					}
				}
				//3�i�K��
				if (iEnemyStrong[2] == 2)
				{
					//60*15�b�ԓ�����
					Enemy3.EnemyMoveTime++;
					if (Enemy3.EnemyMoveTime == 60 * 4)
					{
						//�^�C���̃��Z�b�g
						Enemy3.EnemyMoveTime = 0;
						//���W��������x�擾
						Enemy3.EnemyMoveTrue = false;
					}
					//���W���E�ɂ���Ƃ�
					if (Enemy3.PlayerPos.x < g_pEnemy[4]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_X < ENEMY_SPEED_X3)
							{
								ENEMY_SPEED_X3 -= 0.1f;
							}
						}
					}
					//���W��荶�ɂ���Ƃ�
					if (Enemy3.PlayerPos.x > g_pEnemy[4]->getPos().x)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_X > ENEMY_SPEED_X3)
							{
								ENEMY_SPEED_X3 += 0.1f;
							}
						}
					}
					//���W����ɋ���Ƃ�
					if (Enemy3.PlayerPos.y < g_pEnemy[4]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (-Enemy_Speed_Limit_Y < ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 -= 0.1f;
							}
						}
					}
					//����̈ʒu�����G�����ɂ��鎞
					if (g_pEnemy[4]->getPos().y < g_pGround[0]->getPos().y + EnemyOutLine)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 += 0.2f;
							}
						}
					}
					//���W��艺�ɋ���Ƃ�
					if (Enemy3.PlayerPos.y > g_pEnemy[4]->getPos().y)
					{
						//���Ԃ�10�Ŋ������Ƃ��A0�ɂȂ�����l�����Z����
						if (Enemy3.EnemyMoveTime % 2 == 0)
						{
							//���~�b�g�
							if (Enemy_Speed_Limit_Y > ENEMY_SPEED_Y3)
							{
								ENEMY_SPEED_Y3 += 0.1f;
							}
						}
					}
				}
			}
		}
	}
}