#pragma once

#define 	__MENU__ 		0
#define 	__MAP__ 		1

#include <Aedis.h>

namespace ad
{
	class Drawer
	{
	public:
		void addText(std::string className, ad::Text& classText) { this->text[className] = classText; }
		void drawText(sf::RenderWindow& window, std::string className);
		void addVisuals(std::string className, ad::Visuals& classVisuals) { this->visuals[className] = classVisuals; }
		void drawVisuals(sf::RenderWindow& window, std::string className);
	private:
		std::vector<ad::Visuals> visuals;
		std::vector<ad::Text> text;
	};
}