// Hint class

# include "Hint.hpp"

Hint::Hint()
	: m_isDisplayingHint{ false }
	, m_hintButton{ Arg::topRight(Scene::Width(), 0), { 48, 48 } }
	, m_hintTexture{ U"image/hint.png" }
{

}

void Hint::update()
{
	if (m_hintButton.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);

		if (MouseL.down())
		{
			m_isDisplayingHint = !m_isDisplayingHint;
		}
	}
}

void Hint::draw() const
{
	if (m_isDisplayingHint)
	{
		const double textureScale{ 0.45 };
		m_hintTexture.scaled(textureScale).draw(Scene::Size().x - m_hintTexture.width() * textureScale, 0, ColorF{ 1, 0.8 });
	}

	m_hintButton.draw(Palette::White);
	const char icon{ m_isDisplayingHint ? 'X' : '!' };
	FontAsset(U"TitleFont")(icon).drawAt(36, m_hintButton.center(), Palette::Black);
}
