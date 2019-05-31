#include "EffectHandle.h"

EffectHandle::EffectHandle(EffectType type)
{
	switch (type)
	{
	case EffectType::ECHO:
		fBodyObj = std::make_unique <EchoBody>();
		break;

	case EffectType::DISTORTION:
		//fBodyObj = std::make_unique <DistortionBody>();
		break;

	case EffectType::WAHWAH:
	//	fBodyObj = std::make_unique <WahWahBody>();
		break;

	case EffectType::EFFECTX:
		//fBodyObj = std::make_unique <effect...Body>();
		break;


	default:
		break;

	}
}

std::vector<sf::Int16> EffectHandle::effect(Music &music)
{
	return fBodyObj->effect(music); // ?? czy na pewno dobrze?
}