#include "DistortionBody.h"



void DistortionBody::effect(std::vector<sf::Int16> &samples)
{
	sf::Uint64 length = samples.size();

	for (sf::Uint64 sample = 0 ; sample < length; sample++)
	{
		if (samples.at(sample) >= levelAmplitude) 
		{
			samples.at(sample) = levelAmplitude;
		}
	}
	//return samples;
}

void DistortionBody::setParamInt1(int param1) {}


void DistortionBody::setParamFloat1(float param1) 
{
	levelAmplitude = static_cast<sf::Int16>(32767 * param1);
}
