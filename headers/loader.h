#pragma once

#include <Aedis.h>

namespace ad
{
	class Loader
	{
	public:
		void loadVisuals(std::string filename, ad::Visuals& visuals);
		void loadSounds(std::string filename, ad::Sounds& sounds);
		void loadText(std::string filename, ad::Text& text);
	};
}