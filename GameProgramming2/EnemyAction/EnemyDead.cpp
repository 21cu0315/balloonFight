//----------------------------------------------------------
// �t�@�C����		�FEnemyDead.cpp
// �T�v				�F�G�L���������񂾂Ƃ��̏���
// �쐬��			�F21CU0315 ���쌫
// �X�V���e			�F2022/03/23 21CU0315 ���쌫 �쐬
//----------------------------------------------------------

#include "CActionGameApp.h"

void CActionGameApp::EnemyDead()
{
	//�G1�����񂾂Ƃ�
	if (enemyIsDead[0] == true && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL)
	{
		//���񂾂Ƃ��̃A�j���[�V�����J�E���^�[����
		EnemyDeadAnimeCounter[0]++;
		//�A�j���[�V�����͈̔͂�ݒ肷��
		g_pEnemy[0]->setAnimationRange(13, 14);
		g_pEnemy[1]->setAnimationRange(13, 14);
		//�A�j���[�V�����𓮂�
		g_pEnemy[0]->stepAnimation();
		g_pEnemy[1]->stepAnimation();

		//�G�����񂾂Ƃ��A10�t���[���ɏ�Ɉړ�����
		if (EnemyDeadUp[0] < 10)
		{
			EnemyDeadUp[0]++;
			g_pEnemy[0]->setPos(g_pEnemy[0]->getPos().x, g_pEnemy[0]->getPos().y + 5.0f);
			g_pEnemy[1]->setPos(g_pEnemy[1]->getPos().x, g_pEnemy[1]->getPos().y + 5.0f);
		}
		//10�t���[�����߂�����A���Ɉړ�����
		else if (EnemyDeadUp[0] == 10)
		{
			g_pEnemy[0]->setPos(g_pEnemy[0]->getPos().x, g_pEnemy[0]->getPos().y - 5.0f);
			g_pEnemy[1]->setPos(g_pEnemy[1]->getPos().x, g_pEnemy[1]->getPos().y - 5.0f);

		}
	}
	//�G2�����񂾂Ƃ�
	if (enemyIsDead[1] == true && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
	{
		EnemyDeadAnimeCounter[1]++;
		g_pEnemy[2]->setAnimationRange(13, 14);
		g_pEnemy[3]->setAnimationRange(13, 14);
		g_pEnemy[2]->stepAnimation();
		g_pEnemy[3]->stepAnimation();
		if (EnemyDeadUp[1] < 10)
		{
			EnemyDeadUp[1]++;
			g_pEnemy[2]->setPos(g_pEnemy[2]->getPos().x, g_pEnemy[2]->getPos().y + 5.0f);
			g_pEnemy[3]->setPos(g_pEnemy[3]->getPos().x, g_pEnemy[3]->getPos().y + 5.0f);
		}
		else if (EnemyDeadUp[1] == 10)
		{
			g_pEnemy[2]->setPos(g_pEnemy[2]->getPos().x, g_pEnemy[2]->getPos().y - 5.0f);
			g_pEnemy[3]->setPos(g_pEnemy[3]->getPos().x, g_pEnemy[3]->getPos().y - 5.0f);

		}
	}
	//�G3�����񂾂Ƃ�
	if (enemyIsDead[2] == true && g_pEnemy[4] != NULL && g_pEnemy[5] != NULL)
	{
		EnemyDeadAnimeCounter[2]++;
		g_pEnemy[4]->setAnimationRange(13, 14);
		g_pEnemy[5]->setAnimationRange(13, 14);
		g_pEnemy[4]->stepAnimation();
		g_pEnemy[5]->stepAnimation();
		if (EnemyDeadUp[2] < 10)
		{
			EnemyDeadUp[2]++;
			g_pEnemy[4]->setPos(g_pEnemy[4]->getPos().x, g_pEnemy[4]->getPos().y + 5.0f);
			g_pEnemy[5]->setPos(g_pEnemy[5]->getPos().x, g_pEnemy[5]->getPos().y + 5.0f);
		}
		else if (EnemyDeadUp[2] == 10)
		{
			g_pEnemy[4]->setPos(g_pEnemy[4]->getPos().x, g_pEnemy[4]->getPos().y - 5.0f);
			g_pEnemy[5]->setPos(g_pEnemy[5]->getPos().x, g_pEnemy[5]->getPos().y - 5.0f);
		}
	}
	//�G����ʊO�ɏo�����A�j������
	for (int i = 0; i < EnemyQuantity; ++i)
	{
		if (g_pEnemy[i] != NULL)
		{
			if (g_pEnemy[i]->getPos().y < -WINDOW_HEIGHT / 2 - ENEMY_SIZE_Y / 2)
			{
				disposeSprite(g_pEnemy[i]);
				g_pEnemy[i] = NULL;
			}
		}
	}
	if (g_pEnemy[0] == NULL && g_pEnemy[1] != NULL)
	{
		disposeSprite(g_pEnemy[1]);
		g_pEnemy[1] = NULL;
	}
	if (g_pEnemy[1] == NULL && g_pEnemy[0] != NULL)
	{
		disposeSprite(g_pEnemy[0]);
		g_pEnemy[0] = NULL;
	}
	if (g_pEnemy[2] == NULL && g_pEnemy[3] != NULL)
	{
		disposeSprite(g_pEnemy[3]);
		g_pEnemy[3] = NULL;
	}
	if (g_pEnemy[3] == NULL && g_pEnemy[2] != NULL)
	{
		disposeSprite(g_pEnemy[2]);
		g_pEnemy[2] = NULL;
	}
	if (g_pEnemy[4] == NULL && g_pEnemy[5] != NULL)
	{
		disposeSprite(g_pEnemy[5]);
		g_pEnemy[5] = NULL;
	}
	if (g_pEnemy[5] == NULL && g_pEnemy[4] != NULL)
	{
		disposeSprite(g_pEnemy[4]);
		g_pEnemy[4] = NULL;
	}
}