/*scene.hpp 
Feel free to camo!
*/
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <string>
#include <glm/vec3.hpp>
#include "ray.hpp"

struct Camera
{
	//KONSTRUTOREN----------------------------------------------------------------
	Camera();
	Camera(std::string const& name, float fovx);
	//Camera(std::string const& name, float fovx, 
	//	glm::vec3 const& eye, glm::vec3 const& dir, glm::vec3 const& up);
	
	//VARIABLEN-------------------------------------------------------------------
    std::string m_name;
    float m_fovx;
    
    glm::vec3 m_eye; //<eye>, <dir>
    glm::vec3 m_dir;
    glm::vec3 m_up;
    

};
#endif