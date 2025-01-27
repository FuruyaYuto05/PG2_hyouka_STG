#pragma once

class Bullet
{
public:
    
    Bullet(int posX, int posY, int radius, int speed);

    // アクセッサ
    int GetPosX() const { return bulletPosX_; }
    int GetPosY() const { return bulletPosY_; }
    int GetRadius() const { return bulletRadius_; }
    int GetSpeed() const { return bulletSpeed_; }

    void SetPosX(int x) { bulletPosX_ = x; }
    void SetPosY(int y) { bulletPosY_ = y; }
    void SetRadius(int radius) { bulletRadius_ = radius; }
    void SetSpeed(int speed) { bulletSpeed_ = speed; } 

    //更新
    void Update();
    
    //描画
    void Draw();

    //弾の静的メンバ変数の宣言
    static int isShot;

private:

    int bulletPosX_;
    int bulletPosY_;
    int bulletSpeed_;
    int bulletRadius_;

};

