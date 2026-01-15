#pragma once
# include "Common.hpp"

// タイトル画面クラスの宣言
class Game : public App::Scene
{
public:
	Game(const InitData& init);
	void update() override;
	void draw() const override;
};
