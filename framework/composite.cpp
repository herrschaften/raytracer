/*composite.cpp 
Feel free to compost!
*/
#include "composite.hpp"
/*
!!!
NOT WORKING 
!!!
*/
//KONSTRUTOREN----------------------------------------------------------------------
	Composite::Composite() :
	m_shapes() {}
	Composite::~Composite() {}

//FUNKTIONEN-------------------------------------------------------------------------
	 /*ADD
	  ######################################
	  Fügt Shape hinzu, wenn nicht schon vom
	  Namen vorhanden */
	void Composite::add(shape_pointer shape_ptr) 
	{
		std::cout<<"Hier2\n"<<shape_ptr->name();
    	m_shapes.insert(std::make_pair(shape_ptr->name(),shape_ptr));
    	std::cout<<"Hier3\n";
	}  //Alternative: stackoverflow.com/questions/5106170/how-do-i-know-if-stdmap-insert-succeeded-or-failed

    //Hit Composite::intersect(Ray const& ray) const override;
