/*sphere.hpp 
Feel free to sphere around.
*/

#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include "shape.hpp"
#include "hit.hpp"

class Sphere : public Shape {
public: 
  //KONSTRUTOREN----------------------------------------------------------------
  Sphere();
  Sphere(glm::vec3 const& ctr, float rad);
  Sphere(std::string const& name, Material const& mat, glm::vec3 const& ctr, float rad); 
  Sphere(std::string const& name, std::shared_ptr<Material> mat, glm::vec3 const& ctr, float rad);//Scne Mater
  ~Sphere() override; // Aufgabe 5.8

  //FUNKTIONEN------------------------------------------------------------------
  glm::vec3 const& center() const;
  float radius() const;

  void center(glm::vec3 const& ctr);
  void radius(float const& rad);

  float area() const override;
  float volume() const override;
  
  std::ostream& print(std::ostream& os) const override;
  Hit intersect(Ray const& ray) const override;
  
private:
  glm::vec3 m_center;
  float m_radius;
};

#endif // BUW_SPHERE_HPP