/*composite.cpp 
Feel free to compost!
*/
#include "composite.hpp"
#include <cmath>
#include <catch.hpp>
#include <algorithm>
/*
!!!
NOT WORKING 
!!!
*/
//KONSTRUTOREN----------------------------------------------------------------------
	Composite::Composite() :
	m_name("default-comp"),
	m_shapes() {}

	Composite::Composite(std::string const& name ):
	m_name(name),
	m_shapes() {}

	Composite::~Composite() {}

//FUNKTIONEN-------------------------------------------------------------------------
	 
	 /*ADD
	  ######################################
	  Fügt Shape hinzu! */
	void Composite::add(shape_pointer shape) 
	{
		m_shapes.push_back(shape);
   	}
      /*Fkt: ohit
	  ######################################
	  Gibt das durch einen Ray als erstes
	  getroffene Objekt mit DATA zurück! */
  Hit Composite::ohit(Ray const& ray) const
  {
    Hit hit;
    Hit temphit;
    for( auto &i : m_shapes)
    {
      temphit= i->intersect(ray);
      if(temphit.m_distance<hit.m_distance)
      {
        hit = temphit;
        hit.m_shape=i; //Unschön... aber ist jetzt so basta
      }
    } 
    return hit;
  }
