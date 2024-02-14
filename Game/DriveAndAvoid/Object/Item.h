#pragma once
#include "../Utility/Vector2D.h"

class Item
{
private:
    int type;//タイプ
    int image; //アイテム画像
    float speed; //速さ
    Vector2D location; //位置情報
    Vector2D box_size; //当たり判定の大きさ

public:

    //コンストラクタ
    Item(int type, int handle);

    //デストラクタ
    ~Item();

    void Initialize();//初期化処理
    void Update(float speed);//描画以下の更新を実施する

    //描画に関することを実装する
    void Draw() const; //constは、値が変わらないことを証明

    int GetType()const;//タイプ取得
    Vector2D GetLocation() const;//位置情報の取得
    Vector2D GetBoxSize() const;//当たり判定の大きさを取得

};

