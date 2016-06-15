// shape.cpp GREAT

#include "shape.hpp"
//KONSTRUTOREN----------------------------------------------------------------------
  
  //Default
	Shape::Shape() :
	m_name {"Shape"}, 
	m_color {0.0f, 0.0f, 0.0f} {}

	//Custom
	Shape::Shape(std::string const& name, Color const& color) : 
	m_name {name},
	m_color {color} {}

	  // Destructor 
	Shape::~Shape() 
	{
	  std::cout << "Shape Destructor: " << m_name << std::endl;
	}
//GETTER----------------------------------------------------------------------

	std::string Shape::name() const 
	{
	  return m_name;
	}

//SETTER----------------------------------------------------------------------

	Color const& Shape::color() const 
	{
	  return m_color; 
	}

//FUNKTIONEN---------------------------------------------------------------------

	  // print 1
	std::ostream& Shape::print(std::ostream& os) const 
	{
	  os << "Name: " << m_name << "\n" 

	  << "Color RGB: (" << m_color.r << ", " 
	  << m_color.g << ", " 
	  << m_color.b << ")" << std::endl;
	  return os;
	}

	  // print 2
	std::ostream& operator << (std::ostream& os, Shape const& s) 
	{
	  return s.print(os);
	}