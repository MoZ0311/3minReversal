# include "Common.hpp"
# include "Title.hpp"

void Main()
{
	// --- アセット登録（フォントの準備） ---
	// メインタイトル用（極太・サイズ80）
	FontAsset::Register(U"TitleFont", 80, Typeface::Heavy);
	// サブタイトル用（太字・サイズ30）
	FontAsset::Register(U"SubFont", 30, Typeface::Bold);
	// メニュー用（普通・サイズ24）
	FontAsset::Register(U"MenuFont", 24, Typeface::Regular);

	// --- シーンの設定 ---
	App manager;
	manager.add<Title>(U"Title");

	// --- ゲームループ ---
	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
	}
}
