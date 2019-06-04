#include "RingModulatorBody.h"

//Modulator ko³owy (Ring modulator) wprowadza efekt
	//silnie nieharmonicznego sygna³u, poprzez wymno¿enie
	//sygna³u przez sinus o regulowanej czêstotliwoœci

void RingModulatorBody::effect(std::vector<sf::Int16> &samples)
{

//########################## generowanie sampli, odtworzenie dzwieku z sampli #####################

std::vector<sf::Int16> samples_gen;
for (int t = 0; t < 200; t++)
{
	for (int f = 20; f < 16000; f += 20)
	{
		samples_gen.push_back(5000 * sin(2 * 3.14 * f * t));
	}
}

for (int t = 200; t > 500; t++)
{
	for (int f = 16000; f > 20; f -= 20)
	{
		samples_gen.push_back(5000 * sin(2 * 3.14 * f * t));
	}
}

int fs = 44100;

//const std::vector<sf::Int16> samples1 = samples;
sf::SoundBuffer bufg;

bufg.loadFromSamples(samples_gen.data(), samples_gen.size(), 1, fs);
bufg.saveToFile("generate1.wav");

sf::Sound soundG;
soundG.setBuffer(bufg);
soundG.play();



	/*% This script produces a wah - wah effect by modeling a damped harmonic
		% oscillator with forcing using the finite difference method.The forcing
		% comes from the input audio signal.The scheme acts as a time - varying
		% bandpass filter by using a time - varying frequency of oscillation.
		%--------------------------------------------------------------------------*/


	//% Parameters
		//%--------------------------------------------------------------------------
		int f_wah = 2;                              //% Wah rate(Hz)
		int f_max = 3500;                           //% Max wah frequency(Hz)
		int f_min = 1500;                           //% Min wah frequency(Hz)
		int alpha = 1000;                           //% Damping coefficient
		
		//%--------------------------------------------------------------------------

		//%--------------------------------------------------------------------------

		//% Initial Calculations
		//%--------------------------------------------------------------------------
		int Fs = 44100;           //% Read audio file
		int N = samples.size();                         // % Length of signal
		int T = 1 / Fs;  
		int pi = 3.14; // % Sample period
	//	nT = (0:T:N / Fs - T);                     // % Time vector
		int depth = round((f_max + f_min) / 2);        // % Depth of wah
		int range = round((f_max - f_min) / 2);         //% Range of wah
	//	int omega = depth + range * cos(2 * pi*f_wah*nT); //% Varying frequency signal
		//%--------------------------------------------------------------------------

		//% Finite difference scheme
		//%--------------------------------------------------------------------------
		std::vector<int> x(N);// = zeros(N, 1);     //% Initialize output
		x.at(2) = samples.at(1);        //% Second sample

		//% Constants
	//	std::vector<int> c1 = (2 - T ^ 2 * 2 * pi*omega. ^ 2) / (0.5*alpha*T + 1); //% Vector
	//	std::vector<int> c2 = (0.5*alpha*T - 1) / (0.5*alpha*T + 1);      // % Scalar constant

		for (int n = 2; n < N - 1; n++)
		{
	//		x.at(n + 1) = c1.at(n)*x.at(n) + c2 * x.at(n - 1) + f.at(n);     //% Finite difference scheme
		}






	int start = 0;
	sf::Uint64 length = samples.size();



	std::vector<sf::Int16> delayedSamples;
	for (start; start < length; start++)
	{
		delayedSamples.push_back(samples.at(start));
		//Dsamples.at(i + delay) = Dsamples.at(i) + delayedSamples.at(i);
	}

	for (int i = 0; i < delayedSamples.size() /*- delay*/; i++)
	{
		//delayedSamples.push_back(Dsamples.at(i));
		samples.at(i /*+ delay*/) = samples.at(i /*+ delay*/) + force * delayedSamples.at(i);
	}
	//return samples;
}

void RingModulatorBody::setParamInt1(int param1)
{
	freq = param1;
}

void RingModulatorBody::setParamFloat1(float param1)
{
	force = param1;
}