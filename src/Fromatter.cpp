#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


class Formatter
{
public:

	Formatter(std::string mapFilename)
	{
		this->mapFileName = mapFilename;
	}

	int FormatMap()
	{
		std::ifstream mapFile;
		std::ofstream NewMapFile;

		//���������� ���������� ���� ���� �� ����������� ��������
		mapFile.open(this->mapFileName);
		//��������, newfilename ����� ����������� ��-�������
		std::string newfilename = this->mapFileName + ".formatted";
		NewMapFile.open(newfilename, std::ofstream::trunc);

		std::string tmp;
		while (tmp != "  <data encoding=\"csv\">")
			std::getline(mapFile, tmp);

		std::getline(mapFile, tmp);

		while (tmp != "</data>")
		{
			std::replace(tmp.begin(), tmp.end(), ',', ' ');

			NewMapFile << tmp + "\n";

			std::getline(mapFile, tmp);

		}
		mapFile.close();
		NewMapFile.close();

		return 0;
	}

private:
	std::string mapFileName;
};

int main()
{
	Formatter format("map.tmx");
	return format.FormatMap();
}