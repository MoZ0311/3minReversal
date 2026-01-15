# pragma once
# include <Siv3D.hpp>

// 全シーンで共有するデータ（今は空っぽでOK）
struct GameData {};

// シーンマネージャーの短縮名
using App = SceneManager<String, GameData>;
