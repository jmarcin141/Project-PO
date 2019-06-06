#pragma once

#include "EffectBody.h"


class RingModulatorBody : public EffectBody
{
private:
	int freq = 1000;
	float force = 0.5f; //[%]

public:
	virtual void EffectBody::effect(std::vector<sf::Int16> &samples) override;

	virtual void EffectBody::setParamInt1(int param1) override;

	virtual void EffectBody::setParamFloat1(float param1) override;

};
