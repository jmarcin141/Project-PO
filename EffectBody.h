#pragma once

//#include <vector>
#include "Music.h"
//#include <SFML/Audio.hpp>

//#include "headers.h"

//#include "GlobalVariables.h"

class EffectBody 
{
public:
	virtual void effect(std::vector<sf::Int16> &samples) = 0; //std::vector<sf::Int16> <>void

	virtual void setParamInt1(int param1) = 0;

	//virtual void setParamInt2(int param2) = 0;

	virtual void setParamFloat1(float param1) = 0;

	virtual ~EffectBody() = default;



};