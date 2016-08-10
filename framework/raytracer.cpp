/*raytracer.cpp 
Feel free to be rat-race!
*/
#include "raytracer.hpp"
#include "sdfloader.hpp"
#include "renderer.hpp"
//
#include <iostream>
#include <algorithm>
#include <string>
#include <dirent.h>
//
#include <thread>
#include <fensterchen.hpp>

//KONSTRUTOREN----------------------------------------------------------------------
  //Default
   /*CUSTOM 1 
  ######################################
  Setzt Raytracer Custom auf. Kann nun
  in gewünschter Auflösung beliebig viele
  ".sdf" Dateien nacheinander Rendern! */
  Raytracer::Raytracer(std::string const& inpath, unsigned int width, unsigned int height, std::string const& outpath):
	  m_in {inpath}, 
	  m_width {width}, 
	  m_height {height},
	  m_out{outpath}
	  {}

//FUNKTIONEN----------------------------------------------------------------------
  /*RENDER 1
  ######################################	
  Aufruf zum rendern. Fkt organisiert in 
  Form einer Schleife alle zu rendernden
  Dateien und übergibt die Scenen dazu an
  den Renderer weiter!*/
  void Raytracer::render()
	{
    /*
    ######################################
    Zum durchsuchen der Ordner siehe Quelle:
    http://stackoverflow.com/questions/19189014
    /how-do-i-find-files-with-a-specific-extension
    -in-a-directory-that-is-provided-by
    ######################################*/
    DIR *dir = opendir(m_in.c_str());         //In Input-path
    dirent *entry;    

    std::string suffix=".txt";
    auto fit=[&suffix](const std::string& s) //Lambda: Checks entry for suffix
      { 
      return((s.size() >= suffix.size() )&& (equal(suffix.rbegin(), suffix.rend(), s.rbegin())));
      };

    unsigned int count=1;
    while((entry = readdir(dir))!=nullptr)    //Durch alle Files
    {
      if(fit(entry->d_name))
      { //Ablauf für eine SDF-Datei:

        std::cout << "<Datei: " << count << std::endl; 
        std::string filepath= std::string(m_in)+"/"+entry->d_name;
        std::cout << "-SDFLoader:" << filepath << std::endl;
        Scene scene = SDFLoader::load(filepath);    //LOAD
    
        std::string outputfile=
          std::string(m_out)          //Pfad
          +"/out"                     //Präfix
          +std::string(entry->d_name) //Name
          .substr(0, std::string(entry->d_name).size()-3)
          +"ppm";                     //Suffix

        Renderer rendi(scene, m_width, m_height, outputfile); 
        std::thread thr([&rendi]() { rendi.render(); }); //RENDER
        
      //------------------------------------------------------------------- 
      //folgendes nachher löschen ? 
        Window win(glm::ivec2(m_width,m_height));

        while (rendi.processing()) 
        {
          if (win.isKeyPressed(GLFW_KEY_ESCAPE)) 
          {
              win.stop();
          }

          glDrawPixels( m_width, m_height, GL_RGB, GL_FLOAT
          , rendi.colorbuffer().data());

          win.update();
        }
        thr.join();
        
      //-------------------------------------------------------------------
        std::cout << "-rendered: " << outputfile<< std::endl;         
        count++;
      }
    }
    std::cout << "Kein weiterer File zu rendern!\n";
  }
  