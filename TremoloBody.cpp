#include "TremoloBody.h"

//source : McPherson, Andrew P. Reiss, Joshua D - Audio Effects Theory, Implementation and Application-CRC Press (2014)


float lfo(float phase)
{
		return 0.5f + 0.5f*sinf(2.0 * M_PI * phase);
}


void TremoloBody::effect(std::vector<sf::Int16> &samples)
{
	int numSamples = samples.size(); // How many audio samples to process

	float ph = 0.5f; // Current phase of the LFO (0-1)
	float inverseSampleRate = 1.f; // Defined as 1.0/(sample rate)
	float depth_ = 0.5f; // Depth of the tremolo effect (0-1)


	for (int i = 0; i < numSamples; ++i)
	{
		
		const sf::Int16 in = samples.at(i); // channelData[i];

		samples.at(i) = in *(1.0f - depth_ * lfo(ph) );
		// Update the carrier and LFO phases, keeping them in
		// the range 0-1
		ph += freq * inverseSampleRate;
		if (ph >= 1.0)
			ph -= 1.0;
	}

}

void TremoloBody::setParamInt1(int param1)
{
	freq = param1;
}


void TremoloBody::setParamFloat1(float param1) {};




