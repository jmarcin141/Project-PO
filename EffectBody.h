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

	virtual ~EffectBody() = default;
};