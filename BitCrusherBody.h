#pragma once

#include "EffectBody.h"


class BitCrusherBody : public EffectBody
{
private:
	sf::Int16 levelAmplitude = 64;

public:
	virtual void EffectBody::effect(std::vector<sf::Int16> &samples) override;

	virtual void EffectBody::setParamInt1(int param1) override;

	//virtual void EffectBody::setParamInt2(int param2) override;

	virtual void EffectBody::setParamFloat1(float param1) override;

};
