#pragma once

#include "Enemy.h"

//前方宣言
class Bullet;

class Player
{
public:
 
    Player(int playerPosX, int playerPosY, int playerSpeed, int playerRadius, int playerRespownTimer); 

    // アクセッサ
    int GetPosX() const { return playerPosX_; }
    int GetPosY() const { return playerPosY_; }
    int GetSpeed() const { return playerSpeed_; }
    int GetRadius() const { return playerRadius_; }

    void SetPosX(int x) { playerPosX_ = x; }
    void SetPosY(int y) { playerPosY_ = y; }
    void SetSpeed(int speed) { playerSpeed_ = speed; }
    void SetRadius(int radius) { playerRadius_ = radius; }

    // 更新
    void Update(char* keys, char* preKeys, Enemy* enemy);

    // 描画
    void Draw();

    //自機の静的メンバ変数の宣言
    static int isPlayerAlive;

private:
   
    int playerPosX_;
    int playerPosY_;
    int playerRadius_;
    int playerSpeed_;
    int playerRespownTimer_;
   
    Bullet* bullet_;
};