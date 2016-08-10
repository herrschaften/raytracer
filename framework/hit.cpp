#include "hit.hpp"
#include <cmath> // INFINITY


Hit::Hit():
	m_hit{ false },
	m_distance{ INFINITY },
	m_point{ glm::vec3{ INFINITY, INFINITY, INFINITY } },
	m_normal{ glm::vec3{ INFINITY, INFINITY, INFINITY } },
	m_shape{ nullptr } {}



Hit::Hit(bool hit, double distance, glm::vec3 const& intersection,
        glm::vec3 const& normal, std::shared_ptr<Shape> shape):
	m_hit{hit},
	m_distance{distance},
	m_point{intersection},
	m_normal{normal},
	m_shape{shape} {}

