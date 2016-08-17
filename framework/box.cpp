/*box.cpp 
Feel free to be a box!
*/

#include "box.hpp"
#include <cmath>
#include <catch.hpp>
#include <algorithm>

//KONSTRUTOREN----------------------------------------------------------------
  
  //Default
  Box::Box() : 
  Shape {"Box",{}}, 
  m_min {0.0f, 0.0f, 0.0f}, 
  m_max {1.0f, 1.0f, 1.0f} {}

  // Custom 1 
  Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
  Shape {"Box",{}}, 
  m_min {min}, 
  m_max {max} {}

  /*// Custom 2 //Material Umstellung, deswegen unnötig!
  Box::Box(std::string const& name, Material const& mat, glm::vec3 const& min, glm::vec3 const& max) : 
  Shape {name, mat},
  m_min {min}, 
  m_max {max} {}*/

  // Custom 3
  Box::Box(std::string const& name, std::shared_ptr<Material> mat, glm::vec3 const& min, glm::vec3 const& max) : 
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

//FUNKTIONEN------------------------------------------------------------------
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

  /*Întersect
  ######################################
  Prüft in Hit boxhit.m_hit ob der Strahl
  die Box trifft(bool).
  In welcher Entfernung, boxhit.m_distance
  wird geschnitten?
  Übergabe per Pointer der Box in
  boxhit.m_shape.
  Der Śchnittpunkt liegt in
  boxhit.m_point.

  Grund-Verfahren-Source: 
  http://www.scratchapixel.com/
  lessons/3d-basic-rendering/
  minimal-ray-tracer-rendering
  -simple-shapes/ray-box-intersection
   */
  Hit Box::intersect(Ray const& ray) const
  {

    Hit boxhit;
    
    double t1 = (m_min.x - ray.m_origin.x)*ray.m_inv_direction.x;
    double t2 = (m_max.x - ray.m_origin.x)*ray.m_inv_direction.x;
    double tmin = std::min(t1, t2);
    double tmax = std::max(t1, t2);

    t1 = (m_min.y - ray.m_origin.y)*ray.m_inv_direction.y;
    t2 = (m_max.y - ray.m_origin.y)*ray.m_inv_direction.y;
    tmin = std::max(tmin, std::min(t1, t2));
    tmax = std::min(tmax, std::max(t1, t2));

    t1 = (m_min.z - ray.m_origin.z)*ray.m_inv_direction.z;
    t2 = (m_max.z - ray.m_origin.z)*ray.m_inv_direction.z;
    tmin = std::max(tmin, std::min(t1, t2));
    tmax = std::min(tmax, std::max(t1, t2));

    if (tmax > std::max(0.0, tmin)) //Hit?
    {   
        boxhit.m_hit = true;
        boxhit.m_distance = sqrt(tmin*tmin*(
                                ray.m_direction.x*ray.m_direction.x +
                                ray.m_direction.y*ray.m_direction.y +
                                ray.m_direction.z*ray.m_direction.z));
        
        boxhit.m_shape = this;
        boxhit.m_point = glm::vec3{tmin*ray.m_direction.x, tmin*ray.m_direction.y, tmin*ray.m_direction.z};
        
        if ((boxhit.m_point.x)==Approx(m_max.x))
        {
           boxhit.m_normal=glm::vec3(1.0f,0.0f,0.0f); // right 
        }else if ((boxhit.m_point.x)==Approx(m_min.x))
        {
          boxhit.m_normal=glm::vec3(-1.0f,0.0f,0.0f); //left
        }else if ((boxhit.m_point.y)==Approx(m_max.y))
        {
          boxhit.m_normal=glm::vec3(0.0f,1.0f,0.0f); //fup
        }else if ((boxhit.m_point.y)==Approx(m_min.y))
        {
          boxhit.m_normal=glm::vec3(0.0f,-1.0f,0.0f); //down
        }else if ((boxhit.m_point.z)==Approx(m_max.z))
        {
          boxhit.m_normal=glm::vec3(0.0f,0.0f,1.0f); //front
        }else
        {
          boxhit.m_normal=glm::vec3(0.0f,0.0f,-1.0f); //back
        }   
    }
    return boxhit;
  }