# CMake generated Testfile for 
# Source directory: /home/phil/Desktop/Dropbox/Aktuelle Aufgaben/SoftwareI/ThPhRayMan/raytracer
# Build directory: /home/phil/Desktop/Dropbox/Aktuelle Aufgaben/SoftwareI/ThPhRayMan/raytracer/framework
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(tests "/home/phil/Desktop/Dropbox/Aktuelle Aufgaben/SoftwareI/ThPhRayMan/raytracer/framework/build/Release/tests")
SUBDIRS(external/glfw-3.0.3)
SUBDIRS(framework)
SUBDIRS(source)
SUBDIRS(tests)
