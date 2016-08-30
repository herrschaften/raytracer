/*renderer.hpp 
Feel free to render!
*/
#ifndef BUW_RENDERER_HPP
#define BUW_RENDERER_HPP

#include "color.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include <string>
#include <glm/glm.hpp>
#include "scene.hpp"
#include "hit.hpp"
#include "camera.hpp"


class Renderer
{
public:
  //KONSTRUTOREN----------------------------------------------------------------------
  //Custom 1
  Renderer( Scene const& scene, 
            unsigned int width, 
            unsigned int height, 
            std::string const& ofile);

  //FUNKTIONEN------------------------------------------------------------------------
  void render();
  void write(Pixel const& p);

  //Hit ohit(Ray const& ray) const; //Optional Hit
  Color raytrace(Ray const& ray, unsigned int depth);
  
  inline std::vector<Color> const& colorbuffer() const //für Preview
  {
    return m_colorbuffer;
  }
  inline bool const& processing() const //für Preview
  {
    return m_processing;
  }
  //Lichtberechnung:
  void add_ambientlight(Color & clr, Color const& ka);
  void add_pointlight(Color & clr, std::shared_ptr<Light> const& light, Hit const& Schlag);
  /*->*/void add_diffuselight(Color & clr, Hit const& Schlag, std::shared_ptr<Light> const& light, Ray const& raylight);
  /*->*/void add_specularlight(Color & clr, Hit const& Schlag, std::shared_ptr<Light> const& light,  Ray const& raylight);
  void add_reflectedlight(Color & clr, Hit const& Schlag, Ray const& ray, unsigned int);


private:
  Scene m_scene;
  unsigned int m_width;
  unsigned int m_height;
  std::vector<Color> m_colorbuffer;
  std::string m_outfile;
  PpmWriter m_ppm;
  bool m_processing;
};
#endif // #ifndef BUW_RENDERER_HPP
