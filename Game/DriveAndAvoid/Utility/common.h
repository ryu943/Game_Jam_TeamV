#pragma once
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define WINDOW_HEIGHT 720
#define GAME_UI_LEFT 940

#define WEAKENING 0.5 
#define DEBUFF 1.3

//int�^�ŊǗ�
enum class ITEM_TYPE : int
{
    lifeup, //�c�@�A�b�v
    speed_reduction, //��Q�����x�ቺ
    barrier, // �o���A
    speed_up, //��Q�����x�A�b�v
    score_up, //�X�R�A
    player_speed_up, //�v���C���[�̑��xUP
};