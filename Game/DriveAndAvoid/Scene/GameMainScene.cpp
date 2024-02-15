#include"GameMainScene.h"
#include"../Object/RankingData.h"
#include "../Object/Item.h"
#include"DxLib.h"
#include<math.h>

GameMainScene::GameMainScene() : high_score(0), back_ground(NULL),
barrier_image(NULL),
mileage(0), player(nullptr),
enemy(nullptr), item(nullptr)
{
	for (int i = 0; i < 4; i++)
	{
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
}

GameMainScene::~GameMainScene()
{
	//BGM�̍폜
	DeleteSoundMem(GameMainBGM);
	StopSoundMem(GameMainBGM);
}

//����������
void GameMainScene::Initialize()
{
	//�����_�l����������
	ReadHighScore();

	//�摜�̓ǂݍ���
	back_ground = LoadGraph("Resource/images/back.bmp");
	barrier_image = LoadGraph("Resource/images/barrier.png");
	int result = LoadDivGraph("Resource/images/3nin.png", 3, 3, 1, 63, 120,
		enemy_image);
	enemy_image[3] = LoadGraph("Resource/images/uparupa.png");
	//int result = LoadDivGraph("Resource/images/car.bmp", 3, 3, 1, 63, 120, enemy_image);

	item_img[3] = LoadGraph("Resource/images/ha-to.png");

	//BGM�̓ǂݍ���
	((GameMainBGM = LoadSoundMem("Resource/sounds/BGM/main_bgm.wav")) == -1);
	((HimeiSE = LoadSoundMem("Resource/Sounds/SE/�u���킠�[�[�[���I�v.mp3")) == -1);

	//BGM�̉��ʕύX
	ChangeVolumeSoundMem(140, GameMainBGM);

	//�G���[�`�F�b�N
	if (back_ground == -1)
	{
		throw("Resource/images/back.bmp������܂���\n");
	}

	if (result == -1)
	{
		throw("Resource/images/3nin.png������܂���\n");
	}
	if (barrier_image == -1)
	{
		throw("Resource/images/barrier.png������܂���\n");
	}

	//�I�u�W�F�N�g�̏�����
	player = new Player;
	enemy = new Enemy * [10];
	//item = new Item;

	//�I�u�W�F�N�g�̏�����
	player -> Initialize();

	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}

	for (int i = 0; i < 10; i++)
	{
		item[i] = nullptr;
	}

}

//�X�V����
eSceneType GameMainScene::Update()
{
	//BGM�̍Đ�
	if (CheckSoundMem(GameMainBGM) == 0)
	{
		PlaySoundMem(GameMainBGM, DX_PLAYTYPE_LOOP, TRUE);
	}

	//�v���C���[�̍X�V
	player->Update();

	//�ړ������̍X�V
	mileage+= (int)player->GetSpeed() + 5;
	// 1000�i�ނ��Ƃ�speedUP
	if (mileage % 1000 == 0) {
		player->IncreaseSpeed(1.0f); // 1.0f �̒l�𒲐����ăX�s�[�h�̑����ʂ�ς���
	}
	//�G��������
	if (mileage / 20 % 100 == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (enemy[i] == nullptr)
			{
				int type = GetRand(4) % 4;
				enemy[i] = new Enemy(type, enemy_image[type]);
				enemy[i]->Initialize();
				break;
			}
		}
	}

	//�G�̍X�V�Ɠ����蔻��`�F�b�N
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update(player->GetSpeed());

			//��ʊO�ɍs������A�G���폜���ăX�R�A���Z
			if (enemy[i]->GetLocation().y >= 640.0f)
			{
				enemy_count[enemy[i]->GetType()]++;
				enemy[i]->Finalize();
				delete enemy[i];
				enemy[i] = nullptr;
			}

			//�����蔻��̊m�F
			if (IsHitCheck(player, enemy[i]))
			{
				PlaySoundMem(HimeiSE, DX_PLAYTYPE_BACK, TRUE);
				player->SetActive(false);
				player->DecreaseHp(-100.0f);
				enemy[i]->Finalize();
				delete enemy[i];
				enemy[i] = nullptr;			
			}	
		}
	}


	//�A�C�e������
	if (mileage / 20 % 100 == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (item == nullptr)
			{
				int type = GetRand(3) % 3;
				item[i] = new Item(type, item_image[type]);
				//item->Initialize();
				break;
			}
		}
	}
	//�A�C�e���Ƃ̍X�V�Ɠ����蔻��`�F�b�N
	for (int i = 0; i < 10; i++)
	{
		if (item[i] != nullptr)
		{
			enemy[i]->Update(player->GetSpeed());

			//��ʊO�ɍs������A�G���폜���ăX�R�A���Z
			if (enemy[i]->GetLocation().y >= 640.0f)
			{
				enemy_count[enemy[i]->GetType()]++;
				enemy[i]->Finalize();
				delete enemy[i];
				enemy[i] = nullptr;
			}

			//�����蔻��̊m�F
			if (IsHitCheck(player, enemy[i]))
			{
				PlaySoundMem(HimeiSE, DX_PLAYTYPE_BACK, TRUE);
				player->SetActive(false);
				player->DecreaseHp(-100.0f);
				enemy[i]->Finalize();
				delete enemy[i];
				enemy[i] = nullptr;
			}
		}
	}

	// ��Q������
	//if (mileage / 20 % 100 == 0)
	//{
	//	player->SetActive(false);
	//	player->DecreaseHp(-50.0f);
	//	enemy[i]->Finalize();
	//	delete enemy[i];
	//	enemy[i] = nullptr;
	//}
	
	//�v���C���[�̔R�����̗͂�0�����Ȃ�A���U���g�ɓ]�ڂ���
	if (player->GetFuel() < 0.0f || player->GetHp() < 0.0f)
	{
		return eSceneType::E_RESULT;
	}
	return GetNowScene();
}

//�`�揈��
void GameMainScene::Draw() const
{
	//�w�i�摜�̕`��
	DrawGraph(0, mileage % 480 - 480, back_ground, TRUE);
	DrawGraph(0, mileage % 480, back_ground, TRUE);

	//�G�̕`��
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}
	
	//�A�C�e���̕`��
	for (int i = 0; i < 10; i++)
	{
		if (item[i] != nullptr)
		{
			item[i]->Draw();
		}
	}

	//�v���C���[�̕`��
	player->Draw();

	//for (int i = 0; i < 3; i++)
	//{
	//	item->Draw();
	//}

	//Ul�̕`��
	DrawBox(500, 0, 640, 480, GetColor(0, 153, 0), TRUE);
	SetFontSize(16);
	DrawFormatString(510, 20, GetColor(0, 0, 0), "�n�C�X�R�A");
	DrawFormatString(560, 40, GetColor(255, 255, 255), "%08d", high_score);
	DrawFormatString(510, 80, GetColor(0, 0, 0), "��������");
		for (int i = 0; i < 3; i++)
		{
			DrawRotaGraph(523 + (i * 50), 120, 0.3, 0, enemy_image[i], TRUE,
				FALSE);
			DrawFormatString(510 + (i * 50), 140, GetColor(255, 255, 255), "%03d",
				enemy_count[i]);
		}
		DrawFormatString(510, 200, GetColor(0, 0, 0), "���s����");
		DrawFormatString(510, 220, GetColor(255, 255, 255), "%08d", mileage / 10);
		DrawFormatString(510, 240, GetColor(0, 0, 0), "�X�s�[�h");
		DrawFormatString(555, 260, GetColor(255, 255, 255), "%08.1f",
		player->GetSpeed());

	//�o���A�����̕`��
	for (int i = 0; i < player->GetBarriarCount(); i++) {
		DrawRotaGraph(520 + i * 25, 340, 0.2f, 0, barrier_image, TRUE, FALSE);
	}

	//�R���Q�[�W�̕`��
	float fx = 510.0f;
	float fy = 390.0f;
	DrawFormatStringF(fx, fy, GetColor(0, 0, 0), "FUEL METER");
	DrawBoxAA(fx, fy + 20.0f, fx + (player->GetFuel() * 100 / 20000), fy +
		40.0f, GetColor(0, 102, 204), TRUE);
	DrawBoxAA(fx, fy + 20.0f, fx + 100.0f, fy + 40.0f, GetColor(0, 0, 0),
		FALSE);

	//�̗̓Q�[�W�̕`��
	fx = 510.0f;
	fy = 430.0f;
	DrawFormatStringF(fx, fy, GetColor(0, 0, 0), "PLAYER HP");
	DrawBoxAA(fx, fy + 20.0f, fx + (player->GetHp() * 100 / 1000), fy + 40.0f,
		GetColor(255, 0, 0), TRUE);
	DrawBoxAA(fx, fy + 20.0f, fx + 100.0f, fy + 40.0f, GetColor(0, 0, 0),
		FALSE);
}

//�I��������
void GameMainScene::Finalize()
{
	//�X�R�A���v�Z����
	int score = (mileage / 10 * 10);
	for (int i = 0; i < 3; i++)
	{
		score += (i + 1) * 50 * enemy_count[i];
	}

	//���U���h�f�[�^�̏�������
	FILE* fp = nullptr;
	//�t�@�C���I�[�v��
	errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "w");

		//�G���[�`�F�b�N
		if (result != 0)
		{
			throw("Resource/dat/result_data.csv���J���܂���\n");
		}

	//�X�R�A��ۑ�
	fprintf(fp, "%d,\n", score);

	//���������Ɠ��_��ۑ�
	for (int i = 0; i < 3; i++)
	{
		fprintf(fp, "%d,\n", enemy_count[i]);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	//���I�m�ۂ����I�u�W�F�N�g���폜����
	player->Finalize();
	delete player;

	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Finalize();
			delete enemy[i];
			enemy[i] = nullptr;
		}
	}

	delete[] enemy;
}

//���݂̃V�[�������擾
eSceneType GameMainScene::GetNowScene() const
{
	return eSceneType::E_MAIN;
}

//�n�C�X�R�A�̓ǂݍ���
void GameMainScene::ReadHighScore()
{
	RankingData data;
	data.Initialize();

	high_score = data.GetScore(0);

	data.Finalize();
}

//�����蔻�菈��(�v���C���[�G�j
bool GameMainScene::IsHitCheck(Player* p, Enemy* e)
{
	//�v���C���[���o���A�𒣂��Ă�����A�����蔻��𖳎�����
	if (p->IsBarrier())
	{
		return false;
	}

	//�G��񂪂Ȃ���΁A�����蔻��𖳎�����
	if (e == nullptr)
	{
		return false;
	}

	//�ʒu���̍������擾
	Vector2D diff_location = p->GetLocation()-e->GetLocation();

	//�����蔻��T�C�Y�̑傫�����擾
	Vector2D  box_ex = p->GetBoxSize() + e->GetBoxSize();

	//�R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����Ƃ���
	return((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) <
		box_ex.y));
}



