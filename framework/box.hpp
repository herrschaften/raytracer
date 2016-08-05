// shape.hpp GREAT

#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"
#include "hit.hpp"

class Box : public Shape {
public: 
  Box();
  Box(glm::vec3 const& min, glm::vec3 const& max);
  Box(std::string const& name, Material const& mat, glm::vec3 const& min, glm::vec3 const& max);
  Box(std::string const& name, Material*, glm::vec3 const& min, glm::vec3 const& max);
  ~Box()override;

  glm::vec3 const& max() const;
  glm::vec3 const& min() const;
  void max(glm::vec3 const& max);
  void min(glm::vec3 const& min);

  float area() const override;
  float volume() const override;
  std::ostream& print(std::ostream& os) const override; 
  Hit intersect(Ray const& ray) const override; //Lo und Lucas
  //bool intersect ( Ray const & r , float & distance ) const override;
  

private:
  glm::vec3 m_min;
  glm::vec3 m_max;
};

#endif // BUW_BOX_HPP