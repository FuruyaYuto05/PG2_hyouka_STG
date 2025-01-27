#include <Novice.h>
#include "Enemy.h"
#include "Player.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// 敵とプレイヤーのインスタンスを作成
	Enemy* enemy = new Enemy(1140, 100, 20, 5, 120);  // 敵
	Player* player = new Player(640, 600, 10, 20, 120); // プレイヤー

	enum Scene { TITLE, GAME };

	Scene scene = TITLE;
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		switch (scene) {

		case TITLE:

			//GAMEへ移動
			if (keys[DIK_SPACE]) {
				scene = GAME;
			}

			Novice::ScreenPrintf(0, 0, "START = SPACEkey");
			break;

		case GAME:

			// 更新処理
			enemy->Move(keys, preKeys);  // 敵の移動

			player->Update(keys, preKeys, enemy); // プレイヤーの更新（衝突判定も含む）

			//TITLEへ移動
			if (keys[DIK_R]) {
				scene = TITLE;
			}

			// 描画処理
			enemy->Draw();  // 敵の描画

			player->Draw();  // プレイヤーの描画


			Novice::ScreenPrintf(0, 0, "Return to TITLE = Rkey");
			Novice::ScreenPrintf(0, 50, "Shot to Bullet = SPACEkey");
			Novice::ScreenPrintf(0, 100, "Move = W A S Dkey");

			break;
		}
		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}


	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
