#include "EndScene.h"
#include "DxLib.h"
#include "Scene/TitleScene.h"

EndScene::EndScene() : background_image(NULL)
{

}

EndScene::~EndScene()
{

}

void EndScene::Initialize()
{
    //画像の読み込み
    background_image = LoadGraph("Resource/images/End.bmp");

    //エラーチェック
    if (background_image == -1)
    {
        throw("Resource/images/End.bmpがありません\n");
    }
}

eSceneType EndScene::Update()
{
 
    {
        // 一定時間経過後にゲームを終了する
        return eSceneType::E_END_SCENE;
    }

    return GetNowScene();
}

void EndScene::Draw() const
{
    //背景画像の描画
    DrawGraph(0, 0, background_image, FALSE);
}

void EndScene::Finalize()
{
    //読み込んだ画像の削除
    DeleteGraph(background_image);

    SetFontSize(16);
        DrawString(20, 120, "エンド画面", 0xffffff, 0);

}

eSceneType EndScene::GetNowScene() const
{
    return eSceneType::E_END_SCENE;
}