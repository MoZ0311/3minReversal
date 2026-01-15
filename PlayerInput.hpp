#pragma once

struct PlayerInput
{
	static bool OnClicked()
	{
		return MouseL.down();
	}
};
