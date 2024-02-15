#include"TitleScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

TitleScene::TitleScene() : background_image(NULL), menu_image(NULL),
menu_image2(NULL),menu_image3(NULL),cursor_image(NULL),menu_cursor(0)
{

}

TitleScene::~TitleScene()
{
	//BGM�̍폜
	DeleteSoundMem(TitleBGM);
	StopSoundMem(TitleBGM);
}

//����������
void TitleScene::Initialize()
{
	//�摜�̓ǂݍ���
	background_image = LoadGraph("Resource/images/Title.bmp");
	menu_image = LoadGraph("Resource/images/start_m.bmp");
	menu_image2 = LoadGraph("Resource/images/ranking_m.bmp");
	menu_image3 = LoadGraph("Resource/images/help_m.bmp");
	cursor_image = LoadGraph("Resource/images/cone.bmp");

	//BGM�̓ǂݍ���
	((TitleBGM = LoadSoundMem("Resource/sounds/BGM/main_bgm.wav")) == -1);

	//BGM�̉��ʕύX
	ChangeVolumeSoundMem(140, TitleBGM);

	//�G���[�`�F�b�N
	if (background_image == -1)
	{
		throw("Resource/images/Title.bmp������܂���\n");
	}
	if (menu_image == -1)
	{
		throw("Resource/images/start_m.bmp������܂���\n");
	}
	if (menu_image2 == -1)
	{
		throw("Resource/images/ranking_m.bmp������܂���\n");
	}
	if (menu_image3 == -1)
	{
		throw("Resource/images/help_m.bmp������܂���\n");
	}
	if (cursor_image == -1)
	{
		throw("Resource/images/cone.bmp������܂���\n");
	}

}

//�X�V����
eSceneType TitleScene::Update()
{

	//BGM�̍Đ�
	if (CheckSoundMem(TitleBGM) == 0)
	{
		PlaySoundMem(TitleBGM, DX_PLAYTYPE_LOOP, TRUE);
	}

	//�J�[�\�����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		menu_cursor++;
		//�P�ԉ��ɓ��B������A��ԏ�ɂ���
		if (menu_cursor > 3)
		{
			menu_cursor = 0;
		}
	}

	//�J�[�\����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		menu_cursor--;
		//��ԏ�ɓ��B������A��ԉ��ɂ���
		if (menu_cursor < 0)
		{
			menu_cursor = 3;
		}
	}
	

	//�J�[�\������(���肵����ʂɑJ�ڂ���)
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

	//���݂̃V�[���^�C�v��Ԃ�
	return GetNowScene();
}

//�`�揈��
void TitleScene::Draw() const
{
	//�^�C�g����ʂ̕`��
	DrawGraph(0, 0, background_image, FALSE);

	//���j���[�摜�̕`��
	DrawGraph(120, 200, menu_image, TRUE);
	DrawGraph(120, 240, menu_image2, TRUE);
	DrawGraph(100, 280, menu_image3, TRUE);

	//�J�[�\���摜�̕`��
	DrawRotaGraph(90, 220 + menu_cursor * 40, 0.7, DX_PI / 2.0, cursor_image,
		TRUE);


}


//�I��������
void TitleScene::Finalize()
{
	//�ǂݍ��񂾉摜�̍폜
	DeleteGraph(background_image);
	DeleteGraph(menu_image);
	DeleteGraph(cursor_image);
}

//���݂̃V�[�������擾
eSceneType TitleScene::GetNowScene() const
{
	return eSceneType::E_TITLE;
}

