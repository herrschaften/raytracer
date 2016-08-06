#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "scene.hpp"
#include <glm/vec3.hpp>
#include "color.hpp"
#include <string>



struct Light
{
	//constructors
	//Light(std::string const& name, Color const& clr, unsigned int intensity, glm::vec3 const& pnt)
	std::string name;
	glm::vec3 m_point;
	double m_inten;
	Color m_color;


	
};


#endif