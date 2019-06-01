#pragma once

#include "EffectBody.h"


class EchoBody : public EffectBody
{
public:
	virtual void EffectBody::effect(std::vector<sf::Int16> &samples) override;
};
