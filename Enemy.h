#pragma once

class Enemy
{
public:
    
    Enemy(int posX, int posY, int radius, int speed, int enemyRespownTimer);

    // アクセッサ
    int GetPosX() const { return posX_; }
    int GetPosY() const { return posY_; }
    int GetRadius() const { return radius_; }
    int GetSpeed() const { return speed_; }
   
    void SetPosX(int x) { posX_ = x; }
    void SetPosY(int y) { posY_ = y; }
    void SetRadius(int radius) { radius_ = radius; }
    void SetSpeed(int speed) { speed_ = speed; }
   
    //更新
    void Move(char* keys, char* preKeys);
    
    //描画
    void Draw();

    //敵の静的メンバ変数の宣言
    static int isEnemyAlive;

private:
   
    int posX_;
    int posY_;
    int radius_;
    int speed_;
    int enemyRespownTimer_;
};
