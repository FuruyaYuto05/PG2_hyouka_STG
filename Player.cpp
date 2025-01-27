#include "Novice.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

int Player::isPlayerAlive = true;

Player::Player(int playerPosX, int playerPosY, int playerSpeed, int playerRadius, int playerRespownTimer)
{
	playerPosX_ = playerPosX;
	playerPosY_ = playerPosY;
	playerRadius_ = playerRadius;
	playerSpeed_ = playerSpeed;
	playerRespownTimer_ = playerRespownTimer;

	// 弾の初期化
	bullet_ = new Bullet(playerPosX_, playerPosY_, 10, 10);
}

//===================================================================
// 自機の更新処理
//===================================================================
void Player::Update(char* keys, char* preKeys, Enemy* enemy)
{
	if (isPlayerAlive) {
		// プレイヤーの移動処理
		if (keys[DIK_W]) {
			playerPosY_ -= playerSpeed_;
		}
		if (keys[DIK_A]) {
			playerPosX_ -= playerSpeed_;
		}
		if (keys[DIK_S]) {
			playerPosY_ += playerSpeed_;
		}
		if (keys[DIK_D]) {
			playerPosX_ += playerSpeed_;
		}

		// 弾の発射処理
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !bullet_->isShot) {
			bullet_->SetPosX(playerPosX_);
			bullet_->SetPosY(playerPosY_);
			bullet_->isShot = true;
		}
	}
	// 弾の更新処理
	bullet_->Update();

	// 弾と敵との衝突判定
	if (bullet_->isShot) {
		// 弾が敵に当たった場合
		if (enemy->isEnemyAlive) {
			if (bullet_->GetPosX() > enemy->GetPosX() - enemy->GetRadius() &&
				bullet_->GetPosX() < enemy->GetPosX() + enemy->GetRadius() &&
				bullet_->GetPosY() > enemy->GetPosY() - enemy->GetRadius() &&
				bullet_->GetPosY() < enemy->GetPosY() + enemy->GetRadius()) {
				enemy->isEnemyAlive = false;  // 敵を消す
				bullet_->isShot = false;  // 弾を消す
			}
		}
	}

	// 自機が敵に当たった時
	if (playerPosX_ + playerRadius_ > enemy->GetPosX() - enemy->GetRadius() &&
		playerPosX_ - playerRadius_ < enemy->GetPosX() + enemy->GetRadius() &&
		playerPosY_ + playerRadius_ > enemy->GetPosY() - enemy->GetRadius() &&
		playerPosY_ - playerRadius_ < enemy->GetPosY() + enemy->GetRadius()) {
		isPlayerAlive = false;  // 敵を消す
	}

	//自機の死んだときの動作
	if (!isPlayerAlive) {
		playerRespownTimer_ -= 1;
		playerPosX_ = 640;
		playerPosY_ = 540;
	}

	//自機のリスポーンの動作
	if (playerRespownTimer_ == 0) {
		isPlayerAlive = true;
		playerRespownTimer_ = 120;
	}

}

//===================================================================
// 自機の描画処理
//===================================================================
void Player::Draw()
{
	// 弾の描画
	bullet_->Draw();

	// 自機が生きているときの描画
	if (isPlayerAlive) {
		Novice::DrawEllipse(playerPosX_, playerPosY_, playerRadius_, playerRadius_, 0.0f, 0xffffffff, kFillModeSolid);
	}
}
