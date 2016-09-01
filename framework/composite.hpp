/*composite.hpp 
Feel free to compost!
*/
#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include <memory>
#include <string>
#include <vector>



#include "box.hpp"
#include "sphere.hpp"
#include "ray.hpp"
#include "hit.hpp"



class Composite : public Shape 
{
 public:
    typedef std::shared_ptr<Shape> shape_pointer;
    //KONSTRUTOREN----------------------------------------------------------------------
    Composite();
    Composite(std::string const& name);
    ~Composite();

    //FUNKTIONEN-------------------------------------------------------------------------
    Hit intersect(Ray ray) const;
    /*
    void translate(glm::vec3 const& distance) override;
    void rotate(double angle, glm::vec3 const& point) override;
    void scale(double scale_factor) override;
    */
    void add(shape_pointer  shape_ptr);
    //
    void scale(float faktor) override;
    void rotate(float angle,glm::vec3 const& vec) override;
    void translate(glm::vec3 const& vec) override;


 private:
    std::string m_name;
    std::vector<shape_pointer> m_shapes;
};

#endif
