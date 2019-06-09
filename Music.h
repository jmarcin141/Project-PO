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
	
	std::string fileName;
	//std::string filePath = "E:\\AGH\\Semestr 4\\PO\\Projekty\\Projekt-Efekt-Gitarowy\\Projekt-Efekt-Gitarowy\\My Music\\";
	std::string filePath = "C:\\Users\\Jakub-HP\\Music\\";


	int fs = 44100;

	//int lengthTime = 366; //[s]

public:
	Music(int mFs);

	Music();
	~Music();

	//int fs = 44100;

	sf::Uint64 getLength();

	int getLengthTime();

	int getFs();


	void setFileName(std::string mFileName);

	void saveSound(std::string soundName);

	std::vector<sf::Int16> getSamples();

	void setFs(int mFs);

	void setSpeed(float speed);

	bool getActiveSound();

	bool loadSound();

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

	bool loadSamples(std::vector<sf::Int16> &samples, int f);

};

