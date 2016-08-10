/*raytracer.hpp 
Feel free to be rat-race!
*/
#ifndef BUW_RAYTRACER_HPP
#define BUW_RAYTRACER_HPP

#include <string>
#include "scene.hpp"

class Raytracer{
public: 
	//KONSTRUTOREN----------------------------------------------------------------------
	Raytracer(	std::string const& inpath, 
				unsigned int width, unsigned int height, 
				std::string const& outpath);

	//FUNKTIONEN-------------------------------------------------------------------------
	void render();
	//...erweitern?...

private:
  std::string m_in;
  unsigned int m_width;
  unsigned int m_height;
  std::string m_out;
};

#endif // BUW_BOX_HPP