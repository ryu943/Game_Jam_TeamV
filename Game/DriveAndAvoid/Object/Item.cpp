#include "Item.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "../Utility/Vector2D.h"
#include "../Scene/GameMainScene.h"

//�A�C�e���̕ϐ��錾
 struct ITEM gItem[ITEM_MAX];
 //struct ITEM gItem00 = { TRUE, 0, 0, 0, -50, 50, 50, 0, 1 };

//������
Item::Item(int type, int handle) : type(type), image(handle), speed(0.0f),
location(0.0f), box_size(0.0f)
{
	////�A�C�e���摜�̓Ǎ�
	//if ((gItemImg[0] = LoadGraph("images/ha-to.png")) == -1);
	//if ((gItemImg[1] = LoadGraph("images/gasoline.bmp")) == -1);
	//
	//for (int i = 0; i < ITEM_MAX; i++) {
	//	if (gItemImg[i] == TRUE) {

	//		//�A�C�e���̕\��
	//		DrawRotaGraph(gItem[i].x, gItem[i].y, 1.0f, 0, gItem[i].img, TRUE, FALSE);

	//		//if (gPlayer.flg == FALSE) continue;

	//		//�܂��������Ɉړ�
	//		gItem[i].y += gItem[i].speed + 50;

	//		//��ʂ��͂ݏo���������
	//		if (gItem[i].y > SCREEN_HEIGHT)
	//			gItem[i].flg = FALSE;

	//		//��ʊO�ɍs������A�G���폜���ăX�R�A���Z
	//		//if (gItem[i].y >= 640.0f)
	//		//{
	//		//	delete gItem[i];
	//		//}

	//		//�����蔻��
	//		//if (HitBoxPlayer(&gPlayer, &gItem[i]) == TRUE) {
	//		//	gItem[i].flg = FALSE;
	//		//	//�����A�C�e��
	//		//	if (gItem[i].type == 0) {
	//		//		gPlayer.fuel += gItem[i].point;
	//		//	}
	//		//}
	//	}
	//}

	////���s�������ƂɓG�o���p�^�[���𐧌䂷��
	///*if (gMileage / 10 % 500 == 0) {
	//	CreateItem();
	//}*/

}

//�f�X�g���N�^
Item::~Item()
{

}

//����������
void Item::Initialize()
{
	//�o��������x���W�p�^�[�����擾
	float random_x = (float)(GetRand(4) * 105 + 40);
	//���Y�ʒu�̐ݒ�
	location = Vector2D(random_x, -50.0f);
	//�����蔻��̐ݒ�
	box_size = Vector2D(31.0f, 60.0f);
	//�����̐ݒ�
	speed = (float)(this->type * 2);
}

void Item::Update(float speed)
{
	//�ʒu���Ɉړ��ʂ����Z����
	location += Vector2D(0.0f, this->speed + speed - 6);
}

void Item::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);
}

void Enemy::Finalize()
{

}

//�G�̃^�C�v���擾
int Enemy::GetType() const
{
	return type;
}

//�ʒu�����擾
Vector2D Enemy::GetLocation()const
{
	return location;
}

//�����蔻��̑傫�����擾
Vector2D Enemy::GetBoxSize()const
{
	return box_size;
}
