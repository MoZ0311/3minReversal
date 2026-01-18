# include "Result.hpp"

Result::Result(const InitData& init)
	: IScene{ init }
{
}

void Result::update()
{
	// クリックまたはエンターでタイトルへ戻る
	if (MouseL.down() || KeyEnter.down())
	{
		changeScene(U"Title");
	}
}

void Result::draw() const
{
	const GameResult result = getData().result;

	// 結果に応じてメッセージと背景色を変える
	String titleText;
	String subText;
	ColorF bgColor;
	ColorF textColor;

	switch (result)
	{
	case GameResult::Clear:
		titleText = U"MISSION CLEAR";
		subText = U"残り時間: " + Fmt(U"{:.2f}")(getData().remainingTime) + U"秒";
		bgColor = Palette::White;  // クリアは白背景
		textColor = Palette::Black;
		break;

	case GameResult::TimeUp:
		titleText = U"TIME OVER";
		subText = U"作戦失敗：時間切れ";
		bgColor = Palette::Black;  // 失敗は黒背景
		textColor = Palette::Red;
		break;

	case GameResult::Explosion:
		titleText = U"YOU DIED";
		subText = U"作戦失敗：爆発";
		bgColor = Palette::Red;    // 死亡は赤背景
		textColor = Palette::Black;
		break;

	default:
		break;
	}

	Scene::SetBackground(bgColor);

	FontAsset(U"TitleFont")(titleText).drawAt(Scene::Center().movedBy(0, -50), textColor);
	FontAsset(U"MenuFont")(subText).drawAt(Scene::Center().movedBy(0, 50), textColor);

	FontAsset(U"MenuFont")(U"Click to Return").drawAt(Scene::Center().movedBy(0, 150), textColor);
}
