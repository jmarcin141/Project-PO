#include "deactivateAllWidgetsInVectorOfPointers.h"


void deactivateAllWidgetsInVectorOfPointers(bool openedFiles, std::vector<Fl_Widget*> vectorOfPtr)
{
	if (openedFiles == false)
	{	
		for (unsigned int i = 0; i < vectorOfPtr.size(); i++)
		{
			vectorOfPtr.at(i)->deactivate();
		}
	}
	else //(openedFiles == true)
	{
		for (unsigned int i = 0; i < vectorOfPtr.size(); i++)
		{
			vectorOfPtr.at(i)->activate();
		}
	}
}