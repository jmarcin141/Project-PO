#pragma once

#include <vector>
#include "Music.h"
#include <SFML/Audio.hpp>

class EffectBody
{
public:
	virtual std::vector<sf::Int16> effect(Music &music) = 0;

	virtual ~EffectBody() = default;
};