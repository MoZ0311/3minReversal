// TimeBomb class

#pragma once

class TimeBomb
{
public:

	// コンストラクタ
	TimeBomb();

	// 更新処理
	void update();

	// 描画処理
	void draw(const bool canCutCode) const;

private:

	// 時限爆弾の画像テクスチャ
	Texture m_bombTexture;

	// 赤色のコード
	const Rect m_redCode;

	// 青色のコード
	const Rect m_blueCode;

	// 緑色のコード
	const Rect m_greenCode;

	// コードの選択状態
	int selectedColor;
};
