#include <glm/vec3.hpp> //toBe GREAT

struct Ray{
	Ray():
		origin_{0.0f},
		direction_{0.0}
		{}

	Ray(glm::vec3 const& orig, glm::vec3 const& dir):
		origin_{orig},
		direction_{dir},
		inv_direction{glm::vec3{1.0/dir.x, 1.0/dir.y, 1.0/dir.z}}
	{}
	
	glm::vec3 origin_={0.0f,0.0f,0.0f};//Easy
	glm::vec3 direction_={1.0f,0.0f,0.0f};
	glm::vec3 inv_direction;
};