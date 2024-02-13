// Obstacle.h

#pragma once

//#include "Vector2D.h" // ��������΁A�K�v�ȃw�b�_�[�t�@�C�����܂߂܂�
#include "Utility/Vector2D.h"

class Obstacle {
private:
    Vector2D location;
    int image;
public:
    Obstacle(Vector2D loc, int img);
    void Draw() const;
    const Vector2D& GetLocation() const;
};
