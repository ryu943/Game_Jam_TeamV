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

//����������
void EndScene::Initialize()
{
    //�摜�̓ǂݍ���
    background_image = LoadGraph("Resource/images/End.bmp");
    end_image = LoadGraph("Resource/images/end_m.bmp");
    cursor_image = LoadGraph("Resource/images/cone.bmp");

    //�G���[�`�F�b�N
    if (background_image == -1)
    {
        throw("Resource/images/End.bmp������܂���\n");
    }
    if (end_image == -1)
    {
        throw("Resource/images/end_m.bmp������܂���\n");
    }
    if (cursor_image == -1)
    {
        throw("Resource/images/cone.bmp������܂���\n");
    }

    // ���������Ɍ��݂̎��Ԃ��L�^
    start_time = GetNowCount();
}

//�X�V����
eSceneType EndScene::Update()
{
    //B�{�^���������ꂽ��A�Q�[���I��
    if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
    {
        return eSceneType::E_END;
    }

    // ��莞�Ԍo�ߌ�ɃQ�[�����I������
    if (GetNowCount() - start_time > countdown_timer)
    {
        return eSceneType::E_END;
    }

    return GetNowScene();
}

//�`�揈��
void EndScene::Draw() const
{
    //�w�i�摜�̕`��
    DrawGraph(0, 0, background_image, FALSE);
    SetFontSize(30);
    DrawString(20, 120, "�G���h���", 0xffffff, 0);
    //�G���h�摜�̕`��
    DrawGraph(120, 200, end_image, TRUE);
    //�J�[�\���摜�̕`��
    DrawRotaGraph(90, 220 + menu_cursor * 40, 0.7, DX_PI / 2.0, cursor_image,
        TRUE);
}

//�I��������
void EndScene::Finalize()
{
    //�ǂݍ��񂾉摜�̍폜
    DeleteGraph(background_image);
    DeleteGraph(end_image);
    DeleteGraph(cursor_image);

}

eSceneType EndScene::GetNowScene() const
{
    return eSceneType::E_END_SCENE;
}