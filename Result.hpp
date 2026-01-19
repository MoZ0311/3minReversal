# pragma once
# include "Common.hpp"

class Result : public App::Scene
{
public:
	Result(const InitData& init);
	void update() override;
	void draw() const override;

private:
	// ★ ここに保存用の変数を追加
	String m_titleText;
	String m_subText;
	ColorF m_bgColor;
	ColorF m_textColor;
};
