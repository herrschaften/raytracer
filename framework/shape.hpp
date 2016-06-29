// shape.hpp Great

#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include "color.hpp"
#include "material.hpp"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <cmath>
#include <string>
#include <iostream>

class Shape {
public:
  Shape();
  Shape(std::string const& name, Material const& mat);
  virtual ~Shape(); 

  virtual float area() const = 0;
  virtual float volume() const = 0;
  virtual std::ostream& print(std::ostream& os) const; 
  
  std::string name() const;
  Material const& material() const;

private: 
  std::string m_name;
  Material m_mat;
};

std::ostream& operator << (std::ostream& os, Shape const& s);

#endif // BUW_SHAPE_HPP