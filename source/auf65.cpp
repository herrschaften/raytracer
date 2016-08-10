//auf 65: textfile read
#include <iostream>
#include <fstream>
#include <string>
#include "material.hpp"
#include <map>
#include <sstream>
#include "raytracer.hpp"

int main(int argc, char* argv[]) {
  /*
  ######################################
  //Beispielaufruf
  mit:
    -Input Path (mit n vielen ".txt"-Dateien)
    -width
    -height
    -Output Path (für n viel Bilder)

  ######################################
  */
  Raytracer rat("./zurendern", 60, 60, "./output");  //Vom Pfad in dem ihr die Datei startet bruda
  rat.render();

  return 0;
}