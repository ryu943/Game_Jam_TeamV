#pragma once

class Stage
{
private:
	int image; //ステージ画像
	int mileage; //走行距離
	int speed; //ステージ速度
	bool speed_up; //ステージの速度が上がったのか


public:
	//コンストラクタ→初期化
	Stage();

	//デストラクタ→メモリ確保した物を削除
	~Stage();

	//描画以下の更新を実施する
	void Update();

	//描画に関することを実装する
	void Draw() const;

	//速度を渡す。
	int GetSpeed();

	//総合距離を返す。
	int Getmileage();

	//フラグの返す。
	bool GetFlg();


};

