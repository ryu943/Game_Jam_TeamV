#pragma once
#include "../Utility/SphereCollider.h"
#include"../Utility/common.h"

class Item :
    public SphereCollider
{
private:
    int image; //アイテム画像
    ITEM_TYPE type; //アイテムの種類

public:

    //コンストラクタ
    Item();

    //デストラクタ
    ~Item();

    //描画以下の更新を実施する
    void Update(int speed);

    //描画に関することを実装する
    void Draw() const; //constは、値が変わらないことを証明

    void SetRadius(bool a);

    ITEM_TYPE GetType(); //アイテムの種類判別

};

