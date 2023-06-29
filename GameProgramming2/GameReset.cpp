//----------------------------------------------------------
// �t�@�C����		�FGameReset
// �T�v				�F�Q�[�����I��������A�ĊJ���邽�߂ɕϐ������Z�b�g����
// �쐬��			�F21CU0315
// �X�V���e			�F2022/03/31�@���쌫 �쐬
//----------------------------------------------------------
#include "CActionGameApp.h"

void CActionGameApp::GameReset()
{
	//�o���[���̃A�j���[�V�����p�ϐ�
	iBalloonAnimation = 0;
	//�A�j���[�V�����̃Z�b�g�悤�ϐ�
	iBalloonAnmSet = 0;
	//�A�j���[�V�����̏オ�艺����
	bBalloonAnm = false;
	//�o���[���̏オ�艺����
	BalloonUPDOWN = 0;
	//�o���[������ɍs�������ɍs����
	bBalloonUPOrDOWN = false;

	resetPlayerFishPos = false;

	//�Q�[���I�[�o�[�J�E���^�[
	GameOvercounter = 0;

	
	// �X�R�A�l
	g_number = 0;
	// �X�R�A(���)------------------------------------------
	// ��ڂ̃X�R�A�̕ϐ���IScore�ɂ��܂����B
	// �X�R�A�l
	g_score = 0;

	
	//---------------------------------------------------------------------------------
	// 	//�v���C���[�̉��ړ��̑��x�̃J�E���^�[
	horiSpeedCounter = 0;

	//�����̍ŏ��ɒx�������邽�߂̕ϐ�
	SpeedUpStart = 0;
	//�����̍ŏ��̒x�������邽�߂̕ϐ��i�󒆉��ړ��j
	SpeedUpStart1 = 0;

	//�v���C���[�̉��ړ��̑��x
	playerHoriSpeed = 0.0f; //�@�E�ɍs���Ƃ���+�@�A���ɍs���Ƃ���-
	//�v���C���[�̋󒆉��ړ��̑��x
	playerHoriSpeed1 = 0.0f;  //�@�E�ɍs���Ƃ���+�@�A���ɍs���Ƃ���-�@�@�@

	//�v���C���[�̃W�����v��
	g_jumpPower = 0.0f;
	//�v���C���[�̃W�����v�͂̏��
	g_jumpPowerMax = 3.5f;
	//�W�����v�̑��ړ���
	g_jumpMove = 0.0f;
	//�W�����v�̏㏸�t���O
	g_isJumpRise = false;

	//�d�͂̃J�E���^�[
	g_gravCounter = 0;
	//�W�����v�A�d�͂̌v�Z�p
	g_changeGrav = 0.0f;
	

	//�d�͂̏���
	moveY = 0.0f;
	//�d�͂�������܂ł̎��ԗp�ϐ�
	PlayerGravDownTime = 0;

	//�v���C���[�̎c�@
	iPlayerResidue = 3;
	//�v���C���[�̃o���[���̐�
	PlayerBalloon = 2;
	//�v���C���[������\���ǂ���
	PlayerDieBalloon = false;
	//�v���C���[�̖��G����
	PlayerInvincible = false;


	//-------------------------------------------------------------------------------
	
	for (int i = 0; i < 3; ++i)
	{
		//�G�����j���ꂽ���ǂ����̔���p
		Enemy_Defeat[i] = false;
		//�X�e�[�^�X�̕ύX�p
		EnemyStateChange[i] = 0;
		//�G�̍s���̒i�K���w�肷��ϐ�
		enemyMovementStage[i] = 1;
		//�G�̃o���[�����j�󂳂ꂽ���ǂ����𔻒�p
		enemyBalloonIsBroken[i] =  true;
		//�G�����񂾂��ǂ����𔻒�p
		enemyIsDead[i] =false;
		//�G����������Ƃ��A�j���[�V�����p�J�E���^�[
		enemyFallingCounter[i] = 0;
		//�G���������Ă��邩�ǂ����̔���p
		enemyDeadFalling[i] = false;
		//�G�̃o���[�������ꂽ���A�n�ʂɓ���������Ƀo���[������蒼���^�C�~���O�̃J�E���^�[
		enemyPumpBalloonCDCounter[i] = 0;
		//�G���o���[�������A�j���[�V�����p�J�E���^�[
		enemyPumpBalloonCounter[i] = 0;
		//�G���o���[��������Ă��邩�ǂ����̔���p
		enemyPumpBalloon[i] = false;
		//�G�����񂾂Ƃ��ɏ�ɏオ��͈͗p
		EnemyDeadUp[i] = 0;
		//�G�����񂾂Ƃ��̃A�j���[�V�����p�J�E���^�[
		EnemyDeadAnimeCounter[i] = 0;

		iEnemyStrong[i] = 0;

		//���W���擾�������̔���p
		PosGetSea[i] = false;
		//�G�����n���Ă��邩�ǂ����̔���p
		enemyOnGround[i] = true;
	}
	
	
	iEnemy_Start_Time = 0;
	bEnemyTimeUp = false;
	iEnemyTimeUp = 0;
	
	
	


	

	//-----------------------------------------------------------------------------------
	//���̏���
	//�v���C���[�����ɕ߂܂ꂽ
	playerCaughtByFish = false;
	//�G�����ɕ߂܂�����
	enemyCaughtByFish = false;
	//�����オ��n�߂�
	fishStartedMoving = false;
	//���̃J�E���^�[
	fishCounter = 1;

	//�v���C���[�����ʂƂ��A�j���[�V�����p
	playerDeathAnimeCounter = 0;
	playerDeathGoUpCounter = 0;
	//�v���C���[�����񂾂��ǂ����𔻒肷��p�J�E���^�[
	playerIsDead = false;

	//�v���C���[���W�����v���鎞�̃A�j���[�V�����p
	playerJumpAnimIndex = 0;
	startPlayerJumpAnimCounter = false;
	//���񂾓G�̐�
	noOfDeadEnemy = 0;

	

	

	//-----------------------------------------------------------------------------
	//�v���C���[�̎c�@�̌�
	PlayerRMQuantity = 2;

	//���{�[�����������n�߂�O�̎��Ԃ��v�Z����
	ThunderSpawnCounter = 0;
	//���{�[��������������Atrue��������
	ThunderSpawning = false;



	

	PlayerIsKilledByThunder = false;

	//�Q�[���N���A���Ƀv���C���[���~�߂�֐�
	bPlayerStop = false;
}