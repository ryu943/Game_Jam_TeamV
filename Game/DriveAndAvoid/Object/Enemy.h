#pragma once
#include"../Utility/Vector2D.h"
#include "DxLib.h"
class Enemy
{
private:
	int type; //�^�C�v
	int image; //�摜
	static int image1;
	float speed; //����
	Vector2D location; //�ʒu���
	Vector2D box_size; //�����蔻��̑傫��
	//int newImage = LoadGraph("Resorce/images/gomi.png");
public:
	Enemy(int type, int handle); 
	~Enemy();

	void Initialize();//����������
	void Update(float speed);//�X�V����
	void Draw()const;//�`�揈��
	void Finalize();//�I��������
	static void LoadImages();
	static void DeleteImages();
	int GetType()const;//�^�C�v�擾
	Vector2D GetLocation() const;//�ʒu���̎擾
	Vector2D GetBoxSize() const;//�����蔻��̑傫�����擾
};