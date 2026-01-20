// MessageWindow class

# include "MessageWindow.hpp"

# include "Config.hpp"

using namespace Config;
using namespace Assets;

MessageWindow::MessageWindow()
	: completedCSV{ false }
	, m_csv{}
	, m_rowIndex{ 0 }
	, m_messageText{}
	, m_displayTextLength{ 0 }
	, m_finishSentence{ true }
{

}

void MessageWindow::update()
{
	// CSVが空であれば、早期return
	if (m_csv.isEmpty())
	{
		return;
	}

	// 設定した秒数で文字送り
	m_displayTextLength += 1 / TypeInterval * Scene::DeltaTime();

	// テキストの表示が済んでいるか
	if (m_displayTextLength > m_messageText.length())
	{
		m_finishSentence = true;
	}
	else
	{
		m_finishSentence = false;
	}

	// 左クリックでテキスト送り
	if (MouseL.down())
	{
		getNextMessage();
	}	
}

void MessageWindow::draw() const
{
	// ウィンドウ描画
	const RoundRect textWindow{
		0, Scene::Size().y - MessageWindowHeight,
		Scene::Size().x, MessageWindowHeight, BorderRadius
	};
	textWindow.draw(Palette::Midnightblue).drawFrame(FrameThickness, 0, ColorF{ 0.8 });

	// テキスト描画
	FontAsset(Mamelon)(m_messageText.substr(0, static_cast<size_t>(m_displayTextLength))).draw(FontSize, FrameThickness * 2 + FontSize / 2.0, Scene::Size().y - MessageWindowHeight + FontSize / 2.0);
}

void MessageWindow::getNextMessage()
{
	if (m_finishSentence)
	{
		if (m_rowIndex < m_csv.rows())
		{
			// 次の行へ
			m_messageText = m_csv[m_rowIndex++][0];
			m_displayTextLength = 0;
		}
		else
		{
			// 一つのCSVを全て読み終えた
			m_csv.clear();
			m_rowIndex = 0;
			m_messageText.clear();

			completedCSV = true;
		}
	}
	else
	{
		m_displayTextLength = static_cast<double>(m_messageText.length());
	}
}

void MessageWindow::setCSV(const FilePath& path)
{
	// CSVが空の時のみ、読み込む
	if (m_csv.isEmpty())
	{
		completedCSV = false;
		m_csv.load(path);
		m_displayTextLength = 0;
		getNextMessage();
	}
}
