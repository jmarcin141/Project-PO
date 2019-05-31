#pragma once

#include "EffectBody.h"

class EchoBody : public EffectBody
{
public:
	virtual std::vector<sf::Int16> EffectBody::effect(Music &music) override;
};
