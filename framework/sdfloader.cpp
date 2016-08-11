/*sdfloader.cpp 
Feel free to load.
*/
#include <string>
#include "scene.hpp"
#include "sdfloader.hpp"
#include <fstream>
#include <sstream>

Scene SDFLoader::load(std::string const& inpath)
{
    Scene scene;

    std::string line;
    std::ifstream myfile(inpath);

    if (myfile.is_open())
    {   
        std::cout <<"Deine mutter rotzt in der gegnd umher Vol.i" <<"\n";
        while (getline(myfile,line))
        {   
            std::stringstream ss;
            ss<<line;                   //First Line in
            std::string firstWord;
            ss>>firstWord;              //First Word in

            if (firstWord=="define")
            {   
                std::cout << "Definiere: ";
                ss>>firstWord;
                if(firstWord == "material")//##############-Material
                {   
                    //Material-Info------
                    std::string matname;
                    Color ka;
                    Color kd;
                    Color ks;
                    float faktor;
                    //-------------------

                    std::cout << "Material\n";
                    //Einlesen:
                    ss >> matname;

                    ss >> ka.r;
                    ss >> ka.g;
                    ss >> ka.b;

                    ss >> kd.r;
                    ss >> kd.g;
                    ss >> kd.b;

                    ss >> ks.r;
                    ss >> ks.g;
                    ss >> ks.b;

                    ss >> faktor;

                    //Einspeichern
                    Material* material=new Material(matname, ka, kd, ks, faktor);
                    scene.m_materials.insert(std::pair<std::string, Material*>(matname, material));
                }           
                else if(firstWord == "shape")//##############-Shape
                {
                    ss>>firstWord;
                    std::cout << "Shape: ";

                    if(firstWord == "box") //##############-Box
                    {   
                        std::cout << "Box\n";
                        std::string boxname;
                        glm::vec3 min;
                        glm::vec3 max;
                        std::string materialname;

                        ss >> boxname;
                        ss >> min.x;
                        ss >> min.y;
                        ss >> min.z;

                        ss >> max.x;
                        ss >> max.y;
                        ss >> max.z;

                        ss >> materialname;

                        //Einspeichern
                        Material* material = new Material;
                        material = (scene.m_materials.find(materialname)->second);
                    
                        Box* box = new Box(boxname, material, min, max);
                        
                        scene.m_shapes.push_back(box);
                    }else if(firstWord == "sphere") //##############-Sphere
                    {   
                        std::cout << "Sphere\n";
                        std::string spherename;
                        glm::vec3 center;
                        float radius;
                        std::string materialname;
                        
                        ss >> spherename;

                        ss >> center.x;
                        ss >> center.y;
                        ss >> center.z;

                        ss >> radius;
                        ss >> materialname;

                        //Einspeichern
                        Material* material1 = new Material;
                        material1 = (scene.m_materials.find(materialname)->second);

                        Sphere* sphere = new Sphere(spherename, material1, center, radius);
                        
                        scene.m_shapes.push_back(sphere);
                    }
                }
                else if(firstWord == "light") //##############-Light
                {
                    ss>>firstWord;
                    std::string lightname;
                    Color lightcolor;
                    glm::vec3 lightpoint;

                    std::cout << "Lights: ";

                    if(firstWord != "ambient") //##############-stand.Light
                    {   
                        std::cout << "Diffuse\n";
                        ss >> lightname;
                        ss >> lightpoint.x;
                        ss >> lightpoint.y;
                        ss >> lightpoint.z;

                        ss >> lightcolor.r;
                        ss >> lightcolor.g;
                        ss >> lightcolor.b;
                    
                        //Einspeichern
                        Light* light = new Light(lightname, lightcolor, lightpoint);
                        scene.m_lights.push_back(light);
                    }
                    else                                //##############-ambi. Light
                    {                               
                        std::cout << "Ambient\n";
                        ss >> lightname; //ambient needs no lightname -> its just a color.
                        ss >> lightcolor.r;
                        ss >> lightcolor.g;
                        ss >> lightcolor.b;

                        //Einspeichern
                        scene.m_ambient = lightcolor;
                    }
                }else if(firstWord == "camera")//##############-Camera
                {
                    std::string camname;
                    float fovx;

                    std::cout << "Camera\n";

                    ss >> camname;
                    ss >> fovx;
                
                    //Einspeichern
                    scene.m_camera=Camera(camname,fovx);
                }
            }
        }
    myfile.close();
  }
  else std::cout << "Unable to open file"; 

  return scene;
}