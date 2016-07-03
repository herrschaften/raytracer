// box.cpp GREAT
#include "ray.hpp"
#include "box.hpp"
//KONSTRUTOREN----------------------------------------------------------------------
  
  //Default
  //name:Box, Color: 0,0,0, Seitenlänge: 1
  Box::Box() : 
  Shape {"Box", {}}, 
  m_min {0.0f, 0.0f, 0.0f}, 
  m_max {1.0f, 1.0f, 1.0f} {}

  // Custom 1 
  Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
  Shape {"Box", {}}, 
  m_min {min}, 
  m_max {max} {}

  // Custom 2
  Box::Box(std::string const& name, Material const& mat, glm::vec3 const& min, glm::vec3 const& max) : 
  Shape {name, mat},
  m_min {min}, 
  m_max {max} {}

  //Destruktor
  Box::~Box() 
  {
    std::cout << "Box-Destruction: " << Shape::name()<< std::endl;
  }

//GETTER----------------------------------------------------------------------

  glm::vec3 const& Box::max() const 
  {
    return m_max;
  }

  glm::vec3 const& Box::min() const 
  {
    return m_min;
  }

//SETTER----------------------------------------------------------------------

  void Box::max(glm::vec3 const& max) 
  {
    m_max = max;
  }

  void Box::min(glm::vec3 const& min) 
  {
    m_min = min;
  }

//FUNKTIONEN----------------------------------------------------------------------
  float Box::area() const 
  {
    glm::vec3 diff= m_max - m_min; //Differenz
    return 2 * (abs(diff.x * diff.y) + abs(diff.x * diff.z) + abs(diff.y * diff.z));
  }
  
  float Box::volume() const 
  {
    glm::vec3 diff = m_max - m_min; //Differenz
    return abs(diff.x * diff.y * diff.z);
  }

  // print
  std::ostream& Box::print(std::ostream& os) const 
  {
    Shape::print(os);

    os << "Minimum: (" << m_min.x << ", " 
    << m_min.y << ", " 
    << m_min.z << ")" << "\n" 

    << "Maximum: (" << m_max.x << ", " 
    << m_max.y << ", " 
    << m_max.z << ")" << std::endl;

    return os;
  }

  //intersect
  //aufgabe5.10
bool Box::intersect(Ray const& ray, float& distance)
{
  
  distance = -1;

  float close, next;
 
  glm::vec3 diff = m_max-m_min;
  glm::vec3 diffmin = m_min-ray.origin_;
  glm::vec3 diffmax = m_max-ray.origin_;

  if (ray.direction_==glm::vec3{0.0,0.0,0.0})
  {
    return false;
  }
  else if (ray.direction_.x != 0.0) //x-plane
  {
      float t= (diffmin.x/ray.direction_.x);
      glm::vec3 pnt=ray.origin_+ray.direction_*t;
  } //keep on the good work man
  //
    /*
  float tnear,tfar;
  distance = -1;

  if (ray.direction_.x != 0.0) // direction 0?
  {
    float t1 = (min_.x - ray.origin_.x) / ray.direction_.x;
    float t2 = (max_.x - ray.origin_.x) / ray.direction_.x;
    tfar = std::max(t1,t2);
    tnear = std::min(t1,t2);
  }
  else 
  {
    if(min_.x > ray.origin_.x || max_.x < ray.origin_.x) {return false;}
  }

  if (ray.direction_.y != 0.0)
  {
    float t1 = (min_.y - ray.origin_.y) / ray.direction_.y;
    float t2 = (max_.y - ray.origin_.y) / ray.direction_.y;
    float tnear = std::max(tnear, std::min(t1,t2));
    float tfar = std::min(tfar, std::max(t1,t2));
    if (tnear > tfar)
    {
      return false;
    }
  }
  else 
  {
    if(min_.y > ray.origin_.y || max_.y < ray.origin_.y) {return false;}
  }

  if (ray.direction_.z != 0.0)
  {
    float t1 = (min_.z - ray.origin_.z) / ray.direction_.z;
    float t2 = (max_.z - ray.origin_.z) / ray.direction_.z;
    tnear = std::max(tnear, std::min(t1,t2));
    tfar = std::min(tfar, std::max(t1,t2));
    if (tnear > tfar)
    {
      return false;
    }
  }
  else 
  {
    if(min_.z > ray.origin_.z || max_.z < ray.origin_.z) {return false;}
  }

  distance = tnear*sqrt(ray.direction_.x*ray.direction_.x +
                ray.direction_.y*ray.direction_.y +
                ray.direction_.z*ray.direction_.z);
                */
  return true;
}
