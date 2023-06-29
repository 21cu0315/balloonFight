//----------------------------------------------------------
// �t�@�C����		�FFish.cpp
// �T�v				�F���̏���
// �쐬��			�F21CU0315 ���쌫
// �X�V���e			�F2022/03/11 21CU0315 ���쌫 �쐬
//				  �@ :2022/03/16 21CU0118 ���r�T�V�� resetPlayerFishPos = false�@��PlayerDieActive�Ɉڍs
//					 :2022/03/16 21CU333 �]���q�L �G�����ɐH���鏈��	    
//					�F2022/03/2821cu0118 ���r�T�V�� ���G����ǉ�
//----------------------------------------------------------

#include "CActionGameApp.h"



void CActionGameApp::Fish()
{
	for (int i = 0; i < PlayerQuantity; ++i)
	{
		if (g_pPlayer1[i] != NULL)
		{


			//�v���C���[���w�肳�ꂽ�ʒu�ɓ�������A�J�E���^�[����
			if (g_pPlayer1[0]->getPos().x<(g_pGround[3]->getPos().x - GROUND_SIZE_X / 2 - PLAYER_SIZE_X / 2)
				&& g_pPlayer1[0]->getPos().x >(g_pGround[7]->getPos().x + GROUND_SIZE_X / 2 + PLAYER_SIZE_X / 2) &&
				g_pPlayer1[0]->getPos().y < (GroundPosY + GROUND_SIZE_Y / 2 + PLAYER_SIZE_Y))
			{
				fishCounter++;
			}
			else if (g_pPlayer1[1]->getPos().x<(g_pGround[3]->getPos().x - GROUND_SIZE_X / 2 - PLAYER_SIZE_X / 2)
				&& g_pPlayer1[1]->getPos().x >(g_pGround[7]->getPos().x + GROUND_SIZE_X / 2 + PLAYER_SIZE_X / 2) &&
				g_pPlayer1[1]->getPos().y < (GroundPosY + GROUND_SIZE_Y / 2 + PLAYER_SIZE_Y))
			{
				fishCounter++;
			}
			//�v���C���[�ƓG�͂���ȊO�Ɉʒu�ɂ�����A�J�E���^�[�Ƌ��̈ʒu��␳
			else
			{
				fishCounter = 1;
				g_pFish->setPos(fishPos);
			}
			//�J�E���^�[��5*60�ɂȂ�����A���������n�߂�
			if (fishCounter % 300 == 0)
			{
				fishStartedMoving = true;
				//�v���C���[
				if (g_pPlayer1[0]->getPos().x > -WINDOW_WIDTH / 2 && g_pPlayer1[0]->getPos().x < WINDOW_WIDTH / 2)
				{
					g_pFish->setPos(g_pPlayer1[0]->getPos().x, g_pFish->getPos().y);
				}
				else if (g_pPlayer1[1]->getPos().x > -WINDOW_WIDTH / 2 && g_pPlayer1[1]->getPos().x < WINDOW_WIDTH / 2)
				{
					g_pFish->setPos(g_pPlayer1[1]->getPos().x, g_pFish->getPos().y);
				}
			}
			//���������n�߂���
			if (fishStartedMoving == true)
			{
				g_pFish->setPos(g_pFish->getPos().x, g_pFish->getPos().y + 3.0f);
				//�v���C���[�����ƂԂ�������
				if (g_pPlayer1[i]->collision(g_pFish) != false)
				{
					playerCaughtByFish = true;
					fishStartedMoving = false;
				}
			}
			//�v���C���[�����ɕ߂܂ꂽ��
			if (playerCaughtByFish == true)
			{
				g_pPlayer1[i]->setPos(g_pFish->getPos().x, g_pFish->getPos().y + 25.0f);
				g_pFish->setPos(g_pFish->getPos().x, g_pFish->getPos().y - 2.0f);
			}
			//������ʊO�ɏo����
			if (g_pFish->getPos().y < -WINDOW_HEIGHT / 2 && iPlayerResidue >= 1)
			{
				//���ƃv���C���[�̍��W�����Z�b�g����ϐ���true�ɂ���
				resetPlayerFishPos = true;
			}
			//�v���C���[����ʂ̉��ɏo����
			if (g_pPlayer1[i]->getPos().y < -WINDOW_HEIGHT / 2 - PLAYER_SIZE_X / 2 && iPlayerResidue >= 1)
			{
				//���ƃv���C���[�̍��W�����Z�b�g����ϐ���true�ɂ���
				resetPlayerFishPos = true;
			}
			//���ƃv���C���[�̍��W�����Z�b�g����ϐ���true�ɂȂ����Ƃ�
			if (resetPlayerFishPos == true)
			{

				//���G��
				PlayerInvincible = false;
				//�c�@�̌���
				iPlayerResidue--;
				fishCounter = 1;
				//���Z�b�g�֐�
				AllReset();
			}
		}
	}

	////�G
	//for (int j = 0; j < EnemyQuantity; ++j)
	//{
	//	if (g_pEnemy[j] != NULL)
	//	{
	//		//�G���w�肳�ꂽ�ʒu�ɓ����Ă�����A�J�E���^�[����
	//		if (g_pEnemy[j]->getPos().x < (g_pGround[3]->getPos().x - GROUND_SIZE_X / 2 - ENEMY_SIZE_X / 2)
	//			&& g_pEnemy[j]->getPos().x >(g_pGround[7]->getPos().x + GROUND_SIZE_X / 2 + ENEMY_SIZE_X / 2) &&
	//			g_pEnemy[j]->getPos().y < (GroundPosY + GROUND_SIZE_Y / 2 + ENEMY_SIZE_Y))
	//		{
	//			fishCounter++;
	//		}
	//		//�v���C���[�ƓG�͂���ȊO�Ɉʒu�ɂ�����A�J�E���^�[�Ƌ��̈ʒu��␳
	//		else
	//		{
	//			fishCounter = 1;
	//			g_pFish->setPos(fishPos);
	//		}
	//		//�J�E���^�[��5*60�ɂȂ�����A���������n�߂�
	//		if (fishCounter % 300 == 0)
	//		{
	//			fishStartedMoving = true;
	//		}
	//		//���������n�߂���
	//		if (fishStartedMoving == true)
	//		{
	//			g_pFish->setPos(g_pFish->getPos().x, g_pFish->getPos().y + 3.0f);
	//			//�G�����ƂԂ�������
	//			if (g_pEnemy[j]->collision(g_pFish) != false)
	//			{
	//				enemyCaughtByFish = true;
	//				fishStartedMoving = false;
	//			}
	//		}
	//		//�G�����ɕ߂܂ꂽ��
	//		if (enemyCaughtByFish == true)
	//		{
	//			g_pEnemy[j]->setPos(g_pFish->getPos().x, g_pFish->getPos().y + 25.0f);
	//			g_pFish->setPos(g_pFish->getPos().x, g_pFish->getPos().y - 2.0f);
	//		}
	//		//�G����ʉ��ɏo����
	//		if (g_pEnemy[j]->getPos().y < -WINDOW_HEIGHT / 2 - ENEMY_SIZE_X / 2)
	//		{
	//			//�G��\�������Ȃ��l�ɂ���x
	//			enemyCaughtByFish = false;
	//		}
	//	}
	//}
}