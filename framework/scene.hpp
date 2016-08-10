//toBe GREAT
#ifndef SCENE_HPP
#define SCENE_HPP
#include <vector>
#include <map>
#include "shape.hpp"
#include "material.hpp"
#include "light.hpp"

struct Scene
{
//Assets:
	//-Licht
		std::vector <Light*> m_lights;
		Color m_ambient;
	//-Shapes
		std::vector <Shape*> m_shapes;
	//-Material
		std::map<std::string, Material*> m_materials;

};
#endif