#pragma once

#include "Scene/SceneBase.h"

class EndScene : public SceneBase
{
private:
    int countdown_timer;
    int start_time;
    int background_image;//背景画像
    int end_image;       //エンドボタン画像
    int menu_cursor; //メニューカーソル番号

public:
    EndScene();
    virtual ~EndScene();

    virtual void Initialize() override;
    virtual eSceneType Update() override;
    virtual void Draw() const override;
    virtual void Finalize() override;

    virtual eSceneType GetNowScene() const override;
};
