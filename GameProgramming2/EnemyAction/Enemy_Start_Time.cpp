//----------------------------------------------------------
// �t�@�C����		�FEnemy_Start_Time.cpp
// �T�v				�F�G�������o���܂ł̎���
// �쐬��			�F21CU0118�@���r�T�V��
// �X�V���e			�F2022/03/14�@���r�T�V��쐬
//----------------------------------------------------------
#include "CActionGameApp.h"

bool CActionGameApp::Enemy_Start_Time()
{
	//��3�b�ԓG���d��������
	++iEnemyTimeUp;
	//����
	if (iEnemyTimeUp == 180)
	{
		return true;
	}
	//����ȊO
	return false;
}