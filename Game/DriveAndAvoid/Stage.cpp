#include "Stage.h"
#include"DxLib.h"

#define SPEED_TIMING 100
#define EFFECT_TIME 500

//�R���X�g���N�^
Stage::Stage()
{
	//������
	image = LoadGraph("Resource/Images/back.bmp"); //�X�e�[�W�摜�Ǎ���
	mileage = 0;
	speed = 4;
	speed_up = false;
}

//�f�X�g���N�^
Stage::~Stage()
{

}

//�`��ȊO�̏���
void Stage::Update()
{
	speed_up = false;

	//���s�����𑝂₵�Ă���
	mileage += speed;

	//���s�������A3500�Ŋ����Ă��܂肪0�܂肫�ꂢ�Ɋ���؂ꂽ�Ƃ��ɑ��xUP
	if (mileage % SPEED_TIMING == 0)
	{
		speed += 2;
		speed_up = true;
	}
}

//�`��̂�
void Stage::Draw() const
{
	//�X�e�[�W�`��
	DrawGraph(-80, mileage % 720 - 720, image, FALSE);//�摜�������Ă���悤�Ɍ�����悤�ɕ`��
	DrawGraph(-80, mileage % 720, image, FALSE);//�`��

	//DrawFormatString(100, 100, 0xFFFFF, "��������%d", mileage);
	//DrawFormatString(100, 200, 0xFFFFF, "�X�e�[�W���x%d", speed);
}

//�ϐ��̒l��n���B
int Stage::GetSpeed()
{
	return speed;
}

//����������Ԃ��B
int Stage::Getmileage()
{
	return mileage;
}


bool Stage::GetFlg()
{
	return speed_up;
}


