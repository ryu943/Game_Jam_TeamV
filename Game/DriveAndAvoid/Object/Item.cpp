#include "Item.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "../Utility/Vector2D.h"
#include "../Scene/GameMainScene.h"

//������
Item::Item(int type, int handle) : type(type), image(handle), speed(0.0f),
location(0.0f), box_size(0.0f)
{

}

//�f�X�g���N�^
Item::~Item()
{

}

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

//�`��ȊO�̏����̍X�V
void Item::Update(float speed)
{
	//�ʒu���Ɉړ��ʂ����Z����
	location += Vector2D(0.0f, this->speed + speed - 6);
}

//�`���
void Item::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);
}

int Item::GetType() const
{
	return type;
}

Vector2D Item::GetLocation() const
{
	return location;
}

Vector2D Item::GetBoxSize() const
{
	return box_size;
}