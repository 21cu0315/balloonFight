//----------------------------------------------------------
// �t�@�C����		�FEnemyForm
// �T�v				�F�G���C�ɗ������Ƃ��̖A�̏���
// �쐬��			�F21CU0118�@���r�T�V��
// �X�V���e			�F2022/03/28�@���r�T�V�� �쐬 
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::EnemyFoam()
{
	if (PosGetSea[0] != false)
	{
		//1��
		if (g_pFoam[0] != NULL)
		{
			//�t���[������
			iFoamFleam[0]++;
			//�t���[��������̒l�ɕt������摜�����E�ɗh�炷
			if (iFoamFleam[0] == 2)
			{
				//�֐��̒l��False�Ȃ�
				//���ɓ�����
				if (FoamRL[0] == false)
				{
					//����̒l�ɓ��B�������̔���
					if (-FoamMove_X_Limit < FoamMove_X[0])
					{
						//�l�ɓ��B���ĂȂ���Βl�����Z����
						FoamMove_X[0] -= 0.05;
					}
					//����̒l�ɓ��B���Ă���Βl��true�ɂ���
					else
					{
						FoamRL[0] = true;
					}
				}
				else
				{
					//����̒l�ɓ��B�������̔���
					if (FoamMove_X_Limit > FoamMove_X[0])
					{
						//�l�ɓ��B���ĂȂ���Βl�����Z����
						FoamMove_X[0] += 0.05;
					}
					//����̒l�ɓ��B���Ă���Βl��false�ɂ���
					else
					{
						FoamRL[0] = false;
					}
				}
				//�t���[����0�ɂ���
				iFoamFleam[0] = 0;
			}
			//���ړ��ʂ����Z
			g_pFoam[0]->setPos(g_pFoam[0]->getPos().x + FoamMove_X[0], g_pFoam[0]->getPos().y + 1.0f);

			//����̈ʒu������ɓ��B������摜�̍폜
			if (g_pFoam[0]->getPos().y > WINDOW_TOP)
			{
				disposeSprite(g_pFoam[0]);
				g_pFoam[0] = NULL;
			}
		}
	}

	if (PosGetSea[1] != false)
	{
		//2��
		if (g_pFoam[1] != NULL)
		{
			//�t���[������
			iFoamFleam[1]++;
			//�t���[��������̒l�ɕt������摜�����E�ɗh�炷
			if (iFoamFleam[1] == 2)
			{
				//�֐��̒l��False�Ȃ�
				//���ɓ�����
				if (FoamRL[1] == false)
				{
					//����̒l�ɓ��B�������̔���
					if (-FoamMove_X_Limit < FoamMove_X[1])
					{
						//�l�ɓ��B���ĂȂ���Βl�����Z����
						FoamMove_X[1] -= 0.05;
					}
					//����̒l�ɓ��B���Ă���Βl��true�ɂ���
					else
					{
						FoamRL[1] = true;
					}
				}
				else
				{
					//����̒l�ɓ��B�������̔���
					if (FoamMove_X_Limit > FoamMove_X[1])
					{
						//�l�ɓ��B���ĂȂ���Βl�����Z����
						FoamMove_X[1] += 0.05;
					}
					//����̒l�ɓ��B���Ă���Βl��false�ɂ���
					else
					{
						FoamRL[1] = false;
					}
				}
				//�t���[����0�ɂ���
				iFoamFleam[1] = 0;
			}
			//���ړ��ʂ����Z
			g_pFoam[1]->setPos(g_pFoam[1]->getPos().x + FoamMove_X[1], g_pFoam[1]->getPos().y + 1.0f);

			//����̈ʒu������ɓ��B������摜�̍폜
			if (g_pFoam[1]->getPos().y > WINDOW_TOP)
			{
				disposeSprite(g_pFoam[1]);
				g_pFoam[1] = NULL;
			}
		}
	}

	if (PosGetSea[2] != false)
	{
		//3��
		if (g_pFoam[2] != NULL)
		{
			//�t���[������
			iFoamFleam[2]++;
			//�t���[��������̒l�ɕt������摜�����E�ɗh�炷
			if (iFoamFleam[2] == 2)
			{
				//�֐��̒l��False�Ȃ�
				//���ɓ�����
				if (FoamRL[2] == false)
				{
					//����̒l�ɓ��B�������̔���
					if (-FoamMove_X_Limit < FoamMove_X[2])
					{
						//�l�ɓ��B���ĂȂ���Βl�����Z����
						FoamMove_X[2] -= 0.05;
					}
					//����̒l�ɓ��B���Ă���Βl��true�ɂ���
					else
					{
						FoamRL[2] = true;
					}
				}
				else
				{
					//����̒l�ɓ��B�������̔���
					if (FoamMove_X_Limit > FoamMove_X[2])
					{
						//�l�ɓ��B���ĂȂ���Βl�����Z����
						FoamMove_X[2] += 0.05;
					}
					//����̒l�ɓ��B���Ă���Βl��false�ɂ���
					else
					{
						FoamRL[2] = false;
					}
				}
				//�t���[����0�ɂ���
				iFoamFleam[2] = 0;
			}
			//���ړ��ʂ����Z
			g_pFoam[2]->setPos(g_pFoam[2]->getPos().x + FoamMove_X[2], g_pFoam[2]->getPos().y + 1.0f);

			//����̈ʒu������ɓ��B������摜�̍폜
			if (g_pFoam[2]->getPos().y > WINDOW_TOP)
			{
				disposeSprite(g_pFoam[2]);
				g_pFoam[2] = NULL;
			}
		}
	}
}