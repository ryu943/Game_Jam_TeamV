#pragma once
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define WINDOW_HEIGHT 720
#define GAME_UI_LEFT 940

#define WEAKENING 0.5 
#define DEBUFF 1.3

//int型で管理
enum class ITEM_TYPE : int
{
    lifeup, //残機アップ
    speed_reduction, //障害物速度低下
    barrier, // バリア
    speed_up, //障害物速度アップ
    score_up, //スコア
    player_speed_up, //プレイヤーの速度UP
};