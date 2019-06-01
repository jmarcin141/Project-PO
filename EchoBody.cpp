#include "EchoBody.h"



void EchoBody::effect(std::vector<sf::Int16> &samples)
{
	// echo efekt
	//music.loadSound();

	int start = 0;
	int delay = 3000;
	//int length = 500000;
	sf::Uint64 length = samples.size();
	float echo_force = 1.5;


	std::vector<sf::Int16> delayedSamples;
	for (start; start < length; start++)
	{
		delayedSamples.push_back(samples.at(start));
		//Dsamples.at(i + delay) = Dsamples.at(i) + delayedSamples.at(i);
	}

	for (int i = 0; i < delayedSamples.size() - delay; i++)
	{
		//delayedSamples.push_back(Dsamples.at(i));
		samples.at(i + delay) = samples.at(i + delay) + echo_force * delayedSamples.at(i);
	}
	//return samples;
}


////std::vector<sf::Int16> EchoBody::effect(Music &music)
////{
////	// echo efekt
////	music.loadSound();
////	std::vector<sf::Int16> Dsamples;
////	Dsamples = music.getSamples();
////
////	int start = 0;
////	int delay = 3000;
////	//int length = 500000;
////	sf::Uint64 length = music.getLength();
////	float echo_force = 1.5;
////
////
////	std::vector<sf::Int16> delayedSamples;
////	for (start; start < length; start++)
////	{
////		delayedSamples.push_back(Dsamples.at(start));
////		//Dsamples.at(i + delay) = Dsamples.at(i) + delayedSamples.at(i);
////	}
////
////	for (int i = 0; i < delayedSamples.size() - delay; i++)
////	{
////		//delayedSamples.push_back(Dsamples.at(i));
////		Dsamples.at(i + delay) = Dsamples.at(i + delay) + echo_force * delayedSamples.at(i);
////	}
////	//music.loadSamples(Dsamples, music.fs);
////
////	return Dsamples;
////}