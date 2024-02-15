#pragma once

#include "Scene/SceneBase.h"

class EndScene : public SceneBase
{
private:
    int countdown_timer;
    int start_time;
    int background_image;//�w�i�摜
    int end_image;       //�G���h�{�^���摜
    int menu_cursor; //���j���[�J�[�\���ԍ�

public:
    EndScene();
    virtual ~EndScene();

    virtual void Initialize() override;
    virtual eSceneType Update() override;
    virtual void Draw() const override;
    virtual void Finalize() override;

    virtual eSceneType GetNowScene() const override;
};
