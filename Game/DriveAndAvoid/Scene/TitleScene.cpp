#include"TitleScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

TitleScene::TitleScene() : background_image(NULL), menu_image(NULL),
menu_image2(NULL),menu_image3(NULL),cursor_image(NULL),menu_cursor(0)
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
	background_image = LoadGraph("Resource/images/Title.bmp");
	menu_image = LoadGraph("Resource/images/start_m.bmp");
	menu_image2 = LoadGraph("Resource/images/ranking_m.bmp");
	menu_image3 = LoadGraph("Resource/images/help_m.bmp");
	cursor_image = LoadGraph("Resource/images/cone.bmp");

	//BGMの読み込み
	((TitleBGM = LoadSoundMem("Resource/sounds/BGM/main_bgm.wav")) == -1);

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
	if (menu_image2 == -1)
	{
		throw("Resource/images/ranking_m.bmpがありません\n");
	}
	if (menu_image3 == -1)
	{
		throw("Resource/images/help_m.bmpがありません\n");
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
		//一番上に到達したら、一番下にする
		if (menu_cursor < 0)
		{
			menu_cursor = 3;
		}
	}
	

	//カーソル決定(決定した画面に遷移する)
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{

		switch(menu_cursor)
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
	DrawGraph(120, 240, menu_image2, TRUE);
	DrawGraph(100, 280, menu_image3, TRUE);

	//カーソル画像の描画
	DrawRotaGraph(90, 220 + menu_cursor * 40, 0.7, DX_PI / 2.0, cursor_image,
		TRUE);


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

