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

void EffectHandle::effect(std::vector<sf::Int16> &samples)
{
	return fBodyObj->effect(samples); // ?? czy na pewno dobrze?
}