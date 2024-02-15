#include"Enemy.h"
#include"DxLib.h"
#include "../Scene/GameMainScene.h"
int Enemy::image1;
Enemy::Enemy(int type, int handle) : type(type), image(handle), speed(0.0f),
location(0.0f), box_size(0.0f)
{

}
Enemy::~Enemy()
{

}

//����������
void Enemy::Initialize()
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

void Enemy::Update(float speed)
{
	float x = 0.0f;
	//
	if (type == 3)
	{
		//x += 2.0f;
		x = -1.0f;
	}
	// �ʒu���Ɉړ��ʂ����Z����
	location += Vector2D(x, this->speed + speed - 6);
}

void Enemy::Draw()const
{
	//�G�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);
	//DrawGraph(location.x, location.y, );
	//DrawGraph(location.x, location.y, newImage, FALSE);
	//DrawRotaGraph(location.x, location.y, 1.0, 0.0, image1, TRUE);
}

void Enemy::Finalize()
{

}

void Enemy::LoadImages()
{
	//image1 = LoadGraph("Resource/Images/gomi.png");
}

//void Enemy::DeleteImages()
//{
//	DeleteGraph(image1);
//}



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