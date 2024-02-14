#pragma once
#include "../Utility/Vector2D.h"

//�A�C�e���̍ő吔
const int ITEM_MAX = 3;

//��ʗ̈�̑傫��
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

struct ITEM
    {
        int flg;
        int x, y, w, h;
        int img;
        int speed;
    };

class Item
{
private:
    int type; //�^�C�v
    int image; //�摜
    float speed; //����
    Vector2D location; //�ʒu���
    Vector2D box_size; //�����蔻��̑傫��

    int gItemImg[2];      //�A�C�e���摜

public:

    //�R���X�g���N�^
    Item(int type, int handle);

    //�f�X�g���N�^
    ~Item();

    void Initialize();
    void Update();//�`��ȉ��̍X�V�����{����

    void Update(float speed);//�X�V����
    void Draw() const; //const�́A�l���ς��Ȃ����Ƃ��ؖ�
    void Finalize();//�I��������

    int GetType()const;//�^�C�v�擾
    //Vector2D GetLocation() const;//�ʒu���̎擾
    //Vector2D GetBoxSize() const;//�����蔻��̑傫�����擾

};

