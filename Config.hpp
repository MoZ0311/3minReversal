# pragma once

namespace Config
{
	// メッセージウィンドウの高さ
	static inline constexpr int32 MessageWindowHeight{ 104 };

	// メッセージウィンドウの枠の太さ
	static inline constexpr int32 FrameThickness{ 4 };

	// メッセージウィンドウの角の丸さ
	static inline constexpr int32 BorderRadius{ 8 };

	// 文字送り間隔
	static inline constexpr double TypeInterval{ 0.07 };

	// フォントサイズ
	static inline constexpr int32 FontSize{ 32 };
}

namespace ColorSettings
{
	enum ColorFlag
	{
		None = 0,
		Red = 1 << 0,
		Green = 1 << 1,
		Blue = 1 << 2
	};

	struct ColorInfo
	{
		int32 colorFlag;
		String name;
	};

	static inline const Array<ColorInfo> ColorTable
	{
		{ Red,                   U"赤色" },
		{ Green,                 U"緑色" },
		{ Blue,                  U"青色" },
		{ Red | Green,           U"黄色" },
		{ Red | Blue,            U"マゼンタ" },
		{ Green | Blue,          U"シアン" },
		{ Red | Green | Blue,    U"白色" }
	};

	static inline Color CalculateColorFlag(int32 colorFlag)
	{
		switch (colorFlag)
		{
		case Red:
			return Palette::Red;

		case Green:
			return Palette::Green;

		case Blue:
			return Palette::Blue;

		case (Red | Green):
			return Palette::Yellow;

		case (Red | Blue):
			return Palette::Magenta;

		case (Green | Blue):
			return Palette::Cyan;

		case (Red | Green | Blue):
			return Palette::White;

		default:
			break;
		}

		return Palette::Black;
	}
}

namespace Assets
{
	static inline const String Mamelon{ U"Mamelon"};

	static inline const FilePath PrologueCSV{ U"csv/prologue.csv" };

	// アセットとして登録する
	static inline void RegisterAssets()
	{
		// Main.cppから移植
		FontAsset::Register(U"TitleFont", 80, Typeface::Heavy);
		FontAsset::Register(U"SubFont", 30, Typeface::Bold);
		FontAsset::Register(U"MenuFont", 24, Typeface::Regular);

		// メッセージウィンドウ用のフォント追加
		FontAsset::Register(Mamelon, FontMethod::Bitmap, 48, U"font/Mamelon-3.5-Hi-Regular.otf");
	}
}
