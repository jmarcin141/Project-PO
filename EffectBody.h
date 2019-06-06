#pragma once

#include "Music.h"
#define M_PI 3.141542


class EffectBody 
{
public:
	virtual void effect(std::vector<sf::Int16> &samples) = 0;

	virtual void setParamInt1(int param1) = 0;

	//virtual void setParamInt2(int param2) = 0;

	virtual void setParamFloat1(float param1) = 0;

	virtual ~EffectBody() = default;



};