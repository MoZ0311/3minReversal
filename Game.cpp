# include "Game.hpp"

Game::Game(const InitData& init)
	: IScene{ init }
{
	Scene::SetBackground(ColorF(0.2, 0.2, 0.25));

	// ★修正：Timerに「3分」をセットして開始
	m_timer.set(3min);
	m_timer.start();

	m_rectRed = Rect(150, 300, 100, 200);
	m_rectBlue = Rect(350, 300, 100, 200);
	m_rectYellow = Rect(550, 300, 100, 200);
}

void Game::update()
{
	// 1. 時間切れチェック
	if (m_timer.reachedZero())
	{
		// データを保存
		getData().result = GameResult::TimeUp;
		getData().remainingTime = 0.0;

		// リザルトへ遷移
		changeScene(U"Result");
	}

	// (開発用) 強制的にクリアするテストキー: [C]
	if (KeyC.down())
	{
		m_timer.pause(); // タイマーを止める
		getData().result = GameResult::Clear;
		getData().remainingTime = m_timer.remaining().count(); // 残り時間を保存
		changeScene(U"Result");
	}

	// (開発用) 強制的に爆発するテストキー: [E]
	if (KeyE.down())
	{
		getData().result = GameResult::Explosion;
		getData().remainingTime = 0.0;
		changeScene(U"Result");
	}
}

void Game::draw() const
{
	// --- タイマー表示（計算式を修正） ---
	// 残り時間を「整数（int）」の秒数として取り出す
	const int32 timeLeft = (int32)m_timer.remaining().count();

	// 分と秒に計算する
	const int32 m = timeLeft / 60;
	const int32 s = timeLeft % 60;

	// 表示（00:00 形式）
	FontAsset(U"TitleFont")(Fmt(U"{:02}:{:02}")(m, s))
		.drawAt(Scene::Center().x, 100, Palette::White);


	// --- レバー描画 ---
	m_rectRed.draw(Palette::Red);
	m_rectBlue.draw(Palette::Blue);
	m_rectYellow.draw(Palette::Yellow);

	FontAsset(U"MenuFont")(U"SAFE").drawAt(m_rectRed.bottomCenter().movedBy(0, 30));
	FontAsset(U"MenuFont")(U"DANGER").drawAt(m_rectBlue.bottomCenter().movedBy(0, 30));
	FontAsset(U"MenuFont")(U"SAFE").drawAt(m_rectYellow.bottomCenter().movedBy(0, 30));

	FontAsset(U"MenuFont")(U"「最初に疑え」").drawAt(Scene::Center().x, 200, Palette::Gray);
}
