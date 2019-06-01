#pragma once

#include "Music.h"
//#include <vector>

#include "headers.h"


class Echo : public Music
{
private:
	//float start;
	//float time;
	//float stop;
	//float echoForce;
public:
	Echo();
	~Echo();

	// echo efekt
	void setEcho(std::vector<sf::Int16> &samples);
};

