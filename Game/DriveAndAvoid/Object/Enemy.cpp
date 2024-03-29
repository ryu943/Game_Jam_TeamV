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

//初期化処理
void Enemy::Initialize()
{
	//出現させるx座標パターンを取得
	float random_x = (float)(GetRand(4) * 105 + 40);
	//生産位置の設定
	location = Vector2D(random_x, -50.0f);
	//当たり判定の設定
	box_size = Vector2D(31.0f, 60.0f);
	//速さの設定
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
	// 位置情報に移動量を加算する
	location += Vector2D(x, this->speed + speed - 6);
}

void Enemy::Draw()const
{
	//敵画像の描画
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



//敵のタイプを取得
int Enemy::GetType() const
{
	return type;
}

//位置情報を取得
Vector2D Enemy::GetLocation()const
{
	return location;
}

//当たり判定の大きさを取得
Vector2D Enemy::GetBoxSize()const
{
	return box_size;
}