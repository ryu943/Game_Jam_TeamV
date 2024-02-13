#include "Stage.h"
#include"DxLib.h"

#define SPEED_TIMING 100
#define EFFECT_TIME 500

//コンストラクタ
Stage::Stage()
{
	//初期化
	image = LoadGraph("Resource/Images/back.bmp"); //ステージ画像読込み
	mileage = 0;
	speed = 4;
	speed_up = false;
}

//デストラクタ
Stage::~Stage()
{

}

//描画以外の処理
void Stage::Update()
{
	speed_up = false;

	//走行距離を増やしていく
	mileage += speed;

	//走行距離が、3500で割ってあまりが0つまりきれいに割り切れたときに速度UP
	if (mileage % SPEED_TIMING == 0)
	{
		speed += 2;
		speed_up = true;
	}
}

//描画のみ
void Stage::Draw() const
{
	//ステージ描画
	DrawGraph(-80, mileage % 720 - 720, image, FALSE);//画像が続いているように見えるように描画
	DrawGraph(-80, mileage % 720, image, FALSE);//描画

	//DrawFormatString(100, 100, 0xFFFFF, "総合距離%d", mileage);
	//DrawFormatString(100, 200, 0xFFFFF, "ステージ速度%d", speed);
}

//変数の値を渡す。
int Stage::GetSpeed()
{
	return speed;
}

//総合距離を返す。
int Stage::Getmileage()
{
	return mileage;
}


bool Stage::GetFlg()
{
	return speed_up;
}


