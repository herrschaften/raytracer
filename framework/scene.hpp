//toBe GREAT
#ifndef SCENE_HPP
#define SCENE_HPP
#include <vector>
#include <map>
#include "shape.hpp"
#include "material.hpp"
#include "light.hpp"
//#include "camera.hpp"
struct Scene
{
//Assets:
	//-Licht
		std::vector <Light> SceneLights;
	//-Shapes
		std::vector <Shape*> SceneShapes;
	//-Camera
		//Camera SceneCam;
	//-Material
		std::map<std::string, Material*> SceneMaterials;
	//-Optional Hit
		//OptionlHit intersect(Ray const&)const;
};
#endif// blaiu