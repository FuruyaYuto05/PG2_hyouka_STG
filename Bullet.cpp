#include "Novice.h"
#include "Bullet.h"

int Bullet::isShot = false;

Bullet::Bullet(int posX, int posY, int radius, int speed) {

	bulletPosX_ = posX;
	bulletPosY_ = posY;
	bulletRadius_ = radius;
	bulletSpeed_ = speed;
	
}

//===================================================================
// 敵の更新処理
//===================================================================
void Bullet::Update()
{
	//弾が打たれてる時の挙動
	if (isShot) {
		bulletPosY_ -= bulletSpeed_;
	}

	//弾が画面上端についたとき
	if (bulletPosY_ <= 0) {
		isShot = false;
	}
}

//===================================================================
// 敵の描画処理
//===================================================================
void Bullet::Draw()
{
	//撃たれている時の弾の描画
	if (isShot) {
		Novice::DrawEllipse(bulletPosX_, bulletPosY_, bulletRadius_, bulletRadius_, 0.0f, 0xffffffff, kFillModeSolid);
	}
}