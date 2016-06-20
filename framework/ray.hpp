#include <glm/vec3.hpp> //toBe GREAT

struct Ray{
	Ray();
	Ray(glm::vec3 const& orig, glm::vec3 const& dir):
		origin_{orig},
		direction_{dir}
	{}
	
	glm::vec3 origin_={0.0f,0.0f,0.0f};//Easy
	glm::vec3 direction_={1.0f,0.0f,0.0f};
};