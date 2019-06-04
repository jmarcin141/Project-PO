#pragma once


#include "EffectBody.h"
#include "EchoBody.h"
#include "DistortionBody.h"
#include "BitCrusherBody.h"
#include "WahWahBody.h"


//...#include "EffectBody.h"

#include <memory>

class EffectHandle
{
private:
	using BodyPtr = std::unique_ptr <EffectBody>;
	BodyPtr fBodyObj;

public:
	enum class EffectType
	{
		ECHO, DISTORTION, BITCRUSHER, WAHWAH, EFFECTX, RINGMODULATOR
	};

	EffectHandle(EffectType type); 
	virtual void effect(std::vector<sf::Int16> &samples);


	virtual void setParamInt1(int param1);

	//virtual void setParamInt2(int param2);

	virtual void setParamFloat1(float param1);

	virtual ~EffectHandle() = default;
};


