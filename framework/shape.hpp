/*shape.hpp 
Feel free to shape yourself.
*/
#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include "material.hpp"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <cmath>
#include <string>
#include <iostream>
#include <memory>
#include "ray.hpp"

struct Hit;

class Shape {
public:
  //KONSTRUTOREN----------------------------------------------------------------------
  Shape();
  //Shape(std::string const& name, Material const& mat);
  Shape(std::string const& name, std::shared_ptr<Material> mat);
  virtual ~Shape(); 

  //FUNKTIONEN------------------------------------------------------------------------
  //virtual float area() const = 0;
  //virtual float volume() const = 0;
  virtual std::ostream& print(std::ostream& os) const; 
  virtual Hit intersect(Ray ray) const = 0;
  
  std::string name() const;
  std::shared_ptr<Material> material() const;
  //
  //bool transf()const;
  //glm::vec3 const& transl() const;
  //
  virtual void scale(float faktor) = 0;
  virtual void rotate(float angle,glm::vec3 const& vec) = 0;
  virtual void translate(glm::vec3 const& vec)  = 0;
  //
  //virtual glm::vec3 const& getFixpoint() const = 0;


private: 
  std::string m_name;
  std::shared_ptr<Material> m_mat;
  //
  //bool m_transf;
  //glm::vec3 m_transl;
  //glm::vec3 m_rotate;
  /*
  glm::mat4 m_tmat;
  glm::mat4 m_tmatinv;
  */

};

std::ostream& operator << (std::ostream& os, Shape const& s);

#endif // BUW_SHAPE_HPP