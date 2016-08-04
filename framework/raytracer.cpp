// raytracer.cpp 
// Thorbe GREAT
#include "raytracer.hpp"
#include "sdfloader.hpp"
//
//KONSTRUTOREN----------------------------------------------------------------------
  
  //Default
  
   /*Custom 1 
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


  //Destruktor

//FUNKTIONEN----------------------------------------------------------------------
  /*FKT 1
  ######################################	
  Aufruf zum rendern. Fkt organisiert in 
  Form einer Schleife alle zu rendernden
  Dateien und übergibt die Scenen dazu an
  den Renderer weiter!*/
  void Raytracer::render()
	{
    /*
    ######################################
    Idee.: per while schleife durch Ordner 
    und die jeweilige.txt datei an den 
    Renderer schicken...
    mit boost oder doch lieber Vector oder 
!   andere Lösung... später!
    ######################################*/

    std::string file="../file.txt";
    bool done = false;
    while (!done)  //durch n files
    {
      if (true) //eine ".txt"
      {
        Scene scene = SDFLoader::load(file);
        //renderer(scene, resolution, output);
      }
      done = true;
    }

    /*
		if(!fs::exists(m_in) || !fs::is_directory(m_in)) return;

	    fs::recursive_directory_iterator it(m_in);
	    fs::recursive_directory_iterator endit;
    */
    /*
	    while(it != endit)
	    {
	        if(fs::is_regular_file(*it) && it->path().extension() == ".txt") {
				std::cout<<it->path().filename();
			}			
	        ++it;

	    }
    */
	}