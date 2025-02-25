/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "resource.h"

//########## マクロ定義 ##########
#define GAME_WIDTH			1280	//画面の横の大きさ
#define GAME_HEIGHT			720	    //画面の縦の大きさ
#define GAME_COLOR			32	    //画面のカラービット

#define GAME_WINDOW_BAR		0					//タイトルバーはデフォルトにする
#define GAME_WINDOW_NAME	"BIRDFULLIFE"		//ウィンドウのタイトル

#define GAME_FPS			60	//FPSの数値	

//マウスのボタン
#define MOUSE_BUTTON_CODE	129	//0x0000〜0x0080まで

//キーボードの種類
#define KEY_CODE_KIND		256	//256種類

//パスの長さ
#define PATH_MAX			255	//255文字まで
#define NAME_MAX			255	//255文字まで

//音量
#define GAME_SOUND_VOLUME_PER	30	//音声全部の音量を30%程度にする
#define GAME_SOUND_VOLUME	255 * GAME_SOUND_VOLUME_PER/100	//↑の割合の音量

//フォント
#define FONT_UZU_PATH			TEXT(".\\FONT\\uzura.ttf")	     //フォントの場所
#define FONT_UZU_NAME			TEXT("うずらフォント")			//フォントの名前

//エラーメッセージ
#define FONT_INSTALL_ERR_TITLE	TEXT("フォントインストールエラー")
#define FONT_CREATE_ERR_TITLE	TEXT("フォント作成エラー")

//音楽パス
#define MUSIC_TITLE_BGM_PATH TEXT(".\\MUSIC\\木のお皿.mp3")	                //タイトル画面BGM
#define MUSIC_TITLE_SE_PATH TEXT(".\\MUSIC\\ヒヨコの鳴き声_編集済み.mp3")	//タイトル画面SE
#define MUSIC_RULE_BGM_PATH TEXT(".\\MUSIC\\木のお皿.mp3")					//ルール説明画面BGM
#define MUSIC_PLAY_BGM_PATH TEXT(".\\MUSIC\\キラキラ桜吹雪.mp3")			//プレイ画面BGM
#define MUSIC_END_BGM_PATH TEXT(".\\MUSIC\\ソライロビヨリ.mp3")	            //エンド画面BGM

#define MUSIC_DAMAGE_PATH TEXT(".\\MUSIC\\damage1.mp3")						 //ダメージ効果音
#define MUSIC_GET_PATH TEXT(".\\MUSIC\\score2.mp3")							 //エサをとったときの効果音
#define MUSIC_GET2_PATH TEXT(".\\MUSIC\\食べ物をパクッ.mp3")							 //エサ缶をとったときの効果音
#define MUSIC_LVUP_PATH TEXT(".\\MUSIC\\LveleUP.mp3")						//レベルアップしたときの効果音

//画像パス　※名前の付け方は基本的にIMAGE_シーン名_何の画像か_PATH
#define IMAGE_PLAY_LEVELUP_PATH  TEXT(".\\IMAGE\\LevelUP_rogo.png")         //レベルアップ画像
#define IMAGE_RULE_BACK_PATH     TEXT(".\\IMAGE\\背景_ぼかし.png")          //ルール説明画面背景
#define IMAGE_RULE_EX_PATH       TEXT(".\\IMAGE\\ルール説明Comp.png")           //ルール説明画像
#define IMAGE_END_BACK1_PATH     TEXT(".\\IMAGE\\ed1枠有.png")              //エンド背景ひなパターン1
#define IMAGE_END_BACK2_PATH     TEXT(".\\IMAGE\\ed2枠有.png")              //エンド背景ひなパターン2
#define IMAGE_END_BACK3_PATH     TEXT(".\\IMAGE\\ed3枠有.png")              //エンド背景ひなパターン3
#define IMAGE_END_TBUTTON_PATH   TEXT(".\\IMAGE\\タイトルにもどるボタン暗.png")            //エンド　タイトルへボタン
#define IMAGE_END_ABUTTON_PATH   TEXT(".\\IMAGE\\もういちど遊ぶボタン暗.png")            //エンド　もう一回ボタン
#define IMAGE_END_TBUTTON2_PATH  TEXT(".\\IMAGE\\タイトルにもどるボタン明.png")           //エンド　タイトルへボタン2
#define IMAGE_END_ABUTTON2_PATH  TEXT(".\\IMAGE\\もういちど遊ぶボタン明.png")           //エンド　もう一回ボタン2

#define IMAGE_TITLE_ROGO_PATH    TEXT(".\\IMAGE\\rogo1.png")           //タイトルロゴ
#define IMAGE_TITLE_PUSH_PATH	 TEXT(".\\IMAGE\\PushEnterToStart.png")	//エンターキーでスタートのロゴ

//背景スクロール
#define IMAGE_TITLE_BACK1_PATH    TEXT(".\\IMAGE\\背景連続_補正あり1.png")           //タイトル背景昼1
#define IMAGE_TITLE_BACK2_PATH    TEXT(".\\IMAGE\\背景連続_補正あり2.png")           //タイトル背景昼2
#define IMAGE_TITLE_BACK3_PATH    TEXT(".\\IMAGE\\背景連続_補正あり3.png")           //タイトル背景昼3
#define IMAGE_TITLE_BACK4_PATH    TEXT(".\\IMAGE\\背景連続_補正あり4.png")           //タイトル背景昼4

#define IMAGE_EVENING_BACK1_PATH    TEXT(".\\IMAGE\\背景連続_夕方1.png")           //タイトル背景昼1
#define IMAGE_EVENING_BACK2_PATH    TEXT(".\\IMAGE\\背景連続_夕方2.png")           //タイトル背景昼2
#define IMAGE_EVENING_BACK3_PATH    TEXT(".\\IMAGE\\背景連続_夕方3.png")           //タイトル背景昼3
#define IMAGE_EVENING_BACK4_PATH    TEXT(".\\IMAGE\\背景連続_夕方4.png")           //タイトル背景昼4


#define IMAGE_BACK_NUM	4	//背景画像の枚数



//キャラクター
#define PLAYER_PATH		TEXT(".\\IMAGE\\player_animation.png")	//プレイヤーの画像
#define IMAGE_ENEMY_PATH		TEXT(".\\IMAGE\\カラスアニメーション.png")	//敵（カラスの画像）
#define IMAGE_ENEMY2_PATH		TEXT(".\\IMAGE\\カラスヤンキーアニメーション.png")	//敵（青カラスの画像）
#define ENEMY_NUM				5    //　敵のＭＡＸ値


//アイテム
#define IMAGE_ESA_PATH	TEXT(".\\IMAGE\\米.png")	//エサの画像
#define IMAGE_ESA2_PATH	TEXT(".\\IMAGE\\エサ缶_サイズ調整.png")	//エサの画像
#define IMAGE_LIFE_PATH	TEXT(".\\IMAGE\\ライフ.png")	//ライフの画像
#define ESA_MAX 20		//エサの最大出現数
#define LIFE_MAX 3     //ライフ最大数


//エラーメッセージ
#define IMAGE_LOAD_ERR_TITLE	TEXT("画像読み込みエラー")

//エラーメッセージ
#define MUSIC_LOAD_ERR_TITLE	TEXT("音楽読み込みエラー")

//閉じるボタンを押したとき
#define MSG_CLOSE_TITLE			TEXT("終了メッセージ")
#define MSG_CLOSE_CAPTION		TEXT("ゲームを終了しますか？")

//ひなセリフの表示
#define MESSAGE_FONT_SIZE      100          //フォントの大きさ
#define MESSAGE_MAX_LENGTH     1000          //最大文字数
#define MESSAGE_MAX_LINE       20           //最大行数
#define MESSAGE_BOX_X          610          //メッセージボックスのX座標
#define MESSAGE_BOX_Y          50           //メッセージボックスのY座標
#define MESSAGE_BOX_GRAPHIC_FILENAME       "./IMAGE/背景連続1.png"

enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_SCENE_RULE,
	GAME_SCENE_PLAY,
	GAME_SCENE_END,
};	//ゲームのシーン

enum GAME_LEVEL
{
	LEVEL_EASY,
	LEVEL_NOMAL,
	LEVEL_HARD,
}; //ゲームレベル

//int型のPOINT構造体
typedef struct STRUCT_I_POINT
{
	int x = -1;	//座標を初期化
	int y = -1;	//座標を初期化
}iPOINT;

//マウス構造体
typedef struct STRUCT_MOUSE
{
	int InputValue = 0;	//GetMouseInputの値を入れる
	int WheelValue = 0;	//マウスホイールの回転量(奥はプラス値 / 手前はマイナス値)
	iPOINT Point;		//マウスの座標が入る
	iPOINT OldPoint;	//マウスの座標(直前)が入る
	int OldButton[MOUSE_BUTTON_CODE] = { 0 };	//マウスのボタン入力(直前)が入る
	int Button[MOUSE_BUTTON_CODE] = { 0 };	//マウスのボタン入力が入る
}MOUSE;

//フォント構造体
typedef struct STRUCT_FONT
{
	char path[PATH_MAX];		//パス
	char name[NAME_MAX];		//フォント名
	int handle;					//ハンドル
	int size;					//大きさ
	int bold;					//太さ
	int type;					//タイプ
	
}FONT;

typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];		//パス
	int handle;					//ハンドル
	int e_handle[2];			//エネミー用のハンドル
	int x;						//X位置
	int y;						//Y位置
	int width;					//幅
	int height;					//高さ
	BOOL IsDraw = FALSE;		//描画できるか
}IMAGE;	//画像構造体

typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];		//パス
	int handle;					//ハンドル
}MUSIC;	//音楽構造体

typedef struct STRUCT_CHARA
{
	IMAGE image;				//IMAGE構造体
	int speed;					//速さ
	int handle[2];
	int x;
	int y;
	int width;
	int height;
	BOOL IsDraw;
	RECT rect;

	RECT coll;					//当たり判定
	iPOINT collBeforePt;		//当たる前の座標

	//プレイヤー専用
	int life = LIFE_MAX;		//プレイヤーのライフ

	//エネミー専用
	BOOL IsCreate = FALSE;	//生成したか？

}CHARA;	//キャラクター構造体

typedef struct STRUCT_IMAGE_BACK
{
	IMAGE image;		//IMAGE構造体
	BOOL IsDraw;		//表示できるか
}IMAGE_BACK;	//背景画像の構造体

//########## グローバル変数 ##########
//FPS関連
int StartTimeFps;				//測定開始時刻
int CountFps;					//カウンタ
float CalcFps;					//計算結果
int SampleNumFps = GAME_FPS;	//平均を取るサンプル数

//キーボードの入力を取得
char AllKeyState[KEY_CODE_KIND] = { '\0' };		//すべてのキーの状態が入る
char OldAllKeyState[KEY_CODE_KIND] = { '\0' };	//すべてのキーの状態(直前)が入る

//マウスの座標を取得
MOUSE mouse;

//ゲーム関連
int GameScene;		//ゲームシーンを管理
int GameLevel;      //ゲームレベルを管理

//キャラクター関連
CHARA player; 
CHARA enemy[ENEMY_NUM];
CHARA karasu1;
CHARA karasu2;

//カウントまとめ
int playercount; //プレイヤーのアニメーション用カウント
int enemycount;  //エネミーのアニメーション用カウント
int mutekicount;	//無敵時間を測るカウント
int tennmetu;		//点滅時間を測るカウント
int Lvcount;			//レベルアップの画像を表示する時間
int WordCount;      //文字を出し続ける時間

BOOL SCORE_WORD = FALSE; //エサを取った時のスコアの文字が出るか
BOOL SCORE_WORD2 = FALSE; //エサ缶を取った時のスコアの文字が出るか
BOOL Ishit = TRUE;		//当たり判定がつくか
BOOL IsMuteki = FALSE;	//無敵状態になっているか

//敵生成関連
int enemykind;                          //敵の種類
int enemykazu;
int TekiCreateCnt = 0;					//敵を作る間隔
int TekiCreateCntMax = GAME_FPS * 3;	//敵を作る間隔(MAX)

//アイテム関連
IMAGE esa[ESA_MAX];
IMAGE esakan[ESA_MAX];
IMAGE heart[LIFE_MAX];
int score = 0;
int EsaScore = 50;
int EsakanScore = 100;

//音楽関連
MUSIC TitleBGM;	//タイトルBGM
MUSIC TitleSE;	//タイトルSE
MUSIC RuleBGM;	//ルール説明BGM
MUSIC PlayBGM;  //プレイBGM
MUSIC EndBGM;	//エンドBGM

MUSIC GetSE;   //エサ取り効果音
MUSIC GetSE2;  //エサ缶取り効果音
MUSIC DamageSE;    //ダメージ効果音
MUSIC LvUPSE;    //ダメージ効果音

//画像関連 ※名前の付け方はImageシーン名何の画像か;
IMAGE ImageTitleRogo;				 //タイトルロゴ
IMAGE ImageTitlePush;				 //PUSH_TO_ENTERロゴ

IMAGE ImagePlayLevelup;              //レベルアップ画像
IMAGE ImageRuleEx;                   //ルール説明画像
IMAGE ImageEndTbutton;               //エンドタイトルへボタン
IMAGE ImageEndAbutton;               //エンドもう一回ボタン
IMAGE ImageEndTbutton2;              //エンドタイトルへボタン2
IMAGE ImageEndAbutton2;              //エンドもう一回ボタン2

//背景関連
IMAGE_BACK ImageTitleBack[IMAGE_BACK_NUM];	//タイトル背景
IMAGE ImageRuleBack;                                //ルール説明背景
IMAGE_BACK ImageEveningBack[IMAGE_BACK_NUM];	//夕方背景
IMAGE ImageEndBack1;                                //エンド背景ひなパターン1
IMAGE ImageEndBack2;                                //エンド背景ひなパターン2
IMAGE ImageEndBack3;                                //エンド背景ひなパターン3



//フォント関連
FONT FontUzu;
FONT FontUzu2;

//ひなセリフ関連
char message[MESSAGE_MAX_LENGTH * MESSAGE_MAX_LINE];        //表示したいメッセージ
char messageBuffer[MESSAGE_MAX_LINE][MESSAGE_MAX_LENGTH];   //メッセージを表示するための仮想バッファ
static int currentCursor = 0;                               //何文字目まで表示しているか
static int currentLineCursor = 0;                           //何行目を表示しているか
static int whiteColor;
static int blackColor;
static int messageBoxGraphHandle;
int isJapanese(unsigned char code);

//########## プロトタイプ宣言 ##########//
VOID MY_FPS_UPDATE(VOID);			//FPS値を計測、更新する
VOID MY_FPS_DRAW(VOID);				//FPS値を描画する
VOID MY_FPS_WAIT(VOID);				//FPS値を計測し、待つ

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する
BOOL MY_KEY_DOWN(int);				//キーを押しているか、キーコードで判断する
BOOL MY_KEY_UP(int);				//キーを押し上げたか、キーコードで判断する
BOOL MY_KEYDOWN_KEEP(int, int);		//キーを押し続けているか、キーコードで判断する

VOID MY_MOUSE_UPDATE(VOID);			//マウスの入力情報を更新する
BOOL MY_MOUSE_DOWN(int);			//ボタンを押しているか、マウスコードで判断する
BOOL MY_MOUSE_UP(int);				//ボタンを押し上げたか、マウスコードで判断する
BOOL MY_MOUSEDOWN_KEEP(int, int);	//ボタンを押し続けているか、マウスコードで判断する

BOOL MY_FONT_INSTALL_ONCE(VOID);	//フォントをこのソフト用に、一時的にインストール
VOID MY_FONT_UNINSTALL_ONCE(VOID);	//フォントをこのソフト用に、一時的にアンインストール
BOOL MY_FONT_CREATE(VOID);			//フォントを作成する
VOID MY_FONT_DELETE(VOID);			//フォントを削除する

VOID MY_START(VOID);		        //スタート画面
VOID MY_START_PROC(VOID);	        //スタート画面の処理
VOID MY_START_DRAW(VOID);	        //スタート画面の描画

VOID MY_RULE(VOID);                //ルール説明画面
VOID MY_RULE_PROC(VOID);           //ルール説明画面の処理
VOID MY_RULE_DRAW(VOID);           //ルール説明画面の描画

VOID MY_PLAY_INIT(VOID);	       //プレイ画面初期化
VOID MY_PLAY(VOID);			       //プレイ画面
VOID MY_PLAY_PROC(VOID);	       //プレイ画面の処理
VOID MY_PLAY_DRAW(VOID);	       //プレイ画面の描画

VOID MY_END(VOID);			       //エンド画面
VOID MY_END_PROC(VOID);		       //エンド画面の処理
VOID MY_END_DRAW(VOID);		       //エンド画面の描画

BOOL MY_LOAD_IMAGE(VOID);		   //画像をまとめて読み込む関数
VOID MY_DELETE_IMAGE(VOID);		   //画像をまとめて削除する関数

BOOL MY_LOAD_MUSIC(VOID);		   //音楽をまとめて読み込む関数
VOID MY_DELETE_MUSIC(VOID);		   //音楽をまとめて削除する関数

VOID writeSubstring(char* message, int start, int len,
	int PosX, int PosY, int color, int bufferLine);        //文字列の書き込み
VOID drawMessage(VOID);                                    //文字列の描画
VOID setMessage(const char* ms);                           //描画したいメッセージをセット

BOOL MY_CHECK_RECT_COLL(RECT, RECT);		//当たり判定関数

//当たり判定関数
VOID EnemyAtari(CHARA* e);	//敵

//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);				//Log.txtを出力しない
	ChangeWindowMode(TRUE);								//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//指定の数値でウィンドウを表示する
	SetWindowStyleMode(GAME_WINDOW_BAR);				//タイトルバーはデフォルトにする
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));			//ウィンドウのタイトルの文字
	SetAlwaysRunFlag(TRUE);								//非アクティブでも実行する
	//SetWindowIconID(IDI_ICON1);							//アイコンファイルを読込
	SetWindowUserCloseEnableFlag(FALSE);				//閉じるボタンで、勝手にウィンドウが閉じないようにする

	if (DxLib_Init() == -1) { return -1; }	//ＤＸライブラリ初期化処理

	//画像を読み込む
	if (MY_LOAD_IMAGE() == FALSE) { return -1; }

	//音楽を読み込む
	if (MY_LOAD_MUSIC() == FALSE) { return -1; }

	//フォントを一時的にインストール
	if (MY_FONT_INSTALL_ONCE() == FALSE) { return -1; }
	//フォントハンドルを作成
	if (MY_FONT_CREATE() == FALSE) { return -1; }


	GameScene = GAME_SCENE_START;	//ゲームシーンはスタート画面から
	GameLevel = LEVEL_EASY;         //イージーから
	SetDrawScreen(DX_SCREEN_BACK);	//Draw系関数は裏画面に描画

	//無限ループ
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了
		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		//画面の閉じるボタンを押されたとき
		if (GetWindowUserCloseFlag(TRUE))
		{
			//終了ダイアログを表示
			int Ret = MessageBox(GetMainWindowHandle(), MSG_CLOSE_CAPTION, MSG_CLOSE_TITLE, MB_YESNO | MB_ICONASTERISK);
			if (Ret == IDYES) { break; }	//YESなら、ゲームを中断する
		}

		MY_ALL_KEYDOWN_UPDATE();				//押しているキー状態を取得

		MY_MOUSE_UPDATE();						//マウスの状態を取得

		MY_FPS_UPDATE();	//FPSの処理[更新]

		//シーンごとに処理を行う
		switch (GameScene)
		{
		case GAME_SCENE_START:
			MY_START();	//スタート画面
			break;
		case GAME_SCENE_RULE:
			MY_RULE();
			break;
		case GAME_SCENE_PLAY:
			MY_PLAY();	//プレイ画面
			break;
		case GAME_SCENE_END:
			MY_END();	//エンド画面
			break;
		}

		MY_FPS_DRAW();		//FPSの処理[描画]

		ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画

		MY_FPS_WAIT();		//FPSの処理[待つ]
	}

	//フォントハンドルを破棄
	MY_FONT_DELETE();

	//一時的にインストールしたフォントをアンインストール
	MY_FONT_UNINSTALL_ONCE();

	//画像ハンドルを破棄
	MY_DELETE_IMAGE();

	//音楽ハンドルを破棄
	MY_DELETE_MUSIC();

	DxLib_End();	//ＤＸライブラリ使用の終了処理

	return 0;
}

//########## FPS値を計測、更新する関数 ##########
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1フレーム目なら時刻を記憶
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60フレーム目なら平均を計算
	{
		int now = GetNowCount();
		//現在の時間から、0フレーム目の時間を引き、FPSの数値で割る＝1FPS辺りの平均時間が計算される
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS値を描画する関数 ##########
VOID MY_FPS_DRAW(VOID)
{
	//文字列を描画
	DrawFormatString(0, GAME_HEIGHT - 20, GetColor(255, 0, 0), "FPS:%.1f", CalcFps);
	return;
}

//########## FPS値を計測し、待つ関数 ##########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//かかった時間
	int waitTime = CountFps * 1000 / GAME_FPS - resultTime;	//待つべき時間

	if (waitTime > 0)		//指定のFPS値よりも早い場合
	{
		WaitTimer(waitTime);	//待つ
	}
	return;
}

//########## キーの入力状態を更新する関数 ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{

	//一時的に、現在のキーの入力状態を格納する
	char TempKey[KEY_CODE_KIND];

	//直前のキー入力をとっておく
	for (int i = 0; i < KEY_CODE_KIND; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < KEY_CODE_KIND; i++)
	{
		if (TempKey[i] != 0)	//押されているキーのキーコードを押しているとき
		{
			AllKeyState[i]++;	//押されている
		}
		else
		{
			AllKeyState[i] = 0;	//押されていない
		}
	}
	return;
}

//キーを押しているか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
BOOL MY_KEY_DOWN(int KEY_INPUT_)
{
	//キーコードのキーを押している時
	if (AllKeyState[KEY_INPUT_] != 0)
	{
		return TRUE;	//キーを押している
	}
	else
	{
		return FALSE;	//キーを押していない
	}
}

//キーを押し上げたか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
BOOL MY_KEY_UP(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] >= 1	//直前は押していて
		&& AllKeyState[KEY_INPUT_] == 0)	//今は押していないとき
	{
		return TRUE;	//キーを押し上げている
	}
	else
	{
		return FALSE;	//キーを押し上げていない
	}
}

//キーを押し続けているか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
//引　数：int：キーを押し続ける時間
BOOL MY_KEYDOWN_KEEP(int KEY_INPUT_, int DownTime)
{
	//押し続ける時間=秒数×FPS値
	//例）60FPSのゲームで、1秒間押し続けるなら、1秒×60FPS
	int UpdateTime = DownTime * GAME_FPS;

	if (AllKeyState[KEY_INPUT_] > UpdateTime)
	{
		return TRUE;	//押し続けている
	}
	else
	{
		return FALSE;	//押し続けていない
	}
}

//マウスの入力情報を更新する
VOID MY_MOUSE_UPDATE(VOID)
{
	//マウスの以前の座標を取得
	mouse.OldPoint = mouse.Point;

	//マウスの以前のボタン入力を取得
	for (int i = 0; i < MOUSE_BUTTON_CODE; i++) { mouse.OldButton[i] = mouse.Button[i]; }

	//マウスの座標を取得
	GetMousePoint(&mouse.Point.x, &mouse.Point.y);

	//マウスの押しているボタンを取得
	mouse.InputValue = GetMouseInput();

	//左ボタンを押しているかチェック(TRUEは0以外なので、2も4もTRUE)
	if ((mouse.InputValue & MOUSE_INPUT_LEFT) == MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT]++; }		//押している
	if ((mouse.InputValue & MOUSE_INPUT_LEFT) != MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT] = 0; }		//押していない

	//中ボタンを押しているかチェック(TRUEは0以外なので、2も4もTRUE)
	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) == MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE]++; }	//押している
	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) != MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE] = 0; }	//押していない

	//右ボタンを押しているかチェック(TRUEは0以外なので、2も4もTRUE)
	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) == MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT]++; }		//押している
	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) != MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT] = 0; }	//押していない

	//ホイールの回転量を取得
	mouse.WheelValue = GetMouseWheelRotVol();

	return;
}

//ボタンを押しているか、マウスーコードで判断する
//引　数：int：マウスコード：MOUSE_INPUT_???
BOOL MY_MOUSE_DOWN(int MOUSE_INPUT_)
{
	//マウスコードのボタンを押している時
	if (mouse.Button[MOUSE_INPUT_] != 0)
	{
		return TRUE;	//ボタンを押している
	}
	else
	{
		return FALSE;	//ボタンを押していない
	}
}

//ボタンを押し上げたか、マウスコード判断する
//引　数：int：マウスコード：MOUSE_INPUT_???
BOOL MY_MOUSE_UP(int MOUSE_INPUT_)
{
	if (mouse.OldButton[MOUSE_INPUT_] >= 1	//直前は押していて
		&& mouse.Button[MOUSE_INPUT_] == 0)	//今は押していないとき
	{
		return TRUE;	//ボタンを押し上げている
	}
	else
	{
		return FALSE;	//ボタンを押し上げていない
	}
}

//ボタンを押し続けているか、マウスコード判断する
//引　数：int：マウスコード：MOUSE_INPUT_???
//引　数：int：ボタンを押し続ける時間
BOOL MY_MOUSEDOWN_KEEP(int MOUSE_INPUT_, int DownTime)
{
	//押し続ける時間=秒数×FPS値
	//例）60FPSのゲームで、1秒間押し続けるなら、1秒×60FPS
	int UpdateTime = DownTime * GAME_FPS;

	if (mouse.Button[MOUSE_INPUT_] > UpdateTime)
	{
		return TRUE;	//押し続けている
	}
	else
	{
		return FALSE;	//押し続けていない
	}
}

//フォントをこのソフト用に、一時的にインストール
BOOL MY_FONT_INSTALL_ONCE(VOID)
{
	//フォントを一時的に読み込み(WinAPI)
	if (AddFontResourceEx(FONT_UZU_PATH, FR_PRIVATE, NULL) == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), FONT_UZU_NAME, FONT_INSTALL_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//フォントをこのソフト用に、一時的にアンインストール
VOID MY_FONT_UNINSTALL_ONCE(VOID)
{
	//一時的に読み込んだフォントを削除(WinAPI)
	RemoveFontResourceEx(FONT_UZU_PATH, FR_PRIVATE, NULL);

	return;
}

//フォントを読み込む関数
//引　数：const char *：読み込むフォントの名前
//引　数：int　：フォントの大きさ
//引　数：int　：フォントの太さ
//引　数：int　：フォントのタイプ
//戻り値：BOOL ：エラー時はFALSE / 正常時はTRUE
BOOL MY_FONT_CREATE(VOID)
{
	strcpy_s(FontUzu.path, sizeof(FontUzu.path), FONT_UZU_PATH);
	strcpy_s(FontUzu.name, sizeof(FontUzu.name), FONT_UZU_NAME);
	FontUzu.handle = -1;
	FontUzu.size = 100;
	FontUzu.bold = 1;
	FontUzu.type = DX_FONTTYPE_ANTIALIASING;

	FontUzu.handle = CreateFontToHandle(FontUzu.name, FontUzu.size, FontUzu.bold, FontUzu.type);
	if (FontUzu.handle == -1) { MessageBox(GetMainWindowHandle(), FONT_UZU_NAME, FONT_CREATE_ERR_TITLE, MB_OK); return FALSE; }

	strcpy_s(FontUzu2.path, sizeof(FontUzu2.path), FONT_UZU_PATH);
	strcpy_s(FontUzu2.name, sizeof(FontUzu2.name), FONT_UZU_NAME);
	FontUzu2.handle = -1;
	FontUzu2.size = 50;
	FontUzu2.bold = 1;
	FontUzu2.type = DX_FONTTYPE_ANTIALIASING;

	FontUzu2.handle = CreateFontToHandle(FontUzu2.name, FontUzu2.size, FontUzu2.bold, FontUzu2.type);
	if (FontUzu2.handle == -1) { MessageBox(GetMainWindowHandle(), FONT_UZU_NAME, FONT_CREATE_ERR_TITLE, MB_OK); return FALSE; }

	return TRUE;
}

//フォントを削除する関数
VOID MY_FONT_DELETE(VOID)
{
	DeleteFontToHandle(FontUzu.handle);
	DeleteFontToHandle(FontUzu2.handle);
	return;
}

//スタート画面
VOID MY_START(VOID)
{
	MY_START_PROC();	//スタート画面の処理
	MY_START_DRAW();	//スタート画面の描画


	//DrawString(0, 0, "スタート画面(エンターキーを押して下さい)", GetColor(0, 0, 0));
	return;
}

//スタート画面の処理
VOID MY_START_PROC(VOID)
{
	//BGM再生
	if (CheckSoundMem(TitleBGM.handle) == 0)//まだBGMがなっていなかったら
	{
		ChangeVolumeSoundMem(GAME_SOUND_VOLUME, TitleBGM.handle);
		PlaySoundMem(TitleBGM.handle, DX_PLAYTYPE_LOOP); //ループ再生
	}

	//エンターキーを押したら、ルール説明シーンへ移動する
	if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
	{
		//BGM停止
		if (CheckSoundMem(TitleBGM.handle) != 0)//BGMが流れていたら
		{
			StopSoundMem(TitleBGM.handle); //止める
		}

		ChangeVolumeSoundMem(GAME_SOUND_VOLUME, TitleSE.handle);//SEの音量調整
		PlaySoundMem(TitleSE.handle, DX_PLAYTYPE_BACK);//SEを鳴らす

		//ゲームのシーンをプレイ画面にする
		GameScene = GAME_SCENE_RULE;

		return;
	}


	//背景画像を動かす
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		//画像を移動させる
		ImageTitleBack[num].image.x--;//右から左に流れる

		//背景画像を描画できないとき
		if (ImageTitleBack[num].IsDraw == FALSE)
		{
			//背景画像が画面内にいるとき
			if (ImageTitleBack[num].image.x + ImageTitleBack[num].image.width > 0)
			{
				ImageTitleBack[num].IsDraw = TRUE;	//画像を描画する
			}
		}

		//背景画像が画面を通り越したとき
		if (ImageTitleBack[num].image.x+ImageTitleBack[num].image.width < 0)
		{
			ImageTitleBack[num].image.x = ImageTitleBack[0].image.width * 3;	//画像の幅２つ分、左に移動させる
			ImageTitleBack[num].IsDraw = FALSE;								//画像を描画しない
		}
	}

	return;
}

//スタート画面の描画
VOID MY_START_DRAW(VOID)
{
	//背景を描画する
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		//描画できるときは・・・
		if (ImageTitleBack[num].IsDraw == TRUE)
		{
			//背景を描画
			DrawGraph(ImageTitleBack[num].image.x, ImageTitleBack[num].image.y, ImageTitleBack[num].image.handle, TRUE);

			//【デバッグ用】背景画像の数字をテスト的に表示
			/*DrawFormatString(
				ImageTitleBack[num].image.x,
				ImageTitleBack[num].image.y,
				GetColor(255, 0, 0), "背景画像：%d", num + 1);*/
		}
	}

	DrawGraph(ImageTitleRogo.x, ImageTitleRogo.y, ImageTitleRogo.handle, TRUE);
	DrawGraph(ImageTitlePush.x, ImageTitlePush.y, ImageTitlePush.handle, TRUE);
	return;
}

VOID MY_RULE(VOID)
{
	MY_RULE_PROC();	//プレイ画面の処理
	MY_RULE_DRAW();	//プレイ画面の描画

	DrawString(0, 0, "ルール説明画面(SPACEキーを押して下さい)", GetColor(0, 0, 0));
	return;
}

VOID MY_RULE_PROC(VOID)
{
	//BGM再生
	if (CheckSoundMem(RuleBGM.handle) == 0)//まだBGMがなっていなかったら
	{
		ChangeVolumeSoundMem(GAME_SOUND_VOLUME, RuleBGM.handle);
		PlaySoundMem(RuleBGM.handle, DX_PLAYTYPE_LOOP); //ループ再生
	}

	//スペースキーを押したら、プレイシーンへ移動する
	if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE)
	{
		//BGM停止
		if (CheckSoundMem(RuleBGM.handle) != 0)//BGMが流れていたら
		{
			StopSoundMem(RuleBGM.handle); //止める
		}

		MY_PLAY_INIT();	//ゲーム初期化

		//ゲームのシーンをプレイ画面にする
		GameScene = GAME_SCENE_PLAY;

		return;
	}
	
	
	return;
}

VOID MY_RULE_DRAW(VOID)
{
    DrawGraph(ImageRuleBack.x, ImageRuleBack.y, ImageRuleBack.handle, TRUE);
	DrawGraph(ImageRuleEx.x, ImageRuleEx.y, ImageRuleEx.handle, TRUE);
	DrawStringToHandle(GAME_WIDTH / 2 - FontUzu2.size * 3.5, GAME_HEIGHT - FontUzu2.size * 2, "Play with Space",GetColor(255, 255, 0), FontUzu2.handle);
	
	return;
}

//プレイ画面初期化
VOID MY_PLAY_INIT(VOID)
{
	//背景の初期位置
	//プレイヤーの初期位置を設定
	player.x = 100;
	player.y = 400;


	//エサの初期位置
	for (int i = 0; i < ESA_MAX; i++)
	{
		esa[i] = esa[0];	//エサ0の情報を全てのエサにコピー

		esa[i].x = GAME_WIDTH + 50 + esa[i].width * i * 25;	//エサのX初期位置(エサ20個分の横幅間隔で出現); 

		//エサのY位置をランダムにする
		int ichi = 100 + GetRand(GAME_HEIGHT  - esa[i].height - 100);

		esa[i].y = ichi;

	}


	//エサ缶の初期位置
	for (int i = 0; i < ESA_MAX; i++)
	{
		esakan[i] = esakan[0];

		esakan[i].x = GAME_WIDTH + (10000 * (i+1));	//エサ缶のX初期位置

		//エサ缶のY位置をランダムにする
		int ichi = 100 + GetRand(GAME_HEIGHT - esakan[i].height - 100);

		esakan[i].y = ichi;

	}


	//敵の初期位置
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].IsDraw = FALSE;
		enemy[i].IsCreate = FALSE;
		enemy[i].image.x =GAME_WIDTH /* + i * 100*/;

	}

	//スコアの初期化
	score = 0;

	//ライフの初期化
	player.life = LIFE_MAX;

	//無敵状態の初期化
	/*mutekicount = 100;*/

	//レベルアップ画像の表示カウントの初期化
	Lvcount = 0;

	//スコア演出の初期化
	SCORE_WORD = FALSE;
	WordCount = 0;

	//レベルを戻す
	GameLevel = LEVEL_EASY;

	TekiCreateCnt = 0;	//カウンタ初期化

	return;
}

//プレイ画面
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();	//プレイ画面の処理
	MY_PLAY_DRAW();	//プレイ画面の描画

	//DrawString(0, 0, "プレイ画面(カラスに当たったら負け)", GetColor(0, 0, 0));
	return;
}

//プレイ画面の処理
VOID MY_PLAY_PROC(VOID)
{

	//BGM再生
	if (CheckSoundMem(PlayBGM.handle) == 0)//まだBGMがなっていなかったら
	{
		ChangeVolumeSoundMem(GAME_SOUND_VOLUME, PlayBGM.handle);
		PlaySoundMem(PlayBGM.handle, DX_PLAYTYPE_LOOP); //ループ再生
	}


	if (TekiCreateCnt < TekiCreateCntMax) { TekiCreateCnt++; }
	else
	{
		TekiCreateCnt = 0;	//カウンタ初期化

		//敵を生成するか決める
		for (int index = 0; index < ENEMY_NUM; index++)
		{
			//敵がまだ生成されていないとき
			if (enemy[index].IsCreate == FALSE)
			{

				if (GameLevel == LEVEL_EASY)
				{
					enemy[index] = karasu1;

					enemy[0].image.IsDraw = TRUE;

					/*enemykind = GetRand(10);*/
				}
				else if (GameLevel == LEVEL_NOMAL)
				{

					enemykind = GetRand(1);

					switch (enemykind)
					{
					case 0:
						enemy[index] = karasu1;
						break;
					case 1:
						enemy[index] = karasu2;
						break;
					default:
						break;
					}

					enemykazu = GetRand(1);

					switch (enemykazu)
					{
					case 0:
						enemy[0].image.IsDraw = TRUE;
						break;
					case 1:
						enemy[0].image.IsDraw = TRUE;
						enemy[1].image.IsDraw = TRUE;
						break;
					default:
						break;
					}
				}
				else if (GameLevel == LEVEL_HARD)
				{

					enemykind = GetRand(1);

					switch (enemykind)
					{
					case 0:
						enemy[index] = karasu1;
						break;
					case 1:
						enemy[index] = karasu2;
						break;
					default:
						break;
					}

					enemykazu = GetRand(1);

					switch (enemykazu)
					{
					case 0:
						enemy[0].image.IsDraw = TRUE;
						break;
					case 1:
						enemy[0].image.IsDraw = TRUE;
						enemy[1].image.IsDraw = TRUE;
						break;
					default:
						break;
					}
				}

				
				enemy[index].image.y = 100 + 100 * GetRand(4);
				
				
				/*enemy[index].image.y = 100 + GetRand(GAME_HEIGHT - enemy[index].image.height - 100);*/	//敵の出現Y位置をランダム
				enemy[index].IsCreate = TRUE;
				enemy[index].image.x = GAME_WIDTH;


				//else if (GameLevel == LEVEL_NOMAL)
				//{
				//	enemykind = GetRand(5);
				//}
				//
				//
				//if (2 > enemykind)
				//{
				//	switch (enemykind)
				//	{
				//	case 0:
				//		enemy[index] = karasu1;
				//		break;
				//	case 1:
				//		enemy[index] = karasu2;
				//	default:
				//		break;
				//	}

				//	enemy[index].image.x = GAME_WIDTH;	
				//	//enemy[index].image.y = 100 + GetRand(GAME_HEIGHT  - enemy[index].image.height - 100);	//敵の出現Y位置をランダム
				//	

				//	// 敵のY位置を3通りからランダムで選出
				//	int enemy_y = GetRand(2);

				//	switch (enemy_y)
				//	{
				//		case 0:
				//			enemy[index].image.y = 100;
				//			break;
				//		case 1:
				//			enemy[index].image.y = 350;
				//			break;
				//		case 2:
				//			enemy[index].image.y = 580;
				//			break;
				//	}
				//	
				//	enemy[index].image.IsDraw = TRUE;	
				//	//EnemyAtari(&enemy[index]);

				//	enemy[index].IsCreate = TRUE;
				//}
			}
		}

	}

	//プレイヤーの移動操作
	player.speed = 5; //プレイヤーの速度を設定
	playercount++; //プレイヤーアニメーション用のカウント
	if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE) //SPACEを押していたら上昇
	{
		playercount += 1;
		player.y -= player.speed;
	}
	else //そうでなければ下降
	{
		player.y += player.speed;
	}

	//画面外にプレイヤーが行かないようにする
	if (player.y < 100) { player.y = 100; }
	if (player.y + player.height > GAME_HEIGHT) { player.y = GAME_HEIGHT - player.height; }


	//ライフが０になったらエンドシーンへ遷移する
	if (0>player.life)
	{
		//BGM停止
		if (CheckSoundMem(PlayBGM.handle) != 0)//BGMが流れていたら
		{
			StopSoundMem(PlayBGM.handle); //止める
		}

		for (int i = 0; i < ENEMY_NUM; i++)
		{
			enemy[i].IsCreate = FALSE;
		}


		//ゲームのシーンをエンド画面にする
		GameScene = GAME_SCENE_END;

		return;
	}


	//背景画像を動かす
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		//画像を移動させる
		ImageTitleBack[num].image.x--;//右から左に流れる

		//背景画像を描画できないとき
		if (ImageTitleBack[num].IsDraw == FALSE)
		{
			//背景画像が画面内にいるとき
			if (ImageTitleBack[num].image.x + ImageTitleBack[num].image.width > 0)
			{
				ImageTitleBack[num].IsDraw = TRUE;	//画像を描画する
			}
		}

		//背景画像が画面を通り越したとき
		if (ImageTitleBack[num].image.x + ImageTitleBack[num].image.width < 0)
		{
			ImageTitleBack[num].image.x = ImageTitleBack[0].image.width * 3;	//画像の幅２つ分、左に移動させる
			ImageTitleBack[num].IsDraw = FALSE;								//画像を描画しない
		}
	}


	//夕方背景画像を動かす
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		//画像を移動させる
		ImageEveningBack[num].image.x--;//右から左に流れる

		//背景画像を描画できないとき
		if (ImageEveningBack[num].IsDraw == FALSE)
		{
			//背景画像が画面内にいるとき
			if (ImageEveningBack[num].image.x + ImageEveningBack[num].image.width > 0)
			{
				ImageEveningBack[num].IsDraw = TRUE;	//画像を描画する
			}
		}

		//背景画像が画面を通り越したとき
		if (ImageEveningBack[num].image.x + ImageEveningBack[num].image.width < 0)
		{
			ImageEveningBack[num].image.x = ImageEveningBack[0].image.width * 3;	//画像の幅２つ分、左に移動させる
			ImageEveningBack[num].IsDraw = FALSE;								//画像を描画しない
		}
	}


		RECT PlayerRect;
		PlayerRect.left = player.x + 10;
		PlayerRect.top = player.y + 30;
		PlayerRect.right = player.x + player.width -10;
		PlayerRect.bottom = player.y + player.height;

		
		for (int i = 0; i < ESA_MAX; i++)
		{
			
			if (esa[i].x > 0 - esa[i].width)
			{
				esa[i].x -= 4;	//エサを左に動かす
			}

			if (esakan[i].x > 0 - esakan[i].width)
			{
				esakan[i].x -= 4;	//エサ缶を左に動かす
			}


			//else
			//{
			//	int X_ichi = GetRand(20);
			//	
			//	esa[i].x = GAME_WIDTH /*+ esa[i].width * X_ichi*/;	//エサを右画面外にランダム配置
			//}

			RECT EsaRect;
			EsaRect.left = esa[i].x;
			EsaRect.top = esa[i].y;
			EsaRect.right = esa[i].x + esa[i].width;
			EsaRect.bottom = esa[i].y + esa[i].height;


			RECT EsakanRect;
			EsakanRect.left = esakan[i].x;
			EsakanRect.top = esakan[i].y;
			EsakanRect.right = esakan[i].x + esakan[i].width;
			EsakanRect.bottom = esakan[i].y + esakan[i].height;



			if (esa[i].x + esa[i].width < 0) //エサが画面外に行ったら
			{
				int X_ichi = GetRand(20);

				esa[i].x = GAME_WIDTH * (X_ichi+1);	//エサを右画面外にランダム配置
			}

			if (MY_CHECK_RECT_COLL(PlayerRect, EsaRect) == TRUE) //プレイヤーがエサに当たったら
			{
				score += EsaScore;
				PlaySoundMem(GetSE.handle, DX_PLAYTYPE_BACK);
				WordCount = 0;
				SCORE_WORD = TRUE;
				int X_ichi = GetRand(20);

				esa[i].x = GAME_WIDTH * (X_ichi + 1);	//エサを右画面外にランダム配
			}




			if (esakan[i].x + esakan[i].width < 0) //エサ缶が画面外に行ったら
			{
				esakan[i].x = GAME_WIDTH + (10000 * (i + 1 + ESA_MAX));	//エサ缶を右画面外にランダム配置
			}

			if (MY_CHECK_RECT_COLL(PlayerRect, EsakanRect) == TRUE) //プレイヤーがエサ缶に当たったら
			{
				score += EsakanScore;
				PlaySoundMem(GetSE2.handle, DX_PLAYTYPE_BACK);
				WordCount = 0;
				SCORE_WORD2 = TRUE;

				esakan[i].x = GAME_WIDTH + (10000 * (i + 1 + ESA_MAX));	//エサ缶を右画面外にランダム配置
			}

			
		}

		enemycount++;

		//プレイ画面での敵の構造
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			
			if (enemy[i].image.IsDraw == TRUE)
			{
				
				enemy[i].image.x -= enemy[i].speed;

				EnemyAtari(&enemy[i]);

				if (MY_CHECK_RECT_COLL(enemy[i].rect, PlayerRect) == TRUE)
				{
					/*mutekicount = 0;*/
					if (player.life > 1) //プレイヤーライフが１より大きかったら
					{
						IsMuteki = TRUE;	//一定時間、無敵状態になる
					}					
					player.life--;	//ライフを減らす
					PlaySoundMem(DamageSE.handle, DX_PLAYTYPE_BACK);

					/*enemy[i].IsCreate = FALSE;*/

				}
			}
		}
	

	//無敵時間
	if (IsMuteki == TRUE) //無敵状態になったら
	{
		mutekicount++;		//無敵時間を数えるカウントを増やす。

		if (mutekicount >= 100)	//無敵時間を数えるカウントが１００以上になれば
		{
			Ishit = TRUE;			//当たり判定をオンにする
			IsMuteki = FALSE;		//無敵状態を解除する
			player.IsDraw = TRUE;	//プレイヤーの画像を映す
			mutekicount = 0;		//無敵時間を数えるカウントを０にする
		}
		else if (mutekicount <= 100)	//無敵時間を数えるカウントが１００以下になれば
		{
			Ishit = FALSE;			//当たり判定関数オフ

			if (tennmetu < 5)		//点滅の時間を数えるカウントが５以下なら
			{
				tennmetu += 1;		//点滅時間を数えるカウントを増やす
			}
			else
			{
				//点滅させる
				if (player.IsDraw == TRUE)
				{
					player.IsDraw = FALSE;
				}
				else if (player.IsDraw == FALSE)
				{
					player.IsDraw = TRUE;
				}

				tennmetu = 0;	//点滅時間を数えるカウントを０にする
			}

		}

	}


	//レベルアップ
	if (score >= 500) 
	{
		for (int num = 0; num < IMAGE_BACK_NUM; num++)
		{
			ImageTitleBack[num].IsDraw = FALSE;
		}
		GameLevel = LEVEL_NOMAL;
		if (Lvcount <= 100)
		{
			Lvcount++;
			ImagePlayLevelup.IsDraw = TRUE;
			if (Lvcount == 1)
			{
				ChangeVolumeSoundMem(GAME_SOUND_VOLUME, LvUPSE.handle);
				PlaySoundMem(LvUPSE.handle, DX_PLAYTYPE_BACK);
			}
		}
		else
		{
			ImagePlayLevelup.IsDraw = FALSE;
		}
		
	}

	return;
}

//プレイ画面の描画
VOID MY_PLAY_DRAW(VOID)
{
	//夕方背景を描画する
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		//描画できるときは・・・
		if (ImageEveningBack[num].IsDraw == TRUE)
		{
			//背景を描画
			DrawGraph(ImageEveningBack[num].image.x, ImageEveningBack[num].image.y, ImageEveningBack[num].image.handle, TRUE);

			//【デバッグ用】背景画像の数字をテスト的に表示
			/*DrawFormatString(
				ImageEveningBack[num].image.x,
				ImageEveningBack[num].image.y,
				GetColor(255, 0, 0), "背景画像：%d", num + 1);*/
		}
	}


	//背景を描画する
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		//描画できるときは・・・
		if (ImageTitleBack[num].IsDraw == TRUE)
		{
			//背景を描画
			DrawGraph(ImageTitleBack[num].image.x, ImageTitleBack[num].image.y, ImageTitleBack[num].image.handle, TRUE);

			//【デバッグ用】背景画像の数字をテスト的に表示
			/*DrawFormatString(
				ImageTitleBack[num].image.x,
				ImageTitleBack[num].image.y,
				GetColor(255, 0, 0), "背景画像：%d", num + 1);*/
		}
	}

	//DrawFormatString(600, 0, GetColor(255, 0, 0), "LIFE:%d", player.life);
	DrawFormatStringToHandle(0, 0, GetColor(180, 255, 0),FontUzu.handle, "SCORE:%d", score);

	//エサを描画
	for (int i = 0; i < ESA_MAX; i++)
	{
		if (esa[i].IsDraw == TRUE)
		{
			DrawGraph(esa[i].x, esa[i].y, esa[i].handle, TRUE);
		}
	}


	//エサ缶を描画
	for (int i = 0; i < ESA_MAX; i++)
	{
		if (esakan[i].IsDraw == TRUE)
		{
			DrawGraph(esakan[i].x, esakan[i].y, esakan[i].handle, TRUE);
		}
	}

	//敵の描画
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].image.x + enemy[i].image.width <= 0)
		{
			enemy[i].image.IsDraw = FALSE;
			enemy[i].IsCreate = FALSE;
			enemy[i].image.x = GAME_WIDTH + i * 100;
		}

		int e;

		e = enemycount % 15 / 5;

		if (e == 2)
		{
			e = 0;
		}

		if (enemy[i].image.IsDraw == TRUE)
		{
			DrawGraph(enemy[i].image.x, enemy[i].image.y, enemy[i].image.e_handle[e], TRUE);
		}
	}


	//プレイヤーを描画

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

	
	if (ImagePlayLevelup.IsDraw == TRUE)
	{
		DrawGraph(ImagePlayLevelup.x, ImagePlayLevelup.y, ImagePlayLevelup.handle, TRUE);
	}



	//ライフの描画

	if (player.life > 0)
	{
		DrawGraph(heart[2].x, heart[2].y, heart[2].handle, TRUE);

		if (player.life > 1)
		{
			DrawGraph(heart[1].x, heart[1].y, heart[1].handle, TRUE);

			if (player.life > 2)
			{
				DrawGraph(heart[0].x, heart[0].y, heart[0].handle, TRUE);
			}
		}
	}

	if (SCORE_WORD == TRUE)
	{
		if (WordCount <= 20)
		{
			WordCount++;
			DrawFormatStringToHandle(player.x + player.width / 2, player.y - 25, GetColor(0, 0, 0), FontUzu2.handle, "+%d", EsaScore);
		}
		else
		{
			SCORE_WORD = FALSE;
			WordCount = 0;
		}
	}


	if (SCORE_WORD2 == TRUE)
	{
		if (WordCount <= 30)
		{
			WordCount++;
			DrawFormatStringToHandle(player.x + player.width / 2, player.y - 45, GetColor(218, 179, 0), FontUzu2.handle, "+%d", EsakanScore);
		}
		else
		{
			SCORE_WORD2 = FALSE;
			WordCount = 0;
		}
	}

	return;
}

//エンド画面
VOID MY_END(VOID)
{
	MY_END_PROC();	//エンド画面の処理
	MY_END_DRAW();	//エンド画面の描画

	return;
}

//エンド画面の処理
VOID MY_END_PROC(VOID)
{
	//BGM再生
	if (CheckSoundMem(EndBGM.handle) == 0)//まだBGMがなっていなかったら
	{
		ChangeVolumeSoundMem(GAME_SOUND_VOLUME, EndBGM.handle);
		PlaySoundMem(EndBGM.handle, DX_PLAYTYPE_LOOP); //ループ再生
	}


	//タイトルへ戻るボタン
	if (ImageEndTbutton2.IsDraw == TRUE)
	{
		if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
		{
			//BGM停止
			if (CheckSoundMem(EndBGM.handle) != 0)//BGMが流れていたら
			{
				StopSoundMem(EndBGM.handle); //止める
			}

			GameScene = GAME_SCENE_START;
		}
	}
	//もう一度プレイボタン
	if (ImageEndAbutton2.IsDraw == TRUE)
	{
		if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
		{
			//BGM停止
			if (CheckSoundMem(EndBGM.handle) != 0)//BGMが流れていたら
			{
				StopSoundMem(EndBGM.handle); //止める
			}

			GameScene = GAME_SCENE_RULE;
		}
	}
	
	//下キーを押すと
	if (MY_KEY_UP(KEY_INPUT_DOWN) == TRUE)
	{
		ImageEndAbutton2.IsDraw = TRUE;
		ImageEndTbutton2.IsDraw = FALSE;
	}
	//上キーを押すと
	if (MY_KEY_UP(KEY_INPUT_UP) == TRUE)
	{
		ImageEndAbutton2.IsDraw = FALSE;
		ImageEndTbutton2.IsDraw = TRUE;
	}

	return;
}


//エンド画面の描画
VOID MY_END_DRAW(VOID)
{
	if (score < 500)
	{
		DrawGraph(ImageEndBack1.x, ImageEndBack1.y, ImageEndBack1.handle, TRUE);
		if (MY_KEY_UP(KEY_INPUT_SPACE) == TRUE)
		{
			setMessage("もっとくれ!!");
		}
	}
	else if (score < 1000)
	{
		DrawGraph(ImageEndBack2.x, ImageEndBack2.y, ImageEndBack2.handle, TRUE);
		if (MY_KEY_UP(KEY_INPUT_SPACE) == TRUE)
		{
		    setMessage("おいしかった");
		}
	}
	else if (1000 <= score)
	{
		DrawGraph(ImageEndBack3.x, ImageEndBack3.y, ImageEndBack3.handle, TRUE);
		if (MY_KEY_UP(KEY_INPUT_SPACE) == TRUE)
		{
		    setMessage("成鳥しました");
		}
	}

	DrawStringToHandle(80, 100, "スコア", GetColor(0, 0, 0), FontUzu.handle);
	DrawFormatStringToHandle(150, 250,GetColor(0, 0, 0), FontUzu.handle, "%d", score);
	DrawGraph(ImageEndTbutton.x, ImageEndTbutton.y, ImageEndTbutton.handle, TRUE);
	DrawGraph(ImageEndAbutton.x, ImageEndAbutton.y, ImageEndAbutton.handle, TRUE);

	//タイトルへボタンを光らせる
	if (ImageEndTbutton2.IsDraw == TRUE)
	{
		DrawGraph(ImageEndTbutton2.x, ImageEndTbutton2.y, ImageEndTbutton2.handle, TRUE);
	}
	//もう一度プレイへボタンを光らせる
	if (ImageEndAbutton2.IsDraw == TRUE)
	{
		DrawGraph(ImageEndAbutton2.x, ImageEndAbutton2.y, ImageEndAbutton2.handle, TRUE);
	}
	

	/*DrawBox(50, 460, 550, 560, GetColor(255, 0, 0), TRUE);
	DrawBox(50, 580, 550, 680, GetColor(255, 0, 0), TRUE);*/

	drawMessage();

	return;
}

//画像をまとめて読み込む関数
BOOL MY_LOAD_IMAGE(VOID)
{
	//タイトルロゴ
	strcpy_s(ImageTitleRogo.path, IMAGE_TITLE_ROGO_PATH);		//パスの設定
	ImageTitleRogo.handle = LoadGraph(ImageTitleRogo.path);	    //読み込み
	if (ImageTitleRogo.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_ROGO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleRogo.handle, &ImageTitleRogo.width, &ImageTitleRogo.height);	//画像の幅と高さを取得
	ImageTitleRogo.x = GAME_WIDTH / 2 - ImageTitleRogo.width / 2;		                //左右中央揃え
	ImageTitleRogo.y = GAME_HEIGHT / 2 - ImageTitleRogo.height / 2;	                    //上下中央揃え

	//PUSH_TO_ENTERロゴ
	strcpy_s(ImageTitlePush.path, IMAGE_TITLE_PUSH_PATH);		//パスの設定
	ImageTitlePush.handle = LoadGraph(ImageTitlePush.path);	    //読み込み
	if (ImageTitlePush.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_PUSH_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitlePush.handle, &ImageTitlePush.width, &ImageTitlePush.height);	//画像の幅と高さを取得
	ImageTitlePush.x = GAME_WIDTH / 2 - ImageTitlePush.width / 2;		                //左右中央揃え
	ImageTitlePush.y = GAME_HEIGHT / 4 * 3;	                    //縦3/4位の位置

	//タイトル背景
	strcpy_s(ImageTitleBack[0].image.path, IMAGE_TITLE_BACK1_PATH);			//パスの設定
	strcpy_s(ImageTitleBack[1].image.path, IMAGE_TITLE_BACK2_PATH);		//パスの設定(背景画像反転)
	strcpy_s(ImageTitleBack[2].image.path, IMAGE_TITLE_BACK3_PATH);			//パスの設定
	strcpy_s(ImageTitleBack[3].image.path, IMAGE_TITLE_BACK4_PATH);		//パスの設定(背景画像反転)

	//画像を連続して読み込み
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		ImageTitleBack[num].image.handle = LoadGraph(ImageTitleBack[num].image.path);	//読み込み
		if (ImageTitleBack[num].image.handle == -1)
		{
			//エラーメッセージ表示
			MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BACK1_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
			return FALSE;
		}
		//画像の幅と高さを取得
		GetGraphSize(ImageTitleBack[num].image.handle, &ImageTitleBack[num].image.width, &ImageTitleBack[num].image.height);
	}
	//背景画像�@の設定
	ImageTitleBack[0].image.x = 0 - ImageTitleBack[0].image.width * 0 + 1;	//x原点
	ImageTitleBack[0].image.y = GAME_HEIGHT / 2 - ImageTitleBack[0].image.height / 2; 				//上下中央揃え
	ImageTitleBack[0].IsDraw = FALSE;

	//背景画像�Aの設定
	ImageTitleBack[1].image.x = ImageTitleBack[0].image.width * 1 + 1;	//画像の幅1つ分右に移動
	ImageTitleBack[1].image.y = GAME_HEIGHT / 2 - ImageTitleBack[1].image.height / 2; 				//上下中央揃え
	ImageTitleBack[1].IsDraw = FALSE;

	//背景画像�Bの設定
	ImageTitleBack[2].image.x = ImageTitleBack[0].image.width * 2 + 1;	//画像の幅2つ分右に移動
	ImageTitleBack[2].image.y = GAME_HEIGHT / 2 - ImageTitleBack[2].image.height / 2; 				//上下中央揃え
	ImageTitleBack[2].IsDraw = FALSE;

	//背景画像�Bの設定
	ImageTitleBack[3].image.x = ImageTitleBack[0].image.width * 3 + 1;	//画像の幅3つ分右に移動
	ImageTitleBack[3].image.y = GAME_HEIGHT / 2 - ImageTitleBack[3].image.height / 2; 				//上下中央揃え
	ImageTitleBack[3].IsDraw = FALSE;



	//夕方背景
	strcpy_s(ImageEveningBack[0].image.path, IMAGE_EVENING_BACK1_PATH);			//パスの設定
	strcpy_s(ImageEveningBack[1].image.path, IMAGE_EVENING_BACK2_PATH);		//パスの設定(背景画像反転)
	strcpy_s(ImageEveningBack[2].image.path, IMAGE_EVENING_BACK3_PATH);			//パスの設定
	strcpy_s(ImageEveningBack[3].image.path, IMAGE_EVENING_BACK4_PATH);		//パスの設定(背景画像反転)

	//画像を連続して読み込み
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		ImageEveningBack[num].image.handle = LoadGraph(ImageEveningBack[num].image.path);	//読み込み
		if (ImageEveningBack[num].image.handle == -1)
		{
			//エラーメッセージ表示
			MessageBox(GetMainWindowHandle(), IMAGE_EVENING_BACK1_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
			return FALSE;
		}
		//画像の幅と高さを取得
		GetGraphSize(ImageEveningBack[num].image.handle, &ImageEveningBack[num].image.width, &ImageEveningBack[num].image.height);
	}
	//背景画像�@の設定
	ImageEveningBack[0].image.x = 0 - ImageEveningBack[0].image.width * 0;	//x原点
	ImageEveningBack[0].image.y = GAME_HEIGHT / 2 - ImageEveningBack[0].image.height / 2; 				//上下中央揃え
	ImageEveningBack[0].IsDraw = FALSE;

	//背景画像�Aの設定
	ImageEveningBack[1].image.x = ImageEveningBack[0].image.width * 1;	//画像の幅1つ分右に移動
	ImageEveningBack[1].image.y = GAME_HEIGHT / 2 - ImageEveningBack[1].image.height / 2; 				//上下中央揃え
	ImageEveningBack[1].IsDraw = FALSE;

	//背景画像�Bの設定
	ImageEveningBack[2].image.x = ImageEveningBack[0].image.width * 2;	//画像の幅2つ分右に移動
	ImageEveningBack[2].image.y = GAME_HEIGHT / 2 - ImageEveningBack[2].image.height / 2; 				//上下中央揃え
	ImageEveningBack[2].IsDraw = FALSE;

	//背景画像�Bの設定
	ImageEveningBack[3].image.x = ImageEveningBack[0].image.width * 3;	//画像の幅3つ分右に移動
	ImageEveningBack[3].image.y = GAME_HEIGHT / 2 - ImageEveningBack[3].image.height / 2; 				//上下中央揃え
	ImageEveningBack[3].IsDraw = FALSE;

	//ルール説明背景画像
	strcpy_s(ImageRuleBack.path, IMAGE_RULE_BACK_PATH);		    //パスの設定
	ImageRuleBack.handle = LoadGraph(ImageRuleBack.path);	    //読み込み
	if (ImageRuleBack.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_RULE_BACK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageRuleBack.handle, &ImageRuleBack.width, &ImageRuleBack.height);	//画像の幅と高さを取得
	ImageRuleBack.x = GAME_WIDTH / 2 - ImageRuleBack.width / 2;		                    //左右中央揃え
	ImageRuleBack.y = GAME_HEIGHT / 2 - ImageRuleBack.height / 2;	                    //上下中央揃え


	//ルール説明画像
	strcpy_s(ImageRuleEx.path, IMAGE_RULE_EX_PATH);		    //パスの設定
	ImageRuleEx.handle = LoadGraph(ImageRuleEx.path);	    //読み込み
	if (ImageRuleEx.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_RULE_EX_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageRuleEx.handle, &ImageRuleEx.width, &ImageRuleEx.height);	//画像の幅と高さを取得
	ImageRuleEx.x = GAME_WIDTH / 2 - ImageRuleEx.width / 2;		                    //左右中央揃え
	ImageRuleEx.y = GAME_HEIGHT / 2 - ImageRuleEx.height / 2;	                    //上下中央揃え
	

	//レベルアップ画像
	strcpy_s(ImagePlayLevelup.path, IMAGE_PLAY_LEVELUP_PATH);		    //パスの設定
	ImagePlayLevelup.handle = LoadGraph(ImagePlayLevelup.path);	    //読み込み
	if (ImagePlayLevelup.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_PLAY_LEVELUP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImagePlayLevelup.handle, &ImagePlayLevelup.width, &ImagePlayLevelup.height);	//画像の幅と高さを取得
	ImagePlayLevelup.x = GAME_WIDTH / 2 - ImagePlayLevelup.width / 2;		                    //左右中央揃え
	ImagePlayLevelup.y = GAME_HEIGHT / 2 - ImagePlayLevelup.height / 2;	                    //上下中央揃え
	ImagePlayLevelup.IsDraw = FALSE;

	//エンド背景画像1
	strcpy_s(ImageEndBack1.path, IMAGE_END_BACK1_PATH);		    //パスの設定
	ImageEndBack1.handle = LoadGraph(ImageEndBack1.path);	    //読み込み
	if (ImageEndBack1.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_BACK1_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndBack1.handle, &ImageEndBack1.width, &ImageEndBack1.height);	//画像の幅と高さを取得
	ImageEndBack1.x = GAME_WIDTH / 2 - ImageEndBack1.width / 2;		                    //左右中央揃え
	ImageEndBack1.y = GAME_HEIGHT / 2 - ImageEndBack1.height / 2;	                    //上下中央揃え

	//エンド背景画像2
	strcpy_s(ImageEndBack2.path, IMAGE_END_BACK2_PATH);		    //パスの設定
	ImageEndBack2.handle = LoadGraph(ImageEndBack2.path);	    //読み込み
	if (ImageEndBack2.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_BACK2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndBack2.handle, &ImageEndBack2.width, &ImageEndBack2.height);	//画像の幅と高さを取得
	ImageEndBack2.x = GAME_WIDTH / 2 - ImageEndBack2.width / 2;		                    //左右中央揃え
	ImageEndBack2.y = GAME_HEIGHT / 2 - ImageEndBack2.height / 2;	                    //上下中央揃え

	//エンド背景画像3
	strcpy_s(ImageEndBack3.path, IMAGE_END_BACK3_PATH);		    //パスの設定
	ImageEndBack3.handle = LoadGraph(ImageEndBack3.path);	    //読み込み
	if (ImageEndBack3.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_BACK3_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndBack3.handle, &ImageEndBack3.width, &ImageEndBack3.height);	//画像の幅と高さを取得
	ImageEndBack3.x = GAME_WIDTH / 2 - ImageEndBack3.width / 2;		                    //左右中央揃え
	ImageEndBack3.y = GAME_HEIGHT / 2 - ImageEndBack3.height / 2;	                    //上下中央揃え

	//エンドタイトルへ画像
	strcpy_s(ImageEndTbutton.path, IMAGE_END_TBUTTON_PATH);		    //パスの設定
	ImageEndTbutton.handle = LoadGraph(ImageEndTbutton.path);	    //読み込み
	if (ImageEndTbutton.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_TBUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndTbutton.handle, &ImageEndTbutton.width, &ImageEndTbutton.height);	//画像の幅と高さを取得
	ImageEndTbutton.x = GAME_WIDTH / 2 - ImageEndTbutton.width / 2 - 400;		            //左右中央揃え
	ImageEndTbutton.y = GAME_HEIGHT / 2 - ImageEndTbutton.height / 2 + 100;	                    //上下中央揃え

	//エンドもう一度画像
	strcpy_s(ImageEndAbutton.path, IMAGE_END_ABUTTON_PATH);		    //パスの設定
	ImageEndAbutton.handle = LoadGraph(ImageEndAbutton.path);	    //読み込み
	if (ImageEndAbutton.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_ABUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndAbutton.handle, &ImageEndAbutton.width, &ImageEndAbutton.height);	//画像の幅と高さを取得
	ImageEndAbutton.x = GAME_WIDTH / 2 - ImageEndAbutton.width / 2 - 400;		            //左右中央揃え
	ImageEndAbutton.y = GAME_HEIGHT / 2 - ImageEndAbutton.height / 2 + 220;	                    //上下中央揃え
	
	//エンドタイトルへ2画像
	strcpy_s(ImageEndTbutton2.path, IMAGE_END_TBUTTON2_PATH);		    //パスの設定
	ImageEndTbutton2.handle = LoadGraph(ImageEndTbutton2.path);	    //読み込み
	if (ImageEndTbutton2.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_TBUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndTbutton2.handle, &ImageEndTbutton2.width, &ImageEndTbutton2.height);	//画像の幅と高さを取得
	ImageEndTbutton2.x = GAME_WIDTH / 2 - ImageEndTbutton2.width / 2 - 400;		            //左右中央揃え
	ImageEndTbutton2.y = GAME_HEIGHT / 2 - ImageEndTbutton2.height / 2 + 100;	                    //上下中央揃え
	ImageEndTbutton2.IsDraw = TRUE;

	//エンドもう一度2画像
	strcpy_s(ImageEndAbutton2.path, IMAGE_END_ABUTTON2_PATH);		    //パスの設定
	ImageEndAbutton2.handle = LoadGraph(ImageEndAbutton2.path);	    //読み込み
	if (ImageEndAbutton2.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_ABUTTON2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndAbutton2.handle, &ImageEndAbutton2.width, &ImageEndAbutton2.height);	//画像の幅と高さを取得
	ImageEndAbutton2.x = GAME_WIDTH / 2 - ImageEndAbutton2.width / 2 - 400;		            //左右中央揃え
	ImageEndAbutton2.y = GAME_HEIGHT / 2 - ImageEndAbutton2.height / 2 + 220;	                    //上下中央揃え
	ImageEndAbutton2.IsDraw = FALSE;


	
	//プレイヤーのアニメーション画像
	LoadDivGraph(PLAYER_PATH, 2, 2, 1, 150, 150, player.handle);
	for (int i = 0; i < 2; i++)
	{
		GetGraphSize(player.handle[i], &player.width, &player.height);
	}
	player.IsDraw = TRUE;


	//カラス１
	LoadDivGraph(IMAGE_ENEMY_PATH, 2, 2, 1, 200, 140, karasu1.image.e_handle);
	for (int i = 0; i < 2; i++)
	{
		GetGraphSize(karasu1.image.e_handle[i], &karasu1.image.width, &karasu1.image.height);
	}
	/*strcpy_s(karasu1.image.path, IMAGE_ENEMY_PATH);
	karasu1.image.handle = LoadGraph(karasu1.image.path);
	if (karasu1.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ENEMY_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(karasu1.image.handle, &karasu1.image.width, &karasu1.image.height);*/
	/*karasu1.image.x = GAME_WIDTH + 0 * (+100);
	karasu1.image.y = 100;*/
	karasu1.speed = 4;


	//カラス２
	LoadDivGraph(IMAGE_ENEMY2_PATH, 2, 2, 1, 234, 131, karasu2.image.e_handle);
	for (int i = 0; i < 2; i++)
	{
		GetGraphSize(karasu2.image.e_handle[i], &karasu2.image.width, &karasu2.image.height);
	}
	/*strcpy_s(karasu2.image.path, IMAGE_ENEMY2_PATH);
	karasu2.image.handle = LoadGraph(karasu2.image.path);
	if (karasu2.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ENEMY2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}*/
	GetGraphSize(karasu2.image.handle, &karasu2.image.width, &karasu2.image.height);
	/*karasu2.image.x = GAME_WIDTH + 1 * (+100);
	karasu2.image.y = 500;*/
	karasu2.speed = 6;


	//エサ
	strcpy_s(esa[0].path, IMAGE_ESA_PATH);
	esa[0].handle = LoadGraph(esa[0].path);
	if (esa[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ESA_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(esa[0].handle, &esa[0].width, &esa[0].height);
	esa[0].IsDraw = TRUE;


	//エサ缶
	strcpy_s(esakan[0].path, IMAGE_ESA2_PATH);
	esakan[0].handle = LoadGraph(esakan[0].path);
	if (esakan[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ESA2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(esakan[0].handle, &esakan[0].width, &esakan[0].height);
	esakan[0].IsDraw = TRUE;


	//ハート
	strcpy_s(heart[0].path, IMAGE_LIFE_PATH);
	heart[0].handle = LoadGraph(heart[0].path);
	if (heart[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_LIFE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(heart[0].handle, &heart[0].width, &heart[0].height);	//画像の幅と高さを取得
	heart[0].IsDraw = TRUE;

	//ハートの位置
	for (int i = 0; i < LIFE_MAX; i++)
	{
		heart[i] = heart[0];

		heart[i].x = 900 + heart[i].width * i;
		heart[i].y = 30;

		/*heart[1].x = 770;
		heart[1].y = 30;

		heart[2].x = 690;
		heart[2].y = 30;*/

	}





	return TRUE;
}

//画像をまとめて削除する関数
VOID MY_DELETE_IMAGE(VOID)
{
	DeleteGraph(ImageEndBack1.handle);
	DeleteGraph(ImageEndBack2.handle);
	DeleteGraph(ImageEndBack3.handle);
	DeleteGraph(ImageEndTbutton.handle);
	DeleteGraph(ImageEndAbutton.handle);
	DeleteGraph(ImageEndTbutton2.handle);
	DeleteGraph(ImageEndAbutton2.handle);

	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		DeleteGraph(ImageTitleBack[0].image.handle);
	}
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		DeleteGraph(ImageEveningBack[0].image.handle);
	}
	for (int i = 0; i < LIFE_MAX; i++)
	{
		DeleteGraph(heart[i].handle);
	}
	DeleteGraph(ImageTitleRogo.handle);//タイトルロゴ
	DeleteGraph(ImageTitlePush.handle);//PUSU_TO_ENTERロゴ
	DeleteGraph(ImageEndBack1.handle);//エンド背景1

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

//音楽をまとめて読み込む関数
BOOL MY_LOAD_MUSIC(VOID)
{
	//スタートBGM
	strcpy_s(TitleBGM.path, MUSIC_TITLE_BGM_PATH);
	TitleBGM.handle = LoadSoundMem(TitleBGM.path);
	if (TitleBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_TITLE_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//スタートSE
	strcpy_s(TitleSE.path, MUSIC_TITLE_SE_PATH);
	TitleSE.handle = LoadSoundMem(TitleSE.path);
	if (TitleSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_TITLE_SE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//ルール説明BGM
	strcpy_s(RuleBGM.path, MUSIC_RULE_BGM_PATH);
	RuleBGM.handle = LoadSoundMem(RuleBGM.path);
	if (RuleBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_RULE_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//プレイBGM
	strcpy_s(PlayBGM.path, MUSIC_PLAY_BGM_PATH);
	PlayBGM.handle = LoadSoundMem(PlayBGM.path);
	if (PlayBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_PLAY_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//エサを取った時の効果音
	strcpy_s(GetSE.path, MUSIC_GET_PATH);
	GetSE.handle = LoadSoundMem(GetSE.path);
	if (GetSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_GET_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	//エサ缶を取った時の効果音
	strcpy_s(GetSE2.path, MUSIC_GET2_PATH);
	GetSE2.handle = LoadSoundMem(GetSE2.path);
	if (GetSE2.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_GET2_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//ダメージ効果音
	strcpy_s(DamageSE.path, MUSIC_DAMAGE_PATH);
	DamageSE.handle = LoadSoundMem(DamageSE.path);
	if (DamageSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_DAMAGE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	//レベルアップ時の効果音
	strcpy_s(LvUPSE.path, MUSIC_LVUP_PATH);
	LvUPSE.handle = LoadSoundMem(LvUPSE.path);
	if (LvUPSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_LVUP_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	//エンドBGM
	strcpy_s(EndBGM.path, MUSIC_END_BGM_PATH);
	EndBGM.handle = LoadSoundMem(EndBGM.path);
	if (EndBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_END_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//音楽をまとめて削除する関数
VOID MY_DELETE_MUSIC(VOID)
{
	DeleteSoundMem(TitleBGM.handle);
	DeleteSoundMem(TitleSE.handle);
	DeleteSoundMem(RuleBGM.handle);
	DeleteSoundMem(PlayBGM.handle);
	DeleteSoundMem(GetSE.handle);
	DeleteSoundMem(GetSE2.handle);
	DeleteSoundMem(DamageSE.handle);
	DeleteSoundMem(LvUPSE.handle);
	DeleteSoundMem(EndBGM.handle);

	return;
}

//日本語かどうか判断
int isJapanese(unsigned char code)
{
	if ((code >= 0x81 && code <= 0x9F) ||
		(code >= 0xE0 && code <= 0xFC))
	{
		return 1;
	}
	return 0;
}

// m e s s a g eで指定した文章を start の 位 置 か ら len 文 字 分 表 示 す る
void writeSubstring(char* message, int start, int len,
	int posX, int posY, int color, int bufferLine)
{
	int i;
	//文字数
	int maxLen = strlen(message);

	// s t a r t の 位 置 を 変 更 す る
	// s t a r t の 位 置 ま で に 日 本 語 が で て き て い た ら ， 1 を 足 し て い く
	for (i = 0; i < start && message[i] != '\0'; ) {
		if (isJapanese(message[i])) {
			//日本語の場合，2バ イ ト 分 す す め る
			i += 2;
			// s t a r tに1バイト分足す
			start++;
		}
		else {
			//半角文字の場合，1バ イ ト 分 進 め る
			i++;
		}
	}
	// s t a r t の 位 置 が 表 示 し た い 最 大 文 字 数 よ り 大 き い 場 合
	if (start >= maxLen) {
		return;

	}

	//指定した位置から l e n 文 字 分 表 示 す る
	for (i = 0; i < len && message[start + i] != '\0'; ) {
		if (isJapanese(message[start + i])) {
			//日本語の場合，2文 字 分 b u f f e rにセット
			messageBuffer[bufferLine][i] = message[start + i];
			messageBuffer[bufferLine][i + 1] = message[start + i + 1];
			// l e n は 日 本 語 な の で ， 1 バ イ ト 分 追 加 す る
			len++;
			//2バ イ ト 分 進 め る
			i += 2;
		}
		else {
			//半角文字1文 字 を セ ッ ト
			messageBuffer[bufferLine][i] = message[start + i];
			i++; //1バ イ ト 分 進 め る
		}
	}
	messageBuffer[bufferLine][i] = '\0';
	//メッセージ描画
	DrawStringToHandle(posX, posY, messageBuffer[bufferLine], color,FontUzu.handle);
}


//メッセージ描画
VOID drawMessage()
{
	int i;

	if (message[currentCursor] != '\0') {
		currentCursor++;
	}

	// MESSAGE_MAX_LENGTH ま で 文 字 を 描 画 し た ら 段 落 を 切 り 替 え る
	if (currentCursor % MESSAGE_MAX_LENGTH == 0) {
		if (message[currentCursor] != '\0') {
			currentLineCursor++;
		}

	}
	
	//メッセージ描画部分
	for (i = 0; i < MESSAGE_MAX_LINE; i++) {
		if (i == currentLineCursor) {
			SetFontSize(MESSAGE_FONT_SIZE);
			//メッセージ風に表示
			writeSubstring(message, i * MESSAGE_MAX_LENGTH,
				currentCursor - MESSAGE_MAX_LENGTH * i,
				MESSAGE_BOX_X ,
				MESSAGE_BOX_Y + MESSAGE_FONT_SIZE * i,
				whiteColor, i);
			break;

		}
		else {
			SetFontSize(MESSAGE_FONT_SIZE);
			//メッセージをそのまま表示
			writeSubstring(message, i * MESSAGE_MAX_LENGTH,
				MESSAGE_MAX_LENGTH, 
				MESSAGE_BOX_X,
				MESSAGE_BOX_Y + MESSAGE_FONT_SIZE * i,
				whiteColor, i);

		}

	}
	SetFontSize(16);
}


VOID setMessage(const char* ms)  //描画したいメッセージをセット
{
	currentCursor = 0;
	currentLineCursor = 0;

	strncpy(message, ms, MESSAGE_MAX_LENGTH * MESSAGE_MAX_LINE);   //メッセージをコピー
	
}


//敵の当たり関数

VOID EnemyAtari(CHARA* e)
{
	e->rect.left = e->image.x;
	e->rect.top = e->image.y + 30;
	e->rect.right = e->image.x + e->image.width;
	e->rect.bottom = e->image.y + e->image.height - 20;


	return;
}


//領域の当たり判定
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