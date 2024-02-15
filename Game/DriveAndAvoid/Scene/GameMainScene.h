#pragma once

#include"SceneBase.h"
#include"../Object/Player.h"
#include"../Object/Enemy.h"
#include "../Object/Item.h"

class GameMainScene : public SceneBase
{
private:
	int high_score; //ハイスコア
	int back_ground; //背景画像
	int barrier_image; //バリア画像
	int mileage; //走行距離
	int enemy_image[4];//敵画像
	int enemy_count[4]; //通り過ぎた敵カウント
	Player* player; //プレイヤー
	Enemy** enemy; //敵

	Item* item;
	int item_image;

	int GameMainBGM;
	int HimeiSE;
	int KaihukuSE;
	

public:
	GameMainScene();
	virtual~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;

	void Finalize();

	virtual eSceneType GetNowScene() const override;

private:
	//ハイスコア読み込み処理
	void ReadHighScore();
	//当たり判定
	bool IsHitCheck(Player* P, Enemy* e);
	bool IsItemHitCheck(Player* P, Item* i);
};

