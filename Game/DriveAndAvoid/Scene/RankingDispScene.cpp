#include"RankingDispScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

enum class Ranking
{
	START = 0,
	END
};
RankingDispScene::RankingDispScene() : background_image(NULL), ranking(nullptr)
{
	select = 0;
	cursor = 0;
	title = 0;
	end = 0;
	Once = FALSE;

}

RankingDispScene::~RankingDispScene()
{

}

//����������
void RankingDispScene::Initialize()
{
	
	Once = TRUE;
	end = LoadGraph("Resource/images/end_m.bmp");
	title= LoadGraph("Resource/images/start_m.bmp");
	//�摜�̓ǂݍ���
	background_image = LoadGraph("Resource/images/Rankingcar.png");
	//
	cursor= LoadGraph("Resource/images/cone.bmp");
	//�G���[�`�F�b�N
	if (background_image == -1)
	{
		throw("Resource/images/Rankingcar.bmp������܂���\n");
	}

	//�����L���O�����擾
	ranking = new RankingData;
	ranking->Initialize();
}

//�X�V����
eSceneType RankingDispScene::Update()
{
	//B�{�^���������ꂽ��A�^�C�g���ɖ߂�
	/*if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_TITLE;
	}
	return GetNowScene();*/
	//�\���L�[�i��j����
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK, TRUE);
		select++;
		if (select > 1)select = 0;

	}
	//�\���L�[�i���j����
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK, TRUE);
		select--;
		if (select < 0)select = 1;

	}

	//L�X�e�B�b�N�����
	if (InputControl::GetLeftTrigger() > 10000 && Once == TRUE)
	{
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK, TRUE);
		select++;
		if (select > 1)select = 0;
		Once = FALSE;
	}

	//L�X�e�B�b�N������
	if (InputControl::GetLeftTrigger() < -10000 && Once == TRUE)
	{
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK, TRUE);
		select--;
		if (select < 0)select = 1;
		Once = FALSE;
	}

	//L�X�e�B�b�N�����ɖ߂��ꂽ��Once�����Z�b�g
	if (Once == FALSE && InputControl::GetLeftTrigger()< 10000 && InputControl::GetLeftTrigger() > -10000)
	{
		Once = TRUE;
	}

	//b�{�^���őJ��
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{

		switch (static_cast<Ranking>(select))
		{
			//�Q�[����ʂ�
		case Ranking::START:
			//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK, TRUE);
			return eSceneType::E_TITLE;
			break;
	
			//�G���h��ʂ�
		case Ranking::END:
			//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK, TRUE);
			return eSceneType::E_END_SCENE;
			break;
		default:
			break;
		}
	}
	return GetNowScene();
}

//�`�揈��
void RankingDispScene::Draw() const
{
	//�w�i�摜�̕`��
	DrawGraph(0, 100, background_image, FALSE);
	SetFontSize(20);
	//�擾���������L���O�f�[�^��`�悷��
	for (int i = 0; i < 5; i++)
	{
		DrawFormatString(50, 170 + i * 25, 0xffffff, "%2d %-15s %6d",
			ranking->GetRank(i), ranking->GetName(i), ranking->GetScore(i));
	}
	
	
	//�J�[�\���摜�̕`��
	DrawRotaGraph(170, 350 + select* 40, 0.7, DX_PI / 2.0, cursor,TRUE);
	//DrawString(150, 300, "B�Ń^�C�g��", 0xff0000);
	SetFontSize(64);
	DrawString(200, 100, " RANKING ", 0xffffff, 0);
	//DrawString(200, 330, " TITLE ", 0xffffff, 0);
	//DrawString(200, 370, " END ", 0xffffff, 0);
	DrawGraph(200, 330, title, TRUE);
	DrawGraph(200, 370, end, TRUE);
}
//�I��������
void RankingDispScene::Finalize()
{
	//�ǂݍ��񂾉摜�̍폜
	DeleteGraph(background_image);

	//���I�������̊J��
	ranking->Finalize();
	delete ranking;
}

//���݂̃V�[�������擾
eSceneType RankingDispScene::GetNowScene() const
{
	return eSceneType::E_RANKING_DISP;
}
