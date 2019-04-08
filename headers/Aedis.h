#pragma once

namespace ad
{
	struct Text
	{
		std::string fontname;
		int fontSize;
		sf::Font font;

		sf::Text text;

		std::vector<sf::Text> lines;
	};

	struct Sounds
	{
		sf::Music main;

		std::vector<sf::SoundBuffer> effectsBuffer;
		std::vector<sf::Sound> effects;
	};

	struct Visuals
	{
		sf::Texture texture;

		std::vector<sf::Sprite> sprites;
	};

	struct Animation
	{
		struct Visuals frames;
		int type;

		int updateTime;
	};
};