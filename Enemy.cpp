#include "Enemy.h"
#include "Novice.h"

int Enemy::isEnemyAlive = true;

Enemy::Enemy(int posX, int posY, int radius, int speed, int enemyRespownTimer)
{
	posX_ = posX;
	posY_ = posY;
	radius_ = radius;
	speed_ = speed;
	enemyRespownTimer_ = enemyRespownTimer;//敵のリスポーンタイマー
}

//===================================================================
// 敵の更新処理
//===================================================================
void Enemy::Move(char* keys, char* preKeys)
{
	//敵の移動
	posX_ += speed_;
	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speed_ *= -1;
	}

	//敵の死んだときの動作
	if (!isEnemyAlive) {
		enemyRespownTimer_ -= 1;
	}

	//敵のリスポーンの動作
	if (enemyRespownTimer_ == 0) {
		isEnemyAlive = true;
		enemyRespownTimer_ = 120;

		// 敵の位置を元に戻す（再出現位置を設定）
		posX_ = 1140;
		posY_ = 100;
	}

	// Rキーで敵を再生する処理
	if (keys[DIK_R] && !preKeys[DIK_R]) {
		isEnemyAlive = true;  // 敵を復活

		// 敵の位置を元に戻す（再出現位置を設定）
		posX_ = 640;
		posY_ = 100;
	}

}


//===================================================================
// 敵の描画処理
//===================================================================
void Enemy::Draw()
{
	// 敵が生きている場合のみ描画
	if (isEnemyAlive) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, 0xffffffff, kFillModeSolid);
	}
}
