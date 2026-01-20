# pragma once
# include "Common.hpp"

# include "TimeBomb.hpp"
# include "MessageWindow.hpp"

class Game : public App::Scene
{
public:
	Game(const InitData& init);
	void update() override;
	void draw() const override;

private:
	// ★修正：Stopwatch ではなく Timer を使います
	Timer m_timer;
	
	// 追加実装
	TimeBomb m_timeBomb;
	MessageWindow m_messageWindow;
};
