//sphere.hpp abgeleitetet klasse von shape.hpp
#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "shape.hpp"
#include <math.h>
#include <glm/vec3.hpp>

//definition von sphere

class Sphere : public Shape{
public:
  Sphere();
  Sphere(glm::vec3 const& mpnt, float r);
  Sphere(const Sphere&);

  float area() const override;// foo.area()

  float volume() const override;

  //getter:
  glm::vec3 const& center() const;
  float radius() const;

private:
  glm::vec3 m_center;
  float m_radius;
};
#endif //sphere.hpp