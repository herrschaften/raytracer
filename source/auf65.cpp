//auf 65: textfile read
#include <iostream>
#include <fstream>
#include <string>
#include "material.hpp"
#include <map>
#include <sstream>


int main () {
  std::string line;
  std::ifstream myfile ("../Material.sdf");

  std::map<std::string, Material> materials;

  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      std::stringstream ss;

      ss<<line;

      Material mat;
      
      std::string keyword;

      ss>>keyword;
      ss>>keyword;
      ss>>mat.name;
      //ambient
      ss >> mat.ka.r;
      ss >> mat.ka.g;
      ss >> mat.ka.b;
      //diffuse
      ss >> mat.kd.r;
      ss >> mat.kd.g;
      ss >> mat.kd.b;
      //specular
      ss >> mat.ks.r;
      ss >> mat.ks.g;
      ss >> mat.ks.b;
      //m
      ss >> mat.m;

      materials[mat.name] = mat; //nach alphabet sortiert..

      std::cout<<mat;
    }
    myfile.close();
  }

  else std::cout << "Unable to open file"; 

  return 0;
}