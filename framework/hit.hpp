/*hit.hpp 
Feel free to hit!
*/
#ifndef HIT_HPP
#define HIT_HPP
#include "shape.hpp"
#include <memory>


class Shape;

struct Hit
{
	//KONSTRUTOREN----------------------------------------------------------------
	Hit();
	Hit(bool hit, double distance, glm::vec3 const& intersection,
        glm::vec3 const& normal, std::shared_ptr<Shape> const& shape);

	//VARIABLEN-------------------------------------------------------------------
    bool m_hit; 
    double m_distance;
    glm::vec3 m_point;
    glm::vec3 m_normal;
    std::shared_ptr<Shape> m_shape;
};

#endif