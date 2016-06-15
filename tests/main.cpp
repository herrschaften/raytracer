// main.cpp (Programmiersprachen Aufgabenblatt 5)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
//#include <glm/glm.hpp>
//#include <glm/glx/intersect.hpp>


TEST_CASE("default Konstrukt, getter, area volume","aufgabe5.1-2"){
  //Default: Konstruktor
  auto b1 = std::make_shared<Box> ();
  REQUIRE (b1->min().x == 0.0f);
  REQUIRE (b1->min().y == 0.0f);
  REQUIRE (b1->min().z == 0.0f);

  REQUIRE (b1->max().x == 1.0f);
  REQUIRE (b1->max().y == 1.0f);
  REQUIRE (b1->max().z == 1.0f);

  REQUIRE (b1->area() == 6*1.0f);
  REQUIRE(b1->volume() == 1.0f);
  
  auto s1 = std::make_shared<Sphere> ();
  REQUIRE (s1->radius() == 1.0f);
  REQUIRE (s1->center() == glm::vec3(0.0f,0.0f,0.0f));

  REQUIRE (s1->area() == Approx(4*3.1416));
  REQUIRE (s1->volume() == Approx(4.18879));
  
}

TEST_CASE("customt Konstrukt, getter, area volume","aufgabe5.1-2"){
  //Default: Konstruktor
  auto b1 = std::make_shared<Box> (glm::vec3(0.0,1.0,2.0),glm::vec3(-3.0,-4.0,-5.0));
  REQUIRE (b1->min().x == 0.0f);
  REQUIRE (b1->min().y == 1.0f);
  REQUIRE (b1->min().z == 2.0f);

  REQUIRE (b1->max().x == -3.0f);
  REQUIRE (b1->max().y == -4.0f);
  REQUIRE (b1->max().z == -5.0f);

  REQUIRE (b1->area() == 142.0f);
  REQUIRE(b1->volume() == 105.0f);


  auto s1 = std::make_shared<Sphere> (glm::vec3(3.0,1.0,-4.0), 2.0f);
  REQUIRE (s1->radius() == 2.0f);
  REQUIRE (s1->center() == glm::vec3(3.0f,1.0f,-4.0f));

  REQUIRE (s1->area() == Approx(50.265482f));
  REQUIRE (s1->volume() == Approx(33.5103216f));

}

TEST_CASE("Konstrukts Box, name, color, getter","aufgabe5.3"){
  //Default: Konstruktor

	Box b1{};
  REQUIRE("Box" == b1.name());

  REQUIRE(0.0f == b1.color().r);
  REQUIRE(0.0f == b1.color().g);
  REQUIRE(0.0f == b1.color().b);

  //Custom 1
  Box b2 {{1.5f, 2.7f, -4.1f}, {0.0f, 0.0f, 11.0f}};
  REQUIRE("Box" == b2.name());

  REQUIRE(0.0f == b2.color().r);
  REQUIRE(0.0f == b2.color().g);
  REQUIRE(0.0f == b2.color().b);

  //Custom 2
  Box b3 {"ClevreKiste",{1.0f, 0.5f, 1.0f},{1.5f, 2.7f, -4.1f}, {0.0f, 0.0f, 11.0f}};

  REQUIRE("ClevreKiste" == b3.name());

  REQUIRE(1.0f == b3.color().r);
  REQUIRE(0.5f == b3.color().g);
  REQUIRE(1.0f == b3.color().b);
}

TEST_CASE("Konstrukts Sphere, name, color, getter","aufgabe5.3"){
  //Default: Konstruktor

	Sphere s1{};
  REQUIRE("Sphere" == s1.name());

  REQUIRE(0.0f == s1.color().r);
  REQUIRE(0.0f == s1.color().g);
  REQUIRE(0.0f == s1.color().b);

  //Custom 1
  Sphere s2 {{0.8f, 0.3f, 0.5f}, 7.2f};

  REQUIRE("Sphere" == s2.name());

  REQUIRE(0.0f == s2.color().r);
  REQUIRE(0.0f == s2.color().g);
  REQUIRE(0.0f == s2.color().b);

  //Custom 2
  Sphere s3 {"schlaukugl", {0.8f, 0.3f, 0.5f}, {0.8f, 0.3f, 0.5f}, 0.9f};

  REQUIRE("schlaukugl" == s3.name());

  REQUIRE(0.8f == s3.color().r);
  REQUIRE(0.3f == s3.color().g);
  REQUIRE(0.5f == s3.color().b);

}


TEST_CASE("Shape: print method", "[aufgabe5.4-5]") {

	Box b1{};
  	Box b2 {{1.5f, 2.7f, -4.1f}, {0.0f, 0.0f, 11.0f}};
  	Box b3 {"ClevreKiste",{1.0f, 0.5f, 1.0f},{1.5f, 2.7f, -4.1f}, {0.0f, 0.0f, 11.0f}};
  	std::cout<<"Boxengasse:\n"<<b1<<"\n"<<b2<<"\n"<<b3<<"\n";
	

	Sphere s1{};
	Sphere s2 {{0.8f, 0.3f, 0.5f}, 7.2f};
	Sphere s3 {"schlaukugl", {0.8f, 0.3f, 0.5f}, {0.8f, 0.3f, 0.5f}, 0.9f};
	std::cout<<"kugelgasse:\n"<<s1<<"\n"<<s2<<"\n"<<s3<<"\n";

	//Wie teste ich dingsbums Shape cout..
}

TEST_CASE("intersectRaySphere", "[aufgabe5.6]") {
  // Ray
  glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
  // ray direction has to be normalized !
  // you can use : 
  // v = glm::normalize(some_vector)
  glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};

  // Sphere
  glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
  float sphere_radius{1.0f};

  float distance{0.0f};
  auto result = glm::intersectRaySphere(
    ray_origin, ray_direction,
    sphere_center,
    sphere_radius * sphere_radius, // squared radius !!!
    distance);

  REQUIRE(distance == Approx(4.0f));
  //Selfmade test
  	Sphere s3 {"schlaukugl", {0.8f, 0.3f, 0.5f}, {0.0f, 0.0f, 5.0f}, 1.0f};
  	glm::vec3 ray_direction2{1.0f, 0.0f, 0.0f};
  	Ray rayman {ray_origin, ray_direction2};
  	float raymanistweitweg=0.0f;
	REQUIRE(!(s3.intersect(rayman, raymanistweitweg)));
	Ray rayman2 {ray_origin, ray_direction};
	REQUIRE((s3.intersect(rayman2, raymanistweitweg)));
  	REQUIRE(distance == Approx(4.0f));
  	
  	ray_origin +=glm::vec3(0.0f,0.0f,5.0f);
  	Ray rayman3 {ray_origin,ray_direction2};
  	REQUIRE((s3.intersect(rayman3, raymanistweitweg)));
  	REQUIRE(raymanistweitweg == Approx(1.0f));

}


/* ------------------ Aufgabe 5.8 ------------------ */
/*
TEST_CASE("Destructor: virtual vs. non-virtual", "[aufgabe5.8]") {
  Color red(255, 0, 0); 
  glm::vec3 position(0, 0, 0);

  Sphere* s1 = new Sphere("sphere0", red, position, 1.2); 
  Shape* s2 = new Sphere("sphere1", red, position, 1.2);

  s1->print(std::cout); 
  std::cout << std::endl;
  s2->print(std::cout);
  delete s1; 
  delete s2;
}
*/
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}