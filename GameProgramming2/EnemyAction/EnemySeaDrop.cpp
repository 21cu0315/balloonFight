//----------------------------------------------------------
// �t�@�C����		�FEnemySeaDrop
// �T�v				�F�G���C�ɗ������Ƃ��̖A�̈ʒu�̒���
// // �쐬��		�F21CU0118 ���r�T�V��
// �X�V���e			�F2022/03/28 21CU0118 ���r�T�V��@�쐻
//----------------------------------------------------------

#include "CActionGameApp.h"

void CActionGameApp::EnemySeaDrop()
{
	//�G������̈ʒu�ɗ������Ƃ��̖A�̈ʒu�̒���
	if (PosGetSea[0] == false)
	{
		if (g_pEnemy[0] != NULL)
		{
			//��ʓ��ɓG�������Ă���΍��W���擾����
			if (g_pEnemy[0]->getPos().x > WINDOW_LEFT && g_pEnemy[0]->getPos().x < WINDOW_RIGHT)
			{
				//�C�ɗ��������̔���
				if (g_pEnemy[0]->getPos().y < -WINDOW_HEIGHT/2)
				{
					g_pFoam[0]->setPos(g_pEnemy[0]->getPos().x, ((-WINDOW_HEIGHT / 2) - (80.0f)));
					//���W���擾������ϐ��̒��g��ւ���
					PosGetSea[0] = true;
					//�֐��̏I��
					return;
				}
			}
		}
		if (g_pEnemy[1] != NULL)
		{
			//��ʓ��ɓG�������Ă���΍��W���擾����
			if (g_pEnemy[1]->getPos().x > WINDOW_LEFT && g_pEnemy[1]->getPos().x < WINDOW_RIGHT)
			{
				//�C�ɗ��������̔���
				if (g_pEnemy[1]->getPos().y < -WINDOW_HEIGHT/2)
				{
					g_pFoam[0]->setPos(g_pEnemy[1]->getPos().x, ((-WINDOW_HEIGHT / 2) - (80.0f)));
					//���W���擾������ϐ��̒��g��ւ���
					PosGetSea[0] = true;
					//�֐��̏I��
					return;
				}
			}
		}
	}
	//�G������̈ʒu�ɗ������Ƃ��̖A�̈ʒu�̒���
	if (PosGetSea[1] == false)
	{
		if (g_pEnemy[2] != NULL)
		{
			//��ʓ��ɓG�������Ă���΍��W���擾����
			if (g_pEnemy[2]->getPos().x > WINDOW_LEFT && g_pEnemy[2]->getPos().x < WINDOW_RIGHT)
			{
				//�C�ɗ��������̔���
				if (g_pEnemy[2]->getPos().y < -WINDOW_HEIGHT/2)
				{
					g_pFoam[1]->setPos(g_pEnemy[2]->getPos().x, ((-WINDOW_HEIGHT / 2) - (80.0f)));
					//���W���擾������ϐ��̒��g��ւ���
					PosGetSea[1] = true;
					//�֐��̏I��
					return;
				}
			}
		}
		if (g_pEnemy[3] != NULL)
		{
		//��ʓ��ɓG�������Ă���΍��W���擾����
			if (g_pEnemy[3]->getPos().x > WINDOW_LEFT && g_pEnemy[3]->getPos().x < WINDOW_RIGHT)
			{

				//�C�ɗ��������̔���
				if (g_pEnemy[3]->getPos().y < -WINDOW_HEIGHT/2)
				{
					g_pFoam[1]->setPos(g_pEnemy[3]->getPos().x, ((-WINDOW_HEIGHT / 2) - (80.0f)));
					//���W���擾������ϐ��̒��g��ւ���
					PosGetSea[1] = true;
					//�֐��̏I��
					return;
				}
			}
		}
	}
	//�G������̈ʒu�ɗ������Ƃ��̖A�̈ʒu�̒���
	if (PosGetSea[2] == false)
	{
		if (g_pEnemy[4] != NULL)
		{
			//��ʓ��ɓG�������Ă���΍��W���擾����
			if (g_pEnemy[4]->getPos().x > WINDOW_LEFT && g_pEnemy[4]->getPos().x < WINDOW_RIGHT)
			{
				//�C�ɗ��������̔���
				if (g_pEnemy[4]->getPos().y < -WINDOW_HEIGHT/2)
				{
					g_pFoam[2]->setPos(g_pEnemy[4]->getPos().x, ((-WINDOW_HEIGHT / 2) - (80.0f)));
					//���W���擾������ϐ��̒��g��ւ���
					PosGetSea[2] = true;
					//�֐��̏I��
					return;
				}
			}
		}
		if (g_pEnemy[5] != NULL)
		{
			//��ʓ��ɓG�������Ă���΍��W���擾����
			if (g_pEnemy[5]->getPos().x > WINDOW_LEFT && g_pEnemy[5]->getPos().x < WINDOW_RIGHT)
			{

				//�C�ɗ��������̔���
				if (g_pEnemy[5]->getPos().y < -WINDOW_HEIGHT/2)
				{
					g_pFoam[2]->setPos(g_pEnemy[5]->getPos().x, ((-WINDOW_HEIGHT / 2) - (80.0f)));
					//���W���擾������ϐ��̒��g��ւ���
					PosGetSea[2] = true;
					//�֐��̏I��
					return;
				}
			}
		}
	}
}