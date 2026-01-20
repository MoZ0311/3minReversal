// Question class

# include "Question.hpp"
# include "Config.hpp"

using namespace ColorSettings;

Question::Question()
	: isWrongAnswer{ false }
	, correctAnswerCount{ 0 }
	, m_stopWatch{}
	, m_buttonGreen{ Arg::bottomCenter(Scene::Center().movedBy(0, 150)), { 200, 100 } }
	, m_buttonRed{ m_buttonGreen.movedBy(-250, 0)}
	, m_buttonBlue{ m_buttonGreen.movedBy(250, 0) }
	, m_correctColor{ None }
	, m_prevCorrectColor{ None }
	, m_correctColorString{}
	, m_stringColor{ Palette::White }
	, m_currentColor{ None }
	, m_isAsking{ true }
{
	GetRandomColorFlag();
}

void Question::update()
{
	// ボタンにマウスオーバー時、カーソルの形状を変更
	if (m_buttonGreen.mouseOver() || m_buttonRed.mouseOver() || m_buttonBlue.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	// クリックされたコードに応じて、ビットフラグを立てる
	if (m_buttonGreen.leftClicked())
	{
		CheckCollectColor(Green);
	}
	else if (m_buttonRed.leftClicked())
	{
		CheckCollectColor(Red);
	}
	else if (m_buttonBlue.leftClicked())
	{
		CheckCollectColor(Blue);
	}

	// 問題のリセット処理
	if (!m_isAsking && (m_stopWatch.sF() > 0.1))
	{
		m_isAsking = true;
		GetRandomColorFlag();

		const size_t randomColor{ Random<size_t>(2) };
		m_stringColor = CalculateColorFlag(ColorTable[randomColor].colorFlag);

		// 現在の混色状態もリセット
		m_currentColor = None;
	}

	if (KeyW.down())
	{
		isWrongAnswer = true;
	}
}

void Question::draw() const
{
	// 背景オーバーレイの描画
	Rect{ Scene::Size() }.draw(ColorF{ 0, 0.8 });

	// 目標とする色の提示
	FontAsset(U"TitleFont")(m_correctColorString + U"のボタンを押せ")
		.drawAt(48, Scene::Center().movedBy(0, -50), m_stringColor);

	// ボタンが押されたかを、ビット演算で取得し、描画時の厚みを変更
	const double buttonGreenHeight{ m_currentColor & Green ? 0.3 : 1 };
	const double buttonRedHeight{ m_currentColor & Red ? 0.3 : 1 };
	const double buttonBlueHeight{ m_currentColor & Blue ? 0.3 : 1 };

	// 上で計算した厚み(長方形の高さ)をもとに、角を丸めた長方形を描画
	m_buttonGreen.rounded(40, 40, 0, 0).scaleAt(m_buttonGreen.bottomCenter(), { 1, buttonGreenHeight }).draw(Palette::Lime);
	m_buttonRed.rounded(40, 40, 0, 0).scaleAt(m_buttonRed.bottomCenter(), { 1, buttonRedHeight }).draw(Palette::Red);
	m_buttonBlue.rounded(40, 40, 0, 0).scaleAt(m_buttonBlue.bottomCenter(), { 1, buttonBlueHeight }).draw(Palette::Blue);
}

void Question::GetRandomColorFlag()
{
	// 同じ色が連続して抽選されないように
	do
	{
		const size_t index{ Random<size_t>(ColorTable.size() - 1) };
		m_correctColor = ColorTable[index].colorFlag;
		m_correctColorString = ColorTable[index].name;
	} while (m_correctColor == m_prevCorrectColor);

	m_prevCorrectColor = m_correctColor;
}

void Question::CheckCollectColor(const int32 selectedColor)
{
	// 正解の色に含まれないボタンが押されたとき
	if (!(m_correctColor & selectedColor))
	{
		isWrongAnswer = true;
	}

	// 正解の色の一部であるから、ビットに反映
	m_currentColor |= selectedColor;

	// 正解の色と完全に一致したとき
	if (m_correctColor == m_currentColor)
	{
		++correctAnswerCount;
		m_isAsking = false;
	}

	m_stopWatch.restart();
}
