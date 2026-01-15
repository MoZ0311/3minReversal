# include "Game.hpp"

// コンストラクタ（初期設定）
Game::Game(const InitData& init)
	: IScene{ init }
{
	// 背景を真っ黒にする
	Scene::SetBackground(Palette::Azure);
}

// 更新処理（入力などを監視）
void Game::update()
{
	// 左クリック or エンターで「Game」へ遷移
	// ※今はGameシーンがないので、遷移しようとするとエラーになりますが、
	//   タイトルを表示するだけならこれでOKです。
	if (MouseL.down() || KeyEnter.down())
	{
		// changeScene(U"Game");
	}
}

// 描画処理（画面を描く）
void Game::draw() const
{

}
