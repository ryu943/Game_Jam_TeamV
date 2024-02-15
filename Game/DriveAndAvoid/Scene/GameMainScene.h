#pragma once

#include"SceneBase.h"
#include"../Object/Player.h"
#include"../Object/Enemy.h"
#include "../Object/Item.h"

class GameMainScene : public SceneBase
{
private:
	int high_score; //�n�C�X�R�A
	int back_ground; //�w�i�摜
	int barrier_image; //�o���A�摜
	int mileage; //���s����
	int enemy_image[4];//�G�摜
	int enemy_count[4]; //�ʂ�߂����G�J�E���g
	Player* player; //�v���C���[
	Enemy** enemy; //�G

	Item* item;
	int item_image;

	bool PauseFlg;          //�ꎞ��~�������f

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
	//�n�C�X�R�A�ǂݍ��ݏ���
	void ReadHighScore();
	//�����蔻��
	bool IsHitCheck(Player* P, Enemy* e);
	bool IsItemHitCheck(Player* P, Item* i);
};

