#pragma once
#include "Music.h"
class Echo : public Music
{
private:
	float start;
	float time;
	float stop;
	float echoForce;
public:
	Echo();
	~Echo();

};

