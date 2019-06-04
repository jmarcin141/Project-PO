#include "BitCrusherBody.h"


void BitCrusherBody::effect(std::vector<sf::Int16> &samples)
{
	sf::Uint64 length = samples.size();

	for (sf::Uint64 sample = 0; sample < length - 1; sample++)
	{
		//if (((samples.at(sample)) % levelAmplitude < 64))
		//{
		samples.at(sample) = (rint((sf::Uint8)((samples.at(sample)) * 0x7fff / 0x7fffff))) * 64;// *256;
			//samples.push_back(0);
		//}
	}
}





//void BitCrusherBody::effect(std::vector<sf::Int16> &samples)
//{
//	sf::Uint64 length = samples.size();
//
//	for (sf::Uint64 sample = 0; sample < length - 1; sample++)
//	{
//		if (((samples.at(sample))%levelAmplitude < 64))
//		{
//			samples.at(sample) = levelAmplitude*(samples.at(sample)%levelAmplitude);
//			//samples.push_back(0);
//		}
//	}
//	//return samples;
//
//
//	//sf::Uint64 length = samples.size();
//
//	//for (sf::Uint64 sample = 0; sample < length - 1; sample++)
//	//{
//	//	if ( ( (samples.at(sample) - samples.at(sample+1)) < levelAmplitude) )
//	//	{
//	//		samples.at(sample) = samples.at(sample +1);
//	//		//samples.push_back(0);
//	//	}
//	//}
//	////return samples;
//}

void BitCrusherBody::setParamInt1(int param1) {}


void BitCrusherBody::setParamFloat1(float param1)
{
	levelAmplitude = static_cast<sf::Int16>(32767 * param1);
}
