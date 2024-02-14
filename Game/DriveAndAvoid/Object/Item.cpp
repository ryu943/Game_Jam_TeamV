#include "Item.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "../Utility/Vector2D.h"
#include "../Scene/GameMainScene.h"

//アイテムの変数宣言
 struct ITEM gItem[ITEM_MAX];
 //struct ITEM gItem00 = { TRUE, 0, 0, 0, -50, 50, 50, 0, 1 };

//初期化
Item::Item(int type, int handle) : type(type), image(handle), speed(0.0f),
location(0.0f), box_size(0.0f)
{
	////アイテム画像の読込
	//if ((gItemImg[0] = LoadGraph("images/ha-to.png")) == -1);
	//if ((gItemImg[1] = LoadGraph("images/gasoline.bmp")) == -1);
	//
	//for (int i = 0; i < ITEM_MAX; i++) {
	//	if (gItemImg[i] == TRUE) {

	//		//アイテムの表示
	//		DrawRotaGraph(gItem[i].x, gItem[i].y, 1.0f, 0, gItem[i].img, TRUE, FALSE);

	//		//if (gPlayer.flg == FALSE) continue;

	//		//まっすぐ下に移動
	//		gItem[i].y += gItem[i].speed + 50;

	//		//画面をはみ出したら消去
	//		if (gItem[i].y > SCREEN_HEIGHT)
	//			gItem[i].flg = FALSE;

	//		//画面外に行ったら、敵を削除してスコア加算
	//		//if (gItem[i].y >= 640.0f)
	//		//{
	//		//	delete gItem[i];
	//		//}

	//		//当たり判定
	//		//if (HitBoxPlayer(&gPlayer, &gItem[i]) == TRUE) {
	//		//	gItem[i].flg = FALSE;
	//		//	//給油アイテム
	//		//	if (gItem[i].type == 0) {
	//		//		gPlayer.fuel += gItem[i].point;
	//		//	}
	//		//}
	//	}
	//}

	////走行距離ごとに敵出現パターンを制御する
	///*if (gMileage / 10 % 500 == 0) {
	//	CreateItem();
	//}*/

}

//デストラクタ
Item::~Item()
{

}

//初期化処理
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
	//位置情報に移動量を加算する
	location += Vector2D(0.0f, this->speed + speed - 6);
}

void Item::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);
}

void Enemy::Finalize()
{

}

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
