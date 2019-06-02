#include "RingModulatorBody.h"



void RingModulatorBody::effect(std::vector<sf::Int16> &samples)
{
	// echo efekt
	//music.loadSound();

	int start = 0;
	//int delay = 3000;
	//int length = 500000;
	sf::Uint64 length = samples.size();
	//float echoForce = 1.5;


	std::vector<sf::Int16> delayedSamples;
	for (start; start < length; start++)
	{
		delayedSamples.push_back(samples.at(start));
		//Dsamples.at(i + delay) = Dsamples.at(i) + delayedSamples.at(i);
	}

	for (int i = 0; i < delayedSamples.size() - delay; i++)
	{
		//delayedSamples.push_back(Dsamples.at(i));
		samples.at(i + delay) = samples.at(i + delay) + echoForce * delayedSamples.at(i);
	}
	//return samples;
}

void EchoBody::setParamInt1(int param1)
{
	delay = param1;
}

void EchoBody::setParamFloat1(float param1)
{
	echoForce = param1;
}