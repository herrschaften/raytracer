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
	//-Material
		std::map<std::string, std::shared_ptr<Material>> m_materials;
	//-Camera
		Camera m_camera;
	//-antialiasing faktor
		int aliasfaktor = 2;
	//- reflection depth
		int depth = 3;		



};
#endif