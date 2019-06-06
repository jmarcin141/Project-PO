#include "ReverseBody.h"



void ReverseBody::effect(std::vector<sf::Int16> &samples)
{
	sf::Uint64 length = samples.size();
	std::vector<sf::Int16> mSamples;

	for (int i = length-1; i >= 0; i--)
	{
		mSamples.push_back(samples.at(i));
	}
	samples.swap(mSamples);
}

void ReverseBody::setParamInt1(int param1) {};

void ReverseBody::setParamFloat1(float param1) {};
