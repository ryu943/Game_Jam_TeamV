#include"RankingDispScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

enum class Ranking
{
	START = 0,
	END
};
RankingDispScene::RankingDispScene() : background_image(NULL), ranking(nullptr)
{
	select = 0;
	cursor = 0;
	title = 0;
	end = 0;
	Once = FALSE;

}

RankingDispScene::~RankingDispScene()
{

}

//初期化処理
void RankingDispScene::Initialize()
{
	
	Once = TRUE;
	end = LoadGraph("Resource/images/end_m.bmp");
	title= LoadGraph("Resource/images/start_m.bmp");
	//画像の読み込み
	background_image = LoadGraph("Resource/images/Rankingcar.png");
	//
	cursor= LoadGraph("Resource/images/cone.bmp");
	//エラーチェック
	if (background_image == -1)
	{
		throw("Resource/images/Rankingcar.bmpがありません\n");
	}

	//ランキング情報を取得
	ranking = new RankingData;
	ranking->Initialize();
}

//更新処理
eSceneType RankingDispScene::Update()
{
	//Bボタンが押されたら、タイトルに戻る
	/*if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_TITLE;
	}
	return GetNowScene();*/
	//十字キー（上）入力
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK, TRUE);
		select++;
		if (select > 1)select = 0;

	}
	//十字キー（下）入力
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK, TRUE);
		select--;
		if (select < 0)select = 1;

	}

	//Lスティック上入力
	if (InputControl::GetLeftTrigger() > 10000 && Once == TRUE)
	{
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK, TRUE);
		select++;
		if (select > 1)select = 0;
		Once = FALSE;
	}

	//Lスティック下入力
	if (InputControl::GetLeftTrigger() < -10000 && Once == TRUE)
	{
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK, TRUE);
		select--;
		if (select < 0)select = 1;
		Once = FALSE;
	}

	//Lスティックが元に戻されたらOnceをリセット
	if (Once == FALSE && InputControl::GetLeftTrigger()< 10000 && InputControl::GetLeftTrigger() > -10000)
	{
		Once = TRUE;
	}

	//bボタンで遷移
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{

		switch (static_cast<Ranking>(select))
		{
			//ゲーム画面へ
		case Ranking::START:
			//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK, TRUE);
			return eSceneType::E_TITLE;
			break;
	
			//エンド画面へ
		case Ranking::END:
			//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK, TRUE);
			return eSceneType::E_END_SCENE;
			break;
		default:
			break;
		}
	}
	return GetNowScene();
}

//描画処理
void RankingDispScene::Draw() const
{
	//背景画像の描画
	DrawGraph(0, 100, background_image, FALSE);
	SetFontSize(20);
	//取得したランキングデータを描画する
	for (int i = 0; i < 5; i++)
	{
		DrawFormatString(50, 170 + i * 25, 0xffffff, "%2d %-15s %6d",
			ranking->GetRank(i), ranking->GetName(i), ranking->GetScore(i));
	}
	
	
	//カーソル画像の描画
	DrawRotaGraph(170, 350 + select* 40, 0.7, DX_PI / 2.0, cursor,TRUE);
	//DrawString(150, 300, "Bでタイトル", 0xff0000);
	SetFontSize(64);
	DrawString(200, 100, " RANKING ", 0xffffff, 0);
	//DrawString(200, 330, " TITLE ", 0xffffff, 0);
	//DrawString(200, 370, " END ", 0xffffff, 0);
	DrawGraph(200, 330, title, TRUE);
	DrawGraph(200, 370, end, TRUE);
}
//終了時処理
void RankingDispScene::Finalize()
{
	//読み込んだ画像の削除
	DeleteGraph(background_image);

	//動的メモリの開放
	ranking->Finalize();
	delete ranking;
}

//現在のシーン情報を取得
eSceneType RankingDispScene::GetNowScene() const
{
	return eSceneType::E_RANKING_DISP;
}
