#include "EndScene.h"
#include "DxLib.h"
#include "Scene/TitleScene.h"
#include "Utility/InputControl.h"

EndScene::EndScene() : background_image(NULL), menu_cursor(0),end_image(NULL), countdown_timer(3000)
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

    //エラーチェック
    if (background_image == -1)
    {
        throw("Resource/images/End.bmpがありません\n");
    }
    if (end_image == -1)
    {
        throw("Resource/images/end_m.bmpがありません\n");
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
    //DrawGraph(0, 0, background_image, FALSE);
    SetFontSize(40);
 
    //エンド画像の描画
    DrawGraph(220, 400, end_image, TRUE);

    DrawString(100, 50, "制作<チームV>", GetColor(255, 255, 255));
    
    // メンバー1の名前を描画
    DrawString(50,100, "石嶺　龍", GetColor(255, 255, 255));

    // メンバー2の名前を描画
    DrawString(50, 150, "當銘　耀斗", GetColor(255, 255, 255));

    // メンバー3の名前を描画
    DrawString(50, 200, "新田　陽人", GetColor(255, 255, 255));

    // メンバー4の名前を描画
    DrawString(50, 250, "前泊　愛翔", GetColor(255, 255, 255));

}

//終了時処理
void EndScene::Finalize()
{
    //読み込んだ画像の削除
    DeleteGraph(background_image);
    DeleteGraph(end_image);

}

eSceneType EndScene::GetNowScene() const
{
    return eSceneType::E_END_SCENE;
}