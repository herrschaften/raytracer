/*camera.cpp 
Feel free to camo!
*/
#include "camera.hpp"

	//KONSTRUTOREN----------------------------------------------------------------
		//Default
		Camera::Camera(): 
			m_name{"default-cam"},
			m_fovx{1.5707f}, //bei 90 Grad Pi
			m_cam{},
			m_eye{glm::vec3(0.0f,0.0f,0.0f)},
			m_dir{glm::vec3(0.0f,0.0f,-1.0f)},
			m_up{glm::vec3(0.0f,1.0f,0.0f)}{}
		//Custom 1
		Camera::Camera(std::string const& name, float fovx, glm::mat4 cam):
			m_name{name},
			m_fovx{fovx}, 
			m_cam{cam},
			m_eye{glm::vec3(0.0f,0.0f,0.0f)},
			m_dir{glm::vec3(0.0f,0.0f,-1.0f)},
			m_up{glm::vec3(0.0f,1.0f,0.0f)}{}


		
	
	