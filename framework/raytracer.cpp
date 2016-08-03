// raytracer.cpp 
// Thorbe GREAT
#include "raytracer.hpp"
#include "sdfloader.hpp"
//
//KONSTRUTOREN----------------------------------------------------------------------
  
  //Default
  

  // Custom 1 
  Raytracer::Raytracer(std::string const& inpath, unsigned int width, unsigned int height, std::string const& outpath):
	  m_in {inpath}, 
	  m_width {width}, 
	  m_height {height},
	  m_out{outpath}
	  {}

  //Destruktor
//FUNKTIONEN----------------------------------------------------------------------
	void Raytracer::render()
	{
		
		Scene scene; 
    /*
    ######################################
    Idee.: per while schleife durch Ordner 
    und die jeweilige .txt datei an den 
    Renderer schicken...
    mit boost oder doch lieber Vector oder 
    andere Lösung... später!
    ######################################

    */
    scene = SDFLoader::load("../file.txt");
    //renderer(scene, resolution, output);

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