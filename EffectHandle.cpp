#include "EffectHandle.h"

EffectHandle::EffectHandle(EffectType type)
{
	switch (type)
	{
	case EffectType::ECHO:
		fBodyObj = std::make_unique <EchoBody>();
		break;

	case EffectType::DISTORTION:
		fBodyObj = std::make_unique <DistortionBody>();
		break;

	case EffectType::BITCRUSHER:
		fBodyObj = std::make_unique <BitCrusherBody>();
		break;

	case EffectType::RINGMODULATOR:
		fBodyObj = std::make_unique <RingModulatorBody>();
		break;

	case EffectType::REVERSE:
		fBodyObj = std::make_unique <ReverseBody>();
		break;

	case EffectType::WAHWAH:
		fBodyObj = std::make_unique <WahWahBody>();
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

void EffectHandle::setParamInt1(int param1)
{
	return fBodyObj->setParamInt1(param1);
}

//virtual void setParamInt2(int param2) = 0;

void EffectHandle::setParamFloat1(float param1)
{
	return fBodyObj->setParamFloat1(param1);
}

