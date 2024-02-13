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
    //�摜�̓ǂݍ���
    background_image = LoadGraph("Resource/images/End.bmp");

    //�G���[�`�F�b�N
    if (background_image == -1)
    {
        throw("Resource/images/End.bmp������܂���\n");
    }
}

eSceneType EndScene::Update()
{
 
    {
        // ��莞�Ԍo�ߌ�ɃQ�[�����I������
        return eSceneType::E_END_SCENE;
    }

    return GetNowScene();
}

void EndScene::Draw() const
{
    //�w�i�摜�̕`��
    DrawGraph(0, 0, background_image, FALSE);
}

void EndScene::Finalize()
{
    //�ǂݍ��񂾉摜�̍폜
    DeleteGraph(background_image);

    SetFontSize(16);
        DrawString(20, 120, "�G���h���", 0xffffff, 0);

}

eSceneType EndScene::GetNowScene() const
{
    return eSceneType::E_END_SCENE;
}