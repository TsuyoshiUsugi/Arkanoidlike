#include "sound_manager.h"

void SoundManager::PlaySE(SoundType sound_type)
{
	switch (sound_type)
	{
	case SoundType::Enter:
		PlaySoundMem(sound_enter_, DX_PLAYTYPE_BACK);
		break;
	case SoundType::Explode:
		PlaySoundMem(sound_explode_, DX_PLAYTYPE_BACK);
		break;
	}
}

void SoundManager::LoadSound()
{
	sound_enter_ = LoadSoundMem("sound/Enter.mp3");
	sound_explode_ = LoadSoundMem("sound/Explode.mp3");
}

SoundManager::SoundManager()
{
	LoadSound();
}

std::shared_ptr<SoundManager> SoundManager::GetInstance() {
	static std::shared_ptr<SoundManager> instance = nullptr;
	if (!instance) instance = std::make_shared<SoundManager>();
	return instance;
}




