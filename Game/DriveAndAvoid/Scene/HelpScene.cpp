#include"HelpScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

HelpScene::HelpScene() : background_image(NULL)
{

}

HelpScene::~HelpScene()
{

}

//����������
void HelpScene::Initialize()
{
	//�摜�̓ǂݍ���
	background_image = LoadGraph("Resource/images/haikei2.bmp");

	//�G���[�`�F�b�N
	if (background_image == -1)
	{
		throw("Resource/images/haikei2.bmp������܂���\n");
	}
}

//�X�V����
eSceneType HelpScene::Update()
{
	//B�{�^���������ꂽ��A�^�C�g���̖߂�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_TITLE;
	}

	return GetNowScene();
}

//�`�揈��
void HelpScene::Draw() const
{
	//�w�i�摜�̕`��
	DrawGraph(0, 0, background_image, FALSE);

	//�Q�[������
	SetFontSize(20);
	DrawString(20, 1200, "�w���v���",GetColor(0,0,255));

	DrawString(20, 160, "����͐l�Ԃ�����Ȃ���", GetColor(0,0,255));
	DrawString(20, 180, "���葱����Q�[���ł�", GetColor(0,0,255));
	DrawString(20, 200, "�R�����s���邩�l�Ԃ�", GetColor(0,0,255));
	DrawString(20, 220, "���񓖂���ƃQ�[���I�[�o�[�ł�", GetColor(0,0,255));

	DrawString(150, 450, "---- B�{�^���������ă^�C�g���֖߂�----", GetColor(255,0,0));
}

//�I��������
void HelpScene::Finalize()
{
	//�ǂݍ��񂾉摜�̍폜
	DeleteGraph(background_image);
}

//���݂̃V�[�������擾
eSceneType HelpScene::GetNowScene() const
{
	return eSceneType::E_HELP;
}