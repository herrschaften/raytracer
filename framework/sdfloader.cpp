/*sdfloader.cpp 
Feel free to load.
*/
#include <string>
#include "scene.hpp"
#include "composite.hpp"
#include "sdfloader.hpp"
#include <fstream>
#include <sstream>

Scene SDFLoader::load(std::string const& inpath)
{
    typedef std::shared_ptr<Shape> shape_pointer;

    Scene scene;
    std::map<std::string, shape_pointer> tmpcomp;


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
                    float kr;
                    float ko;
                    float ke;
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

                    ss >> kr;
                    ss >> ko;
                    ss >> ke;
                    ss >> faktor;

                    //Einspeichern
                    std::shared_ptr<Material> material=std::make_shared<Material>(matname, ka, kd, ks, kr, ko, ke, faktor);
                    scene.m_materials.insert(std::pair<std::string, std::shared_ptr<Material>>(matname, material));
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
                        std::shared_ptr<Material> material=(scene.m_materials.find(materialname)->second);
        
                        shape_pointer box= std::make_shared<Box>(boxname, material, min, max);
                        tmpcomp.insert(std::pair<std::string, shape_pointer>(box->name(), box));
                 
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
                        std::shared_ptr<Material> material=(scene.m_materials.find(materialname)->second);

                        shape_pointer sphere= std::make_shared<Sphere>(spherename, material, center, radius);
                        tmpcomp.insert(std::pair<std::string, shape_pointer>(sphere->name(), sphere));
                        
                    }else if (firstWord == "composite")
                    {
                        std::cout<< "Composite\n";
                        std::string compname;
                        std::string shapename;

                        ss>> compname;
                        scene.m_composite= std::make_shared<Composite>(compname);
                        while (!ss.eof())
                        {
                            ss>>shapename;
                            auto search = tmpcomp.find(shapename);
                            if(search != tmpcomp.end()) 
                            {
                                scene.m_composite->add(search->second);
                            }   
                        }
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
                        std::shared_ptr<Light> light= std::make_shared<Light>(lightname, lightcolor, lightpoint);
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
                    glm::vec3 pos;
                    glm::vec3 dir;
                    glm::vec3 up;

                    glm::mat4 cam;

                    std::cout << "Camera\n";

                    ss >> camname;
                    ss >> fovx;
           
                    ss >> pos.x;
                    ss >> pos.y;
                    ss >> pos.z;

                    ss >> dir.x;
                    ss >> dir.y;
                    ss >> dir.z;

                    ss >> up.x;
                    ss >> up.y;
                    ss >> up.z;

                    //Rechnung
                    dir=glm::normalize(dir);
                    up=glm::normalize(up);
                    cam[3]= glm::vec4(pos,1.0f);

                    cam[2]= glm::vec4(dir*-1.0f,0.0f);

                    cam[0]= glm::vec4(glm::cross(glm::normalize(dir),up),0.0f);

                    cam[1]= glm::vec4(up,0.0f);
                    
                    //Einspeichern
                    scene.m_camera=Camera(camname,fovx, cam);
                }
            }else if (firstWord == "transform")
            {
                std::string shapename, transform;
                float x, y, z;

                ss >> shapename;
                

                auto shape = tmpcomp.find(shapename);
                if(shape != tmpcomp.end()) 
                {   
                    ss >> transform;
                    if (transform == "scale") 
                    {
                        float faktor;
                        ss >> faktor;   //EASY VERSION
                        shape->second->scale(faktor);
                    }else if (transform == "rotate") 
                    {     
                        float angle;
                        ss >> angle;

                        ss >> x;
                        ss >> y;
                        ss >> z;

                        shape->second->rotate(angle,glm::vec3(x,y,z));
                    }else if (transform == "translate")
                    {
                        ss >> x;
                        ss >> y;
                        ss >> z;

                        shape->second->translate(glm::vec3(x,y,z));
                    }
                }/*else if(shapename == scene.m_camera.m_name)
                {
                    hier
                } */                    
            }
        }
    myfile.close();
  }
  else std::cout << "Unable to open file"; 

  return scene;
}