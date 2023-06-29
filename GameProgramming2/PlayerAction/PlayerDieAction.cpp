//----------------------------------------------------------
// �t�@�C����		�FPlayerDieAction()
// �T�v				�F�v���C���[�����񂾂Ƃ��̏���
// �쐬��			�F21cu0118 ���r�T�V��
// �X�V���e			�F2022/03/16 21cu0118 ���r�T�V�� �쐬
//					�F2022/03/18 21CU0315 ���쌫 �v���C���[�����ʂƂ��̃A�j���[�V������ǉ�
//----------------------------------------------------------
#include "CActionGameApp.h"



void CActionGameApp::PlayerDieActionActive()
{
	//�v���C���[�̍��W������̒l��������������
	//�v���C���[�𗎂Ƃ�
	if (resetPlayerFishPos != false)
	{
		//�ϐ���߂�F
		PlayerDieBalloon = false;
		//�o���[���̎c�@�̕���
		PlayerBalloon = 3;
		//�ϐ��̕ύX
		resetPlayerFishPos = false;
	}
	else if (PlayerIsKilledByThunder == true)
	{
		playerDeathAnimeCounter++;
		playerDeathGoUpCounter++;
		for (int i = 0; i < PlayerQuantity; ++i)
		{
			g_pPlayer1[i]->setAnimationRange(31, 32);
			if (playerDeathAnimeCounter % 3 == 0)
			{
				g_pPlayer1[i]->stepAnimation();
				playerDeathAnimeCounter = 0;
			}
		}

		if (playerDeathGoUpCounter > 60)
		{
			g_pPlayer1[0]->setPos(g_pPlayer1[0]->getPos().x, g_pPlayer1[0]->getPos().y - 5.0f);
			g_pPlayer1[1]->setPos(g_pPlayer1[1]->getPos().x, g_pPlayer1[1]->getPos().y - 5.0f);
		}

	}
	else
	{
		playerDeathAnimeCounter++;
		playerDeathGoUpCounter++;
		for (int i = 0; i < PlayerQuantity; ++i)
		{
			if (g_pPlayer1[i] != NULL)
			{
				g_pPlayer1[i]->setAnimationRange(28, 30);
				if (playerDeathAnimeCounter % 3 == 0)
				{
					g_pPlayer1[i]->stepAnimation();
					playerDeathAnimeCounter = 0;
				}
			}
		}
		if (playerDeathGoUpCounter < 30)
		{
			g_pPlayer1[0]->setPos(g_pPlayer1[0]->getPos().x, g_pPlayer1[0]->getPos().y + 5.0f);
			g_pPlayer1[1]->setPos(g_pPlayer1[1]->getPos().x, g_pPlayer1[1]->getPos().y + 5.0f);
		}
		else
		{
			g_pPlayer1[0]->setPos(g_pPlayer1[0]->getPos().x, g_pPlayer1[0]->getPos().y - 5.0f);
			g_pPlayer1[1]->setPos(g_pPlayer1[1]->getPos().x, g_pPlayer1[1]->getPos().y - 5.0f);
		}
	}
}