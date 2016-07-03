//toBe GREAT
#include <shape.hpp>
//#include <camera>
//#include <light>
#include <material.hpp>

struct Scene{
	//Assets:
	//-Licht
	//std::vector <Light> SceneLights;
	//-Shapes
	std::vector <Shape> SceneShapes;
	//-Camera
	Camera SceneCam;
	//-Material
	std::map<Name, Material> SceneMaterials;
	//-Optional Hit
	//OptionlHit intersect(Ray const&)const;
};