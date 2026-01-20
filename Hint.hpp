// Hint class

#pragma once

class Hint
{
public:

	// コンストラクタ
	Hint();

	// 更新処理
	void update();

	// 描画処理
	void draw() const;

private:

	// ヒント表示中か
	bool m_isDisplayingHint;

	// ヒントのトグルボタン
	const Rect m_hintButton;

	// ヒントの画像テクスチャ
	const Texture m_hintTexture;
};
