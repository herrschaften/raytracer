/*box.hpp 
Feel free to be a box!
*/

#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"
#include "hit.hpp"

class Box : public Shape{
public: 
  //KONSTRUTOREN----------------------------------------------------------------
  Box();
  Box(glm::vec3 const& min, glm::vec3 const& max);
  //Box(std::string const& name, Material const& mat, glm::vec3 const& min, glm::vec3 const& max);
  Box(std::string const& name, std::shared_ptr<Material> mat, glm::vec3 const& min, glm::vec3 const& max);
  ~Box()override;

  //GETTER----------------------------------------------------------------------
  glm::vec3 const& max() const;
  glm::vec3 const& min() const;

  //SETTER----------------------------------------------------------------------
  void max(glm::vec3 const& max);
  void min(glm::vec3 const& min);

  //FUNKTIONEN------------------------------------------------------------------
  //float area() const override;
  //float volume() const override;
  std::ostream& print(std::ostream& os) const override; 
  Hit intersect(Ray ray) const override;
  
  

private:
  glm::vec3 m_min;
  glm::vec3 m_max;
};

#endif // BUW_BOX_HPP