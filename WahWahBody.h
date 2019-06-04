#pragma once

#include "EffectBody.h"

//#define lfoskipsamples 30
#define M_PI 3.141542
//#define mCurRate 0.6f


class WahWahBody : public EffectBody
{
private:
	int lfoskipsamples = 1000;
	float mCurRate = 2.f;

public:
	virtual void EffectBody::effect(std::vector<sf::Int16> &samples) override;

	virtual void EffectBody::setParamInt1(int param1) override;

	virtual void EffectBody::setParamFloat1(float param1) override;

};


//bool EffectWahwah::ProcessSimpleMono(float *buffer, sampleCount len);
