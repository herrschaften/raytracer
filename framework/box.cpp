#include "box.hpp"



Box::Box() :
  m_min{1.0},
  m_max{0.0}{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
  m_min{min},
  m_max{max}{}

float Box::area() const{
    return 2*(
    	abs(m_min.x-m_max.x)*abs(m_min.y-m_max.y)+
    	abs(m_min.y-m_max.y)*abs(m_min.z-m_max.z)+
    	abs(m_min.z-m_max.z)*abs(m_min.x-m_max.x)
    	);
  }
  
float Box::volume() const{
    return (abs(m_min.x-m_max.x)*abs(m_min.y-m_max.y)*abs(m_min.z-m_max.z));
  }

//getter:
glm::vec3 const& Box::min() const {return m_min;}
glm::vec3 const& Box::max() const {return m_max;}