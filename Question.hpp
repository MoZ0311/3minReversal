// Question class

#pragma once

class Question
{
public:

	// コンストラクタ
	Question();

	// 更新処理
	void update();

	// 描画処理
	void draw() const;

	// 間違えたボタンを押したか
	bool isWrongAnswer;

	// 正解数
	int32 correctAnswerCount;

private:

	// ランダムな色(ビットフラグで定義される7色)を設定する
	void GetRandomColorFlag();

	// 入力された色と、正解の色との関係性を調べる
	void CheckCollectColor(const int32 selectedColor);

	// 判定まで少し待つためのストップウォッチ
	Stopwatch m_stopWatch;

	// 緑色のボタン
	const Rect m_buttonGreen;

	// 赤色のボタン
	const Rect m_buttonRed;

	// 青色のボタン
	const Rect m_buttonBlue;

	// 正解の色
	int32 m_correctColor;

	// 前の正解の色
	int32 m_prevCorrectColor;

	// 文字
	String m_correctColorString;

	// 文字の色
	Color m_stringColor;

	// 現在の色
	int32 m_currentColor;

	// 出題中か
	bool m_isAsking;
};
