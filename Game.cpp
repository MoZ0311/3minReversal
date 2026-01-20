# include "Game.hpp"
# include "Config.hpp"

using namespace Assets;
Game::Game(const InitData& init)
	: IScene{ init }
	, m_targetCount{ 30 }
	, m_bombTexture{ U"image/bomb.png" }
	, m_timer{ 3min }
	, m_question{}
	, m_messageWindow{}
	, m_hint{}
{
	Scene::SetBackground(ColorF(0.2, 0.2, 0.25));

	// 最初のCSV設定
	m_messageWindow.setCSV(Assets::PrologueCSV);

	// タイマースタート
	m_timer.start();
}

void Game::update()
{
	if (m_messageWindow.completedCSV)
	{
		m_question.update();
		m_hint.update();
	}
	else
	{
		m_messageWindow.update();
	}

	// 1. 時間切れチェック
	if (m_timer.reachedZero())
	{
		// データを保存
		getData().result = GameResult::TimeUp;
		getData().remainingTime = 0.0;

		// リザルトへ遷移
		changeScene(U"Result");
	}

	// 指定の正解数を達成したとき/強制的にクリアするテストキー: [C]
	if (m_question.correctAnswerCount >= m_targetCount || KeyC.down())
	{
		m_timer.pause(); // タイマーを止める
		getData().result = GameResult::Clear;
		getData().remainingTime = m_timer.remaining().count(); // 残り時間を保存
		changeScene(U"Result");
	}

	// 間違えたボタンを押したとき
	if (m_question.isWrongAnswer)
	{
		getData().result = GameResult::Explosion;
		getData().remainingTime = 0.0;
		changeScene(U"Result");
	}

	// 時間切れ用のデバッグキー: [T]
	if (KeyT.down())
	{
		m_timer.set(0s);
	}	
}

void Game::draw() const
{
	// 爆弾のテクスチャ描画
	m_bombTexture.scaled(0.5).drawAt(Scene::Center());

	if (m_messageWindow.completedCSV)
	{
		m_question.draw();
		m_hint.draw();
	}
	else
	{
		m_messageWindow.draw();
	}

	// --- タイマー表示（計算式を修正） ---
	// 残り時間を「整数（int）」の秒数として取り出す
	const int32 timeLeft = (int32)m_timer.remaining().count();

	// 分と秒に計算する
	const int32 m = timeLeft / 60;
	const int32 s = timeLeft % 60;

	// 表示（00:00 形式）
	FontAsset(U"TitleFont")(Fmt(U"{:02}:{:02}")(m, s))
		.drawAt(Scene::Center().x, 50, Palette::White);
}
