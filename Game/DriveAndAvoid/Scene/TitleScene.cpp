#include"TitleScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

TitleScene::TitleScene() : background_image(NULL), menu_image(NULL),
cursor_image(NULL), menu_cursor(0)
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
	background_image = LoadGraph("Resource/images/Title.png");
	menu_image = LoadGraph("Resource/images/menu.bmp");
	cursor_image = LoadGraph("Resource/images/cone.bmp");

	//BGM�̓ǂݍ���
	((TitleBGM = LoadSoundMem("Resource/sounds/BGM/title_bgm.wav")) == -1);

	// SE�̓ǂݍ���
	((DecisionSE = LoadSoundMem("Resource/Sounds/SE/Cursor_SE.wav")) == -1);
	// SE�̓ǂݍ���
	((SelectSE = LoadSoundMem("Resource/Sounds/SE/Kettei_SE.wav")) == -1);

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
		PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK, TRUE);
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
		PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK, TRUE);
		//��ԏ�ɓ��B������A��ԉ��ɂ���
		if (menu_cursor < 0)
		{
			menu_cursor = 3;
		}
	}
	

	//�J�[�\������(���肵����ʂɑJ�ڂ���
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK, TRUE);
		switch (menu_cursor)
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

	//�J�[�\���摜�̕`��
	DrawRotaGraph(90, 220 + menu_cursor * 40, 0.7, DX_PI / 2.0, cursor_image, TRUE);

	SetFontSize(60);
	DrawBox(35, 40, 600, 120, GetColor(255, 255, 255), TRUE);
	DrawString(50, 50, "���s�ғV���唚��!!", 0xff0000);
	

	// �n�C���C�g���ʂ̒ǉ�
	int highlightColor = GetColor(255, 255, 255);  // �n�C���C�g�Ɏg�p���鉩�F
	int pressedColor = GetColor(255, 0, 0);  // �{�^���������ꂽ�Ƃ��̐F

	switch (menu_cursor)
	{
	case 0:
		if (InputControl::GetButtonDown(XINPUT_BUTTON_B)) {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);
			DrawBox(110, 200 + menu_cursor * 40, 280, 240 + menu_cursor * 40, pressedColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // �u�����h���[�h�����ɖ߂�
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);  // �����x��ύX���ăn�C���C�g���ʂ�ǉ�
			DrawBox(110, 200 + menu_cursor * 40, 400, 240 + menu_cursor * 40, highlightColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // �u�����h���[�h�����ɖ߂�
		}
		break;
	case 1:
		if (InputControl::GetButtonDown(XINPUT_BUTTON_B)) {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);
			DrawBox(110, 240, 280, 280, pressedColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // �u�����h���[�h�����ɖ߂�
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);  // �����x��ύX���ăn�C���C�g���ʂ�ǉ�
			DrawBox(110, 200 + menu_cursor * 40, 400, 240 + menu_cursor * 40, highlightColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // �u�����h���[�h�����ɖ߂�
		}
		break;
	case 2:
		if (InputControl::GetButtonDown(XINPUT_BUTTON_B)) {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);
			DrawBox(110, 280, 280, 320, pressedColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // �u�����h���[�h�����ɖ߂�
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);  // �����x��ύX���ăn�C���C�g���ʂ�ǉ�
			DrawBox(110, 200 + menu_cursor * 40, 400, 240 + menu_cursor * 40, highlightColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // �u�����h���[�h�����ɖ߂�
		}
		break;
	case 3:
		if (InputControl::GetButtonDown(XINPUT_BUTTON_B)) {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);
			DrawBox(110, 320, 280, 360, pressedColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // �u�����h���[�h�����ɖ߂�
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ADD, 128);  // �����x��ύX���ăn�C���C�g���ʂ�ǉ�
			DrawBox(110, 200 + menu_cursor * 40, 400, 240 + menu_cursor * 40, highlightColor, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // �u�����h���[�h�����ɖ߂�
		}
		break;
	}
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

