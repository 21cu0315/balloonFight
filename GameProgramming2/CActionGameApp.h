/**
* @file CActionGameApp.h
* @author �D�ˁ@�엲
* @date ���t�i2017.02.14�j
*/
#pragma once

#include "stdafx.h"
#include "CApplication.h"
#include "CPicture.h"
#include "MediaResource.h"
#include "UVAnimation.h"
#include "CFont.h"
// --------------------------------------------
// �g���͍דc��K���L�q�i2021_09_29�j
#include "CSound.h"
// --------------------------------------------

#define SeaPosY -(WINDOW_HEIGHT / 2.0) + 40.0f
#define GroundPosY -(WINDOW_HEIGHT / 2.0) + 104.0f
#define PlatFormPosY -112.0f
#define EnemyType01_01 0 
#define EnemyType01_02 1
#define EnemyType02_01 2
#define EnemyType02_02 3
#define EnemyType03_01 4 
#define EnemyType03_02 5

#define PlayerAnimation 0

#define EnemyOutLine 20.0f
#define EnemyBalloonCeckCnt 3

#define EnemyStage1 1
#define EnemyStage2 2
#define EnemyStage3 3

class CActionGameApp :
	public CApplication
{
	typedef CApplication super;
private:
	int m_activeEnemies = 0;

	CPicture* createSprite(LPCWSTR path_, float width_ = WINDOW_WIDTH, float height_ = WINDOW_HEIGHT);
	void renderSprite(CPicture* object);
	void renderSprite(CPicture* object, XMFLOAT3 color);
	void renderSprite(CPicture* object, float r, float g, float b);
	void renderSprite(CPicture* object, XMFLOAT4 color);
	void disposeSprite(CPicture* object);
	CFont* createFont(LPCWSTR path_, int digits_, float width_, float height_);
	void renderFont(CFont* object, int num_);
	void disposeFont(CFont* object);
	bool createSpaceship(void);
	void initCameraInfo();
	void doOpenning();
	void doPlaying();
	void doGameClear();
	void doGameOver();
	void doEnding();

	void procTitle();
	void procGame();
	void procClear();
	void procGameOver();

	// --------------------------------------------
	// �g���͍דc��K���L�q�i2021_09_29�j

	CSound* createSound(const char* filePath_, const bool loop_ = false);
	void PlaySourceSound(CSound* const objects);
	void disposeSound(CSound* const objects);
	// --------------------------------------------

	// �ۑ�p�֐�
	void procTitleBegin();
	void procTitleMain();
	void procTitleEnd();
	void procPlayBegin();
	void procPlayMain();
	void procPlayEnd();
	void procClearBegin();
	void procClearMain();
	void procClearEnd();
	void procOverBegin();
	void procOverMain();
	void procOverEnd();


	//�v���C���[�̍s�������p�ϐ�
	void PlayerAction();
	//�v���C���[�̃W�����v�̏���
	void PlayerJump();
	//�v���C���[�̉�ʊO�̏���
	void PlayerOffScreen();
	//�v���C���[�̉��ړ��̏���
	void PlayerMove();
	//�v���C���[�̓����蔻��
	void PlayerCollusionDetection();
	//�v���C���[�����񂾂Ƃ��̗�������
	void PlayerDieActionActive();
	//�v���C���[�̎c�@�̏���
	void PlayerResidue();

	//�G�̍s�������p
	void EnemyAction();
	//�G�̓���(1�i�K��)
	void EnemyFly1();
	//�G�������o�����Ԃ̑���̂��߂̊֐�
	bool Enemy_Start_Time();
	//�G�ƃv���C���[�̓����蔻��
	void PECollusionDetection();
	//�G�̉�ʊO�̍s��
	void EnemyOffScreen();
	//�G�̓����蔻��
	void EnemyCollisionDetection();
	//�G�̃o���[����j�󂵂���
	void EnemyBalloonBreak();
	//�G�̃o���[����j�󂵂���̍s��
	void EnemyNotBalloon();
	//�G�����񂾂Ƃ��̏���
	void EnemyDead();
	//�G���C�ɗ������Ƃ��̖A�̈ʒu�𒲐�����֐�
	void EnemySeaDrop();
	//�G����������ъC�ɗ������Ƃ��ɏo�Ă���A�̏���
	void EnemyFoam();


	//���{�[���̏���
	void Thunder();
	//���{�[���̕���
	void ThunderDirection(int noOfThunder);
	//���̏���
	void Fish();

	//�Ăяo�������Ŏc�@�ȊO�̑S�Ă̒l�����Z�b�g����֐�
	void AllReset();

	//�Q�[���̏I���p�֐�
	void GameClearSet();

	//�Q�[�����I��������A�ĊJ���邽�߂ɕϐ������Z�b�g����
	void GameReset();


public:
	CActionGameApp();
	~CActionGameApp();
	void render(XMFLOAT4X4 matView, XMFLOAT4X4 matProj);
	void release();


private:

	//�^�C�g����ʂ��Ǘ�����ϐ�
	CPicture* BackGround = NULL;
	//�^�C�g����ʂ̃o���[�����Ǘ�����ϐ�
	CPicture* g_pTitleBalloon = NULL;
	//�o���[���̃A�j���[�V�����p�ϐ�
	int iBalloonAnimation = 0;
	//�A�j���[�V�����̃Z�b�g�悤�ϐ�
	int iBalloonAnmSet = 0;
	//�A�j���[�V�����̏オ�艺����
	bool bBalloonAnm = false;
	//�o���[���̏オ�艺����
	int BalloonUPDOWN = 0;
	//�o���[������ɍs�������ɍs����
	bool bBalloonUPOrDOWN = false;




	//�Q�[����ʂ̃t�F�[�Y���Ǘ�����ϐ�
	ePhase g_GamePhase = eBegin;
	//�Q�[����ʂ��玟�֐i�ނƂ��̃t���[���Ǘ�����ϐ�
	eGameStatus g_NextStatusFromGame = eNone;




	//----------------------------------------------------------------------------------
		//�w�i�̉摜���Ǘ�����ϐ�
	CPicture* g_pBackground = NULL;


	//�v���C���[�̉摜�̌�
	int PlayerQuantity = 2;
	//�v���C���[�@�̉摜���Ǘ�����ϐ�
	CPicture* g_pPlayer1[2] = { NULL,NULL };
	//�v���C���[�̕\���T�C�Y
	const float PLAYER_SIZE_X = 64.0f;
	const float PLAYER_SIZE_Y = 96.0f;
	//�v���C���[�̏������W
	XMFLOAT2 PlayerSet[2] =
	{
		{-400.0f, -300.0f},
		{-400.0f + WINDOW_WIDTH,-300.0f},
	};

	//�G�̉摜�̌�
	int EnemyQuantity = 6;
	//�G�̉摜���Ǘ�����ϐ�
	CPicture* g_pEnemy[6] = { NULL,NULL };
	//�G�̉摜�̕\���T�C�Y
	const float ENEMY_SIZE_X = 64.0f;
	const float ENEMY_SIZE_Y = 96.0f;
	XMFLOAT2 EnemySet[6] =
	{
		{-150.0f,-36.0f},
		{-150.0f + WINDOW_WIDTH,-36.0f},
		{0.0f,-36.0f},
		{0.0f + WINDOW_WIDTH,-36.0f},
		{150.0f,-36.0f},
		{150.0f + WINDOW_WIDTH,-36.0f},
	};
	//�G���Q�[���ɑ��݂��Ă��鐔
	int Enemy_Number = 3; //��{3��


	//�C�̉摜�̌�
	int SeaQuantity = 9;
	//�C�̉摜���Ǘ�����ϐ�
	CPicture* g_pSea[9] = { NULL, NULL };
	//�C�̉摜�̑傫���̊Ǘ�
	const float SEA_SIZE_X = 124.0f;
	const float SEA_SIZE_Y = 80.0f;
	//�C�̉摜�̍��W
	XMFLOAT2 SeaSet[9] =
	{
		{0.0f,SeaPosY},
		{SEA_SIZE_X,SeaPosY},
		{SEA_SIZE_X * 2,SeaPosY},
		{SEA_SIZE_X * 3,SeaPosY},
		{SEA_SIZE_X * 4,SeaPosY},
		{-SEA_SIZE_X,SeaPosY},
		{-SEA_SIZE_X * 2,SeaPosY},
		{-SEA_SIZE_X * 3,SeaPosY},
		{-SEA_SIZE_X * 4,SeaPosY},
	};

	//����̌�
	int PlatFormQuantityL = 6;
	//����(L)�̉摜���Ǘ�����ϐ�
	CPicture* g_pPlatFormL[6] = { NULL,NULL };
	//����(L)�̑傫���̊Ǘ�
	const float PLATFORML_SIZE_X = 64.0f;
	const float PLATFORML_SIZE_Y = 32.0f;
	//����(L)�̍��W
	XMFLOAT2 PlatFormSetL[6] =
	{
		{PLATFORML_SIZE_X / 2,-100.0f},
		{(PLATFORML_SIZE_X / 2) + PLATFORML_SIZE_X,-100.0f},
		{(PLATFORML_SIZE_X / 2) + (PLATFORML_SIZE_X * 2),-100.0f},
		{-PLATFORML_SIZE_X / 2,-100.0f},
		{-(PLATFORML_SIZE_X / 2) - PLATFORML_SIZE_X,-100.0f},
		{-(PLATFORML_SIZE_X / 2) - (PLATFORML_SIZE_X * 2),-100.0f},
	};

	//����S�̌�
	int PlatFormQuantityS = 2;
	//����(S)�̉摜���Ǘ�����ϐ�
	CPicture* g_pPlatFormS[2] = { NULL, NULL };
	//����(S)�̑傫���̊Ǘ�
	const float PLATFORMS_SIZE_ALL = 32.0f;
	//����(S)�̍��W�̊Ǘ�
	XMFLOAT2 PlatFormSetS[2] =
	{
		{PLATFORML_SIZE_X * 3.0f + PLATFORMS_SIZE_ALL / 2 , -100.0f},
		{-PLATFORML_SIZE_X * 3.0f - PLATFORMS_SIZE_ALL / 2, -100.0f},
	};

	//�n�ʂ̉摜�̌�
	int GroundQuantity = 8;
	//�n�ʂ̉摜���Ǘ�����ϐ�
	CPicture* g_pGround[8] = { NULL,NULL };
	//�n�ʂ̑傫���̊Ǘ�
	const float GROUND_SIZE_X = 64.0f;
	const float GROUND_SIZE_Y = 72.0f;
	//�n�ʂ̍��W�̊Ǘ�
	XMFLOAT2 GroundSet[8] =
	{
		{(WINDOW_WIDTH / 2) - 32.0f,GroundPosY},
		{(WINDOW_WIDTH / 2) - (24.0f + GROUND_SIZE_Y),GroundPosY},
		{(WINDOW_WIDTH / 2) - (16.0f + (GROUND_SIZE_Y * 2)),GroundPosY},
		{(WINDOW_WIDTH / 2) - (8.0f + (GROUND_SIZE_Y * 3)),GroundPosY},
		{-(WINDOW_WIDTH / 2) + 32.0f,GroundPosY},
		{-(WINDOW_WIDTH / 2) + (24.0f + GROUND_SIZE_Y),GroundPosY},
		{-(WINDOW_WIDTH / 2) + (16.0f + (GROUND_SIZE_Y * 2)),GroundPosY},
		{-(WINDOW_WIDTH / 2) + (8.0f + (GROUND_SIZE_Y * 3)),GroundPosY},
	};

	//�_�̉摜���Ǘ�����ϐ�
	CPicture* g_pCloud = NULL;
	//�_�̉摜�̑傫���̊Ǘ�
	const float CLOUD_SIZE_X = 124.0f;
	const float CLOUD_SIZE_Y = 120.0f;
	//�_�̍��W
	XMFLOAT2 CloudSet = { 90.0f,200.0f };

	//���{�[�����Ǘ�����\����
	struct ThunderData
	{
		CPicture* obj;		//�摜�Ǘ��p
		XMFLOAT2 beginPos;			//�������W
		float thunderMoveX;			//���ړ��̒l
		float thunderMoveY;			//�c�ړ��̒l
		int thunderDirRand;			//���������߂闐���̕ϐ�
		bool isMoving;		//���{�[���������Ă��邩�𔻒f����ϐ�
	};

	//���{�[���̉摜�̐�
	int ThunderQuantity = 2;
	//���{�[���̉摜�̑傫���̊Ǘ�
	const float THUNDER_SIZE_X = 40.0f;
	const float THUNDER_SIZE_Y = 40.0f;
	//���{�[���̍��W
	ThunderData g_pThunder[2] =
	{
		{NULL,{90.0f,200.0f},0.0f,0.0f,0,false},
		{NULL,{90.0f,200.0f},0.0f,0.0f,0,false},
	};
	//���{�̂̉摜�p�̕ϐ�
	CPicture* g_pThunderBody = NULL;
	//���{�̂̕ۑ��p�̈ʒu�p�̕ϐ�
	XMFLOAT2 ThunderBodyPos = { 0.0f,800.0f };

	//���̉摜�̊Ǘ��p�ϐ�
	CPicture* g_pFish = NULL;
	//���̉摜�̑傫���̊Ǘ�
	const float FISH_SIZE_X = 80.0f;
	const float FISH_SIZE_Y = 80.0f;
	//���̍��W
	XMFLOAT2 fishPos = { 0.0f,-440.0f };

	bool resetPlayerFishPos = false;

	// �Q�[���I�[�o�[ --------------------------------
	//�t�F�[�Y
	ePhase g_GameOverPhase = eBegin;
	//�摜
	CPicture* g_pGameOver = NULL;
	//�t���[
	eGameStatus g_NextStatusFromOver = eNone;
	//�T�C�Y
	float GAMEOVER_SIZE_X;
	float GAMEOVER_SIZE_Y;
	//�Q�[���I�[�o�[�J�E���^�[
	int GameOvercounter;

	// �X�R�A------------------------------------------
	// �X�R�A�̉摜���Ǘ�����ϐ�
	CFont* g_pNumber = NULL;
	// �X�R�A�l
	int g_number = 0;
	// �X�R�A�̕\���T�C�Y
	const float NUMBER_SIZE_X = 25.0f;
	const float NUMBER_SIZE_Y = 25.0f;

	// �X�R�A(���)------------------------------------------
	// ��ڂ̃X�R�A�̕ϐ���IScore�ɂ��܂����B

	// �X�R�A�̉摜���Ǘ�����ϐ�
	CFont* g_pScore = NULL;
	// �X�R�A�l
	int g_score = 0;
	// �X�R�A�̕\���T�C�Y
	const float SCORE_SIZE_X = 25.0f;
	const float SCORE_SIZE_Y = 25.0f;

	// Top-------------------------------------------------
	//Top�̉摜���Ǘ�����ϐ�
	CPicture* g_pTop = NULL;
	// I-------------------------------------------------
	//I-�̉摜���Ǘ�����ϐ�
	CPicture* g_pI = NULL;

	//---------------------------------------------------------------------------------
	// 	//�v���C���[�̉��ړ��̑��x�̃J�E���^�[
	int horiSpeedCounter = 0;
	///�v���C���[�̉��ړ����x�̏���l
	float SpeedLimit = 3.0f;
	//�v���C���[�̋󒆉��ړ����x�̏���l
	float SpeedLimit1 = 0.8f;

	//�����̍ŏ��ɒx�������邽�߂̕ϐ�
	int SpeedUpStart = 0;
	//�����̍ŏ��̒x�������邽�߂̕ϐ��i�󒆉��ړ��j
	int SpeedUpStart1 = 0;

	//�v���C���[�̉��ړ��̑��x
	float playerHoriSpeed = 0.0f; //�@�E�ɍs���Ƃ���+�@�A���ɍs���Ƃ���-
	//�v���C���[�̋󒆉��ړ��̑��x
	float playerHoriSpeed1 = 0.0f;  //�@�E�ɍs���Ƃ���+�@�A���ɍs���Ƃ���-�@�@�@

	//�v���C���[�̃W�����v��
	float g_jumpPower = 0.0f;
	//�v���C���[�̃W�����v�͂̏��
	float g_jumpPowerMax = 3.5f;
	//�W�����v�̑��ړ���
	float g_jumpMove = 0.0f;
	//�W�����v�̏㏸�t���O
	bool g_isJumpRise = false;

	//�d�͂̃J�E���^�[
	int g_gravCounter = 0;
	//�W�����v�A�d�͂̌v�Z�p
	float g_changeGrav = 0.0f;
	//�������d�͂̏���
	const float GravLimi = -4.0f;

	//�d�͂̏���
	float moveY = 0.0f;
	//�d�͂�������܂ł̎��ԗp�ϐ�
	int PlayerGravDownTime = 0;

	//�v���C���[�̎c�@
	int iPlayerResidue = 3;
	//�v���C���[�̃o���[���̐�
	int PlayerBalloon = 2;
	//�v���C���[������\���ǂ���
	bool PlayerDieBalloon = false;
	//�v���C���[�̖��G����
	bool PlayerInvincible = false;


	//--------------------------------------------------------------------------------
	//�G�̑��ړ����x���(�c�Ɖ�)
	float ENEMY_SPEED_X = 0.0f;
	float ENEMY_SPEED_Y = 0.0f;
	float ENEMY_SPEED_X2 = 0.0f;
	float ENEMY_SPEED_Y2 = 0.0f;
	float ENEMY_SPEED_X3 = 0.0f;
	float ENEMY_SPEED_Y3 = 0.0f;
	//�G�̈ړ��̍ő�l
	const float Enemy_Speed_Limit_X = 3.0f;
	const float Enemy_Speed_Limit_Y = 2.0f;
	const float Enemy_Speed_Limit_Balloon_X = 0.2f;
	//�G�̍s�����Ǘ�����\����
	struct Enemy_Move
	{
		XMFLOAT2 PlayerPos; //�v���C���[�̏������W�擾
		bool EnemyMoveTrue; //���W�擾�����ǂ����̔���
		int EnemyMoveTime;	//�擾�܂ł̎���
		int EnemyMove_2_3; //2�i�K�ڈȍ~�̈�莞�ԓG�������Ȃ�����
	};
	//�G1�̍s���p
	Enemy_Move Enemy1 = { {0.0f,0.0f},false,0,0 };
	Enemy_Move Enemy2 = { {0.0f,0.0f},false,0,0 };
	Enemy_Move Enemy3 = { {0.0f,0.0f},false,0,0 };
	//�G�����j���ꂽ���ǂ����̔���p
	bool Enemy_Defeat[3] = { false,false,false };
	//�X�e�[�^�X�̕ύX�p
	int EnemyStateChange[3] = { 0,0,0 };
	//�G�������o���܂ł̎��ԗp�̕ϐ�
	int iEnemy_Start_Time = 0;
	//��莞�Ԃ��߂������̔���p�ϐ�
	bool bEnemyTimeUp = false;
	//���ԑ���p�̕ϐ�
	int iEnemyTimeUp = 0;
	//�G�̃o���[�����j�󂳂ꂽ���ɔj�󂳂ꂽ�ꏊ�̍��W��ۑ�����ϐ�
	XMFLOAT2 EnemyBreakBalloon[3] = { {0,0},{0,0},{0,0} };
	//���W���擾�������̔���p�ϐ�
	bool getPos_Enemy[3] = { false,false };
	//�E�ɍs�������ɍs�����̔���
	//false = ��
	//true  = �E
	bool RightorLeft[3] = { false,false };


	//�G�̍s���̒i�K���w�肷��ϐ�
	int enemyMovementStage[3] = { 1,1,1 };

	//-----------------------------------------------------------------------------------
	//���̏���
	//�v���C���[�����ɕ߂܂ꂽ
	bool playerCaughtByFish = false;
	//�G�����ɕ߂܂�����
	bool enemyCaughtByFish = false;
	//�����オ��n�߂�
	bool fishStartedMoving = false;
	//���̃J�E���^�[
	int fishCounter = 1;

	//�v���C���[�����ʂƂ��A�j���[�V�����p
	int playerDeathAnimeCounter = 0;
	int playerDeathGoUpCounter = 0;
	//�v���C���[�����񂾂��ǂ����𔻒肷��p�J�E���^�[
	bool playerIsDead = false;

	//�v���C���[���W�����v���鎞�̃A�j���[�V�����p
	int playerJumpAnimIndex = 0;
	bool startPlayerJumpAnimCounter = false;

	//�G�̃o���[�����j�󂳂ꂽ���ǂ����𔻒�p
	bool enemyBalloonIsBroken[3] = { true, true, true };
	//�G�����񂾂��ǂ����𔻒�p
	bool enemyIsDead[3] = { false,false, false };

	//�G����������Ƃ��A�j���[�V�����p�J�E���^�[
	int enemyFallingCounter[3] = { 0,0,0 };
	//�G���������Ă��邩�ǂ����̔���p
	bool enemyDeadFalling[3] = { false,false,false };
	//�G�̃o���[�������ꂽ���A�n�ʂɓ���������Ƀo���[������蒼���^�C�~���O�̃J�E���^�[
	int enemyPumpBalloonCDCounter[3] = { 0,0,0 };
	//�G���o���[�������A�j���[�V�����p�J�E���^�[
	int enemyPumpBalloonCounter[3] = { 0,0,0 };
	//�G���o���[��������Ă��邩�ǂ����̔���p
	bool enemyPumpBalloon[3] = { false,false,false };

	//�G�����񂾂Ƃ��ɏ�ɏオ��͈͗p
	int EnemyDeadUp[3] = { 0,0,0 };
	//�G�����񂾂Ƃ��̃A�j���[�V�����p�J�E���^�[
	int EnemyDeadAnimeCounter[3] = { 0,0,0 };
	//���񂾓G�̐�
	int noOfDeadEnemy = 0;
	
	int iEnemyStrong[3] = { 0,0 };

//-----------------------------------------------------------------------------
	//�A�̉摜�̍쐬
	//�A�̉摜�p�̕ϐ��̍쐬
	CPicture* g_pFoam[3] = { NULL,NULL };
	//�A�̉摜�p�̍��W�Ǘ��p�ϐ�
	XMFLOAT2 FoamPos[3] = { {0,0},{0,0} };
	//�A�̉摜�̌��̕ϐ�
	int FoamQuantity = 3;
	//�A�̃t���[���Ǘ��p�ϐ�
	int iFoamFleam[3] = { 0,0 };
	//���E�̂ǂ���ɓ����̂��̌���p�ϐ�
	bool FoamRL[3] = { false,false };
	//�A�̍��E�̗h��̑���p�ϐ���
	//���E�n
	float FoamMove_X[3] = { 0.0f,0.0f };
	float FoamMove_X_Limit = 1.0f;

//-----------------------------------------------------------------------------
	//���W���擾�������̔���p
	bool PosGetSea[3] = { false,false,false };



	//�v���C���[�̎c�@�̉摜�p�̕ϐ�
	CPicture* g_pPlayer_RM[2] = { NULL , NULL };
	//�v���C���[�̎c�@�̌�
	int PlayerRMQuantity = 2;
	//�v���C���[�̎c�@�̍��W
	XMFLOAT2 g_PlayerRM[2] = {
		{-170.0f , 420.0f},
		{-150.0f , 420.0f},
	};

	//���{�[�����������n�߂�O�̎��Ԃ��v�Z����
	int ThunderSpawnCounter = 0;
	//���{�[��������������Atrue��������
	bool ThunderSpawning = false;
	//���{�[���̐������x���Ǘ�����J�E���^�[
	int ThunderSpawnCD = NULL;


	bool enemyOnGround[3] = { true,true,true };

	bool PlayerIsKilledByThunder = false;

	//�Q�[���N���A���Ƀv���C���[���~�߂�֐�
	bool bPlayerStop = false;
};