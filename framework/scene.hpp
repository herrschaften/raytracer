/*scene.hpp 
Feel free in any scenario?!
*/
#ifndef SCENE_HPP
#define SCENE_HPP
#include <vector>
#include <map>

#include "composite.hpp"
#include "shape.hpp"
#include "light.hpp"
#include "camera.hpp"


struct Scene
{
//Assets:
	//-Licht
		std::vector <std::shared_ptr<Light>> m_lights;
		Color m_ambient;
	//-Shapes
		std::shared_ptr<Composite> m_composite; 
		std::vector <std::shared_ptr<Shape>> m_shapes;
	//-Material
		std::map<std::string, std::shared_ptr<Material>> m_materials;
	//-Camera
		Camera m_camera;


};
#endif