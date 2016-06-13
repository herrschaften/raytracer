//shape.hpp
#ifndef SHAPE_HPP
#define SHAPE_HPP

//basisklasse shape deklaration
//vererbt an:
//Sphere
//Box
//

class Shape{
public:
  virtual float area() const = 0; // foo.area()
  virtual float volume() const = 0;

protected:

private:
};
#endif //shape.hpp