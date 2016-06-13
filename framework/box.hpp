//box.hpp abgeleitete Klasse von shape.hpp
#ifndef BOX_HPP
#define BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape{
public:
  Box();
  Box(glm::vec3 const& min, glm::vec3 const& max);
  Box(const Box&);

  float area() const override;
  
  float volume() const override;

  //getter:
  glm::vec3 const& min() const;
  glm::vec3 const& max() const;

private:
  glm::vec3 m_min;
  glm::vec3 m_max;
};
#endif //box.hpp