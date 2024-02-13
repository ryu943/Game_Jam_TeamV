#pragma once

#include "Scene/SceneBase.h"

class EndScene : public SceneBase
{
private:
    int background_image;//�w�i�摜

public:
    EndScene();
    virtual ~EndScene();

    virtual void Initialize() override;
    virtual eSceneType Update() override;
    virtual void Draw() const override;
    virtual void Finalize() override;

    virtual eSceneType GetNowScene() const override;
};
