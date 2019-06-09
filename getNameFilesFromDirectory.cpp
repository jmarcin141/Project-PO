#include "getNameFilesFromDirectory.h"


std::vector<std::string> getNameFilesFromDirectory()
{
	std::vector<std::string> files;
	//std::string path = "E:/AGH/Semestr 4/PO/Projekty/Projekt-Efekt-Gitarowy/Projekt-Efekt-Gitarowy/My Music";
	std::string path = "C:/Users/Jakub-HP/Music";
	for (const auto & entry : std::experimental::filesystem::directory_iterator(path))
	{
		if (entry.path() != (path + "/desktop.ini"))
		{
			std::cout << entry.path() << std::endl;
			files.push_back(entry.path().string());
		}
	}

	for (int i = 0; i < files.size(); i++)
	{
		files.at(i).erase(0, path.size() + 1);
		std::cout << files.at(i) << std::endl;
	}

	return files;
}