#include "Item.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

//初期化
Item::Item()
{
	//アイテムの効果をランダムで決める
	int a = GetRand(5);

	//キャスト<変換元>(変換するやつ)
	//         int      ←float
	type = static_cast<ITEM_TYPE>(a);
	location.x = GetRand(900);
	location.y = -100;
	radius = 20;

	switch (type)
	{
	case ITEM_TYPE::lifeup:
		image = LoadGraph("Resources/Images/ha-to.png");
		break;
	case ITEM_TYPE::speed_reduction:
		image = LoadGraph("Resources/Images/speed_downstream.png");
		break;
	case ITEM_TYPE::barrier:
		image = LoadGraph("Resources/Images/無敵.png");
		break;
	case ITEM_TYPE::speed_up:
		image = LoadGraph("Resources/Images/speed_up.png");
		break;
	case ITEM_TYPE::score_up:
		image = LoadGraph("Resources/Images/23269489.png");
		break;
	case ITEM_TYPE::player_speed_up:
		image = LoadGraph("Resources/Images/player_speed.png");
		break;
	default:
		break;
	}

}

//デストラクタ
Item::~Item()
{

}

//描画以外の処理の更新
void Item::Update(int speed)
{
	location.y += speed;
}


//描画のみ
void Item::Draw() const
{
	DrawRotaGraph(location.x, location.y, 1.5f, (M_PI / 180), image, TRUE);
	//DrawCircle(location.x, location.y, radius, GetColor(255, 0, 0), TRUE);
}

void Item::SetRadius(bool a)
{
	if (a)
	{
		radius = 60;
	}
	else
	{
		radius = 20;
	}
}

ITEM_TYPE Item::GetType()
{
	return type;
}
