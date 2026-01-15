# pragma once
# include "Common.hpp"

// タイトル画面クラスの宣言
class Title : public App::Scene
{
public:
	Title(const InitData& init);
	void update() override;
	void draw() const override;
};
