# include "Common.hpp"
# include "Title.hpp"
# include "Game.hpp"
# include "Result.hpp" // ★追加1
# include "Config.hpp"

using namespace Assets;

void Main()
{
	FontAsset::Register(U"TitleFont", 80, Typeface::Heavy);
	FontAsset::Register(U"SubFont", 30, Typeface::Bold);
	FontAsset::Register(U"MenuFont", 24, Typeface::Regular);

	Assets::RegisterAssets();

	App manager;
	manager.add<Title>(U"Title");
	manager.add<Game>(U"Game");
	manager.add<Result>(U"Result"); // ★追加2：リザルトを登録

	manager.init(U"Title");

	while (System::Update())
	{
		ClearPrint();
		if (not manager.update())
		{
			break;
		}
	}
}
