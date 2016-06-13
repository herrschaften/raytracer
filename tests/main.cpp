#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("center test","aufgabe5.2"){//{{{
  //Box b1{};
  auto b1 = std::make_shared<Box> ();
  REQUIRE (b1->min().x == 1.0f);
  auto s1 = std::make_shared<Sphere> ();
  REQUIRE (s1->radius() == 1.0f);
}//}}}

TEST_CASE("methoden area volume","aufgabe5.2"){//{{{
  //Default: Konstruktor
  auto b1 = std::make_shared<Box> ();
  REQUIRE (b1->area() == 6*1.0f);
  REQUIRE(b1->volume() == 1.0f);

  auto s1 = std::make_shared<Sphere> ();
  REQUIRE (s1->area() == Approx(4*3.1416));
  REQUIRE (s1->volume() == Approx(4.18879));
}//}}}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}