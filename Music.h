#pragma once
#include <iostream>
#include <SFML/Audio.hpp>


class Music
{
private:
	sf::SoundBuffer buf;
	sf::Sound sound;
	float position;
	std::vector<sf::Int16> samples;

public:
	Music();
	~Music();

	int fs = 44100;
	sf::Uint64 getLength();

	std::vector<sf::Int16> getSamples();

	bool getActiveSound();

	void loadSound();

	void playSoud();

	void stopSound();

	void pauseSound();

	void loopSound();

	void rewindSound();

	void forwardSound();

	void volumePlus();

	void volumeMinus();

	void setVolume(double vol);	

	void speedPlus();

	void speedMinus();

	sf::Time getTime();

	//std::vector<sf::Int16> soundData();

	void loadSamples(std::vector<sf::Int16> &samples, int f);

};

