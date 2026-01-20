// TimeBomb class

# include "TimeBomb.hpp"

# include "Config.hpp"

using namespace Config;
using namespace ColorSettings;

TimeBomb::TimeBomb()
	: m_bombTexture{ U"image/bomb.png" }
	, m_redCode{ 100, 148, 600, 12 }
	, m_greenCode{ m_redCode.movedBy(0, 100)}
	, m_blueCode{ m_redCode.movedBy(0, 200)}
	, selectedColor{ None }
{

}

void TimeBomb::update()
{
	// コードにマウスオーバー時、カーソルの形状を変更
	if (m_redCode.mouseOver() || m_greenCode.mouseOver() || m_blueCode.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	// クリックされたコードに応じて、ビットフラグを立てる
	if (m_redCode.leftClicked())
	{
		selectedColor |= Red;
	}
	else if (m_greenCode.leftClicked())
	{
		selectedColor |= Green;
	}
	else if (m_blueCode.leftClicked())
	{
		selectedColor |= Blue;
	}

	const Color currentColor{ CalculateColorFlag(selectedColor) };
	Print << currentColor;
}

void TimeBomb::draw(const bool canCutCode) const
{
	// 爆弾のテクスチャ描画
	m_bombTexture.scaled(0.5).drawAt(Scene::Center());

	// コードが切れる状態(ストーリーが終わった)なら、コードを描画
	if (canCutCode)
	{
		Rect{ Scene::Size() }.draw(ColorF{ 0, 0.8 });
		m_redCode.draw(Palette::Red);
		m_greenCode.draw(Palette::Green);
		m_blueCode.draw(Palette::Blue);
	}
}
