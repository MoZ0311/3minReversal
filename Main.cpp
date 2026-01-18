# include "Common.hpp"
# include "Title.hpp"
# include "Game.hpp"
# include "Result.hpp" // ★追加1

void Main()
{
	FontAsset::Register(U"TitleFont", 80, Typeface::Heavy);
	FontAsset::Register(U"SubFont", 30, Typeface::Bold);
	FontAsset::Register(U"MenuFont", 24, Typeface::Regular);

	App manager;
	manager.add<Title>(U"Title");
	manager.add<Game>(U"Game");
	manager.add<Result>(U"Result"); // ★追加2：リザルトを登録

	manager.init(U"Title");

	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
	}
}
