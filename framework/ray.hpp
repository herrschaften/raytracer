/*ray.hpp 
Feel free to be a Rayman!
*/
#ifndef RAY_HPP
#define RAY_HPP

#include <glm/glm.hpp> //toBe GREAT

struct Ray{

	 //KONSTRUTOREN----------------------------------------------------------------
	Ray():
		m_origin{0.0f},
		m_direction{0.0}
		{} 
	Ray(glm::vec3 const& orig, glm::vec3 const& dir):
		m_origin{orig},
		m_direction{dir},
		m_inv_direction{glm::vec3{1.0/dir.x, 1.0/dir.y, 1.0/dir.z}}
		{}

	//VARIABLEN--------------------------------------------------------------------
	glm::vec3 m_origin={0.0f,0.0f,0.0f};//Easy
	glm::vec3 m_direction={1.0f,0.0f,0.0f};
	glm::vec3 m_inv_direction;
};
Ray transformRay(glm::mat4 const& mat, Ray const& ray);
#endif