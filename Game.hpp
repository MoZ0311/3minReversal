# pragma once
# include "Common.hpp"

class Game : public App::Scene
{
public:
	Game(const InitData& init);
	void update() override;
	void draw() const override;

private:
	// ★修正：Stopwatch ではなく Timer を使います
	Timer m_timer;

	Rect m_rectRed;
	Rect m_rectBlue;
	Rect m_rectYellow;
};
