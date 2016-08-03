// SDFLoader.hpp
// Tohrbe GREAT

#ifndef BUW_SDFLOADER_HPP
#define BUW_SDFLOADER_HPP

#include "scene.hpp"
#include <string>
#include <vector>

class SDFLoader {
public:
    static Scene load(std::string const& inpath);
    /*static Material getMaterial(string name, std::vector<Material> data);
    static LightPoint getLight(string name, std::vector<LightPoint> data);
    static std::shared_ptr<RenderObject> const& getShape(string name, std::vector<std::shared_ptr<RenderObject>> data); 
	*/
};
#endif // BUW_SDFLOADER_HPP