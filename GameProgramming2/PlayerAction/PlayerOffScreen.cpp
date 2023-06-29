//----------------------------------------------------------
// �t�@�C����		�FPlayerOffScreen.cpp
// �T�v				�F�v���C���[�̉�ʊO�̏���
// �쐬��			�F21CU0315 ���쌫
// �X�V���e			�F2022/03/03 21CU0315 ���쌫 �쐬
//					�F2022/03/07 21CU0315 ���쌫 �v���C���[�̉摜�̈ʒu��␳���鏈�����C��
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::PlayerOffScreen()
{
	if (g_pPlayer1[0] != NULL && g_pPlayer1[1] != NULL)
	{
		//�v���C���[�̉摜�̏c�ʒu���C������
		if (g_pPlayer1[0]->getPos().x > -WINDOW_WIDTH / 2 && g_pPlayer1[0]->getPos().x < WINDOW_WIDTH / 2)
		{
			g_pPlayer1[1]->setPos(g_pPlayer1[1]->getPos().x, g_pPlayer1[0]->getPos().y);
		}
		else if (g_pPlayer1[1]->getPos().x > -WINDOW_WIDTH / 2 && g_pPlayer1[1]->getPos().x < WINDOW_WIDTH / 2)
		{
			g_pPlayer1[0]->setPos(g_pPlayer1[0]->getPos().x, g_pPlayer1[1]->getPos().y);
		}

		//�v���C���[�̉摜�̉����x����v����
		for (int i = 0; i < 2; ++i)
		{
			g_pPlayer1[i]->setPos(g_pPlayer1[i]->getPos().x + playerHoriSpeed * 1.0f, g_pPlayer1[i]->getPos().y);
		}
		//�v���C���[�����Ɉړ����鎞�A�摜�����[�v�ł���悤�ɔz�u����
		if (playerHoriSpeed > 0)
		{
			if (g_pPlayer1[0]->getPos().x > (WINDOW_WIDTH / 2) + 64.0f)
			{
				g_pPlayer1[0]->setPos((g_pPlayer1[1]->getPos().x - WINDOW_WIDTH), g_pPlayer1[1]->getPos().y);
			}
			else if (g_pPlayer1[1]->getPos().x > (WINDOW_WIDTH / 2) + 64.0f)
			{
				g_pPlayer1[1]->setPos((g_pPlayer1[0]->getPos().x - WINDOW_WIDTH), g_pPlayer1[0]->getPos().y);
			}
		}
		else if (playerHoriSpeed < 0)
		{
			if (g_pPlayer1[0]->getPos().x < (-WINDOW_WIDTH / 2) - 64.0f)
			{
				g_pPlayer1[0]->setPos((g_pPlayer1[1]->getPos().x + WINDOW_WIDTH), g_pPlayer1[1]->getPos().y);
			}
			else if (g_pPlayer1[1]->getPos().x < (-WINDOW_WIDTH / 2) - 64.0f)
			{
				g_pPlayer1[1]->setPos((g_pPlayer1[0]->getPos().x + WINDOW_WIDTH), g_pPlayer1[0]->getPos().y);
			}
		}
	}
}