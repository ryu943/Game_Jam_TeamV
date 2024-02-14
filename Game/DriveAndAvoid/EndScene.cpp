#include "EndScene.h"
#include "DxLib.h"
#include "Scene/TitleScene.h"
#include "Utility/InputControl.h"

EndScene::EndScene() : background_image(NULL),cursor_image(NULL), menu_cursor(0),end_image(NULL), countdown_timer(4000)
{

}

EndScene::~EndScene()
{

}

//初期化処理
void EndScene::Initialize()
{
    //画像の読み込み
    background_image = LoadGraph("Resource/images/End.bmp");
    end_image = LoadGraph("Resource/images/end_m.bmp");
    cursor_image = LoadGraph("Resource/images/cone.bmp");

    //エラーチェック
    if (background_image == -1)
    {
        throw("Resource/images/End.bmpがありません\n");
    }
    if (end_image == -1)
    {
        throw("Resource/images/end_m.bmpがありません\n");
    }
    if (cursor_image == -1)
    {
        throw("Resource/images/cone.bmpがありません\n");
    }

    // 初期化時に現在の時間を記録
    start_time = GetNowCount();
}

//更新処理
eSceneType EndScene::Update()
{
    //Bボタンが押されたら、ゲーム終了
    if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
    {
        return eSceneType::E_END;
    }

    // 一定時間経過後にゲームを終了する
    if (GetNowCount() - start_time > countdown_timer)
    {
        return eSceneType::E_END;
    }

    return GetNowScene();
}

//描画処理
void EndScene::Draw() const
{
    //背景画像の描画
    DrawGraph(0, 0, background_image, FALSE);
    SetFontSize(30);
    DrawString(20, 120, "エンド画面", 0xffffff, 0);
    //エンド画像の描画
    DrawGraph(120, 200, end_image, TRUE);
    //カーソル画像の描画
    DrawRotaGraph(90, 220 + menu_cursor * 40, 0.7, DX_PI / 2.0, cursor_image,
        TRUE);
}

//終了時処理
void EndScene::Finalize()
{
    //読み込んだ画像の削除
    DeleteGraph(background_image);
    DeleteGraph(end_image);
    DeleteGraph(cursor_image);

}

eSceneType EndScene::GetNowScene() const
{
    return eSceneType::E_END_SCENE;
}