# pragma once
# include "Common.hpp"

# include "Question.hpp"
# include "MessageWindow.hpp"
# include "Hint.hpp"

class Game : public App::Scene
{
public:
	Game(const InitData& init);
	void update() override;
	void draw() const override;

private:

	// 必要な正解数
	const int32 m_targetCount;

	// 時限爆弾の画像テクスチャ
	const Texture m_bombTexture;

	// ★修正：Stopwatch ではなく Timer を使います
	Timer m_timer;
	
	// 追加実装
	Question m_question;
	MessageWindow m_messageWindow;
	Hint m_hint;
};
