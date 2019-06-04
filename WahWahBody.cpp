#include "WahWahBody.h"


//bool EffectWahwah::ProcessSimpleMono(float *buffer, sampleCount len)
void WahWahBody::effect(std::vector<sf::Int16> &samples)
{
	float freq = float(1.5);
	int startphase = 0;
	float depth = (float)0.7;
	float freqofs = (float)0.3;
	float res = float(2.5);

	float lfoskip = freq * 2 * M_PI / mCurRate;
	int skipcount = 0;
	int xn1 = 0;
	int xn2 = 0;
	int yn1 = 0;
	int yn2 = 0;
	int b0 = 0;
	int b1 = 0;
	int b2 = 0;
	int a0 = 0;
	int a1 = 0;
	int a2 = 0;

	int phase = startphase;
	//if (mCurChannel == Track::RightChannel)
	//	phase += (float)M_PI;





	float frequency, omega, sn, cs, alpha;
	sf::Int16 in, out;

	for (int i = 0; i < samples.size(); i++) {
		in = samples.at(i);

		if ((skipcount++) % lfoskipsamples == 0) {
			frequency = (1 + cos(skipcount * lfoskip + phase)) / 2;
			frequency = frequency * depth * (1 - freqofs) + freqofs;
			frequency = exp((frequency - 1) * 6);
			omega = M_PI * frequency;
			sn = sin(omega);
			cs = cos(omega);
			alpha = sn / (2 * res);
			b0 = (1 - cs) / 2;
			b1 = 1 - cs;
			b2 = (1 - cs) / 2;
			a0 = 1 + alpha;
			a1 = -2 * cs;
			a2 = 1 - alpha;
		};
		out = (b0 * in + b1 * xn1 + b2 * xn2 - a1 * yn1 - a2 * yn2) / a0;
		xn2 = xn1;
		xn1 = in;
		yn2 = yn1;
		yn1 = out;

		// Prevents clipping
	//	if (out < -1.0)
	//		out = float(-1.0);
	//	else if (out > 1.0)
	//		out = float(1.0);

		samples.at(i) = static_cast<sf::Int16>(out);// *32767;
	}

}

void WahWahBody::setParamInt1(int param1) {}


void WahWahBody::setParamFloat1(float param1)
{
	//levelAmplitude = static_cast<sf::Int16>(32767 * param1);
}




//source : https://searchcode.com/codesearch/view/20121801/


//float frequency, omega, sn, cs, alpha;
//float in, out;
//
//for (int i = 0; i < len; i++) {
//	in = buffer[i];
//
//	if ((skipcount++) % lfoskipsamples == 0) {
//		frequency = (1 + cos(skipcount * lfoskip + phase)) / 2;
//		frequency = frequency * depth * (1 - freqofs) + freqofs;
//		frequency = exp((frequency - 1) * 6);
//		omega = M_PI * frequency;
//		sn = sin(omega);
//		cs = cos(omega);
//		alpha = sn / (2 * res);
//		b0 = (1 - cs) / 2;
//		b1 = 1 - cs;
//		b2 = (1 - cs) / 2;
//		a0 = 1 + alpha;
//		a1 = -2 * cs;
//		a2 = 1 - alpha;
//	};
//	out = (b0 * in + b1 * xn1 + b2 * xn2 - a1 * yn1 - a2 * yn2) / a0;
//	xn2 = xn1;
//	xn1 = in;
//	yn2 = yn1;
//	yn1 = out;
//
//	// Prevents clipping
//	if (out < -1.0)
//		out = float(-1.0);
//	else if (out > 1.0)
//		out = float(1.0);
//
//	buffer[i] = (float)out;
//}
