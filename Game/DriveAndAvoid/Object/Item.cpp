#include "Item.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "../Utility/Vector2D.h"
#include "../Scene/GameMainScene.h"

//初期化
Item::Item(int type, int handle) : type(type), image(handle), speed(0.0f),
location(0.0f), box_size(0.0f)
{

}

//デストラクタ
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

//描画以外の処理の更新
void Item::Update(float speed)
{
	//位置情報に移動量を加算する
	location += Vector2D(0.0f, this->speed + speed - 6);
}

//描画の
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