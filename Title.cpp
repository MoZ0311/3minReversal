# include "Title.hpp"

// コンストラクタ（初期設定）
Title::Title(const InitData& init)
	: IScene{ init }
{
	// 背景を真っ黒にする
	Scene::SetBackground(Palette::Black);
}

// 更新処理（入力などを監視）
void Title::update()
{
	// 左クリック or エンターで「Game」へ遷移
	// ※今はGameシーンがないので、遷移しようとするとエラーになりますが、
	//   タイトルを表示するだけならこれでOKです。
	if (MouseL.down() || KeyEnter.down())
	{
		changeScene(U"Game");
	}
}

// 描画処理（画面を描く）
void Title::draw() const
{
	const Point center = Scene::Center();

	// 1. サブタイトル（少し暗い赤）
	FontAsset(U"SubFont")(U"3分クライマックスパズル")
		.drawAt(center.movedBy(0, -120), ColorF(0.7, 0.0, 0.0));

	// 2. メインタイトル（鮮やかな赤）
	FontAsset(U"TitleFont")(U"止まらない\nカウントダウン")
		.drawAt(center.movedBy(0, -20), Palette::Red);

	// 3. "CLICK TO START" の点滅演出
	// 1.5秒周期で透明度を変える
	const double alpha = Periodic::Sine0_1(1.5s);

	FontAsset(U"MenuFont")(U"- CLICK TO START -")
		.drawAt(center.movedBy(0, 150), ColorF(1.0, alpha)); // 白く点滅
}
