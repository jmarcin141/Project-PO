#include "printTimeMusic.h"


void printTimeMusic(std::vector<Fl_Widget*> widget, int mTime)
{

	char timeTxtA[15] = "Music length: ";
	char timeTxtB[9] = "00:00:00";
	char timeTxt[25];

	int seconds = mTime % 60;
	int minutes = (mTime - seconds) / 60;

	timeTxtB[4] = 48 + minutes % 10;
	timeTxtB[3] = 48 + minutes / 10;

	timeTxtB[7] = 48 + seconds % 10;
	timeTxtB[6] = 48 + seconds / 10;

	for (int i = 0; i <= 24; i++)
	{
		if (i < 14)
		{
			timeTxt[i] = timeTxtA[i];
		}
		else if (i >= 14)
		{
			timeTxt[i] = timeTxtB[i - 14];
		}
	}
	widget.at(0)->copy_label(timeTxt);
}