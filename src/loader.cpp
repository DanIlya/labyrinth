#include <loader.h>
#include <inttypes.h>

namespace ad
{
	void Loader::loadVisuals(std::string filename, ad::Visuals& visuals)
	{
		visuals.texture.loadFromFile(filename);

		for(int i = 0; i < visuals.texture.getSize().x / visuals.texture.getSize().y; i++)
		{
			sf::Sprite sprite;
			sprite.setTextureRect(sf::IntRect(i * visuals.texture.getSize().x, 0, visuals.texture.getSize().x, visuals.texture.getSize().x));
			sprite.setTexture(visuals.texture, false);
			visuals.sprites.push_back(sprite);
		}
	}
	void Loader::loadSounds(std::string filename, ad::Sounds& sounds)
	{
		/*add flags which kind of music should and shouldnt be loaded (main / effects)*/

		std::string objectName;
		std::ifstream musicFile;
		sf::SoundBuffer soundBuffer;
		sf::Sound sound;

		musicFile.open(filename);

		std::getline(musicFile, objectName);
		sounds.main.openFromFile(objectName);

		//for loop
		std::getline(musicFile, objectName);
		soundBuffer.loadFromFile(objectName);
		sound.setBuffer(soundBuffer);
		sounds.effectsBuffer.push_back(soundBuffer);

		musicFile.close();
	}
	void Loader::loadText(std::string filename, ad::Text& text)
	{
		int8_t verticalPadding;
		int8_t horizontalPadding;
		int8_t verticalMargin;
		int8_t horizontalMargin;
		
		std::string line;
		std::ifstream file;
		std::vector<std::string> lines;

		file.open(filename);
		//эта ошибка должна выводиться красным цветом в логгере if(!fs.is_open()) { std::cout << "failed to open " + filename, exit(1); }

		std::getline(file, text.fontname);		//fontname
		file >> text.fontSize;					//fontsize
		file >> verticalPadding;
		file >> horizontalPadding;
		file >> verticalMargin;
		file >> horizontalMargin;

		while(std::getline(file, line))
			lines.push_back(line);				//options

		text.font.loadFromFile(text.fontname);
		text.text.setFont(text.font);
		text.text.setCharacterSize(text.fontSize);
		
		for (auto i = optionStrings.begin(); i < optionStrings.end(); ++i)
		{
			text.text.setString(option);
			text.text.setPosition(horizontalMargin + horizontalPadding, verticalMargin + (i - optionStrings.begin())  * verticalPadding);
			text.lines.push_back(text.text);
		}

		file.close();
	}
	//void Loader::loadMapArray() {}
}