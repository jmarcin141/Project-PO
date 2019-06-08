#pragma once

#include "EffectBody.h"


class TremoloBody : public EffectBody
{
private:
	int freq = 200;

public:
	virtual void EffectBody::effect(std::vector<sf::Int16> &samples) override;

	virtual void EffectBody::setParamInt1(int param1) override;

	virtual void EffectBody::setParamFloat1(float param1) override;

};


//bool EffectWahwah::ProcessSimpleMono(float *buffer, sampleCount len);
