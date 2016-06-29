#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <ostream>
#include "color.hpp"
#include <string>

struct Material //Aufgabe 6.4
{	
//KONSTRUTOREN----------------------------------------------------------------------
  
  //Default
	Material():
	name 	{"Default"}, 
	ka  	{0.0f,0.0f,0.0f},
	kd  	{0.0f,0.0f,0.0f},
	ks  	{0.0f,0.0f,0.0f},
	m   	{0.0f}{}

	//Custom 
	Material(std::string const& Name, Color const& k1, Color const& k2, Color const& k3, float M):
	name	{Name},
	ka 		{k1},
	kd 		{k2},
	ks 		{k3},
	m 		{M}{}

//Funktionen-------------------------------------------------------------------------
	//print
	friend std::ostream& operator<<(std::ostream& os, Material const& mat ) 
	{
		os << "name: " << mat.name << "\n"
		<<"ka: "<< mat.ka
		<<",kd: "<< mat.kd
		<<",ks: "<< mat.ks
		<<",m: " << mat.m << "\n";
		return os;
	}

	//Variablen
	std::string name;

	Color ka;
	Color kd;
	Color ks;
	
	float m;
};
#endif
