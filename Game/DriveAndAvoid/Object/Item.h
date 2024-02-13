#pragma once
#include "../Utility/SphereCollider.h"
#include"../Utility/common.h"

class Item :
    public SphereCollider
{
private:
    int image; //�A�C�e���摜
    ITEM_TYPE type; //�A�C�e���̎��

public:

    //�R���X�g���N�^
    Item();

    //�f�X�g���N�^
    ~Item();

    //�`��ȉ��̍X�V�����{����
    void Update(int speed);

    //�`��Ɋւ��邱�Ƃ���������
    void Draw() const; //const�́A�l���ς��Ȃ����Ƃ��ؖ�

    void SetRadius(bool a);

    ITEM_TYPE GetType(); //�A�C�e���̎�ޔ���

};

