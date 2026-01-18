# pragma once
# include <Siv3D.hpp>

// ゲームの結果種類
enum class GameResult
{
	None,
	Clear,      // 解除成功
	TimeUp,     // 時間切れ
	Explosion   // 爆発（誤操作）
};

struct GameData
{
	// 結果をここに保存して、リザルト画面で読み取る
	GameResult result = GameResult::None;

	// 残り時間（クリア時のスコア用）
	double remainingTime = 0.0;
};

using App = SceneManager<String, GameData>;
