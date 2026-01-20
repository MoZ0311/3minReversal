# include "Result.hpp"

Result::Result(const InitData& init)
	: IScene{ init }
	// メンバ変数の初期化（安全のためデフォルト値を入れておく）
	, m_bgColor(Palette::Black)
	, m_textColor(Palette::White)
{
	const GameResult result = getData().result;

	// ★ 判定ロジックをここに移動
	// draw() の中身がスッキリし、処理も1回だけで済みます
	switch (result)
	{
	case GameResult::Clear:
		m_titleText = U"MISSION CLEAR";
		m_subText = U"残り時間: " + Fmt(U"{:.2f}")(getData().remainingTime) + U"秒";
		m_bgColor = Palette::White;
		m_textColor = Palette::Black;
		break;

	case GameResult::TimeUp:
		m_titleText = U"TIME OVER";
		m_subText = U"作戦失敗：時間切れ";
		m_bgColor = Palette::Black;
		m_textColor = Palette::Red;
		break;

	case GameResult::Explosion:
		m_titleText = U"YOU DIED";
		m_subText = U"作戦失敗：爆発";
		m_bgColor = Palette::Red;
		m_textColor = Palette::Black;
		break;

	default:
		// 万が一データがない場合の保険
		m_titleText = U"ERROR";
		m_bgColor = Palette::Gray;
		break;
	}
}

void Result::update()
{
	if (MouseL.down() || KeyEnter.down())
	{
		changeScene(U"Title");
	}
}

void Result::draw() const
{
	// ★ drawは「表示するだけ」にする（超高速！）

	Scene::SetBackground(m_bgColor);

	FontAsset(U"TitleFont")(m_titleText)
		.drawAt(Scene::Center().movedBy(0, -50), m_textColor);

	FontAsset(U"MenuFont")(m_subText)
		.drawAt(Scene::Center().movedBy(0, 50), m_textColor);

	FontAsset(U"MenuFont")(U"Click to Return")
		.drawAt(Scene::Center().movedBy(0, 150), m_textColor);
}
