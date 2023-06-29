//----------------------------------------------------------
// �t�@�C����		�FEnemyNotBalloon
// �T�v				�F�G�̃o���[�����j�󂳂ꂽ���ǂ���
// �쐬��			�F21CU0118�@���r�T�V��
// �X�V���e			�F2022/03/15�@���r�T�V�� �쐬 
//					�F2022/03/30�@���쌫�@�G���p���V���[�g���J������ԂŎ��ʂƂ��̃o�O���C��
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyNotBalloon()
{
	//�G�̈ړ�
	//1�̖�
	if (enemyBalloonIsBroken[0] != false && enemyOnGround[0] != true && enemyIsDead[0] != true)
	{
		//���������Ă��鎞
		if (RightorLeft[0] == false)
		{
			ENEMY_SPEED_X += 0.05f;
 			if (ENEMY_SPEED_X > 2.0f)
			{
				RightorLeft[0] = true;
			}
		}
		//�E����
		else if (RightorLeft[0] != false)
		{
			ENEMY_SPEED_X -= 0.05f;
			if (ENEMY_SPEED_X < -2.0f)
			{
				RightorLeft[0] = false;
			}
		}
		if (enemyDeadFalling[0] == true && g_pEnemy[0] != NULL && g_pEnemy[1] != NULL)
		{
			//���ړ��ʂ���
			g_pEnemy[0]->setPos(g_pEnemy[0]->getPos().x + ENEMY_SPEED_X, g_pEnemy[0]->getPos().y);
			g_pEnemy[1]->setPos(g_pEnemy[1]->getPos().x + ENEMY_SPEED_X, g_pEnemy[1]->getPos().y);
		}
	}
	//2�̖�
	if (enemyBalloonIsBroken[1] != false && enemyOnGround[1] != true && enemyIsDead[1] != true)
	{
		//���������Ă��鎞
		if (RightorLeft[1] == false)
		{
			ENEMY_SPEED_X2 += 0.05f;
			if (ENEMY_SPEED_X2 > 2.0f)
			{
				RightorLeft[1] = true;
			}
		}
		//�E����
		else if (RightorLeft[1] != false)
		{
			ENEMY_SPEED_X2 -= 0.05f;
			if (ENEMY_SPEED_X2 < -2.0f)
			{
				RightorLeft[1] = false;
			}
		}
		if (enemyDeadFalling[1] == true && g_pEnemy[2] != NULL && g_pEnemy[3] != NULL)
		{
			//���ړ��ʂ���
			g_pEnemy[2]->setPos(g_pEnemy[2]->getPos().x + ENEMY_SPEED_X2, g_pEnemy[2]->getPos().y);
			g_pEnemy[3]->setPos(g_pEnemy[3]->getPos().x + ENEMY_SPEED_X2, g_pEnemy[3]->getPos().y);
		}
	}
	//3�̖�
	if (enemyBalloonIsBroken[2] != false && enemyOnGround[2] != true && enemyIsDead[2] != true)
	{
		//���������Ă��鎞
		if (RightorLeft[2] == false)
		{
			ENEMY_SPEED_X3 += 0.05f;
			if (ENEMY_SPEED_X3 > 2.0f)
			{
				RightorLeft[2] = true;
			}
		}
		//�E����
		else if (RightorLeft[2] != false)
		{
			ENEMY_SPEED_X3 -= 0.05f;
			if (ENEMY_SPEED_X3 < -2.0f)
			{
				RightorLeft[2] = false;
			}
		}
		if (enemyDeadFalling[2] == true && g_pEnemy[4] != NULL && g_pEnemy[5] != NULL)
		{
			//���ړ��ʂ���
			g_pEnemy[4]->setPos(g_pEnemy[4]->getPos().x + ENEMY_SPEED_X3, g_pEnemy[4]->getPos().y);
			g_pEnemy[5]->setPos(g_pEnemy[5]->getPos().x + ENEMY_SPEED_X3, g_pEnemy[5]->getPos().y);
		}
	}
}