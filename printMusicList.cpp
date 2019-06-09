#include "printMusicList.h"


void printMusicList(Fl_Widget* widget)
{
	std::vector<std::string> files = getNameFilesFromDirectory();

	char textNameFiles[1000] = {};
	for (unsigned int i = 0, index = 0; i < files.size(); i++)
	{
		for (unsigned int j = 0; j < files.at(i).size(); j++)
		{
			textNameFiles[index++] = files.at(i).at(j);
			if (j == files.at(i).size() - 1)
			{
				textNameFiles[index++] = '\n';
			}
		}
	}
	widget->copy_label(textNameFiles);
}