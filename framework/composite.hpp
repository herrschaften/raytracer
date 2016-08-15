/*composite.hpp 
Feel free to compost!
*/
#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include <memory>
#include <string>
#include <map>

#include "box.hpp"
#include "ray.hpp"

class Composite : public Shape 
{
    /*
    !!!
NOT WORKING 
!!!
*/
 public:
    //
    typedef std::shared_ptr<Shape> shape_pointer;

    //KONSTRUTOREN----------------------------------------------------------------------
    Composite();
    ~Composite();

    //FUNKTIONEN-------------------------------------------------------------------------
    //Hit intersect(Ray const& ray) const override;
    /*
    void translate(glm::vec3 const& distance) override;
    void rotate(double angle, glm::vec3 const& point) override;
    void scale(double scale_factor) override;
    */

    void add(shape_pointer shape_ptr);
 

 private:
    std::map<std::string, shape_pointer> m_shapes;
};

#endif