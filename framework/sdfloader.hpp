/*sdfloader.hpp 
Feel free to load.
*/
#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP
#include <string>
#include "scene.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "color.hpp"
#include <glm/vec3.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include "material.hpp"
#include <sstream>
#include <map>

class SDFLoader {
public:
    static Scene load(std::string const& inpath); //static: freie Funktion
};
#endif
