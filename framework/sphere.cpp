/*sphere.cpp 
Feel free to sphere around.
*/

#include "sphere.hpp"

 //KONSTRUTOREN----------------------------------------------------------------------
  //Default 
  Sphere::Sphere() :
  Shape {"Sphere", {}},
  m_center {0.0f, 0.0f, 0.0f}, 
  m_radius {1.0f} 
  {}

  // Custom 1
  Sphere::Sphere(glm::vec3 const& ctr, float rad) :
  Shape {"Sphere",{}}, 
  m_center {ctr},
  m_radius {rad} 
  {std::cout << "Sphere-Construction: " << name()<< std::endl;}

  /*//Custom 2
  Sphere::Sphere(std::string const& name, Material const& mat, glm::vec3 const& ctr, float rad) :
  Shape {name, mat},
  m_center {ctr}, 
  m_radius {rad} 
  {std::cout << "Sphere-Construction: " << Shape::name()<< std::endl;}*/

  //Custom 3
  Sphere::Sphere(std::string const& name, std::shared_ptr<Material> mat, glm::vec3 const& ctr, float rad) :
  Shape {name, mat},
  m_center {ctr}, 
  m_radius {rad} 
  {std::cout << "Sphere-Construction: " << Shape::name()<< std::endl;}

  //Destruktor
  Sphere::~Sphere() 
  {
    std::cout << "Sphere-Destruction: " << Shape::name()<< std::endl;
  }

//GETTER----------------------------------------------------------------------
  glm::vec3 const& Sphere::center() const 
  {
    return m_center;
  }
  float Sphere::radius() const 
  {
    return m_radius;
  }

//Setter----------------------------------------------------------------------
  void Sphere::center(glm::vec3 const& ctr) 
  {
    m_center = ctr;
  }
  void Sphere::radius(float const& rad) 
  {
    m_radius = rad;
  }

//FUNKTIONEN----------------------------------------------------------------------
 /* Uninteressant:
  float Sphere::area() const 
  {
    return (4.0f*M_PI*pow(m_radius,2.0f));
  }
  float Sphere::volume() const 
  {
    return (4.0f*M_PI*pow(m_radius,3.0f)/3.0f);//Betrag unnötig?
  }*/
  //print
  std::ostream& Sphere::print(std::ostream& os) const 
  {
    Shape::print(os); //Name, Color

    os << "Center: (" << m_center.x << ", " 
    << m_center.y << ", " 
    << m_center.z << ")" << "\n" 

    << "Radius: " << m_radius
    << std::endl;

    return os;
  }
  Hit Sphere::intersect(Ray ray) const
    {
      if (transf())
      {
        ray.m_origin-=transl();
      }
      Hit spherehit;

      spherehit.m_hit = glm::intersectRaySphere
        (
          ray.m_origin, ray.m_direction,
          m_center, m_radius, 
          spherehit.m_point, spherehit.m_normal //Indirekte param.
        ); 

      if (spherehit.m_hit) //=true ->extra Info
      {
        spherehit.m_distance = glm::distance(ray.m_origin, spherehit.m_point);
        spherehit.m_shape = this;
         if (transf())
        {
          spherehit.m_point+=transl();
        }
        
      }
        
      return spherehit;
    }

    void Sphere::scale(float faktor)
    {
      m_radius*=faktor;
    }

    void Sphere::rotate(float angle,glm::vec3 const& vec)
    {
      //DO NOTHING: YOu ALWAYS lOOk tHe Same, beautifull shape
      //my dear, you are a Sphere!
      //-and not an Egg, or some other dreck!
    }