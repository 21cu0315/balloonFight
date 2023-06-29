//----------------------------------------------------------
// �t�@�C����		�FEnemyBalloonBreak
// �T�v				�F�G�̃o���[�����j�󂳂ꂽ���̏���
// // �쐬��			�F21CU0315 ���쌫
// �X�V���e			�F2022/03/23 21CU0315 ���쌫 �쐬
//					�F2022/03/25 21CU0118 ���r�T�V�� �������̃X�s�[�h�̕ύX
//----------------------------------------------------------
#include "CActionGameApp.h"

int enemyFallingCounter[3] = { 0,0,0 };

void CActionGameApp::EnemyBalloonBreak()
{
	//Enemy1�̃o���[�������ꂽ��
	if (enemyBalloonIsBroken[0] == true && enemyIsDead[0] != true)
	{
		//Enemy1�̗����J�E���^�[����
		enemyFallingCounter[0]++;
		for (int i = 0; i < GroundQuantity; ++i)
		{
			if (g_pGround[i] != NULL && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL)
			{
				//Enemy1���n�ʂɓ��������Ƃ�
				if (g_pEnemy[0]->collision(g_pGround[i]) == true || g_pEnemy[1]->collision(g_pGround[i]) == true)
				{
					//�G���o���[��������Ă��Ȃ���������������
					if (enemyPumpBalloon[0] != true)
					{
						g_pEnemy[0]->setAnimation(2);
						g_pEnemy[1]->setAnimation(2);
					}
					//�������Ă��Ȃ�
					enemyDeadFalling[0] = false;
					//�G���n�ʂƐڂ��Ă���
					enemyOnGround[0] = true;
					ENEMY_SPEED_X = 0.0f;
					//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
					g_pEnemy[0]->setPos(g_pEnemy[0]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					g_pEnemy[1]->setPos(g_pEnemy[1]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					//�n�ʂɓ���������o���[������蒼���܂ł̎��Ԃ��v�Z����
					if (enemyPumpBalloonCDCounter[0] < 300)
					{
						enemyPumpBalloonCDCounter[0]++;
					}
					else if (enemyPumpBalloonCDCounter[0] == 300)
					{
						//�G���o���[�������n�߂�
						enemyPumpBalloon[0] = true;
					}
				}
				//�������Ă��Ȃ���
				else
				{
					ENEMY_SPEED_Y = -0.5f;
					//�����̃A�j���[�V�����𔭓�����
					enemyDeadFalling[0] = true;
				}
			}
			for (int j = 0; j < PlatFormQuantityL; ++j)
			{
				if (g_pPlatFormL[j] != NULL && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL)
				{
					//Enemy1������L�ɓ��������Ƃ�
					if (g_pEnemy[0]->collision(g_pPlatFormL[j]) == true || g_pEnemy[1]->collision(g_pPlatFormL[j]) == true)
					{
						//�G���o���[��������Ă��Ȃ���������������
						if (enemyPumpBalloon[0] != true)
						{
							g_pEnemy[0]->setAnimation(2);
							g_pEnemy[1]->setAnimation(2);
						}
						//�������Ă��Ȃ�
						enemyDeadFalling[0] = false;
						//�G���n�ʂƐڂ��Ă���
						enemyOnGround[0] = true;
						ENEMY_SPEED_X = 0.0f;
						//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
						g_pEnemy[0]->setPos(g_pEnemy[0]->getPos().x, g_pPlatFormL[j]->getPos().y + 64.0f);
						g_pEnemy[1]->setPos(g_pEnemy[1]->getPos().x, g_pPlatFormL[j]->getPos().y + 64.0f);
						//�n�ʂɓ���������o���[������蒼���܂ł̎��Ԃ��v�Z����
						if (enemyPumpBalloonCDCounter[0] < 300)
						{
							enemyPumpBalloonCDCounter[0]++;
						}
						else if (enemyPumpBalloonCDCounter[0] == 300)
						{
							//�G���o���[�������n�߂�
							enemyPumpBalloon[0] = true;
						}
					}
					//�������Ă��Ȃ���
					else
					{
						ENEMY_SPEED_Y = -0.5f;
						//�����̃A�j���[�V�����𔭓�����
						enemyDeadFalling[0] = true;
					}
				}
			}

			for (int k = 0; k < PlatFormQuantityS; ++k)
			{
				if (g_pPlatFormS[k] != NULL && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL)
				{
					//Enemy1������S�ɓ��������Ƃ�
					if (g_pEnemy[0]->collision(g_pPlatFormS[k]) == true || g_pEnemy[1]->collision(g_pPlatFormS[k]) == true)
					{
						if (enemyPumpBalloon[0] != true)
						{
							g_pEnemy[0]->setAnimation(2);
							g_pEnemy[1]->setAnimation(2);
						}
						//�������Ă��Ȃ�
						enemyDeadFalling[0] = false;
						//�G���n�ʂƐڂ��Ă���
						enemyOnGround[0] = true;
						ENEMY_SPEED_X = 0.0f;
						//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
						g_pEnemy[0]->setPos(g_pEnemy[0]->getPos().x, g_pPlatFormS[k]->getPos().y + 64.0f);
						g_pEnemy[1]->setPos(g_pEnemy[1]->getPos().x, g_pPlatFormS[k]->getPos().y + 64.0f);
						//�n�ʂɓ���������o���[������蒼���܂ł̎��Ԃ��v�Z����
						if (enemyPumpBalloonCDCounter[0] < 300)
						{
							enemyPumpBalloonCDCounter[0]++;
						}
						if (enemyPumpBalloonCDCounter[0] == 300)
						{
							//�G���o���[�������n�߂�
							enemyPumpBalloon[0] = true;
						}
					}
					//�������Ă��Ȃ���
					else
					{
						ENEMY_SPEED_Y = -0.5f;
						//�����̃A�j���[�V�����𔭓�����
						enemyDeadFalling[0] = true;
					}
				}
			}
		}
		//�������Ă��鎞�A�A�j���[�V�����̏���
		if (enemyDeadFalling[0] == true)
		{
			if (enemyFallingCounter[0] <= 10)
			{
				//�A�j���[�V�����͈̔͂�ݒ�
				g_pEnemy[0]->setAnimationRange(10, 12);
				g_pEnemy[1]->setAnimationRange(10, 12);
				//�T�t���[�����A�j���[�V�����𓮂�
				if (enemyFallingCounter[0] % 5 == 0)
				{
					g_pEnemy[0]->stepAnimation();
					g_pEnemy[1]->stepAnimation();
				}
			}
		}
		//�G���o���[�������n�߂���
		if (enemyPumpBalloon[0] == true)
		{
			//�G���o���[�������A�j���[�V�����̃J�E���^�[����
			enemyPumpBalloonCounter[0]++;
			//�A�j���[�V�����͈̔͂�ݒ�
			g_pEnemy[0]->setAnimationRange(3, 9);
			g_pEnemy[1]->setAnimationRange(3, 9);
			//30�t���[�����A�A�j���[�V�����𓮂�
			if (enemyPumpBalloonCounter[0] % 10 == 0)
			{
				g_pEnemy[0]->stepAnimation();
				g_pEnemy[1]->stepAnimation();
			}
			//�A�j���[�V��������񂾂������悤�ɐݒ肷��
			else if (enemyPumpBalloonCounter[0] > 70)
			{
				//�G�̕ϐ������Z�b�g����
				enemyPumpBalloon[0] = false;
				enemyBalloonIsBroken[0] = false;
				g_pEnemy[0]->setAnimation(0);
				g_pEnemy[1]->setAnimation(0);
				enemyPumpBalloonCDCounter[0] = 0;
				enemyFallingCounter[0] = 0;
				enemyPumpBalloonCounter[0] = 0;
				enemyOnGround[0] = false;
			}
		}
	}
	//Enemy2�̃o���[�������ꂽ��
	if (enemyBalloonIsBroken[1] == true && enemyIsDead[1] != true)
	{
		//Enemy2�̗����J�E���^�[
		enemyFallingCounter[1]++;
		for (int i = 0; i < GroundQuantity; ++i)
		{
			if (g_pGround[i] != NULL && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
			{
				//Enemy2���n�ʂƓ��������Ƃ�
				if (g_pEnemy[2]->collision(g_pGround[i]) == true || g_pEnemy[3]->collision(g_pGround[i]) == true)
				{
					//�G���o���[��������Ă��Ȃ���������������
					if (enemyPumpBalloon[1] != true)
					{
						g_pEnemy[2]->setAnimation(2);
						g_pEnemy[3]->setAnimation(2);
					}
					//�������Ă��Ȃ�
					enemyDeadFalling[1] = false;
					//�G���n�ʂƐڂ��Ă���
					enemyOnGround[1] = true;
					ENEMY_SPEED_X2 = 0.0f;
					//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
					g_pEnemy[2]->setPos(g_pEnemy[2]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					g_pEnemy[3]->setPos(g_pEnemy[3]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					//�n�ʂɓ���������o���[������蒼���܂ł̎��Ԃ��v�Z����
					if (enemyPumpBalloonCDCounter[1] < 300)
					{
						enemyPumpBalloonCDCounter[1]++;
					}
					else if (enemyPumpBalloonCDCounter[1] == 300)
					{
						//�G���o���[�������n�߂�
						enemyPumpBalloon[1] = true;
					}
				}
				//�������Ă��Ȃ���
				else
				{
					ENEMY_SPEED_Y2 = -0.5f;
					//�����A�j���[�V�����𔭓�
					enemyDeadFalling[1] = true;
				}
			}
		}
		for (int j = 0; j < PlatFormQuantityL; ++j)
		{
			if (g_pPlatFormL[j] != NULL && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
			{
				//Enemy2������L�Ɠ��������Ƃ�
				if (g_pEnemy[2]->collision(g_pPlatFormL[j]) == true || g_pEnemy[3]->collision(g_pPlatFormL[j]) == true)
				{
					//�G���o���[��������Ă��Ȃ���������������
					if (enemyPumpBalloon[1] != true)
					{
						g_pEnemy[2]->setAnimation(2);
						g_pEnemy[3]->setAnimation(2);
					}
					//�������Ă��Ȃ�
					enemyDeadFalling[1] = false;
					//�G���n�ʂƐڂ��Ă���
					enemyOnGround[1] = true;
					ENEMY_SPEED_X2 = 0.0f;
					//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
					g_pEnemy[2]->setPos(g_pEnemy[2]->getPos().x, g_pPlatFormL[j]->getPos().y + 64.0f);
					g_pEnemy[3]->setPos(g_pEnemy[3]->getPos().x, g_pPlatFormL[j]->getPos().y + 64.0f);
					//�n�ʂɓ���������o���[������蒼���܂ł̎��Ԃ��v�Z����
					if (enemyPumpBalloonCDCounter[1] < 300)
					{
						enemyPumpBalloonCDCounter[1]++;
					}
					else if (enemyPumpBalloonCDCounter[1] == 300)
					{
						//�G���o���[�������n�߂�
						enemyPumpBalloon[1] = true;
					}
				}
				else
				{
					ENEMY_SPEED_Y2 = -0.5f;
					//�����̃A�j���[�V�����𔭓�����
					enemyDeadFalling[1] = true;
				}
			}
		}
		for (int k = 0; k < PlatFormQuantityS; ++k)
		{
			if (g_pPlatFormS[k] != NULL && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
			{
				//Enemy2������S�Ɠ��������Ƃ�
				if (g_pEnemy[2]->collision(g_pPlatFormS[k]) == true || g_pEnemy[3]->collision(g_pPlatFormS[k]) == true)
				{
					//�G���o���[��������Ă��Ȃ���������������
					if (enemyPumpBalloon[1] != true)
					{
						g_pEnemy[2]->setAnimation(2);
						g_pEnemy[3]->setAnimation(2);
					}
					//�������Ă��Ȃ�
					enemyDeadFalling[1] = false;
					//�G���n�ʂƐڂ��Ă���
					enemyOnGround[1] = true;
					ENEMY_SPEED_X2 = 0.0f;
					//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
					g_pEnemy[2]->setPos(g_pEnemy[2]->getPos().x, g_pPlatFormS[k]->getPos().y + 64.0f);
					g_pEnemy[3]->setPos(g_pEnemy[3]->getPos().x, g_pPlatFormS[k]->getPos().y + 64.0f);
					//�n�ʂɓ���������o���[������蒼���܂ł̎��Ԃ��v�Z����
					if (enemyPumpBalloonCDCounter[1] < 300)
					{
						enemyPumpBalloonCDCounter[1]++;
					}
					else if (enemyPumpBalloonCDCounter[1] == 300)
					{
						//�G���o���[�������n�߂�
						enemyPumpBalloon[1] = true;
					}
				}
				else
				{
					ENEMY_SPEED_Y2 = -0.5f;
					//�����̃A�j���[�V�����𔭓�����
					enemyDeadFalling[1] = true;
				}
			}
		}
		//�������Ă��鎞�A�A�j���[�V�����̏���
		if (enemyDeadFalling[1] == true)
		{
			if (enemyFallingCounter[1] <= 10)
			{
				g_pEnemy[2]->setAnimationRange(10, 12);
				g_pEnemy[3]->setAnimationRange(10, 12);
				if (enemyFallingCounter[1] % 5 == 0)
				{
					g_pEnemy[2]->stepAnimation();
					g_pEnemy[3]->stepAnimation();
				}
			}
		}
		//�G���o���[�������n�߂���
		if (enemyPumpBalloon[1] == true)
		{
			//�G���o���[�������A�j���[�V�����̃J�E���^�[����
			enemyPumpBalloonCounter[1]++;
			//�A�j���[�V�����͈̔͂�ݒ�
			g_pEnemy[2]->setAnimationRange(3, 9);
			g_pEnemy[3]->setAnimationRange(3, 9);
			//30�t���[�����A�A�j���[�V�����𓮂�
			if (enemyPumpBalloonCounter[1] % 10 == 0)
			{
				g_pEnemy[2]->stepAnimation();
				g_pEnemy[3]->stepAnimation();
			}
			//�A�j���[�V��������񂾂������悤�ɐݒ肷��
			else if (enemyPumpBalloonCounter[1] > 70)
			{
				//�G�̕ϐ������Z�b�g����
				enemyPumpBalloon[1] = false;
				enemyBalloonIsBroken[1] = false;
				g_pEnemy[2]->setAnimation(0);
				g_pEnemy[3]->setAnimation(0);
				enemyPumpBalloonCDCounter[1] = 0;
				enemyFallingCounter[1] = 0;
				enemyPumpBalloonCounter[1] = 0;
				enemyOnGround[1] = false;
			}
		}
	}
	//Enemy3�̃o���[�������ꂽ��
	if (enemyBalloonIsBroken[2] == true && enemyIsDead[2] != true)
	{
		//Enemy3�̗����J�E���^�[����
		enemyFallingCounter[2]++;
		for (int i = 0; i < GroundQuantity; ++i)
		{
			if (g_pGround[i] != NULL && g_pEnemy[4] != NULL && g_pEnemy[5] != NULL)
			{
				//Enemy3���n�ʂƓ��������Ƃ�
				if (g_pEnemy[4]->collision(g_pGround[i]) == true || g_pEnemy[5]->collision(g_pGround[i]) == true)
				{
					//�G���o���[��������Ă��Ȃ���������������
					if (enemyPumpBalloon[2] != true)
					{
						g_pEnemy[4]->setAnimation(2);
						g_pEnemy[5]->setAnimation(2);
					}
					//�������Ă��Ȃ�
					enemyDeadFalling[2] = false;
					//�G���n�ʂƐڂ��Ă���
					enemyOnGround[2] = true;
					ENEMY_SPEED_X3 = 0.0f;
					//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
					g_pEnemy[4]->setPos(g_pEnemy[4]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					g_pEnemy[5]->setPos(g_pEnemy[5]->getPos().x, g_pGround[i]->getPos().y + 84.0f);
					//�n�ʂɓ���������o���[������蒼���܂ł̎��Ԃ��v�Z����
					if (enemyPumpBalloonCDCounter[2] < 300)
					{
						enemyPumpBalloonCDCounter[2]++;
					}
					else if (enemyPumpBalloonCDCounter[2] == 300)
					{
						//�G���o���[�������n�߂�
						enemyPumpBalloon[2] = true;
					}
				}
				else
				{
					ENEMY_SPEED_Y3 = -0.5f;
					//�����̃A�j���[�V�����𔭓�����
					enemyDeadFalling[2] = true;
				}
			}
		}
		for (int j = 0; j < PlatFormQuantityL; ++j)
		{
			if (g_pPlatFormL[j] != NULL && g_pEnemy[4] != NULL && g_pEnemy[5] != NULL)
			{
				//Enemy3������L�Ɠ��������Ƃ�
				if (g_pEnemy[4]->collision(g_pPlatFormL[j]) == true || g_pEnemy[5]->collision(g_pPlatFormL[j]) == true)
				{
					//�G���o���[��������Ă��Ȃ���������������
					if (enemyPumpBalloon[2] != true)
					{
						g_pEnemy[4]->setAnimation(2);
						g_pEnemy[5]->setAnimation(2);
					}
					//�������Ă��Ȃ�
					enemyDeadFalling[2] = false;
					//�G���n�ʂƐڂ��Ă���
					enemyOnGround[2] = true;
					ENEMY_SPEED_X3 = 0.0f;
					//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
					g_pEnemy[4]->setPos(g_pEnemy[4]->getPos().x, g_pPlatFormL[j]->getPos().y + 64.0f);
					g_pEnemy[5]->setPos(g_pEnemy[5]->getPos().x, g_pPlatFormL[j]->getPos().y + 64.0f);
					//�n�ʂɓ���������o���[������蒼���܂ł̎��Ԃ��v�Z����
					if (enemyPumpBalloonCDCounter[2] < 300)
					{
						enemyPumpBalloonCDCounter[2]++;
					}
					else if (enemyPumpBalloonCDCounter[2] == 300)
					{
						//�G���o���[�������n�߂�
						enemyPumpBalloon[2] = true;
					}
				}
				else
				{
					ENEMY_SPEED_Y3 = -0.5f;
					//�����̃A�j���[�V�����𔭓�����
					enemyDeadFalling[2] = true;
				}
			}
		}
		for (int k = 0; k < PlatFormQuantityS; ++k)
		{
			if (g_pPlatFormS[k] != NULL && g_pEnemy[4] != NULL && g_pEnemy[5] != NULL)
			{
				//Enemy3������S�Ɠ��������Ƃ�
				if (g_pEnemy[4]->collision(g_pPlatFormS[k]) == true || g_pEnemy[5]->collision(g_pPlatFormS[k]) == true)
				{
					//�G���o���[��������Ă��Ȃ���������������
					if (enemyPumpBalloon[2] != true)
					{
						g_pEnemy[4]->setAnimation(2);
						g_pEnemy[5]->setAnimation(2);
					}
					//�������Ă��Ȃ�
					enemyDeadFalling[2] = false;
					//�G���n�ʂƐڂ��Ă���
					enemyOnGround[2] = true;
					ENEMY_SPEED_X3 = 0.0f;
					//�v���C���[�̍��W�����ɐڂ���ʒu�܂Œ�������
					g_pEnemy[4]->setPos(g_pEnemy[4]->getPos().x, g_pPlatFormS[k]->getPos().y + 64.0f);
					g_pEnemy[5]->setPos(g_pEnemy[5]->getPos().x, g_pPlatFormS[k]->getPos().y + 64.0f);
					//�n�ʂɓ���������o���[������蒼���܂ł̎��Ԃ��v�Z����
					if (enemyPumpBalloonCDCounter[2] < 300)
					{
						enemyPumpBalloonCDCounter[2]++;
					}
					else if (enemyPumpBalloonCDCounter[2] == 300)
					{
						//�G���o���[�������n�߂�
						enemyPumpBalloon[2] = true;
					}
				}
				else
				{
					ENEMY_SPEED_Y3 = -0.5f;
					//�����̃A�j���[�V�����𔭓�����
					enemyDeadFalling[2] = true;
				}
			}
		}
		//�������Ă��鎞�A�A�j���[�V�����̏���
		if (enemyDeadFalling[2] == true)
		{
			if (enemyFallingCounter[2] <= 10)
			{
				g_pEnemy[4]->setAnimationRange(10, 12);
				g_pEnemy[5]->setAnimationRange(10, 12);
				if (enemyFallingCounter[2] % 5 == 0)
				{
					g_pEnemy[4]->stepAnimation();
					g_pEnemy[5]->stepAnimation();
				}
			}
		}
		//�G���o���[�������n�߂���
		if (enemyPumpBalloon[2] == true)
		{
			//�G���o���[�������A�j���[�V�����̃J�E���^�[����
			enemyPumpBalloonCounter[2]++;
			//�A�j���[�V�����͈̔͂�ݒ�
			g_pEnemy[4]->setAnimationRange(3, 9);
			g_pEnemy[5]->setAnimationRange(3, 9);
			//30�t���[�����A�A�j���[�V�����𓮂�
			if (enemyPumpBalloonCounter[2] % 10 == 0)
			{
				g_pEnemy[4]->stepAnimation();
				g_pEnemy[5]->stepAnimation();
			}
			//�A�j���[�V��������񂾂������悤�ɐݒ肷��
			else if (enemyPumpBalloonCounter[2] > 70)
			{
				//�G�̕ϐ������Z�b�g����
				enemyPumpBalloon[2] = false;
				enemyBalloonIsBroken[2] = false;
				g_pEnemy[4]->setAnimation(0);
				g_pEnemy[5]->setAnimation(0);
				enemyPumpBalloonCDCounter[2] = 0;
				enemyFallingCounter[2] = 0;
				enemyPumpBalloonCounter[2] = 0;
				enemyOnGround[2] = false;
			}
		}
	}
}