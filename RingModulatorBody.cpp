#include "RingModulatorBody.h"

//Modulator ko³owy (Ring modulator) wprowadza efekt
	//silnie nieharmonicznego sygna³u, poprzez wymno¿enie
	//sygna³u przez sinus o regulowanej czêstotliwoœci

// source, knowledge about effects : http://users.cs.cf.ac.uk/Dave.Marshall/CM0268/PDF/10_CM0268_Audio_FX.pdf


void RingModulatorBody::effect(std::vector<sf::Int16> &samples)
{
	//ring modulator
	int fs = 44100;
	for (int i = 0; i < samples.size(); i++)
	{
		samples.at(i) = samples.at(i) * ((1 - force) + (force * (sin(2 * M_PI * i * freq/fs)))); //freq/fs
	}
}


void RingModulatorBody::setParamInt1(int param1)
{
	freq = param1;
}

void RingModulatorBody::setParamFloat1(float param1)
{
	force = param1;
}