#include"TitleScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

TitleScene::TitleScene() : background_image(NULL), menu_image(NULL),
cursor_image(NULL), menu_cursor(0)
{

}

TitleScene::~TitleScene()
{
	//BGMの削除
	DeleteSoundMem(TitleBGM);
	StopSoundMem(TitleBGM);
}

//初期化処理
void TitleScene::Initialize()
{
	//画像の読み込み
	background_image = LoadGraph("Resource/images/Title.png");
	menu_image = LoadGraph("Resource/images/menu.bmp");
	cursor_image = LoadGraph("Resource/images/cone.bmp");

	//BGMの読み込み
	((TitleBGM = LoadSoundMem("Resource/sounds/BGM/title_bgm.wav")) == -1);

	// SEの読み込み
	((DecisionSE = LoadSoundMem("Resource/Sounds/SE/Cursor_SE.wav")) == -1);
	// SEの読み込み
	((SelectSE = LoadSoundMem("Resource/Sounds/SE/Kettei_SE.wav")) == -1);

	//BGMの音量変更
	ChangeVolumeSoundMem(140, TitleBGM);

	//エラーチェック
	if (background_image == -1)
	{
		throw("Resource/images/Title.bmpがありません\n");
	}
	if (menu_image == -1)
	{
		throw("Resource/images/start_m.bmpがありません\n");
	}
	
	if (cursor_image == -1)
	{
		throw("Resource/images/cone.bmpがありません\n");
	}

}

//更新処理
eSceneType TitleScene::Update()
{
	//BGMの再生
	if (CheckSoundMem(TitleBGM) == 0)
	{
		PlaySoundMem(TitleBGM, DX_PLAYTYPE_LOOP, TRUE);
	}

	//カーソル下移動
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		menu_cursor++;
		PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK, TRUE);
		//１番下に到達したら、一番上にする
		if (menu_cursor > 3)
		{
			menu_cursor = 0;
		}
	}

	//カーソル上移動
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		menu_cursor--;
		PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK, TRUE);
		//一番上に到達したら、一番下にする
		if (menu_cursor < 0)
		{
			menu_cursor = 3;
		}
	}
	

	//カーソル決定(決定した画面に遷移する
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK, TRUE);
		switch (menu_cursor)
		{
		case 0:
			return eSceneType::E_MAIN;
		case 1:
			return eSceneType::E_RANKING_DISP;
		case 2:
			return eSceneType::E_HELP;
		default:
			return eSceneType::E_END_SCENE;
		}
	}

	
	//現在のシーンタイプを返す
	return GetNowScene();
}

//描画処理
void TitleScene::Draw() const
{
	//タイトル画面の描画
	DrawGraph(0, 0, background_image, FALSE);

	//メニュー画像の描画
	DrawGraph(120, 200, menu_image, TRUE);

	//カーソル画像の描画
	DrawRotaGraph(90, 220 + menu_cursor * 40, 0.7, DX_PI / 2.0, cursor_image, TRUE);

	SetFontSize(60);
	DrawBox(35, 40, 600, 120, GetColor(255, 255, 255), TRUE);
	DrawString(50, 50, "歩行者天国大爆走!!", 0xff0000);
	

	// ハイライト効果の追加
	int highlightColor = GetColor(255, 255, 255);  // ハイライトに使用する黄色
	int pressedColor = GetColor(255, 0, 0);  // ボタンが押されたときの色

	switch (menu_cursor)
	{
	case 0:
		if (InputControl::GetButtonDown(XINPUT_BUTTON_B)) {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);
			DrawBox(110, 200 + menu_cursor * 40, 280, 240 + menu_cursor * 40, pressedColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // ブレンドモードを元に戻す
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);  // 透明度を変更してハイライト効果を追加
			DrawBox(110, 200 + menu_cursor * 40, 400, 240 + menu_cursor * 40, highlightColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // ブレンドモードを元に戻す
		}
		break;
	case 1:
		if (InputControl::GetButtonDown(XINPUT_BUTTON_B)) {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);
			DrawBox(110, 240, 280, 280, pressedColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // ブレンドモードを元に戻す
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);  // 透明度を変更してハイライト効果を追加
			DrawBox(110, 200 + menu_cursor * 40, 400, 240 + menu_cursor * 40, highlightColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // ブレンドモードを元に戻す
		}
		break;
	case 2:
		if (InputControl::GetButtonDown(XINPUT_BUTTON_B)) {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);
			DrawBox(110, 280, 280, 320, pressedColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // ブレンドモードを元に戻す
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);  // 透明度を変更してハイライト効果を追加
			DrawBox(110, 200 + menu_cursor * 40, 400, 240 + menu_cursor * 40, highlightColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // ブレンドモードを元に戻す
		}
		break;
	case 3:
		if (InputControl::GetButtonDown(XINPUT_BUTTON_B)) {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);
			DrawBox(110, 320, 280, 360, pressedColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // ブレンドモードを元に戻す
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);  // 透明度を変更してハイライト効果を追加
			DrawBox(110, 200 + menu_cursor * 40, 400, 240 + menu_cursor * 40, highlightColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // ブレンドモードを元に戻す
		}
		break;
	}
}


//終了時処理
void TitleScene::Finalize()
{
	//読み込んだ画像の削除
	DeleteGraph(background_image);
	DeleteGraph(menu_image);
	DeleteGraph(cursor_image);
}

//現在のシーン情報を取得
eSceneType TitleScene::GetNowScene() const
{
	return eSceneType::E_TITLE;
}

