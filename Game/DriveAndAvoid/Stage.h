#pragma once

class Stage
{
private:
	int image; //�X�e�[�W�摜
	int mileage; //���s����
	int speed; //�X�e�[�W���x
	bool speed_up; //�X�e�[�W�̑��x���オ�����̂�


public:
	//�R���X�g���N�^��������
	Stage();

	//�f�X�g���N�^���������m�ۂ��������폜
	~Stage();

	//�`��ȉ��̍X�V�����{����
	void Update();

	//�`��Ɋւ��邱�Ƃ���������
	void Draw() const;

	//���x��n���B
	int GetSpeed();

	//����������Ԃ��B
	int Getmileage();

	//�t���O�̕Ԃ��B
	bool GetFlg();


};

