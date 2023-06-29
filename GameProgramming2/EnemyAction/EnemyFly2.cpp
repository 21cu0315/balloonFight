//----------------------------------------------------------
// �t�@�C����		�FEnemyFly2
// �T�v				�F�G�L�����N�^�[1�i�K�ڂ̍s��
// �쐬��			�F21cu0118 ���r�T�V��
// �X�V���e			�F2022/03/15 21cu0118 ���r�T�V�� �쐬
//					�F2022/03/15 21cu0118 ���r�T�V�� �G�����̒l�܂œ����Ȃ�����v���O�����쐬
//					�F2022/03/16 21cu0118 ���r�T�V�� �G���C�ɗ����Ȃ��悤�ɂ���v���O�������쐬
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyFly2()
{
	//�v���C���[1�̍s��
	if (Enemy_Defeat[0] == false)
	{
		if (g_pEnemy[0] != NULL && EnemyStateChange[0] == 1)
		{
			//3�b�Ԃ͓����Ȃ�
			if (Enemy1.EnemyMove_2_3 != 180)
			{
				Enemy1.EnemyMove_2_3++;
			}
			else
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
					//60*15�b�ԓ�����
					Enemy1.EnemyMoveTime++;
					if (Enemy1.EnemyMoveTime == 60 * 2)
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
					if (g_pEnemy[0]->getPos().y < g_pGround[0]->getPos().y + 20.0f)
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
			}
		}
	}
	//�v���C���[2�̍s��
	if (Enemy_Defeat[1] == false)
	{
		if (g_pEnemy[2] != NULL && EnemyStateChange[1] == 1)
		{
			//3�b�Ԃ͓����Ȃ�
			if (Enemy2.EnemyMove_2_3 != 180)
			{
				Enemy2.EnemyMove_2_3++;
			}
			else
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
					else if (Enemy2.PlayerPos.x > g_pEnemy[2]->getPos().x)
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
					if (g_pEnemy[0]->getPos().y < g_pGround[0]->getPos().y + 20.0f)
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
			}
		}
	}
	//�v���C���[3�̍s��
	if (Enemy_Defeat[2] == false)
	{
		if (g_pEnemy[4] != NULL && EnemyStateChange[2] == 1)
		{
			//3�b�Ԃ͓����Ȃ�
			if (Enemy3.EnemyMove_2_3 != 180)
			{
				Enemy3.EnemyMove_2_3++;
			}
			else
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
					//60*15�b�ԓ�����
					Enemy3.EnemyMoveTime++;
					if (Enemy3.EnemyMoveTime == 60 * 2)
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
					else if (Enemy3.PlayerPos.x > g_pEnemy[4]->getPos().x)
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
					if (g_pEnemy[2]->getPos().y < g_pGround[0]->getPos().y + 10.0f)
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
					//���W����ɋ���Ƃ�
					else if (Enemy3.PlayerPos.y > g_pEnemy[4]->getPos().y)
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
			}
		}
	}
}