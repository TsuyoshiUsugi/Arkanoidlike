#pragma once
#include "object.h"
#include "../dxlib_ext/dxlib_ext.h"

enum SoundType
{
	Enter,
	Explode
};

class SoundManager
{
private:
	int sound_enter_;
	int sound_explode_;
public:
	SoundManager();
	static std::shared_ptr<SoundManager> GetInstance();
	static void Destroy();
	void PlayBGM();
	void PlaySE(SoundType sound_type);
	void LoadSound();
};

