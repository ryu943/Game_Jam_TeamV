#pragma once
#include "../Utility/Vector2D.h"

class Item
{
private:
    int type;//�^�C�v
    int image; //�A�C�e���摜
    float speed; //����
    Vector2D location; //�ʒu���
    Vector2D box_size; //�����蔻��̑傫��

public:

    //�R���X�g���N�^
    Item(int type, int handle);

    //�f�X�g���N�^
    ~Item();

    void Initialize();//����������
    void Update(float speed);//�`��ȉ��̍X�V�����{����

    //�`��Ɋւ��邱�Ƃ���������
    void Draw() const; //const�́A�l���ς��Ȃ����Ƃ��ؖ�

    int GetType()const;//�^�C�v�擾
    Vector2D GetLocation() const;//�ʒu���̎擾
    Vector2D GetBoxSize() const;//�����蔻��̑傫�����擾

};

