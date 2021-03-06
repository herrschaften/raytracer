/*renderer.cpp 
Feel free to render!
*/
#include "renderer.hpp"
#include <glm/glm.hpp>
#include <math.h>//asin

//KONSTRUTOREN----------------------------------------------------------------------
   /*Custom 1 
  ######################################
  Setzt Renderer Custom mit gewünschter
  Szene, Resolution und Output auf. 
  Nun kann gerendert werden */
  Renderer::Renderer(Scene const& scene, unsigned int width, unsigned int height, std::string const& ofile): 
    m_scene(scene),
    m_width(width), 
    m_height(height), 
    m_colorbuffer(width*height, Color(0.0, 0.0, 0.0)), 
    m_outfile(ofile),
    m_ppm(m_width, m_height),
    m_processing(false)
    {}

//FUNKTIONEN------------------------------------------------------------------------
  /*Fkt: render
  ######################################
  Organisiert die Pixel Farbgebung! */
  void Renderer::render()
  {

    m_processing=true;
    
    float distance =-(float(m_width)/2)/tan(M_PI*m_scene.m_camera.m_fovx/(2*180)); //IN Grad
    std::cout<<distance<<"\n";
    
    float height = (-float(m_height)/2); 
    for (unsigned y = 0; y < m_height; ++y) {     //Vertikal
      float width = (-float(m_width)/2);
      
      for (unsigned x = 0; x < m_width; ++x) {    //Horizontal
        Pixel p(x,y);
        //std::cout<<"Pixel"<<x<<","<<y<<"\n";

        //For Preview
        p.color=Color(1.0,1.0,1.0);
        write(p); 

        Ray rayman {{0,0,0}, glm::vec3(width, height, distance)};

       if (m_scene.aliasfaktor>0)
       {
         p.color=antialiasing(rayman, m_scene.aliasfaktor, m_scene.depth);   //ANTIALIASIN
       }else{
        rayman.m_direction=glm::normalize(rayman.m_direction);
        rayman=transformRay(m_scene.m_camera.m_cam,rayman);
        p.color = raytrace(rayman, m_scene.depth);
      }
      
       
       tonemapping(p); 

        write(p);
        width++;
      }
      height++;
    }
    m_ppm.save(m_outfile);
    m_processing=false;
  }

   /*Fkt: write
  ######################################
  Schreibt einfach schön herum
  (ppmwriter)! Hab ich nicht geschrieben */
  void Renderer::write(Pixel const& p)
  {
    // flip pixels, suck dick , because of opengl glDrawPixels
    size_t buf_pos = (m_width*p.y + p.x);
    if (buf_pos >= m_colorbuffer.size() || (int)buf_pos < 0) 
    {
      std::cerr << "Fatal Error Renderer::write(Pixel p) : "
        << "pixel out of ppm_ : "
        << (int)p.x << "," << (int)p.y
        << std::endl;
    }else 
    {
      m_colorbuffer[buf_pos] = p.color;
    }
    m_ppm.write(p);
  }

   /*Fkt: raytrace
  ######################################
  Ermittelt die Fabrbe!:
       */
  Color Renderer::raytrace(Ray const& ray, unsigned int depth)
  {

    Hit Hitze =m_scene.m_composite->intersect(ray); 
     
    if(Hitze.m_hit==true) //Treffer?
    {  
      Color clr;
  
      add_ambientlight(clr,Hitze.m_shape->material()->ka);      //AMBIENT
            
      //Überprüfe nun alle direkten Lichtwege
      for(auto& light : m_scene.m_lights) 
      {
        add_pointlight(clr, light, Hitze, ray);                      //DIFFUSE & SPECULAR 
      }

      if (depth>0)
      {
        add_reflectedlight(clr, Hitze,ray, depth);              //REFLECTION
        if (Hitze.m_shape->material()->opac)
        {
          refractedlight(clr, Hitze,ray, depth);
        }
      }
                                                                //REFRACTION?
    return clr;   
    }
  return m_scene.m_ambient; //Schuß ins nirgendswo!
  }    

/*Lichtberechnungen:
######################################*/
void Renderer::add_ambientlight(Color & clr, Color const& ka)
{
  clr+=(m_scene.m_ambient)*(ka);  //+=I_a*k_a
}

void Renderer::add_pointlight(Color & clr, std::shared_ptr<Light> const& light, Hit const& Schlag, Ray const& ray)
{
        
        glm::vec3 direct=glm::normalize(light->m_point-Schlag.m_point);
        Ray raylight
        {
          Schlag.m_point+(direct*0.001f), //nicht selbst Treffen
          direct
        };       

        int distance= glm::length(Schlag.m_point-light->m_point);
        Hit LightHitze = m_scene.m_composite->intersect(raylight);
        
        if (LightHitze.m_distance>distance) //Licht?
        {
          add_diffuselight(clr, Schlag, light, raylight);
          add_specularlight(clr, Schlag, light, raylight, ray);
        }//else{Schatten
}

/*->*/void Renderer::add_diffuselight(Color & clr, Hit const& Schlag, std::shared_ptr<Light> const& light,  Ray const& raylight)
      {
        float faktor=(glm::dot(glm::normalize(Schlag.m_normal) , raylight.m_direction));
        clr+= (light->m_color) * (Schlag.m_shape->material()->kd) * (std::max(faktor,0.0f));  
      }

/*->*/void Renderer::add_specularlight(Color & clr, Hit const& Schlag, std::shared_ptr<Light> const& light,  Ray const& raylight, Ray const& ray)
      {
        
        float faktor = glm::dot(
                                  glm::normalize(ray.m_direction), 
                                  glm::normalize(glm::reflect(raylight.m_direction, Schlag.m_normal))
                                  ); 
        
        faktor = pow(std::max(faktor, 0.0f),Schlag.m_shape->material()->m);
        clr+= (light->m_color) * (Schlag.m_shape->material()->ks) * (faktor);
      }

void Renderer::add_reflectedlight(Color & clr, Hit const& Schlag, Ray const& ray, unsigned int depth)
{
  glm::vec3 direct=glm::normalize(glm::reflect(ray.m_direction,Schlag.m_normal));
  Ray rayrefly{Schlag.m_point+(direct*0.001f),direct};  
  
  Color refColor = raytrace(rayrefly, depth-1);   // Ebene tiefer bitte!
  clr += (refColor) * (Schlag.m_shape->material()->ks);// * (Schlag.m_shape->material()->kr);
}

void Renderer::refractedlight(Color & clr, Hit const& Schlag, Ray const& ray, unsigned int depth)
{
  glm::vec3 direct=glm::normalize(glm::refract(ray.m_direction,Schlag.m_normal, Schlag.m_shape->material()->eta));
  Ray refr_ray{Schlag.m_point+(direct*0.001f),direct}; 

  Color refr_Color = raytrace(refr_ray, depth-1);
  clr+=refr_Color*(Schlag.m_shape->material()->opac); 
}

void Renderer::tonemapping(Pixel & p)
{
  p.color.r= p.color.r/(p.color.r+1);
  p.color.g= p.color.g/(p.color.g+1);
  p.color.b= p.color.b/(p.color.b+1);
}

  //antialiasing(renderer.rayman, m_scene.aliasfaktor, m_scene.depth)
  Color Renderer::antialiasing(Ray const& ray,float aliasfaktor, unsigned int depth)
  {
    Color clr;
    int breite= sqrt(aliasfaktor);
   

        float height = (-1.0f); 
        for (unsigned y = 0; y < breite; ++y) {     //Vertikal
          float width = (-1.0f);
          
          for (unsigned x = 0; x < breite; ++x) {    //Horizontal
           
            
            Ray rayman {{0,0,0}, glm::normalize(glm::vec3(ray.m_direction.x+width, ray.m_direction.y+height, ray.m_direction.z))};

            rayman=transformRay(m_scene.m_camera.m_cam,rayman);
            clr +=raytrace((rayman), depth);

            width+=2/breite;
          }
          height+=2/breite;
        }

     

        clr.r=clr.r/aliasfaktor; 
        clr.g=clr.g/aliasfaktor;
        clr.b=clr.b/aliasfaktor;
    
      return clr;
      

      
     
    }