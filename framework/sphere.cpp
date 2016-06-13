#include "sphere.hpp"



Sphere::Sphere() : 
  m_center{0.0f, .0f, .0f},
  m_radius{1.0f}{}

Sphere::Sphere(glm::vec3 const& mpnt, float r) : 
  m_center{mpnt},
  m_radius{r}{}

 float Sphere::area() const
{
	return (4.0f*M_PI*pow(m_radius,2.0f));
}

float Sphere::volume() const //yolo420
{
	return (4.0f*M_PI*pow(m_radius,3.0f)/3.0f);
}

//getter:
glm::vec3 const& Sphere::center() const {return m_center;}
float Sphere::radius() const {return m_radius;}
