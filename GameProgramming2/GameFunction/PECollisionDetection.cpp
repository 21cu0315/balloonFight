//----------------------------------------------------------
// �t�@�C����		�FPECollusionDetection.cpp
// �T�v				�F�v���C���[�ƓG�L�����̓����蔻��
// �쐬��			�F21CU0315 ���쌫
// �X�V���e			�F2022/03/07 21CU0315 ���쌫 �쐬
//					�F2022/03/08 21CU0315 ���쌫 �v���C���[�ƓG�̈ʒu�ɂ���āA�����蔻����C��
//					�F2022/03/15 21CU0315 ���쌫 �v���C���[�ƓG�̓����蔻����C��
//					�F2022/03/15 21CU0118 ���r�T�V�� �G�̏��������ǉ�
//					�F2022/03/15 21CU0118 ���r�T�V�� �G�̏�������̏C��
//					�F2022/03/25 21CU0118 ���r�T�V�� �G�ƃv���C���[�̓����蔻��ɏ����A�G�̃X�s�[�h��0�Aif���̒ǉ�
//					�F2022/03/30 21CU0118 ���r�T�V�� �G�������Ă��Ȃ����̏����̒ǉ�
//					�F2022/04/05 21CU0315 ���쌫 �v���C���[�ƓG�̓����蔻��͈̔͂����P���܂���
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::PECollusionDetection()
{
	//�v���C���[�ƓG�̓����蔻��
	for (int i = 0; i < EnemyQuantity; ++i)
	{
		for (int j = 0; j < PlayerQuantity; ++j)
		{
			if (g_pEnemy[i] != NULL)
			{
				if (PlayerInvincible != false && playerIsDead != true)
				{
					if (g_pPlayer1[j]->getPos().x < WINDOW_WIDTH / 2 + PLAYER_SIZE_X / 2 && g_pPlayer1[j]->getPos().x > -WINDOW_WIDTH / 2 - PLAYER_SIZE_X / 2
						&& g_pEnemy[i]->getPos().x < WINDOW_WIDTH / 2 + PLAYER_SIZE_X / 2 && g_pEnemy[i]->getPos().x > -WINDOW_WIDTH / 2 - PLAYER_SIZE_X / 2)
					{
						if (j == 0)
						{
							if (i == EnemyType01_01 || i == EnemyType01_02)
							{
								if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] != true)
								{
									//������
									//�v���C���[���E�A�G�l�~�[����
									if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x  && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 64.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = 2.0f;
										ENEMY_SPEED_X = -2.0f;

									}
									//�v���C���[�����A�G�l�~�[���E
									else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x  && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 64.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = -2.0f;
										ENEMY_SPEED_X = 2.0f;
									}
									//�v���C���[���ォ��
									else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + (96.0f + GravLimi))
									{
										//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
										moveY = 2.0f;
									}
									//�v���C���[��������
									else if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y - 96.0f);
										moveY = -2.0f;
										ENEMY_SPEED_Y = 2.0f;
									}
									//�v���C���[�̃o���[���̓����蔻��
									if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - 36.0f)
									{
										//�v���C���[�̎c�@�̒���
										/*
										* �ŏ��Ƀo���[���̎c�@�̒���
										* �o���[���̎c�@���Ȃ��Ȃ�����v���C���[�̎c�@
										*/
										if (enemyBalloonIsBroken[0] != true)
										{
											if (PlayerBalloon > 0)
											{
												//�o���[���̎c�@�̌���
												PlayerBalloon--;
												//�����Ńo���[���̎c�@�̊m�F
												//�o���[���̎c�@��0�ɂȂ��Ă�����
												//�v���C���[�̎c�@�̌���
												if (PlayerBalloon == 0)
												{
													PlayerDieBalloon = true;
												};
												return;
											}
										}
									}
									else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + 36.0f)
									{
										if (enemyBalloonIsBroken[0] == false)
										{
											g_score += 500;
											enemyBalloonIsBroken[0] = true;
											//�X�s�[�h��0�ɂ���
											ENEMY_SPEED_X = 0.0f;
											//�����̕ύX
											if (iEnemyStrong[0] == 0)
											{
												iEnemyStrong[0] = 1;
											}
											else if (iEnemyStrong[0] == 1)
											{
												iEnemyStrong[0] = 2;
											}
										}
										//�G�̃o���[�������ꂽ��
										else if (enemyBalloonIsBroken[0] == true)
										{
											if (enemyIsDead[0] != true)
											{
												g_score += 1000;
												enemyIsDead[0] = true;
											}
										}
									}
								}
								else if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] == true && g_pPlayer1[j]->getPos().y <= g_pEnemy[i]->getPos().y + 60.0f)
								{
									if (enemyIsDead[0] != true)
									{
										g_score += 750;
										enemyIsDead[0] = true;

										if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 26.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 26.0f)
										{
											//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
											g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 60.0f);
											moveY = 2.0f;
										}
										else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 26.0f)
										{
											g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 58.0f, g_pPlayer1[j]->getPos().y);
											playerHoriSpeed = 2.0f;
											ENEMY_SPEED_X = -2.0f;
										}
										else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 26.0f)
										{
											g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 58.0f, g_pPlayer1[j]->getPos().y);
											playerHoriSpeed = -2.0f;
											ENEMY_SPEED_X = 2.0f;
										}
									}
								}
							}
							else if (i == EnemyType02_01 || i == EnemyType02_02)
							{
								if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[1] != true)
								{
									//������
									//�v���C���[���E�A�G�l�~�[����
									if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f))
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 64.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = 2.0f;
										ENEMY_SPEED_X2 = -2.0f;

									}
									//�v���C���[�����A�G�l�~�[���E
									else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 64.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = -2.0f;
										ENEMY_SPEED_X2 = 2.0f;

									}
									//�v���C���[���ォ��
									else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + (96.0f + GravLimi))
									{
										//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
										moveY = 2.0f;
									}
									//�v���C���[��������
									else if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y - 96.0f);
										moveY = -2.0f;
										ENEMY_SPEED_Y2 = 2.0f;
									}
									//�v���C���[�̃o���[���̓����蔻��
									if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - 36.0f)
									{
										//�v���C���[�̎c�@�̒���
										/*
										* �ŏ��Ƀo���[���̎c�@�̒���
										* �o���[���̎c�@���Ȃ��Ȃ�����v���C���[�̎c�@
										*/
										if (enemyBalloonIsBroken[1] != true)
										{
											if (PlayerBalloon > 0)
											{
												//�o���[���̎c�@�̌���
												PlayerBalloon--;
												//�����Ńo���[���̎c�@�̊m�F
												//�o���[���̎c�@��0�ɂȂ��Ă�����
												//�v���C���[�̎c�@�̌���
												if (PlayerBalloon == 0)
												{
													PlayerDieBalloon = true;
												};
												return;
											}
										}
									}
									else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + 36.0f)
									{
										if (enemyBalloonIsBroken[1] == false)
										{
											g_score += 500;
											enemyBalloonIsBroken[1] = true;
											//�X�s�[�h��0�ɂ���
											ENEMY_SPEED_X2 = 0.0f;
											//�����̕ύX
											if (iEnemyStrong[1] == 0)
											{
												iEnemyStrong[1] = 1;
											}
											else if (iEnemyStrong[1] == 1)
											{
												iEnemyStrong[1] = 2;
											}
										}
										//�G�̃o���[�������ꂽ��
										else if (enemyBalloonIsBroken[1] == true)
										{
											if (enemyIsDead[1] != true)
											{
												g_score += 1000;
												enemyIsDead[1] = true;
											}
										}
									}
								}
								else if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] == true && g_pPlayer1[j]->getPos().y <= g_pEnemy[i]->getPos().y + 60.0f)
								{
									if (enemyIsDead[1] != true)
									{
										g_score += 750;
										enemyIsDead[1] = true;

										if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 26.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 26.0f)
										{
											//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
											g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 60.0f);
											moveY = 2.0f;
										}
										else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 26.0f)
										{
											g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 58.0f, g_pPlayer1[j]->getPos().y);
											playerHoriSpeed = 2.0f;
											ENEMY_SPEED_X2 = -2.0f;
										}
										else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 26.0f)
										{
											g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 58.0f, g_pPlayer1[j]->getPos().y);
											playerHoriSpeed = -2.0f;
											ENEMY_SPEED_X2 = 2.0f;
										}
									}
								}
							}
							else if (i == EnemyType03_01 || i == EnemyType03_02)
							{
								if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[2] != true)
								{
									//������
									//�v���C���[���E�A�G�l�~�[����
									if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f))
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 64.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = 2.0f;
										ENEMY_SPEED_X3 = -2.0f;

									}
									//�v���C���[�����A�G�l�~�[���E
									else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 64.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = -2.0f;
										ENEMY_SPEED_X3 = 2.0f;

									}
									//�v���C���[���ォ��
									else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + (96.0f + GravLimi))
									{
										//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
										moveY = 2.0f;
									}
									//�v���C���[��������
									else if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
									{
										//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y - 96.0f);
										moveY = -2.0f;
										ENEMY_SPEED_Y3 = 2.0f;
									}
									//�v���C���[�̃o���[���̓����蔻��
									if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - 36.0f)
									{
										//�v���C���[�̎c�@�̒���
										/*
										* �ŏ��Ƀo���[���̎c�@�̒���
										* �o���[���̎c�@���Ȃ��Ȃ�����v���C���[�̎c�@
										*/
										if (enemyBalloonIsBroken[2] != true)
										{
											if (PlayerBalloon > 0)
											{
												//�o���[���̎c�@�̌���
												PlayerBalloon--;
												//�����Ńo���[���̎c�@�̊m�F
												//�o���[���̎c�@��0�ɂȂ��Ă�����
												//�v���C���[�̎c�@�̌���
												if (PlayerBalloon == 0)
												{
													PlayerDieBalloon = true;
												};
												return;
											}
										}
									}
									else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + 36.0f)
									{
										if (enemyBalloonIsBroken[2] == false)
										{
											g_score += 500;
											enemyBalloonIsBroken[2] = true;
											//�X�s�[�h��0�ɂ���
											ENEMY_SPEED_X3 = 0.0f;
											//�����̕ύX
											if (iEnemyStrong[2] == 0)
											{
												iEnemyStrong[2] = 1;
											}
											else if (iEnemyStrong[2] == 1)
											{
												iEnemyStrong[2] = 2;
											}
										}
										//�G�̃o���[�������ꂽ��
										else if (enemyBalloonIsBroken[2] == true)
										{
											if (enemyIsDead[2] != true)
											{
												g_score += 1000;
												enemyIsDead[2] = true;
											}
										}
									}
								}
								else if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] == true && g_pPlayer1[j]->getPos().y <= g_pEnemy[i]->getPos().y + 60.0f)
								{
									if (enemyIsDead[2] != true)
									{
										g_score += 750;
										enemyIsDead[2] = true;

										if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 26.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 26.0f)
										{
											//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
											g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 60.0f);
											moveY = 2.0f;
										}
										else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 26.0f)
										{
											g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 58.0f, g_pPlayer1[j]->getPos().y);
											playerHoriSpeed = 2.0f;
											ENEMY_SPEED_X3 = -2.0f;
										}
										else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 26.0f)
										{
											g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 58.0f, g_pPlayer1[j]->getPos().y);
											playerHoriSpeed = -2.0f;
											ENEMY_SPEED_X3 = 2.0f;
										}
									}
								}
							}
						}
						else if (j == 1)
						{
						if (i == EnemyType01_01 || i == EnemyType01_02)
						{

							if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] != true)
							{
								//������
								//�v���C���[���E�A�G�l�~�[����
								if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f))
								{
									g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 64.0f, g_pPlayer1[j]->getPos().y);
									playerHoriSpeed = 2.0f;
									ENEMY_SPEED_X = -2.0f;

								}
								//�v���C���[�����A�G�l�~�[���E
								else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
								{
									g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 64.0f, g_pPlayer1[j]->getPos().y);
									playerHoriSpeed = -2.0f;
									ENEMY_SPEED_X = 2.0f;

								}
								//�v���C���[���ォ��
								else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y)
								{
									//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
									g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
									moveY = 2.0f;
								}
								//�v���C���[��������
								else if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y)
								{
									//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
									g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y - 96.0f);
									moveY = -2.0f;
									ENEMY_SPEED_Y = 2.0f;
								}
								//�v���C���[�̃o���[���̓����蔻��
								if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - 36.0f)
								{
									//�v���C���[�̎c�@�̒���
									/*
									* �ŏ��Ƀo���[���̎c�@�̒���
									* �o���[���̎c�@���Ȃ��Ȃ�����v���C���[�̎c�@
									*/
									if (enemyBalloonIsBroken[0] != true)
									{
										if (PlayerBalloon > 0)
										{
											//�o���[���̎c�@�̌���
											PlayerBalloon--;
											//�����Ńo���[���̎c�@�̊m�F
											//�o���[���̎c�@��0�ɂȂ��Ă�����
											//�v���C���[�̎c�@�̌���
											if (PlayerBalloon == 0)
											{
												PlayerDieBalloon = true;
											};
											return;
										}
									}
								}
								else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + 36.0f)
								{
									if (enemyBalloonIsBroken[0] == false)
									{
										g_score += 500;
										enemyBalloonIsBroken[0] = true;
										//�X�s�[�h��0�ɂ���
										ENEMY_SPEED_X = 0.0f;
										//�����̕ύX
										if (iEnemyStrong[0] == 0)
										{
											iEnemyStrong[0] = 1;
										}
										else if (iEnemyStrong[0] == 1)
										{
											iEnemyStrong[0] = 2;
										}
									}
									//�G�̃o���[�������ꂽ��
									else if (enemyBalloonIsBroken[0] == true)
									{
										if (enemyIsDead[0] != true)
										{
											g_score += 1000;
											enemyIsDead[0] = true;
											//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
											if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
												moveY = 2.0f;
											}
											else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x + 64.0f, g_pEnemy[i]->getPos().y);
											}
											else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x - 64.0f, g_pEnemy[i]->getPos().y);
											}
										}
									}
								}
							}
							else if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] == true && g_pPlayer1[j]->getPos().y <= g_pEnemy[i]->getPos().y + 60.0f)
							{
								if (enemyIsDead[0] != true)
								{
									g_score += 750;
									enemyIsDead[0] = true;

									if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 26.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 26.0f)
									{
										//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 60.0f);
										moveY = 2.0f;
									}
									else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 26.0f)
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 58.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = 2.0f;
										ENEMY_SPEED_X = -2.0f;
									}
									else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 26.0f)
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 58.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = -2.0f;
										ENEMY_SPEED_X = 2.0f;
									}
								}
							}
						}
						else if (i == EnemyType02_01 || i == EnemyType02_02)
						{
							if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[1] != true)
							{
								//������
								//�v���C���[���E�A�G�l�~�[����
								if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f))
								{
									g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 64.0f, g_pPlayer1[j]->getPos().y);
									playerHoriSpeed = 2.0f;
									ENEMY_SPEED_X2 = -2.0f;

								}
								//�v���C���[�����A�G�l�~�[���E
								else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
								{
									g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 64.0f, g_pPlayer1[j]->getPos().y);
									playerHoriSpeed = -2.0f;
									ENEMY_SPEED_X2 = 2.0f;

								}
								//�v���C���[���ォ��
								else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y)
								{
									//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
									g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
									moveY = 2.0f;
								}
								//�v���C���[��������
								else if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y)
								{
									//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
									g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y - 96.0f);
									moveY = -2.0f;
									ENEMY_SPEED_Y2 = 2.0f;
								}
								//�v���C���[�̃o���[���̓����蔻��
								if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - 36.0f)
								{
									//�v���C���[�̎c�@�̒���
									/*
									* �ŏ��Ƀo���[���̎c�@�̒���
									* �o���[���̎c�@���Ȃ��Ȃ�����v���C���[�̎c�@
									*/
									if (enemyBalloonIsBroken[1] != true)
									{
										if (PlayerBalloon > 0)
										{
											//�o���[���̎c�@�̌���
											PlayerBalloon--;
											//�����Ńo���[���̎c�@�̊m�F
											//�o���[���̎c�@��0�ɂȂ��Ă�����
											//�v���C���[�̎c�@�̌���
											if (PlayerBalloon == 0)
											{
												PlayerDieBalloon = true;
											};
											return;
										}
									}
								}
								else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + 36.0f)
								{
									if (enemyBalloonIsBroken[1] == false)
									{
										g_score += 500;
										enemyBalloonIsBroken[1] = true;
										//�X�s�[�h��0�ɂ���
										ENEMY_SPEED_X2 = 0.0f;
										//�����̕ύX
										if (iEnemyStrong[1] == 0)
										{
											iEnemyStrong[1] = 1;
										}
										else if (iEnemyStrong[1] == 1)
										{
											iEnemyStrong[1] = 2;
										}
									}
									//�G�̃o���[�������ꂽ��
									else if (enemyBalloonIsBroken[1] == true)
									{
										if (enemyIsDead[1] != true)
										{
											g_score += 1000;
											enemyIsDead[1] = true;
											//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
											if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
												moveY = 2.0f;
											}
											else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x + 64.0f, g_pEnemy[i]->getPos().y);
											}
											else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x - 64.0f, g_pEnemy[i]->getPos().y);
											}
										}
									}
								}
							}
							else if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] == true && g_pPlayer1[j]->getPos().y <= g_pEnemy[i]->getPos().y + 60.0f)
							{
								if (enemyIsDead[1] != true)
								{
									g_score += 750;
									enemyIsDead[1] = true;

									if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 26.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 26.0f)
									{
										//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 60.0f);
										moveY = 2.0f;
									}
									else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 26.0f)
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 58.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = 2.0f;
										ENEMY_SPEED_X2 = -2.0f;
									}
									else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 26.0f)
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 58.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = -2.0f;
										ENEMY_SPEED_X2 = 2.0f;
									}
								}
							}
						}
						else if (i == EnemyType03_01 || i == EnemyType03_02)
						{
							if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[2] != true)
							{
								//������
								//�v���C���[���E�A�G�l�~�[����
								if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f))
								{
									g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 64.0f, g_pPlayer1[j]->getPos().y);
									playerHoriSpeed = 2.0f;
									ENEMY_SPEED_X3 = -2.0f;

								}
								//�v���C���[�����A�G�l�~�[���E
								else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f && g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y + (96.0f + GravLimi) && g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y - (96.0f + GravLimi))
								{
									g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 64.0f, g_pPlayer1[j]->getPos().y);
									playerHoriSpeed = -2.0f;
									ENEMY_SPEED_X3 = 2.0f;

								}
								//�v���C���[���ォ��
								else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y)
								{
									//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
									g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
									moveY = 2.0f;
								}
								//�v���C���[��������
								else if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y)
								{
									//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
									g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y - 96.0f);
									moveY = -2.0f;
									ENEMY_SPEED_Y3 = 2.0f;
								}
								//�v���C���[�̃o���[���̓����蔻��
								if (g_pPlayer1[j]->getPos().y < g_pEnemy[i]->getPos().y - 36.0f)
								{
									//�v���C���[�̎c�@�̒���
									/*
									* �ŏ��Ƀo���[���̎c�@�̒���
									* �o���[���̎c�@���Ȃ��Ȃ�����v���C���[�̎c�@
									*/
									if (enemyBalloonIsBroken[2] != true)
									{
										if (PlayerBalloon > 0)
										{
											//�o���[���̎c�@�̌���
											PlayerBalloon--;
											//�����Ńo���[���̎c�@�̊m�F
											//�o���[���̎c�@��0�ɂȂ��Ă�����
											//�v���C���[�̎c�@�̌���
											if (PlayerBalloon == 0)
											{
												PlayerDieBalloon = true;
											};
											return;
										}
									}
								}
								else if (g_pPlayer1[j]->getPos().y > g_pEnemy[i]->getPos().y + 36.0f)
								{
									if (enemyBalloonIsBroken[2] == false)
									{
										g_score += 500;
										enemyBalloonIsBroken[2] = true;
										//�X�s�[�h��0�ɂ���
										ENEMY_SPEED_X3 = 0.0f;
										//�����̕ύX
										if (iEnemyStrong[2] == 0)
										{
											iEnemyStrong[2] = 1;
										}
										else if (iEnemyStrong[2] == 1)
										{
											iEnemyStrong[2] = 2;
										}
									}
									//�G�̃o���[�������ꂽ��
									else if (enemyBalloonIsBroken[2] == true)
									{
										if (enemyIsDead[2] != true)
										{
											g_score += 1000;
											enemyIsDead[2] = true;
											//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
											if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 64.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 96.0f);
												moveY = 2.0f;
											}
											else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x + 64.0f, g_pEnemy[i]->getPos().y);
											}
											else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 64.0f)
											{
												g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x - 64.0f, g_pEnemy[i]->getPos().y);
											}
										}
									}
								}
							}
							else if (g_pPlayer1[j]->collision(g_pEnemy[i]) != false && enemyOnGround[0] == true && g_pPlayer1[j]->getPos().y <= g_pEnemy[i]->getPos().y + 60.0f)
							{
								if (enemyIsDead[2] != true)
								{
									g_score += 750;
									enemyIsDead[2] = true;

									if (g_pPlayer1[j]->getPos().x < g_pEnemy[i]->getPos().x + 26.0f && g_pPlayer1[j]->getPos().x > g_pEnemy[i]->getPos().x - 26.0f)
									{
										//�v���C���[�̍��W��G�ɐڂ���ʒu�܂Œ�������
										g_pPlayer1[j]->setPos(g_pPlayer1[j]->getPos().x, g_pEnemy[i]->getPos().y + 60.0f);
										moveY = 2.0f;
									}
									else if (g_pPlayer1[j]->getPos().x >= g_pEnemy[i]->getPos().x + 26.0f)
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x + 58.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = 2.0f;
										ENEMY_SPEED_X3 = -2.0f;
									}
									else if (g_pPlayer1[j]->getPos().x <= g_pEnemy[i]->getPos().x - 26.0f)
									{
										g_pPlayer1[j]->setPos(g_pEnemy[i]->getPos().x - 58.0f, g_pPlayer1[j]->getPos().y);
										playerHoriSpeed = -2.0f;
										ENEMY_SPEED_X3 = 2.0f;
									}
								}
							}
						}
						}
					}
				}
			}
		}

	}
}