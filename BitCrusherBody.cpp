#include "BitCrusherBody.h"


void BitCrusherBody::effect(std::vector<sf::Int16> &samples)
{
	sf::Uint64 length = samples.size();
	int mask = 0xD000;


	switch (resolution)
	{
	case 2:
		mask = 0xFFFE;
		break;

	case 3:
		mask = 0xFFFC;
		break;

	case 4:
		mask = 0xFFF7;
		break;

	case 5:
		mask = 0xFFF0;
		break;

	case 6:
		mask = 0xFFC0;
		break;

	case 7:
		mask = 0xFF70;
		break;

	case 8:
		mask = 0xFE000;
		break;

	case 9:
		mask = 0xFC00;
		break;

	case 10:
		mask = 0xE000;
		break;

	default:
		mask = 0xFFFF;
		break;
	}

	for (sf::Uint64 sample = 0; sample < length; sample++)
	{
		samples.at(sample) = rint((sf::Int16)(samples.at(sample) & mask));
	}


	std::vector<sf::Int16> lowerSamplings;
	for (sf::Uint64 sample = 0; sample < length ; sample += 4 * resolution)
	{
		lowerSamplings.push_back(samples.at(sample));
	}
	samples = lowerSamplings;


	//for (sf::Uint64 sample = 0; sample < length; sample++)
	//{
	//	if (resolution == 8)
	//	{

	//	}
	//	else
	//	{
	//		samples.at(sample) = rint((sf::Int16)(samples.at(sample) & mask));
	//	}

		//samples.at(sample) = (rint((sf::Int8)(samples.at(sample)) >> resolution))*pow(2,resolution-1);// / 0x7fffff))) * 64;// *256;
		

		//if (((samples.at(sample)) % resolution < 64))
		//{
		//samples.at(sample) = /*rint((sf::Uint8)*/((((samples.at(sample)) * 0x7fff / 0x7fffff))) * 64;// *256;
		//	samples.push_back(0);
		//}
	
}

void BitCrusherBody::setParamInt1(int param1)
{
	resolution = param1;
}


void BitCrusherBody::setParamFloat1(float param1) {};



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


