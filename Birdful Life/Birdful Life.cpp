/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "resource.h"

//########## �}�N����` ##########
#define GAME_WIDTH			1280	//��ʂ̉��̑傫��
#define GAME_HEIGHT			720	    //��ʂ̏c�̑傫��
#define GAME_COLOR			32	    //��ʂ̃J���[�r�b�g

#define GAME_WINDOW_BAR		0					//�^�C�g���o�[�̓f�t�H���g�ɂ���
#define GAME_WINDOW_NAME	"BIRDFULLIFE"		//�E�B���h�E�̃^�C�g��

#define GAME_FPS			60	//FPS�̐��l	

//�}�E�X�̃{�^��
#define MOUSE_BUTTON_CODE	129	//0x0000�`0x0080�܂�

//�L�[�{�[�h�̎��
#define KEY_CODE_KIND		256	//256���

//�p�X�̒���
#define PATH_MAX			255	//255�����܂�
#define NAME_MAX			255	//255�����܂�

//����
#define GAME_SOUND_VOLUME_PER	30	//�����S���̉��ʂ�30%���x�ɂ���
#define GAME_SOUND_VOLUME	255*GAME_SOUND_VOLUME_PER/100	//���̊����̉���

//�t�H���g
#define FONT_TANU_PATH			TEXT(".\\FONT\\TanukiMagic.ttf")	//�t�H���g�̏ꏊ
#define FONT_TANU_NAME			TEXT("���ʂ������}�W�b�N")			//�t�H���g�̖��O

//�G���[���b�Z�[�W
#define FONT_INSTALL_ERR_TITLE	TEXT("�t�H���g�C���X�g�[���G���[")
#define FONT_CREATE_ERR_TITLE	TEXT("�t�H���g�쐬�G���[")

//���y�p�X
#define MUSIC_TITLE_BGM_PATH TEXT(".\\MUSIC\\�؂̂��M.mp3")	                //�^�C�g�����BGM
#define MUSIC_TITLE_SE_PATH TEXT(".\\MUSIC\\�q���R�̖���_�ҏW�ς�.mp3")	//�^�C�g�����SE
#define MUSIC_RULE_BGM_PATH TEXT(".\\MUSIC\\�؂̂��M.mp3")	                //���[���������BGM
#define MUSIC_PLAY_BGM_PATH TEXT(".\\MUSIC\\�L���L��������.mp3")	        //�v���C���BGM
#define MUSIC_END_BGM_PATH TEXT(".\\MUSIC\\�\���C���r����.mp3")	            //�G���h���BGM

#define MUSIC_DAMAGE_PATH TEXT(".\\MUSIC\\damage1.mp3")	            //�_���[�W���ʉ�
#define MUSIC_GET_PATH TEXT(".\\MUSIC\\score2.mp3")	            //�G�T���Ƃ����Ƃ��̌��ʉ�

#define MUSIC_KARASU_PATH TEXT(".\\MUSIC\\.mp3")	            //�J���X�o�����̖���


//�摜�p�X�@�����O�̕t�����͊�{�I��IMAGE_�V�[����_���̉摜��_PATH
#define IMAGE_RULE_EX_PATH       TEXT(".\\IMAGE\\LevelUP_rogo.png")         //���[�������摜
#define IMAGE_END_BACK1_PATH     TEXT(".\\IMAGE\\�w�i�A��_�␳����1.png")   //�G���h�w�i�Ђȃp�^�[��1
#define IMAGE_END_BACK2_PATH     TEXT(".\\IMAGE\\�w�i�A��_�␳����1.png")   //�G���h�w�i�Ђȃp�^�[��2
#define IMAGE_END_BACK3_PATH     TEXT(".\\IMAGE\\�w�i�A��_�␳����1.png")   //�G���h�w�i�Ђȃp�^�[��3
#define IMAGE_END_TBUTTON_PATH   TEXT(".\\IMAGE\\Easy_logo.png")            //�G���h�@�^�C�g���փ{�^��
#define IMAGE_END_ABUTTON_PATH   TEXT(".\\IMAGE\\Hard_logo.png")            //�G���h�@�������{�^��
#define IMAGE_END_TBUTTON2_PATH  TEXT(".\\IMAGE\\Easy_logo2.png")           //�G���h�@�^�C�g���փ{�^��2
#define IMAGE_END_ABUTTON2_PATH  TEXT(".\\IMAGE\\Hard_logo2.png")           //�G���h�@�������{�^��2

#define IMAGE_TITLE_ROGO_PATH    TEXT(".\\IMAGE\\rogo1.png")           //�^�C�g�����S
#define IMAGE_TITLE_PUSH_PATH	 TEXT(".\\IMAGE\\PushEnterToStart.png")	//�G���^�[�L�[�ŃX�^�[�g�̃��S

//�w�i�X�N���[��
#define IMAGE_TITLE_BACK1_PATH    TEXT(".\\IMAGE\\�w�i�A��_�␳����1.png")           //�^�C�g���w�i��1
#define IMAGE_TITLE_BACK2_PATH    TEXT(".\\IMAGE\\�w�i�A��_�␳����2.png")           //�^�C�g���w�i��2
#define IMAGE_TITLE_BACK3_PATH    TEXT(".\\IMAGE\\�w�i�A��_�␳����3.png")           //�^�C�g���w�i��3
#define IMAGE_TITLE_BACK4_PATH    TEXT(".\\IMAGE\\�w�i�A��_�␳����4.png")           //�^�C�g���w�i��4

#define IMAGE_TITLE_BACK_NUM	4	//�w�i�摜�̖���



//�L�����N�^�[
#define PLAYER_PATH		TEXT(".\\IMAGE\\player_animation.png")	//�v���C���[�̉摜
#define IMAGE_ENEMY_PATH		TEXT(".\\IMAGE\\�J���X�m�[�}��.png")	//�G�i�J���X�̉摜�j
#define IMAGE_ENEMY2_PATH		TEXT(".\\IMAGE\\�J���X�m�[�}��2.png")	//�G�i�J���X�̉摜�j
#define ENEMY_NUM				50    //�@�G�̂l�`�w�l


//�A�C�e��
#define IMAGE_ESA_PATH	TEXT(".\\IMAGE\\��.png")	//�G�T�̉摜
#define ESA_MAX 10		//�G�T�̍ő�o����


//�G���[���b�Z�[�W
#define IMAGE_LOAD_ERR_TITLE	TEXT("�摜�ǂݍ��݃G���[")

//�G���[���b�Z�[�W
#define MUSIC_LOAD_ERR_TITLE	TEXT("���y�ǂݍ��݃G���[")

//����{�^�����������Ƃ�
#define MSG_CLOSE_TITLE			TEXT("�I�����b�Z�[�W")
#define MSG_CLOSE_CAPTION		TEXT("�Q�[�����I�����܂����H")

//�ЂȃZ���t�̕\��
#define MESSAGE_FONT_SIZE      100          //�t�H���g�̑傫��
#define MESSAGE_MAX_LENGTH     1000          //�ő啶����
#define MESSAGE_MAX_LINE       20           //�ő�s��
#define MESSAGE_BOX_X          700          //���b�Z�[�W�{�b�N�X��X���W
#define MESSAGE_BOX_Y          50           //���b�Z�[�W�{�b�N�X��Y���W
#define MESSAGE_BOX_GRAPHIC_FILENAME       "./IMAGE/�w�i�A��1.png"

enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_SCENE_RULE,
	GAME_SCENE_PLAY,
	GAME_SCENE_END,
};	//�Q�[���̃V�[��

//int�^��POINT�\����
typedef struct STRUCT_I_POINT
{
	int x = -1;	//���W��������
	int y = -1;	//���W��������
}iPOINT;

//�}�E�X�\����
typedef struct STRUCT_MOUSE
{
	int InputValue = 0;	//GetMouseInput�̒l������
	int WheelValue = 0;	//�}�E�X�z�C�[���̉�]��(���̓v���X�l / ��O�̓}�C�i�X�l)
	iPOINT Point;		//�}�E�X�̍��W������
	iPOINT OldPoint;	//�}�E�X�̍��W(���O)������
	int OldButton[MOUSE_BUTTON_CODE] = { 0 };	//�}�E�X�̃{�^������(���O)������
	int Button[MOUSE_BUTTON_CODE] = { 0 };	//�}�E�X�̃{�^�����͂�����
}MOUSE;

//�t�H���g�\����
typedef struct STRUCT_FONT
{
	char path[PATH_MAX];		//�p�X
	char name[NAME_MAX];		//�t�H���g��
	int handle;					//�n���h��
	int size;					//�傫��
	int bold;					//����
	int type;					//�^�C�v
	
}FONT;

typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];		//�p�X
	int handle;					//�n���h��
	int x;						//X�ʒu
	int y;						//Y�ʒu
	int width;					//��
	int height;					//����
	BOOL IsDraw = FALSE;		//�`��ł��邩
}IMAGE;	//�摜�\����

typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];		//�p�X
	int handle;					//�n���h��
}MUSIC;	//���y�\����

typedef struct STRUCT_CHARA
{
	IMAGE image;				//IMAGE�\����
	int speed;					//����
	int handle[2];
	int x;
	int y;
	int width;
	int height;
	BOOL IsDraw;
	RECT rect;

	RECT coll;					//�����蔻��
	iPOINT collBeforePt;		//������O�̍��W

	//�v���C���[��p
	int life = 100;		//�v���C���[�̃��C�t

	//�G�l�~�[��p
	BOOL IsCreate = FALSE;	//�����������H

}CHARA;	//�L�����N�^�[�\����

typedef struct STRUCT_IMAGE_BACK
{
	IMAGE image;		//IMAGE�\����
	BOOL IsDraw;		//�e��\���ł��邩
}IMAGE_BACK;	//�w�i�摜�̍\����

//########## �O���[�o���ϐ� ##########
//FPS�֘A
int StartTimeFps;				//����J�n����
int CountFps;					//�J�E���^
float CalcFps;					//�v�Z����
int SampleNumFps = GAME_FPS;	//���ς����T���v����

//�L�[�{�[�h�̓��͂��擾
char AllKeyState[KEY_CODE_KIND] = { '\0' };		//���ׂẴL�[�̏�Ԃ�����
char OldAllKeyState[KEY_CODE_KIND] = { '\0' };	//���ׂẴL�[�̏��(���O)������

//�}�E�X�̍��W���擾
MOUSE mouse;

//�Q�[���֘A
int GameScene;		//�Q�[���V�[�����Ǘ�

//�L�����N�^�[�֘A
CHARA player; 
CHARA enemy[ENEMY_NUM];
CHARA karasu1;
CHARA karasu2;

int playercount; //�v���C���[�̃A�j���[�V�����p�J�E���g
int mutekicount;	//���G���Ԃ𑪂�J�E���g
int tennmetu;		//�_�Ŏ��Ԃ𑪂�J�E���g

BOOL Ishit = TRUE;		//�����蔻�肪����
BOOL IsMuteki = FALSE;	//���G��ԂɂȂ��Ă��邩

int TekiCreateCnt = 0;					//�G�����Ԋu
int TekiCreateCntMax = GAME_FPS * 5;	//�G�����Ԋu(MAX)

//�A�C�e���֘A
IMAGE esa[ESA_MAX];
int score = 0;

//���y�֘A
MUSIC TitleBGM;	//�^�C�g��BGM
MUSIC TitleSE;	//�^�C�g��SE
MUSIC RuleBGM;	//���[������BGM
MUSIC PlayBGM;
MUSIC EndBGM;	//�G���hBGM

MUSIC GetSE;	//�G�T�����ʉ�
MUSIC DamageSE;	//�_���[�W���ʉ�
MUSIC KarasuSE;	//�J���X����


//�摜�֘A �����O�̕t������Image�V�[�������̉摜��;
IMAGE ImageTitleRogo;				 //�^�C�g�����S
IMAGE ImageTitlePush;				 //PUSH_TO_ENTER���S

IMAGE ImageRuleEx;                   //���[�������摜
IMAGE ImageEndTbutton;               //�G���h�^�C�g���փ{�^��
IMAGE ImageEndAbutton;               //�G���h�������{�^��
IMAGE ImageEndTbutton2;              //�G���h�^�C�g���փ{�^��2
IMAGE ImageEndAbutton2;              //�G���h�������{�^��2

//�w�i�֘A
IMAGE_BACK ImageTitleBack[IMAGE_TITLE_BACK_NUM];	//�^�C�g���w�i
IMAGE ImageEndBack1;                                //�G���h�w�i�Ђȃp�^�[��1
IMAGE ImageEndBack2;                                //�G���h�w�i�Ђȃp�^�[��2
IMAGE ImageEndBack3;                                //�G���h�w�i�Ђȃp�^�[��3

//�ЂȃZ���t�֘A
char message[MESSAGE_MAX_LENGTH * MESSAGE_MAX_LINE];        //�\�����������b�Z�[�W
char messageBuffer[MESSAGE_MAX_LINE][MESSAGE_MAX_LENGTH];   //���b�Z�[�W��\�����邽�߂̉��z�o�b�t�@
static int currentCursor = 0;                               //�������ڂ܂ŕ\�����Ă��邩
static int currentLineCursor = 0;                           //���s�ڂ�\�����Ă��邩
static int whiteColor;
static int blackColor;
static int messageBoxGraphHandle;
int isJapanese(unsigned char code);

//########## �v���g�^�C�v�錾 ##########//
VOID MY_FPS_UPDATE(VOID);			//FPS�l���v���A�X�V����
VOID MY_FPS_DRAW(VOID);				//FPS�l��`�悷��
VOID MY_FPS_WAIT(VOID);				//FPS�l���v�����A�҂�

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[�̓��͏�Ԃ��X�V����
BOOL MY_KEY_DOWN(int);				//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
BOOL MY_KEY_UP(int);				//�L�[�������グ�����A�L�[�R�[�h�Ŕ��f����
BOOL MY_KEYDOWN_KEEP(int, int);		//�L�[�����������Ă��邩�A�L�[�R�[�h�Ŕ��f����

VOID MY_MOUSE_UPDATE(VOID);			//�}�E�X�̓��͏����X�V����
BOOL MY_MOUSE_DOWN(int);			//�{�^���������Ă��邩�A�}�E�X�R�[�h�Ŕ��f����
BOOL MY_MOUSE_UP(int);				//�{�^���������グ�����A�}�E�X�R�[�h�Ŕ��f����
BOOL MY_MOUSEDOWN_KEEP(int, int);	//�{�^�������������Ă��邩�A�}�E�X�R�[�h�Ŕ��f����

BOOL MY_FONT_INSTALL_ONCE(VOID);	//�t�H���g�����̃\�t�g�p�ɁA�ꎞ�I�ɃC���X�g�[��
VOID MY_FONT_UNINSTALL_ONCE(VOID);	//�t�H���g�����̃\�t�g�p�ɁA�ꎞ�I�ɃA���C���X�g�[��
BOOL MY_FONT_CREATE(VOID);			//�t�H���g���쐬����
VOID MY_FONT_DELETE(VOID);			//�t�H���g���폜����

VOID MY_START(VOID);		        //�X�^�[�g���
VOID MY_START_PROC(VOID);	        //�X�^�[�g��ʂ̏���
VOID MY_START_DRAW(VOID);	        //�X�^�[�g��ʂ̕`��

VOID MY_RULE(VOID);                //���[���������
VOID MY_RULE_PROC(VOID);           //���[��������ʂ̏���
VOID MY_RULE_DRAW(VOID);           //���[��������ʂ̕`��

VOID MY_PLAY_INIT(VOID);	       //�v���C��ʏ�����
VOID MY_PLAY(VOID);			       //�v���C���
VOID MY_PLAY_PROC(VOID);	       //�v���C��ʂ̏���
VOID MY_PLAY_DRAW(VOID);	       //�v���C��ʂ̕`��

VOID MY_END(VOID);			       //�G���h���
VOID MY_END_PROC(VOID);		       //�G���h��ʂ̏���
VOID MY_END_DRAW(VOID);		       //�G���h��ʂ̕`��

BOOL MY_LOAD_IMAGE(VOID);		   //�摜���܂Ƃ߂ēǂݍ��ފ֐�
VOID MY_DELETE_IMAGE(VOID);		   //�摜���܂Ƃ߂č폜����֐�

BOOL MY_LOAD_MUSIC(VOID);		   //���y���܂Ƃ߂ēǂݍ��ފ֐�
VOID MY_DELETE_MUSIC(VOID);		   //���y���܂Ƃ߂č폜����֐�

VOID writeSubstring(char* message, int start, int len,
	int PosX, int PosY, int color, int bufferLine);        //������̏�������
VOID drawMessage(VOID);                                    //������̕`��
VOID setMessage(const char* ms);                           //�`�悵�������b�Z�[�W���Z�b�g

BOOL MY_CHECK_RECT_COLL(RECT, RECT);		//�����蔻��֐�

//�����蔻��֐�
VOID EnemyAtari(CHARA* e);	//�G

//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);				//Log.txt���o�͂��Ȃ�
	ChangeWindowMode(TRUE);								//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//�w��̐��l�ŃE�B���h�E��\������
	SetWindowStyleMode(GAME_WINDOW_BAR);				//�^�C�g���o�[�̓f�t�H���g�ɂ���
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));			//�E�B���h�E�̃^�C�g���̕���
	SetAlwaysRunFlag(TRUE);								//��A�N�e�B�u�ł����s����
	//SetWindowIconID(IDI_ICON1);							//�A�C�R���t�@�C����Ǎ�
	SetWindowUserCloseEnableFlag(FALSE);				//����{�^���ŁA����ɃE�B���h�E�����Ȃ��悤�ɂ���

	if (DxLib_Init() == -1) { return -1; }	//�c�w���C�u��������������

	//�摜��ǂݍ���
	if (MY_LOAD_IMAGE() == FALSE) { return -1; }

	//���y��ǂݍ���
	if (MY_LOAD_MUSIC() == FALSE) { return -1; }

	//�t�H���g���ꎞ�I�ɃC���X�g�[��
	if (MY_FONT_INSTALL_ONCE() == FALSE) { return -1; }
	//�t�H���g�n���h�����쐬
	if (MY_FONT_CREATE() == FALSE) { return -1; }


	GameScene = GAME_SCENE_START;	//�Q�[���V�[���̓X�^�[�g��ʂ���
	SetDrawScreen(DX_SCREEN_BACK);	//Draw�n�֐��͗���ʂɕ`��

	//�������[�v
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��
		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		//��ʂ̕���{�^���������ꂽ�Ƃ�
		if (GetWindowUserCloseFlag(TRUE))
		{
			//�I���_�C�A���O��\��
			int Ret = MessageBox(GetMainWindowHandle(), MSG_CLOSE_CAPTION, MSG_CLOSE_TITLE, MB_YESNO | MB_ICONASTERISK);
			if (Ret == IDYES) { break; }	//YES�Ȃ�A�Q�[���𒆒f����
		}

		MY_ALL_KEYDOWN_UPDATE();				//�����Ă���L�[��Ԃ��擾

		MY_MOUSE_UPDATE();						//�}�E�X�̏�Ԃ��擾

		MY_FPS_UPDATE();	//FPS�̏���[�X�V]

		//�V�[�����Ƃɏ������s��
		switch (GameScene)
		{
		case GAME_SCENE_START:
			MY_START();	//�X�^�[�g���
			break;
		case GAME_SCENE_RULE:
			MY_RULE();
			break;
		case GAME_SCENE_PLAY:
			MY_PLAY();	//�v���C���
			break;
		case GAME_SCENE_END:
			MY_END();	//�G���h���
			break;
		}

		MY_FPS_DRAW();		//FPS�̏���[�`��]

		ScreenFlip();		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		MY_FPS_WAIT();		//FPS�̏���[�҂�]
	}

	//�t�H���g�n���h����j��
	MY_FONT_DELETE();

	//�ꎞ�I�ɃC���X�g�[�������t�H���g���A���C���X�g�[��
	MY_FONT_UNINSTALL_ONCE();

	//�摜�n���h����j��
	MY_DELETE_IMAGE();

	//���y�n���h����j��
	MY_DELETE_MUSIC();

	DxLib_End();	//�c�w���C�u�����g�p�̏I������

	return 0;
}

//########## FPS�l���v���A�X�V����֐� ##########
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1�t���[���ڂȂ玞�����L��
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60�t���[���ڂȂ畽�ς��v�Z
	{
		int now = GetNowCount();
		//���݂̎��Ԃ���A0�t���[���ڂ̎��Ԃ������AFPS�̐��l�Ŋ��遁1FPS�ӂ�̕��ώ��Ԃ��v�Z�����
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS�l��`�悷��֐� ##########
VOID MY_FPS_DRAW(VOID)
{
	//�������`��
	DrawFormatString(0, GAME_HEIGHT - 20, GetColor(255, 0, 0), "FPS:%.1f", CalcFps);
	return;
}

//########## FPS�l���v�����A�҂֐� ##########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//������������
	int waitTime = CountFps * 1000 / GAME_FPS - resultTime;	//�҂ׂ�����

	if (waitTime > 0)		//�w���FPS�l���������ꍇ
	{
		WaitTimer(waitTime);	//�҂�
	}
	return;
}

//########## �L�[�̓��͏�Ԃ��X�V����֐� ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{

	//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����
	char TempKey[KEY_CODE_KIND];

	//���O�̃L�[���͂��Ƃ��Ă���
	for (int i = 0; i < KEY_CODE_KIND; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < KEY_CODE_KIND; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}

//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
//���@���Fint�F�L�[�R�[�h�FKEY_INPUT_???
BOOL MY_KEY_DOWN(int KEY_INPUT_)
{
	//�L�[�R�[�h�̃L�[�������Ă��鎞
	if (AllKeyState[KEY_INPUT_] != 0)
	{
		return TRUE;	//�L�[�������Ă���
	}
	else
	{
		return FALSE;	//�L�[�������Ă��Ȃ�
	}
}

//�L�[�������グ�����A�L�[�R�[�h�Ŕ��f����
//���@���Fint�F�L�[�R�[�h�FKEY_INPUT_???
BOOL MY_KEY_UP(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] >= 1	//���O�͉����Ă���
		&& AllKeyState[KEY_INPUT_] == 0)	//���͉����Ă��Ȃ��Ƃ�
	{
		return TRUE;	//�L�[�������グ�Ă���
	}
	else
	{
		return FALSE;	//�L�[�������グ�Ă��Ȃ�
	}
}

//�L�[�����������Ă��邩�A�L�[�R�[�h�Ŕ��f����
//���@���Fint�F�L�[�R�[�h�FKEY_INPUT_???
//���@���Fint�F�L�[�����������鎞��
BOOL MY_KEYDOWN_KEEP(int KEY_INPUT_, int DownTime)
{
	//���������鎞��=�b���~FPS�l
	//��j60FPS�̃Q�[���ŁA1�b�ԉ���������Ȃ�A1�b�~60FPS
	int UpdateTime = DownTime * GAME_FPS;

	if (AllKeyState[KEY_INPUT_] > UpdateTime)
	{
		return TRUE;	//���������Ă���
	}
	else
	{
		return FALSE;	//���������Ă��Ȃ�
	}
}

//�}�E�X�̓��͏����X�V����
VOID MY_MOUSE_UPDATE(VOID)
{
	//�}�E�X�̈ȑO�̍��W���擾
	mouse.OldPoint = mouse.Point;

	//�}�E�X�̈ȑO�̃{�^�����͂��擾
	for (int i = 0; i < MOUSE_BUTTON_CODE; i++) { mouse.OldButton[i] = mouse.Button[i]; }

	//�}�E�X�̍��W���擾
	GetMousePoint(&mouse.Point.x, &mouse.Point.y);

	//�}�E�X�̉����Ă���{�^�����擾
	mouse.InputValue = GetMouseInput();

	//���{�^���������Ă��邩�`�F�b�N(TRUE��0�ȊO�Ȃ̂ŁA2��4��TRUE)
	if ((mouse.InputValue & MOUSE_INPUT_LEFT) == MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT]++; }		//�����Ă���
	if ((mouse.InputValue & MOUSE_INPUT_LEFT) != MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT] = 0; }		//�����Ă��Ȃ�

	//���{�^���������Ă��邩�`�F�b�N(TRUE��0�ȊO�Ȃ̂ŁA2��4��TRUE)
	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) == MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE]++; }	//�����Ă���
	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) != MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE] = 0; }	//�����Ă��Ȃ�

	//�E�{�^���������Ă��邩�`�F�b�N(TRUE��0�ȊO�Ȃ̂ŁA2��4��TRUE)
	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) == MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT]++; }		//�����Ă���
	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) != MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT] = 0; }	//�����Ă��Ȃ�

	//�z�C�[���̉�]�ʂ��擾
	mouse.WheelValue = GetMouseWheelRotVol();

	return;
}

//�{�^���������Ă��邩�A�}�E�X�[�R�[�h�Ŕ��f����
//���@���Fint�F�}�E�X�R�[�h�FMOUSE_INPUT_???
BOOL MY_MOUSE_DOWN(int MOUSE_INPUT_)
{
	//�}�E�X�R�[�h�̃{�^���������Ă��鎞
	if (mouse.Button[MOUSE_INPUT_] != 0)
	{
		return TRUE;	//�{�^���������Ă���
	}
	else
	{
		return FALSE;	//�{�^���������Ă��Ȃ�
	}
}

//�{�^���������グ�����A�}�E�X�R�[�h���f����
//���@���Fint�F�}�E�X�R�[�h�FMOUSE_INPUT_???
BOOL MY_MOUSE_UP(int MOUSE_INPUT_)
{
	if (mouse.OldButton[MOUSE_INPUT_] >= 1	//���O�͉����Ă���
		&& mouse.Button[MOUSE_INPUT_] == 0)	//���͉����Ă��Ȃ��Ƃ�
	{
		return TRUE;	//�{�^���������グ�Ă���
	}
	else
	{
		return FALSE;	//�{�^���������グ�Ă��Ȃ�
	}
}

//�{�^�������������Ă��邩�A�}�E�X�R�[�h���f����
//���@���Fint�F�}�E�X�R�[�h�FMOUSE_INPUT_???
//���@���Fint�F�{�^�������������鎞��
BOOL MY_MOUSEDOWN_KEEP(int MOUSE_INPUT_, int DownTime)
{
	//���������鎞��=�b���~FPS�l
	//��j60FPS�̃Q�[���ŁA1�b�ԉ���������Ȃ�A1�b�~60FPS
	int UpdateTime = DownTime * GAME_FPS;

	if (mouse.Button[MOUSE_INPUT_] > UpdateTime)
	{
		return TRUE;	//���������Ă���
	}
	else
	{
		return FALSE;	//���������Ă��Ȃ�
	}
}

//�t�H���g�����̃\�t�g�p�ɁA�ꎞ�I�ɃC���X�g�[��
BOOL MY_FONT_INSTALL_ONCE(VOID)
{
	//�t�H���g���ꎞ�I�ɓǂݍ���(WinAPI)
	if (AddFontResourceEx(FONT_TANU_PATH, FR_PRIVATE, NULL) == 0)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), FONT_TANU_NAME, FONT_INSTALL_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//�t�H���g�����̃\�t�g�p�ɁA�ꎞ�I�ɃA���C���X�g�[��
VOID MY_FONT_UNINSTALL_ONCE(VOID)
{
	//�ꎞ�I�ɓǂݍ��񂾃t�H���g���폜(WinAPI)
	RemoveFontResourceEx(FONT_TANU_PATH, FR_PRIVATE, NULL);

	return;
}

//�t�H���g��ǂݍ��ފ֐�
//���@���Fconst char *�F�ǂݍ��ރt�H���g�̖��O
//���@���Fint�@�F�t�H���g�̑傫��
//���@���Fint�@�F�t�H���g�̑���
//���@���Fint�@�F�t�H���g�̃^�C�v
//�߂�l�FBOOL �F�G���[����FALSE / ���펞��TRUE
BOOL MY_FONT_CREATE(VOID)
{
	return TRUE;
}

//�t�H���g���폜����֐�
VOID MY_FONT_DELETE(VOID)
{

	return;
}

//�X�^�[�g���
VOID MY_START(VOID)
{
	MY_START_PROC();	//�X�^�[�g��ʂ̏���
	MY_START_DRAW();	//�X�^�[�g��ʂ̕`��


	//DrawString(0, 0, "�X�^�[�g���(�G���^�[�L�[�������ĉ�����)", GetColor(0, 0, 0));
	return;
}

//�X�^�[�g��ʂ̏���
VOID MY_START_PROC(VOID)
{
	//BGM�Đ�
	if (CheckSoundMem(TitleBGM.handle) == 0)//�܂�BGM���Ȃ��Ă��Ȃ�������
	{
		ChangeVolumeSoundMem(GAME_SOUND_VOLUME, TitleBGM.handle);
		PlaySoundMem(TitleBGM.handle, DX_PLAYTYPE_LOOP); //���[�v�Đ�
	}

	//�G���^�[�L�[����������A�v���C�V�[���ֈړ�����
	if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
	{

		//�v���C���[�̏����ʒu��ݒ�
		player.x = 100;
		player.y = 400;


		//�G�T�̏����ʒu
		for (int i = 0; i < ESA_MAX; i++)
		{
			esa[i] = esa[0];	//�G�T0�̏���S�ẴG�T�ɃR�s�[

			esa[i].x = (GAME_WIDTH + esa[i].width * i * 5);	//�G�T��X�����ʒu(�G�T�܌��̉����Ԋu�ŏo��); 

			//�G�T��Y�ʒu�������_���ɂ���
			int ichi = GetRand(GAME_HEIGHT - esa[i].height);
			
			esa[i].y = ichi;
		}


		//BGM��~
		if (CheckSoundMem(TitleBGM.handle) != 0)//BGM������Ă�����
		{
			StopSoundMem(TitleBGM.handle); //�~�߂�
		}

		ChangeVolumeSoundMem(GAME_SOUND_VOLUME, TitleSE.handle);//SE�̉��ʒ���
		PlaySoundMem(TitleSE.handle, DX_PLAYTYPE_BACK);//SE��炷

		MY_PLAY_INIT();	//�Q�[��������

		//�Q�[���̃V�[�����v���C��ʂɂ���
		GameScene = GAME_SCENE_RULE;

		return;
	}


	//�w�i�摜�𓮂���
	for (int num = 0; num < IMAGE_TITLE_BACK_NUM; num++)
	{
		//�摜���ړ�������
		ImageTitleBack[num].image.x--;//�E���獶�ɗ����

		//�w�i�摜��`��ł��Ȃ��Ƃ�
		if (ImageTitleBack[num].IsDraw == FALSE)
		{
			//�w�i�摜����ʓ��ɂ���Ƃ�
			if (ImageTitleBack[num].image.x + ImageTitleBack[num].image.width > 0)
			{
				ImageTitleBack[num].IsDraw = TRUE;	//�摜��`�悷��
			}
		}

		//�w�i�摜����ʂ�ʂ�z�����Ƃ�
		if (ImageTitleBack[num].image.x+ImageTitleBack[num].image.width < 0)
		{
			ImageTitleBack[num].image.x = ImageTitleBack[0].image.width * 3;	//�摜�̕��Q���A���Ɉړ�������
			ImageTitleBack[num].IsDraw = FALSE;								//�摜��`�悵�Ȃ�
		}
	}

	return;
}

//�X�^�[�g��ʂ̕`��
VOID MY_START_DRAW(VOID)
{
	//�w�i��`�悷��
	for (int num = 0; num < IMAGE_TITLE_BACK_NUM; num++)
	{
		//�`��ł���Ƃ��́E�E�E
		if (ImageTitleBack[num].IsDraw == TRUE)
		{
			//�w�i��`��
			DrawGraph(ImageTitleBack[num].image.x, ImageTitleBack[num].image.y, ImageTitleBack[num].image.handle, TRUE);

			//�y�f�o�b�O�p�z�w�i�摜�̐������e�X�g�I�ɕ\��
			DrawFormatString(
				ImageTitleBack[num].image.x,
				ImageTitleBack[num].image.y,
				GetColor(255, 0, 0), "�w�i�摜�F%d", num + 1);
		}
	}

	DrawGraph(ImageTitleRogo.x, ImageTitleRogo.y, ImageTitleRogo.handle, TRUE);
	DrawGraph(ImageTitlePush.x, ImageTitlePush.y, ImageTitlePush.handle, TRUE);
	return;
}

VOID MY_RULE(VOID)
{
	MY_RULE_PROC();	//�v���C��ʂ̏���
	MY_RULE_DRAW();	//�v���C��ʂ̕`��

	DrawString(0, 0, "���[���������(S�L�[�������ĉ�����)", GetColor(0, 0, 0));
	return;
}

VOID MY_RULE_PROC(VOID)
{
	//BGM�Đ�
	if (CheckSoundMem(RuleBGM.handle) == 0)//�܂�BGM���Ȃ��Ă��Ȃ�������
	{
		ChangeVolumeSoundMem(GAME_SOUND_VOLUME, RuleBGM.handle);
		PlaySoundMem(RuleBGM.handle, DX_PLAYTYPE_LOOP); //���[�v�Đ�
	}

	//�X�y�[�X�L�[����������A�v���C�V�[���ֈړ�����
	if (MY_KEY_DOWN(KEY_INPUT_S) == TRUE)
	{
		//BGM��~
		if (CheckSoundMem(RuleBGM.handle) != 0)//BGM������Ă�����
		{
			StopSoundMem(RuleBGM.handle); //�~�߂�
		}

		MY_PLAY_INIT();	//�Q�[��������

		//�Q�[���̃V�[�����v���C��ʂɂ���
		GameScene = GAME_SCENE_PLAY;

		return;
	}
	//�w�i�摜�𓮂���
	for (int num = 0; num < IMAGE_TITLE_BACK_NUM; num++)
	{
		//�摜���ړ�������
		ImageTitleBack[num].image.x--;//�E���獶�ɗ����

		//�w�i�摜��`��ł��Ȃ��Ƃ�
		if (ImageTitleBack[num].IsDraw == FALSE)
		{
			//�w�i�摜����ʓ��ɂ���Ƃ�
			if (ImageTitleBack[num].image.x + ImageTitleBack[num].image.width > 0)
			{
				ImageTitleBack[num].IsDraw = TRUE;	//�摜��`�悷��
			}
		}

		//�w�i�摜����ʂ�ʂ�z�����Ƃ�
		if (ImageTitleBack[num].image.x + ImageTitleBack[num].image.width < 0)
		{
			ImageTitleBack[num].image.x = ImageTitleBack[0].image.width * 3;	//�摜�̕��Q���A���Ɉړ�������
			ImageTitleBack[num].IsDraw = FALSE;								//�摜��`�悵�Ȃ�
		}
	}
	
	return;
}

VOID MY_RULE_DRAW(VOID)
{
	// �w�i��`�悷��
		for (int num = 0; num < IMAGE_TITLE_BACK_NUM; num++)
		{
			//�`��ł���Ƃ��́E�E�E
			if (ImageTitleBack[num].IsDraw == TRUE)
			{
				//�w�i��`��
				DrawGraph(ImageTitleBack[num].image.x, ImageTitleBack[num].image.y, ImageTitleBack[num].image.handle, TRUE);

				//�y�f�o�b�O�p�z�w�i�摜�̐������e�X�g�I�ɕ\��
				DrawFormatString(
					ImageTitleBack[num].image.x,
					ImageTitleBack[num].image.y,
					GetColor(255, 0, 0), "�w�i�摜�F%d", num + 1);
			}
		}

		DrawGraph(ImageRuleEx.x, ImageRuleEx.y, ImageRuleEx.handle, TRUE);
	
	return;
}

//�v���C��ʏ�����
VOID MY_PLAY_INIT(VOID)
{
	//�X�R�A�̏�����
	score = 0;
	//���C�t�̏�����

	return;
}

//�v���C���
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();	//�v���C��ʂ̏���
	MY_PLAY_DRAW();	//�v���C��ʂ̕`��

	DrawString(0, 0, "�v���C���(A�������ĉ�����)", GetColor(0, 0, 0));
	return;
}

//�v���C��ʂ̏���
VOID MY_PLAY_PROC(VOID)
{

	//BGM�Đ�
	if (CheckSoundMem(PlayBGM.handle) == 0)//�܂�BGM���Ȃ��Ă��Ȃ�������
	{
		ChangeVolumeSoundMem(GAME_SOUND_VOLUME, PlayBGM.handle);
		PlaySoundMem(PlayBGM.handle, DX_PLAYTYPE_LOOP); //���[�v�Đ�
	}

	if (TekiCreateCnt < TekiCreateCntMax) { TekiCreateCnt++; }
	else
	{
		TekiCreateCnt = 0;	//�J�E���^������

		//�G�𐶐����邩���߂�
		for (int index = 0; index < ENEMY_NUM; index++)
		{
			//�G���܂���������Ă��Ȃ��Ƃ�
			if (enemy[index].IsCreate == FALSE)
			{
				//�����_����0~3���o��ΓG����
				int kind = GetRand(30);
				if (3 >= kind)
				{
					switch (kind)
					{
					case 0:
						enemy[index] = karasu1;
						break;
					case 1:
						enemy[index] = karasu2;
					default:
						break;
					}

					enemy[index].image.x = GAME_WIDTH + index * (+100);	
					enemy[index].image.y = GetRand(GAME_HEIGHT - enemy[index].image.height);	//�G�̏o��Y�ʒu�������_��
					enemy[index].image.IsDraw = TRUE;	
					EnemyAtari(&enemy[index]);

					enemy[index].IsCreate = TRUE;
				}
			}
		}

	}

	playercount++; //�v���C���[�A�j���[�V�����p�̃J�E���g


	//�v���C���[�̈ړ�����
	player.speed = 5; //�v���C���[�̑��x��ݒ�
	if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE) //SPACE�������Ă�����㏸
	{
		playercount += 1;
		player.y -= player.speed;
	}
	else //�����łȂ���Ή��~
	{
		player.y += player.speed;
	}

	//��ʊO�Ƀv���C���[���s���Ȃ��悤�ɂ���
	if (player.y < 0) { player.y = 0; }
	if (player.y + player.height > GAME_HEIGHT) { player.y = GAME_HEIGHT - player.height; }


	//A�L�[����������A�G���h�V�[���ֈړ�����
	if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		//BGM��~
		if (CheckSoundMem(TitleBGM.handle) != 0)//BGM������Ă�����
		{
			StopSoundMem(TitleBGM.handle); //�~�߂�
		}

		//�Q�[���̃V�[�����G���h��ʂɂ���
		GameScene = GAME_SCENE_END;

		return;
	}


	//�w�i�摜�𓮂���
	for (int num = 0; num < IMAGE_TITLE_BACK_NUM; num++)
	{
		//�摜���ړ�������
		ImageTitleBack[num].image.x--;//�E���獶�ɗ����

		//�w�i�摜��`��ł��Ȃ��Ƃ�
		if (ImageTitleBack[num].IsDraw == FALSE)
		{
			//�w�i�摜����ʓ��ɂ���Ƃ�
			if (ImageTitleBack[num].image.x + ImageTitleBack[num].image.width > 0)
			{
				ImageTitleBack[num].IsDraw = TRUE;	//�摜��`�悷��
			}
		}

		//�w�i�摜����ʂ�ʂ�z�����Ƃ�
		if (ImageTitleBack[num].image.x + ImageTitleBack[num].image.width < 0)
		{
			ImageTitleBack[num].image.x = ImageTitleBack[0].image.width * 3;	//�摜�̕��Q���A���Ɉړ�������
			ImageTitleBack[num].IsDraw = FALSE;								//�摜��`�悵�Ȃ�
		}
	}


	//�G�T�𓮂���
	for (int i = 0; i < ESA_MAX; i++)
	{
		if (esa[i].x > 0 - esa[i].width)
		{
			esa[i].x -= 4;
		}
	}

	

		RECT PlayerRect;
		PlayerRect.left = player.x;
		PlayerRect.top = player.y;
		PlayerRect.right = player.x + player.width;
		PlayerRect.bottom = player.y + player.height;

		for (int i = 0; i < ESA_MAX; i++)
		{
			RECT EsaRect;
			EsaRect.left = esa[i].x;
			EsaRect.top = esa[i].y;
			EsaRect.right = esa[i].x + esa[i].width;
			EsaRect.bottom = esa[i].y + esa[i].height;

			if (MY_CHECK_RECT_COLL(PlayerRect, EsaRect) == TRUE)
			{
				esa[i].IsDraw = FALSE;
				esa[i].x = -100;
				score += 50;
				PlaySoundMem(GetSE.handle, DX_PLAYTYPE_BACK);
			}
		}

		//�v���C��ʂł̓G�̍\��
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			enemy[i].image.x -= enemy[i].speed;

			EnemyAtari(&enemy[i]);

			if (enemy[i].image.IsDraw == TRUE)
			{
				if (MY_CHECK_RECT_COLL(enemy[i].rect, PlayerRect) == TRUE)
				{
					player.life -= 1;	//���C�t�����炷
					/*mutekicount = 0;*/
					IsMuteki = TRUE;	//��莞�ԁA���G��ԂɂȂ�
					PlaySoundMem(DamageSE.handle, DX_PLAYTYPE_BACK); 

					enemy[i].IsCreate = FALSE;

				}
			}
		}
	

	//���G����
	if (IsMuteki == TRUE)
	{
		mutekicount++;		//���G���Ԃ𐔂���J�E���g�𑝂₷�B

		if (mutekicount >= 100)
		{
			Ishit = TRUE;
			IsMuteki = FALSE;
			player.IsDraw = TRUE;
			mutekicount = 0;
		}
		else if (mutekicount <= 100)
		{
			Ishit = FALSE;	//�����蔻��֐��I�t

			if (tennmetu < 5) //�_�ł̎��ԊԊu��ݒ�
			{
				tennmetu += 1;
			}
			else
			{
				if (player.IsDraw == TRUE)
				{
					player.IsDraw = FALSE;
				}
				else if (player.IsDraw == FALSE)
				{
					player.IsDraw = TRUE;
				}

				tennmetu = 0;
			}

		}

	}

	return;
}

//�v���C��ʂ̕`��
VOID MY_PLAY_DRAW(VOID)
{
	//�w�i��`�悷��
	for (int num = 0; num < IMAGE_TITLE_BACK_NUM; num++)
	{
		//�`��ł���Ƃ��́E�E�E
		if (ImageTitleBack[num].IsDraw == TRUE)
		{
			//�w�i��`��
			DrawGraph(ImageTitleBack[num].image.x, ImageTitleBack[num].image.y, ImageTitleBack[num].image.handle, TRUE);

			//�y�f�o�b�O�p�z�w�i�摜�̐������e�X�g�I�ɕ\��
			DrawFormatString(
				ImageTitleBack[num].image.x,
				ImageTitleBack[num].image.y,
				GetColor(255, 0, 0), "�w�i�摜�F%d", num + 1);
		}
	}

	DrawFormatString(600, 0, GetColor(255, 0, 0), "LIFE:%d", player.life);
	DrawFormatString(700, 0, GetColor(255, 0, 0), "SCORE:%d", score);

	//�G�T��`��
	for (int i = 0; i < ESA_MAX; i++)
	{
		if (esa[i].IsDraw == TRUE)
		{
			DrawGraph(esa[i].x, esa[i].y, esa[i].handle, TRUE);
		}
		DrawBox(esa[i].x, esa[i].y, esa[i].x + esa[i].width, esa[i].y + esa[i].height, GetColor(255, 0, 0), FALSE);
	}


	//�G�̕`��
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		DrawBox(enemy[i].rect.left, enemy[i].rect.top, enemy[i].rect.right, enemy[i].rect.bottom, GetColor(255, 0, 0), FALSE);

		if (enemy[i].image.x <= 0)
		{
			enemy[i].image.IsDraw = FALSE;
		}
		else if (enemy[i].image.x <= GAME_WIDTH)
		{
			PlaySoundMem(KarasuSE.handle, DX_PLAYTYPE_BACK); //�J���X����ʓ��ɓ���������������
			enemy[i].image.IsDraw = TRUE;
		}

		if (enemy[i].image.IsDraw == TRUE)
		{
			DrawGraph(enemy[i].image.x, enemy[i].image.y, enemy[i].image.handle, TRUE);
		}
	}


	//�v���C���[��`��

	int a;

	a = playercount % 15 / 5; 

	if (a == 2)
	{
		a = 0;
	}

	if (player.IsDraw == TRUE)
	{
		DrawGraph(player.x, player.y, player.handle[a], TRUE);
	}


	DrawBox(player.x, player.y, player.x + player.width, player.y + player.height, GetColor(255, 0, 0), FALSE);	


	return;
}

//�G���h���
VOID MY_END(VOID)
{
	MY_END_PROC();	//�G���h��ʂ̏���
	MY_END_DRAW();	//�G���h��ʂ̕`��

	DrawString(0, 0, "�G���h���(�G�X�P�[�v�L�[�������ĉ�����)", GetColor(0, 0, 0));
	return;
}

//�G���h��ʂ̏���
VOID MY_END_PROC(VOID)
{
	//BGM�Đ�
	if (CheckSoundMem(EndBGM.handle) == 0)//�܂�BGM���Ȃ��Ă��Ȃ�������
	{
		ChangeVolumeSoundMem(GAME_SOUND_VOLUME, EndBGM.handle);
		PlaySoundMem(EndBGM.handle, DX_PLAYTYPE_LOOP); //���[�v�Đ�
	}

	//�G�X�P�[�v�L�[����������A�X�^�[�g�V�[���ֈړ�����
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE)
	{
		GameScene = GAME_SCENE_START;
	}

	//�^�C�g���֖߂�{�^��
	if (ImageEndTbutton2.IsDraw == TRUE)
	{
		if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE)
		{
			//BGM��~
			if (CheckSoundMem(EndBGM.handle) != 0)//BGM������Ă�����
			{
				StopSoundMem(EndBGM.handle); //�~�߂�
			}

			MY_PLAY_INIT();
			GameScene = GAME_SCENE_START;
		}
	}
	//������x�v���C�{�^��
	if (ImageEndAbutton2.IsDraw == TRUE)
	{
		if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE)
		{
			//BGM��~
			if (CheckSoundMem(EndBGM.handle) != 0)//BGM������Ă�����
			{
				StopSoundMem(EndBGM.handle); //�~�߂�
			}

			MY_PLAY_INIT();
			GameScene = GAME_SCENE_RULE;
		}
	}
	
	//���L�[��������
	if (MY_KEY_UP(KEY_INPUT_DOWN) == TRUE)
	{
		ImageEndAbutton2.IsDraw = TRUE;
		ImageEndTbutton2.IsDraw = FALSE;
	}
	//��L�[��������
	if (MY_KEY_UP(KEY_INPUT_UP) == TRUE)
	{
		ImageEndAbutton2.IsDraw = FALSE;
		ImageEndTbutton2.IsDraw = TRUE;
	}

	return;
}


//�G���h��ʂ̕`��
VOID MY_END_DRAW(VOID)
{
	if (score < 100)
	{
		DrawGraph(ImageEndBack1.x, ImageEndBack1.y, ImageEndBack1.handle, TRUE);
		setMessage("���͂悤");
	}
	else if (score < 200)
	{
		DrawGraph(ImageEndBack2.x, ImageEndBack2.y, ImageEndBack2.handle, TRUE);
		setMessage("����ɂ���");
	}
	else if (score < 300)
	{
		DrawGraph(ImageEndBack3.x, ImageEndBack3.y, ImageEndBack3.handle, TRUE);
		setMessage("���悤�Ȃ�");
	}

	DrawGraph(ImageEndTbutton.x, ImageEndTbutton.y, ImageEndTbutton.handle, TRUE);
	DrawGraph(ImageEndAbutton.x, ImageEndAbutton.y, ImageEndAbutton.handle, TRUE);
	//�^�C�g���փ{�^�������点��
	if (ImageEndTbutton2.IsDraw == TRUE)
	{
		DrawGraph(ImageEndTbutton2.x, ImageEndTbutton2.y, ImageEndTbutton2.handle, TRUE);
	}
	//������x�v���C�փ{�^�������点��
	if (ImageEndAbutton2.IsDraw == TRUE)
	{
		DrawGraph(ImageEndAbutton2.x, ImageEndAbutton2.y, ImageEndAbutton2.handle, TRUE);
	}
	

	/*DrawBox(50, 460, 550, 560, GetColor(255, 0, 0), TRUE);
	DrawBox(50, 580, 550, 680, GetColor(255, 0, 0), TRUE);*/

	drawMessage();

	return;
}

//�摜���܂Ƃ߂ēǂݍ��ފ֐�
BOOL MY_LOAD_IMAGE(VOID)
{
	//�^�C�g�����S
	strcpy_s(ImageTitleRogo.path, IMAGE_TITLE_ROGO_PATH);		//�p�X�̐ݒ�
	ImageTitleRogo.handle = LoadGraph(ImageTitleRogo.path);	    //�ǂݍ���
	if (ImageTitleRogo.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_ROGO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleRogo.handle, &ImageTitleRogo.width, &ImageTitleRogo.height);	//�摜�̕��ƍ������擾
	ImageTitleRogo.x = GAME_WIDTH / 2 - ImageTitleRogo.width / 2;		                //���E��������
	ImageTitleRogo.y = GAME_HEIGHT / 2 - ImageTitleRogo.height / 2;	                    //�㉺��������

	//PUSH_TO_ENTER���S
	strcpy_s(ImageTitlePush.path, IMAGE_TITLE_PUSH_PATH);		//�p�X�̐ݒ�
	ImageTitlePush.handle = LoadGraph(ImageTitlePush.path);	    //�ǂݍ���
	if (ImageTitlePush.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_PUSH_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitlePush.handle, &ImageTitlePush.width, &ImageTitlePush.height);	//�摜�̕��ƍ������擾
	ImageTitlePush.x = GAME_WIDTH / 2 - ImageTitlePush.width / 2;		                //���E��������
	ImageTitlePush.y = GAME_HEIGHT / 4 * 3;	                    //�c3/4�ʂ̈ʒu

	//�^�C�g���w�i
	strcpy_s(ImageTitleBack[0].image.path, IMAGE_TITLE_BACK1_PATH);			//�p�X�̐ݒ�
	strcpy_s(ImageTitleBack[1].image.path, IMAGE_TITLE_BACK2_PATH);		//�p�X�̐ݒ�(�w�i�摜���])
	strcpy_s(ImageTitleBack[2].image.path, IMAGE_TITLE_BACK3_PATH);			//�p�X�̐ݒ�
	strcpy_s(ImageTitleBack[3].image.path, IMAGE_TITLE_BACK4_PATH);		//�p�X�̐ݒ�(�w�i�摜���])

	//�摜��A�����ēǂݍ���
	for (int num = 0; num < IMAGE_TITLE_BACK_NUM; num++)
	{
		ImageTitleBack[num].image.handle = LoadGraph(ImageTitleBack[num].image.path);	//�ǂݍ���
		if (ImageTitleBack[num].image.handle == -1)
		{
			//�G���[���b�Z�[�W�\��
			MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BACK1_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
			return FALSE;
		}
		//�摜�̕��ƍ������擾
		GetGraphSize(ImageTitleBack[num].image.handle, &ImageTitleBack[num].image.width, &ImageTitleBack[num].image.height);
	}
	//�w�i�摜�@�̐ݒ�
	ImageTitleBack[0].image.x = 0 - ImageTitleBack[0].image.width * 0;	//x���_
	ImageTitleBack[0].image.y = GAME_HEIGHT / 2 - ImageTitleBack[0].image.height / 2; 				//�㉺��������
	ImageTitleBack[0].IsDraw = FALSE;

	//�w�i�摜�A�̐ݒ�
	ImageTitleBack[1].image.x = ImageTitleBack[0].image.width * 1;	//�摜�̕�1���E�Ɉړ�
	ImageTitleBack[1].image.y = GAME_HEIGHT / 2 - ImageTitleBack[1].image.height / 2; 				//�㉺��������
	ImageTitleBack[1].IsDraw = FALSE;

	//�w�i�摜�B�̐ݒ�
	ImageTitleBack[2].image.x = ImageTitleBack[0].image.width * 2;	//�摜�̕�2���E�Ɉړ�
	ImageTitleBack[2].image.y = GAME_HEIGHT / 2 - ImageTitleBack[2].image.height / 2; 				//�㉺��������
	ImageTitleBack[2].IsDraw = FALSE;

	//�w�i�摜�B�̐ݒ�
	ImageTitleBack[3].image.x = ImageTitleBack[0].image.width * 3;	//�摜�̕�3���E�Ɉړ�
	ImageTitleBack[3].image.y = GAME_HEIGHT / 2 - ImageTitleBack[3].image.height / 2; 				//�㉺��������
	ImageTitleBack[3].IsDraw = FALSE;

	//���[�������摜
	strcpy_s(ImageRuleEx.path, IMAGE_RULE_EX_PATH);		    //�p�X�̐ݒ�
	ImageRuleEx.handle = LoadGraph(ImageRuleEx.path);	    //�ǂݍ���
	if (ImageRuleEx.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_RULE_EX_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageRuleEx.handle, &ImageRuleEx.width, &ImageRuleEx.height);	//�摜�̕��ƍ������擾
	ImageRuleEx.x = GAME_WIDTH / 2 - ImageRuleEx.width / 2;		                    //���E��������
	ImageRuleEx.y = GAME_HEIGHT / 2 - ImageRuleEx.height / 2;	                    //�㉺��������

	//�G���h�w�i�摜1
	strcpy_s(ImageEndBack1.path, IMAGE_END_BACK1_PATH);		    //�p�X�̐ݒ�
	ImageEndBack1.handle = LoadGraph(ImageEndBack1.path);	    //�ǂݍ���
	if (ImageEndBack1.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_END_BACK1_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndBack1.handle, &ImageEndBack1.width, &ImageEndBack1.height);	//�摜�̕��ƍ������擾
	ImageEndBack1.x = GAME_WIDTH / 2 - ImageEndBack1.width / 2;		                    //���E��������
	ImageEndBack1.y = GAME_HEIGHT / 2 - ImageEndBack1.height / 2;	                    //�㉺��������

	//�G���h�w�i�摜2
	strcpy_s(ImageEndBack2.path, IMAGE_END_BACK2_PATH);		    //�p�X�̐ݒ�
	ImageEndBack2.handle = LoadGraph(ImageEndBack2.path);	    //�ǂݍ���
	if (ImageEndBack2.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_END_BACK2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndBack2.handle, &ImageEndBack2.width, &ImageEndBack2.height);	//�摜�̕��ƍ������擾
	ImageEndBack2.x = GAME_WIDTH / 2 - ImageEndBack2.width / 2;		                    //���E��������
	ImageEndBack2.y = GAME_HEIGHT / 2 - ImageEndBack2.height / 2;	                    //�㉺��������

	//�G���h�w�i�摜3
	strcpy_s(ImageEndBack3.path, IMAGE_END_BACK3_PATH);		    //�p�X�̐ݒ�
	ImageEndBack3.handle = LoadGraph(ImageEndBack3.path);	    //�ǂݍ���
	if (ImageEndBack3.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_END_BACK3_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndBack3.handle, &ImageEndBack3.width, &ImageEndBack3.height);	//�摜�̕��ƍ������擾
	ImageEndBack3.x = GAME_WIDTH / 2 - ImageEndBack3.width / 2;		                    //���E��������
	ImageEndBack3.y = GAME_HEIGHT / 2 - ImageEndBack3.height / 2;	                    //�㉺��������

	//�G���h�^�C�g���։摜
	strcpy_s(ImageEndTbutton.path, IMAGE_END_TBUTTON_PATH);		    //�p�X�̐ݒ�
	ImageEndTbutton.handle = LoadGraph(ImageEndTbutton.path);	    //�ǂݍ���
	if (ImageEndTbutton.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_END_TBUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndTbutton.handle, &ImageEndTbutton.width, &ImageEndTbutton.height);	//�摜�̕��ƍ������擾
	ImageEndTbutton.x = GAME_WIDTH / 2 - ImageEndTbutton.width / 2 - 250;		            //���E��������
	ImageEndTbutton.y = GAME_HEIGHT / 2 - ImageEndTbutton.height / 2 + 100;	                    //�㉺��������

	//�G���h������x�摜
	strcpy_s(ImageEndAbutton.path, IMAGE_END_ABUTTON_PATH);		    //�p�X�̐ݒ�
	ImageEndAbutton.handle = LoadGraph(ImageEndAbutton.path);	    //�ǂݍ���
	if (ImageEndAbutton.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_END_ABUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndAbutton.handle, &ImageEndAbutton.width, &ImageEndAbutton.height);	//�摜�̕��ƍ������擾
	ImageEndAbutton.x = GAME_WIDTH / 2 - ImageEndAbutton.width / 2 - 250;		            //���E��������
	ImageEndAbutton.y = GAME_HEIGHT / 2 - ImageEndAbutton.height / 2 + 220;	                    //�㉺��������
	
	//�G���h�^�C�g����2�摜
	strcpy_s(ImageEndTbutton2.path, IMAGE_END_TBUTTON2_PATH);		    //�p�X�̐ݒ�
	ImageEndTbutton2.handle = LoadGraph(ImageEndTbutton2.path);	    //�ǂݍ���
	if (ImageEndTbutton2.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_END_TBUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndTbutton2.handle, &ImageEndTbutton2.width, &ImageEndTbutton2.height);	//�摜�̕��ƍ������擾
	ImageEndTbutton2.x = GAME_WIDTH / 2 - ImageEndTbutton2.width / 2 - 250;		            //���E��������
	ImageEndTbutton2.y = GAME_HEIGHT / 2 - ImageEndTbutton2.height / 2 + 100;	                    //�㉺��������
	ImageEndTbutton2.IsDraw = TRUE;

	//�G���h������x2�摜
	strcpy_s(ImageEndAbutton2.path, IMAGE_END_ABUTTON2_PATH);		    //�p�X�̐ݒ�
	ImageEndAbutton2.handle = LoadGraph(ImageEndAbutton2.path);	    //�ǂݍ���
	if (ImageEndAbutton2.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_END_ABUTTON2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndAbutton2.handle, &ImageEndAbutton2.width, &ImageEndAbutton2.height);	//�摜�̕��ƍ������擾
	ImageEndAbutton2.x = GAME_WIDTH / 2 - ImageEndAbutton2.width / 2 - 250;		            //���E��������
	ImageEndAbutton2.y = GAME_HEIGHT / 2 - ImageEndAbutton2.height / 2 + 220;	                    //�㉺��������
	ImageEndAbutton2.IsDraw = FALSE;


	
	//�v���C���[�̃A�j���[�V�����摜
	LoadDivGraph(PLAYER_PATH, 2, 2, 1, 150, 150, player.handle);
	for (int i = 0; i < 2; i++)
	{
		GetGraphSize(player.handle[i], &player.width, &player.height);
	}
	player.IsDraw = TRUE;


	//�J���X�P
	strcpy_s(karasu1.image.path, IMAGE_ENEMY_PATH);
	karasu1.image.handle = LoadGraph(karasu1.image.path);
	if (karasu1.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ENEMY_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(karasu1.image.handle, &karasu1.image.width, &karasu1.image.height);
	karasu1.image.x = GAME_WIDTH + 0 * (+100);
	karasu1.image.y = 100;
	karasu1.speed = 4;


	//�J���X�Q
	strcpy_s(karasu2.image.path, IMAGE_ENEMY2_PATH);
	karasu2.image.handle = LoadGraph(karasu2.image.path);
	if (karasu2.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ENEMY2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(karasu2.image.handle, &karasu2.image.width, &karasu2.image.height);
	karasu2.image.x = GAME_WIDTH + 1 * (+100);
	karasu2.image.y = 500;
	karasu2.speed = 6;


	//�G�T
	strcpy_s(esa[0].path, IMAGE_ESA_PATH);
	esa[0].handle = LoadGraph(esa[0].path);
	if (esa[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ESA_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(esa[0].handle, &esa[0].width, &esa[0].height);
	esa[0].IsDraw = TRUE;




	return TRUE;
}

//�摜���܂Ƃ߂č폜����֐�
VOID MY_DELETE_IMAGE(VOID)
{
	DeleteGraph(ImageEndBack1.handle);
	DeleteGraph(ImageEndTbutton.handle);
	DeleteGraph(ImageEndAbutton.handle);
	DeleteGraph(ImageEndTbutton2.handle);
	DeleteGraph(ImageEndAbutton2.handle);

	for (int num = 0; num < IMAGE_TITLE_BACK_NUM; num++)
	{
		DeleteGraph(ImageTitleBack[0].image.handle);
	}
	DeleteGraph(ImageTitleRogo.handle);//�^�C�g�����S
	DeleteGraph(ImageTitlePush.handle);//PUSU_TO_ENTER���S
	DeleteGraph(ImageEndBack1.handle);//�G���h�w�i1

	for (int i = 0; i < 2; i++)
	{
		DeleteGraph(player.handle[i]);
	}

	for (int i = 0; i < ESA_MAX; i++)
	{
		DeleteGraph(esa[0].handle);
	}

	return;
}

//���y���܂Ƃ߂ēǂݍ��ފ֐�
BOOL MY_LOAD_MUSIC(VOID)
{
	//�X�^�[�gBGM
	strcpy_s(TitleBGM.path, MUSIC_TITLE_BGM_PATH);
	TitleBGM.handle = LoadSoundMem(TitleBGM.path);
	if (TitleBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_TITLE_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�X�^�[�gSE
	strcpy_s(TitleSE.path, MUSIC_TITLE_SE_PATH);
	TitleSE.handle = LoadSoundMem(TitleSE.path);
	if (TitleSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_TITLE_SE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���[������BGM
	strcpy_s(RuleBGM.path, MUSIC_RULE_BGM_PATH);
	RuleBGM.handle = LoadSoundMem(RuleBGM.path);
	if (RuleBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_RULE_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�v���C���BGM
	strcpy_s(PlayBGM.path, MUSIC_PLAY_BGM_PATH);
	PlayBGM.handle = LoadSoundMem(PlayBGM.path);
	if (PlayBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_PLAY_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�G�T���Ƃ����Ƃ��̌��ʉ�
	strcpy_s(GetSE.path, MUSIC_GET_PATH);
	GetSE.handle = LoadSoundMem(GetSE.path);
	if (GetSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_GET_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�_���[�W���󂯂��Ƃ��̌��ʉ�
	strcpy_s(DamageSE.path, MUSIC_DAMAGE_PATH);
	DamageSE.handle = LoadSoundMem(DamageSE.path);
	if (DamageSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_DAMAGE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�G���hBGM
	strcpy_s(EndBGM.path, MUSIC_END_BGM_PATH);
	EndBGM.handle = LoadSoundMem(EndBGM.path);
	if (EndBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_END_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//���y���܂Ƃ߂č폜����֐�
VOID MY_DELETE_MUSIC(VOID)
{
	DeleteSoundMem(TitleBGM.handle);
	DeleteSoundMem(TitleSE.handle);
	DeleteSoundMem(RuleBGM.handle);
	DeleteSoundMem(PlayBGM.handle);
	DeleteSoundMem(GetSE.handle);
	DeleteSoundMem(DamageSE.handle);
	DeleteSoundMem(EndBGM.handle);

	return;
}

int isJapanese(unsigned char code)
{
	if ((code >= 0x81 && code <= 0x9F) ||
		(code >= 0xE0 && code <= 0xFC))
	{
		return 1;
	}
	return 0;
}

// m e s s a g e�Ŏw�肵�����͂� start �� �� �u �� �� len �� �� �� �\ �� �� ��
void writeSubstring(char* message, int start, int len,
	int posX, int posY, int color, int bufferLine)
{
	int i;
	//������
	int maxLen = strlen(message);

	// s t a r t �� �� �u �� �� �X �� ��
	// s t a r t �� �� �u �� �� �� �� �{ �� �� �� �� �� �� �� �� �� �C 1 �� �� �� �� �� ��
	for (i = 0; i < start && message[i] != '\0'; ) {
		if (isJapanese(message[i])) {
			//���{��̏ꍇ�C2�o �C �g �� �� �� �� ��
			i += 2;
			// s t a r t��1�o�C�g������
			start++;
		}
		else {
			//���p�����̏ꍇ�C1�o �C �g �� �i �� ��
			i++;
		}
	}
	// s t a r t �� �� �u �� �\ �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��
	if (start >= maxLen) {
		return;

	}

	//�w�肵���ʒu���� l e n �� �� �� �\ �� �� ��
	for (i = 0; i < len && message[start + i] != '\0'; ) {
		if (isJapanese(message[start + i])) {
			//���{��̏ꍇ�C2�� �� �� b u f f e r�ɃZ�b�g
			messageBuffer[bufferLine][i] = message[start + i];
			messageBuffer[bufferLine][i + 1] = message[start + i + 1];
			// l e n �� �� �{ �� �� �� �� �C 1 �o �C �g �� �� �� �� ��
			len++;
			//2�o �C �g �� �i �� ��
			i += 2;
		}
		else {
			//���p����1�� �� �� �Z �b �g
			messageBuffer[bufferLine][i] = message[start + i];
			i++; //1�o �C �g �� �i �� ��
		}
	}
	messageBuffer[bufferLine][i] = '\0';
	//���b�Z�[�W�`��
	DrawString(posX, posY, messageBuffer[bufferLine], color);
}


//���b�Z�[�W�`��
VOID drawMessage()
{
	int i;

	//���b�Z�[�W�{�b�N�X�`��
	//DrawGraph(MESSAGE_BOX_X, MESSAGE_BOX_Y, messageBoxGraphHandle, FALSE);
	DrawBox(MESSAGE_BOX_X, MESSAGE_BOX_Y, MESSAGE_BOX_X + 500, MESSAGE_BOX_Y + 100, GetColor(0, 255, 0), TRUE);

	if (message[currentCursor] != '\0') {
		currentCursor++;
	}

	// MESSAGE_MAX_LENGTH �� �� �� �� �� �` �� �� �� �� �i �� �� �� �� �� �� ��
	if (currentCursor % MESSAGE_MAX_LENGTH == 0) {
		if (message[currentCursor] != '\0') {
			currentLineCursor++;
		}

	}
	
	//���b�Z�[�W�`�敔��
	for (i = 0; i < MESSAGE_MAX_LINE; i++) {
		if (i == currentLineCursor) {
			SetFontSize(MESSAGE_FONT_SIZE);
			//���b�Z�[�W���ɕ\��
			writeSubstring(message, i * MESSAGE_MAX_LENGTH,
				currentCursor - MESSAGE_MAX_LENGTH * i,
				MESSAGE_BOX_X ,
				MESSAGE_BOX_Y + MESSAGE_FONT_SIZE * i,
				whiteColor, i);
			break;

		}
		else {
			SetFontSize(MESSAGE_FONT_SIZE);
			//���b�Z�[�W�����̂܂ܕ\��
			writeSubstring(message, i * MESSAGE_MAX_LENGTH,
				MESSAGE_MAX_LENGTH, 
				MESSAGE_BOX_X,
				MESSAGE_BOX_Y + MESSAGE_FONT_SIZE * i,
				whiteColor, i);

		}

	}
	SetFontSize(16);
}


VOID setMessage(const char* ms)  //�`�悵�������b�Z�[�W���Z�b�g
{
	currentCursor = 0;
	currentLineCursor = 0;

	strncpy(message, ms, MESSAGE_MAX_LENGTH * MESSAGE_MAX_LINE);   //���b�Z�[�W���R�s�[
	
}


//�G�̓�����֐�

VOID EnemyAtari(CHARA* e)
{
	e->rect.left = e->image.x;
	e->rect.top = e->image.y;
	e->rect.right = e->image.x + e->image.width;
	e->rect.bottom = e->image.y + e->image.height;

	return;
}

int ENEMY_CHECK()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].image.IsDraw == FALSE) //�G�̉摜���Ȃ������瓖���蔻�肪�Ȃ��Ȃ�
		{
			return i;
		}
	}
	return -1;
}

//�̈�̓����蔻��
BOOL MY_CHECK_RECT_COLL(RECT a, RECT b)
{

	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top)
	{
		if (Ishit == TRUE)
		{
			return TRUE;
		}

	}
	return FALSE;
}