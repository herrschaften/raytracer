// box.cpp GREAT
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

  // Custom 3
  Box::Box(std::string const& name, Material* const& mat, glm::vec3 const& min, glm::vec3 const& max) : 
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

Hit Box::intersect(Ray const& ray) const
{

    Hit boxhit;
    
    double t1 = (m_min.x - ray.origin_.x)*ray.inv_direction.x;
    double t2 = (m_max.x - ray.origin_.x)*ray.inv_direction.x;
    double tmin = std::min(t1, t2);
    double tmax = std::max(t1, t2);

    t1 = (m_min.y - ray.origin_.y)*ray.inv_direction.y;
    t2 = (m_max.y - ray.origin_.y)*ray.inv_direction.y;
    tmin = std::max(tmin, std::min(t1, t2));
    tmax = std::min(tmax, std::max(t1, t2));

    t1 = (m_min.z - ray.origin_.z)*ray.inv_direction.z;
    t2 = (m_max.z - ray.origin_.z)*ray.inv_direction.z;
    tmin = std::max(tmin, std::min(t1, t2));
    tmax = std::min(tmax, std::max(t1, t2));



    if (tmax > std::max(0.0, tmin))
    {   
        boxhit.m_hit = true;
        boxhit.m_distance = sqrt(tmin*tmin*(
                                ray.direction_.x*ray.direction_.x +
                                ray.direction_.y*ray.direction_.y +
                                ray.direction_.z*ray.direction_.z));

        boxhit.m_shape = std::make_shared<Box> (*this);
        boxhit.m_intersection = glm::vec3{tmin*ray.direction_.x, tmin*ray.direction_.y, tmin*ray.direction_.z};
    }

    /* Alte!

  float txmin = (m_min.x - ray.origin.x) / ray.direction.x; 
    float txmax = (m_max.x - ray.origin.x) / ray.direction.x; 
 
    if (txmin > txmax) std::swap(txmin, txmax); 
    float tmin = txmin;
    float tmax = txmax;
 
    float tymin = (m_min.y - ray.origin.y) / ray.direction.y; 
    float tymax = (m_max.y - ray.origin.y) / ray.direction.y; 
 
    if (tymin > tymax) std::swap(tymin, tymax); 
 
    if ((tmin > tymax) || (tymin > tmax)) 
        boxhit.m_hit = false; 
 
    if (tymin > tmin) 
        tmin = tymin; 
 
    if (tymax < tmax) 
        tmax = tymax; 
 
    float tzmin = (m_min.z - ray.origin.z) / ray.direction.z; 
    float tzmax = (m_max.z - ray.origin.z) / ray.direction.z; 
 
    if (tzmin > tzmax) std::swap(tzmin, tzmax); 
 
    if ((tmin > tzmax) || (tzmin > tmax)) 
        boxhit.m_hit = false; 
 
    if (tzmin > tmin) 
        tmin = tzmin; 
 
    if (tzmax < tmax) 
        tmax = tzmax; 
 
    boxhit.m_hit = true;
   
    
    if (boxhit.m_hit)
    {
        boxhit.m_distance = sqrt((txmin-ray.origin.x)*(txmin-ray.origin.x)+
                                (tymin-ray.origin.y)*(tymin-ray.origin.y)+
                                (tzmin-ray.origin.z)*(tzmin-ray.origin.z)
                                );

        boxhit.m_shape = std::make_shared<Box> (*this);
        boxhit.m_intersection = glm::vec3{tmin*ray.m_dir.x, tmin*ray.m_dir.y, tmin*ray.m_dir.z};
    }

    //nur zum pushen hinzugefügt
    */

    



    /*
    if (tmax > std::max(0.0, tmin)) {
        boxhit.m_distance = 
        );

        boxhit.m_intersection = glm::vec3{
            tmin*ray.m_dir.x, tmin*ray.m_dir.y, tmin*ray.m_dir.z
            };
        boxhit.m_normal = normal(boxhit.m_intersection);
        boxhit.m_shape = std::make_shared<Box>(*this);
        boxhit.m_hit = true;
    }
    */

    return boxhit;
}
/*
  //intersect
  //aufgabe5.10
  bool Box::intersect ( Ray const & r , float & distance ) const
  {  //Source: http://www.scratchapixel.com/lessons/3d-basic-rendering/
     //minimal-ray-tracer-rendering-simple-shapes/ray-box-intersection
      //eventuell robusterbauen
      float tmin = (m_min.x - r.origin_.x) / r.direction_.x; 
      float tmax = (m_max.x - r.origin_.x) / r.direction_.x; 
   
      if (tmin > tmax) std::swap(tmin, tmax); 
   
      float tymin = (m_min.y - r.origin_.y) / r.direction_.y; 
      float tymax = (m_max.y - r.origin_.y) / r.direction_.y; 
   
      if (tymin > tymax) std::swap(tymin, tymax); 
   
      if ((tmin > tymax) || (tymin > tmax)) 
          return false; 
   
      if (tymin > tmin) 
          tmin = tymin; 
   
      if (tymax < tmax) 
          tmax = tymax; 
   
      float tzmin = (m_min.z - r.origin_.z) / r.direction_.z; 
      float tzmax = (m_max.z - r.origin_.z) / r.direction_.z; 
   
      if (tzmin > tzmax) std::swap(tzmin, tzmax); 
   
      if ((tmin > tzmax) || (tzmin > tmax)) 
          return false; 
   
      if (tzmin > tmin) 
          tmin = tzmin; 
   
      if (tzmax < tmax) 
          tmax = tzmax; 
      distance=tmin;
    //distance anpassen!!
      
      return true; 

  } */