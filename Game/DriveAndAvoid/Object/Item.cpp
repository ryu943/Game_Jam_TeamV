#include "Item.h"
#include"DxLib.h"
#include "../Scene/GameMainScene.h"

Item::Item(int type, int handle) : type(type), image(handle), speed(0.0f),
location(0.0f), box_size(0.0f)
{
	Itemimg = LoadGraph("Resource/images/ha-to.png");
}

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
	speed = (float)(this->type * 1);
}

void Item::Update(float speed)
{
	float x = 0.0f;
	if (type == 1)
	{
		x += 1.0f;
	}
	// �ʒu���Ɉړ��ʂ����Z����
	location += Vector2D(x, this->speed + speed - 6);

}

void Item::Draw() const
{
	//�A�C�e���摜�̕`��
	//DrawGraph(location.x, location.y, 1.0, 0.0, Itemimg, TRUE);
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

}

void Item::Finalize()
{
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