#include "Item.h"

Item::Item(int type, int handle) : type(type), image(handle), speed(0.0f),
location(0.0f), box_size(0.0f)
{
}

Item::~Item()
{
}

void Item::Initialize()
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

void Item::Update(float speed)
{
	float x = 0.0f;
	//
	if (type == 3)
	{
		x += 1.0f;
	}
	// 位置情報に移動量を加算する
	location += Vector2D(x, this->speed + speed - 6);
}

void Item::Draw() const
{
	DrawGraph(location.x, location.y, Itemimg, FALSE);
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
