#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"



TEST_CASE("default Konstrukt, getter, area volume","aufgabe5.1-2"){
  //Default: Konstruktor
  auto b1 = std::make_shared<Box> ();
  REQUIRE (b1->min().x == 1.0f);
  REQUIRE (b1->min().y == 1.0f);
  REQUIRE (b1->min().z == 1.0f);

  REQUIRE (b1->max().x == 0.0f);
  REQUIRE (b1->max().y == 0.0f);
  REQUIRE (b1->max().z == 0.0f);

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


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}