#pragma once
#include "../Utility/Vector2D.h"

//アイテムの最大数
const int ITEM_MAX = 3;

//画面領域の大きさ
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
    int type; //タイプ
    int image; //画像
    float speed; //速さ
    Vector2D location; //位置情報
    Vector2D box_size; //当たり判定の大きさ

    int gItemImg[2];      //アイテム画像

public:

    //コンストラクタ
    Item(int type, int handle);

    //デストラクタ
    ~Item();

    void Initialize();
    void Update();//描画以下の更新を実施する

    void Update(float speed);//更新処理
    void Draw() const; //constは、値が変わらないことを証明
    void Finalize();//終了時処理

    int GetType()const;//タイプ取得
    //Vector2D GetLocation() const;//位置情報の取得
    //Vector2D GetBoxSize() const;//当たり判定の大きさを取得

};

