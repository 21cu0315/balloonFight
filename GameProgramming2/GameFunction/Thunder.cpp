//----------------------------------------------------------
// �t�@�C����		�FThunder.cpp
// �T�v				�F���{�[���̏���
// �쐬��			�F21CU0315 ���쌫
// �X�V���e			�F2022/03/09 21CU0315 ���쌫 �쐬
//					�F2022/03/10 21CU0315 ���쌫 ���{�[���ƃv���C���[�̓����蔻��
//----------------------------------------------------------


#include "CActionGameApp.h"
#include <time.h>
#include <cstdlib>

void CActionGameApp::Thunder()
{
	//30�b���o������A���{�[�����������n�߂�
	ThunderSpawnCounter++;

	if (ThunderSpawnCounter == 60 * 30)
	{
		ThunderSpawning = true;
	}
	
	
	//���{�[������������Ă��鎞
	if (ThunderSpawning == true)
	{
		for (int i = 0; i < ThunderQuantity; ++i)
		{
			//�c�ړ��̏���
			if (g_pThunder[i].obj->getPos().y > (WINDOW_HEIGHT / 2 - THUNDER_SIZE_Y / 2))
			{
				g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, WINDOW_HEIGHT / 2 - THUNDER_SIZE_Y / 2);
				g_pThunder[i].thunderMoveY *= -1.0f;
			}
			else
			{
				g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, g_pThunder[i].obj->getPos().y + g_pThunder[i].thunderMoveY);
			}
			//���ړ��̏���
			if (g_pThunder[i].obj->getPos().x > (WINDOW_WIDTH / 2 - THUNDER_SIZE_Y / 2))
			{
				g_pThunder[i].obj->setPos(WINDOW_WIDTH / 2 - THUNDER_SIZE_Y / 2, g_pThunder[i].obj->getPos().y);
				g_pThunder[i].thunderMoveX *= -1.0f;
			}
			else if (g_pThunder[i].obj->getPos().x < (-WINDOW_WIDTH / 2 + THUNDER_SIZE_Y / 2))
			{
				g_pThunder[i].obj->setPos(-WINDOW_WIDTH / 2 + THUNDER_SIZE_Y / 2, g_pThunder[i].obj->getPos().y);
				g_pThunder[i].thunderMoveX *= -1.0f;
			}
			else
			{
				g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x + g_pThunder[i].thunderMoveX, g_pThunder[i].obj->getPos().y);
			}
			//��ʂ̉��ɏo�����A���Z�b�g����
			if (g_pThunder[i].obj->getPos().y < -WINDOW_HEIGHT / 2)
			{
				g_pThunder[i].obj->setPos(90.0f, 200.0f);
				g_pThunder[i].thunderMoveX = 0.0f;
				g_pThunder[i].thunderMoveY = 0.0f;
				g_pThunder[i].isMoving = false;
			}




			//���{�[���������������ꂽ���̏���
			ThunderSpawnCD++;
		
		

			if (g_pThunder[0].isMoving == false && g_pThunder[1].isMoving == false)
			{
				if (ThunderSpawnCD % 300 == 0)
				{
					ThunderDirection(0);
					g_pThunder[0].isMoving = true;
					ThunderSpawnCD = 1;
				}
			}
			else if (g_pThunder[0].isMoving != false && g_pThunder[1].isMoving == false)
			{
				if (ThunderSpawnCD % 300 == 0)
				{
					ThunderDirection(1);
					g_pThunder[1].isMoving = true;
					ThunderSpawnCD = 1;
				}
			}
			else if (g_pThunder[0].isMoving == false && g_pThunder[1].isMoving != false)
			{
				if (ThunderSpawnCD % 300 == 0)
				{
					ThunderDirection(0);
					g_pThunder[0].isMoving = true;
					ThunderSpawnCD = 1;
				}
			}
			
			//�n�ʂƂ̓����蔻��
			for (int i = 0; i < ThunderQuantity; ++i)
			{
				for (int j = 0; j < GroundQuantity; ++j)
				{
					if (g_pThunder[i].obj->collision(g_pGround[j]))
					{
						g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, g_pGround[j]->getPos().y + GROUND_SIZE_Y / 2 + THUNDER_SIZE_Y / 2);
						g_pThunder[i].thunderMoveY *= -1.0f;
					}
				}
			}
			//����S�Ƃ̓����蔻��
			for (int i = 0; i < ThunderQuantity; ++i)
			{
				for (int j = 0; j < PlatFormQuantityS; ++j)
				{
					if (g_pThunder[i].obj->getPos().y > g_pPlatFormS[j]->getPos().y)
					{
						if (g_pThunder[i].obj->collision(g_pPlatFormS[j]))
						{
							g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, g_pPlatFormS[j]->getPos().y + PLATFORMS_SIZE_ALL / 2 + THUNDER_SIZE_Y / 2);
							g_pThunder[i].thunderMoveY *= -1.0f;
						}
					}
					else if (g_pThunder[i].obj->getPos().y < g_pPlatFormS[j]->getPos().y)
					{
						if (g_pThunder[i].obj->collision(g_pPlatFormS[j]))
						{
							g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, g_pPlatFormS[j]->getPos().y - PLATFORMS_SIZE_ALL / 2 - THUNDER_SIZE_Y / 2);
							g_pThunder[i].thunderMoveY *= -1.0f;
						}
					}
				}
			}
			//����L�Ƃ̓����蔻��
			for (int i = 0; i < ThunderQuantity; ++i)
			{
				for (int j = 0; j < PlatFormQuantityL; ++j)
				{
					if (g_pThunder[i].obj->getPos().y > g_pPlatFormL[j]->getPos().y)
					{
						if (g_pThunder[i].obj->collision(g_pPlatFormL[j]))
						{
							g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, g_pPlatFormL[j]->getPos().y + PLATFORMS_SIZE_ALL / 2 + THUNDER_SIZE_Y / 2);
							g_pThunder[i].thunderMoveY *= -1.0f;
						}
					}
					else if (g_pThunder[i].obj->getPos().y < g_pPlatFormL[j]->getPos().y)
					{
						if (g_pThunder[i].obj->collision(g_pPlatFormL[j]))
						{
							g_pThunder[i].obj->setPos(g_pThunder[i].obj->getPos().x, g_pPlatFormL[j]->getPos().y - PLATFORMS_SIZE_ALL / 2 - THUNDER_SIZE_Y / 2);
							g_pThunder[i].thunderMoveY *= -1.0f;
						}
					}
				}
			}

			//�v���C���[�Ƃ̓����蔻��
			for (int i = 0; i < ThunderQuantity; ++i)
			{
				for (int j = 0; j < PlayerQuantity; ++j)
				{
					if (g_pPlayer1[j]->collision(g_pThunder[i].obj) && g_pThunder[i].isMoving == true && PlayerInvincible != false)
					{
						g_pThunder[i].obj->setPos(90.0f, 200.0f);
						g_pThunder[i].thunderMoveX = 0.0f;
						g_pThunder[i].thunderMoveY = 0.0f;
						g_pThunder[i].isMoving = false;
						PlayerDieBalloon = true;
						PlayerIsKilledByThunder = true;
					}
				}
			}
		}
	}
	//�A�j���[�V������������
	for (int i = 0; i < ThunderQuantity; ++i)
	{
		g_pThunder[i].obj->stepAnimation();
	}
}

void CActionGameApp::ThunderDirection(int noOfThunder)
{
	//�����\�̎��ݒ�
	srand((unsigned)time(NULL));
	g_pThunder[noOfThunder].thunderDirRand = rand() % 4;

	if (g_pThunder[noOfThunder].thunderDirRand == 0)
	{
		g_pThunder[noOfThunder].thunderMoveX = 1.5f;
		g_pThunder[noOfThunder].thunderMoveY = 4.0f;
	}
	else if (g_pThunder[noOfThunder].thunderDirRand == 1)
	{
		g_pThunder[noOfThunder].thunderMoveX = -1.5f;
		g_pThunder[noOfThunder].thunderMoveY = 4.0f;
	}
	else if (g_pThunder[noOfThunder].thunderDirRand == 2)
	{
		g_pThunder[noOfThunder].thunderMoveX = 1.5f;
		g_pThunder[noOfThunder].thunderMoveY = -4.0f;
	}
	else if (g_pThunder[noOfThunder].thunderDirRand == 3)
	{
		g_pThunder[noOfThunder].thunderMoveX = -1.5f;
		g_pThunder[noOfThunder].thunderMoveY = -4.0f;
	}
}