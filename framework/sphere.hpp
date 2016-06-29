// shape.hpp GREAT

#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include "shape.hpp"
#include "ray.hpp"

class Sphere : public Shape {
public: 
  Sphere();
  Sphere(glm::vec3 const& ctr, float rad);
  Sphere(std::string const& name, Material const& mat, glm::vec3 const& ctr, float rad); 
  ~Sphere() override; // Aufgabe 5.8

  glm::vec3 const& center() const;
  float radius() const;
  void center(glm::vec3 const& ctr);
  void radius(float const& rad);

  float area() const override;
  float volume() const override;
  std::ostream& print(std::ostream& os) const override;
 
  bool intersect(Ray const& ray, float& distance);

private:
  glm::vec3 m_center;
  float m_radius;
};

#endif // BUW_SPHERE_HPP