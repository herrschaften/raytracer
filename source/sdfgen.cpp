
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <iostream>
#include <sys/stat.h>
#include <cmath>
#include <math.h> 

float calcradius(float value)
{
	return (-0.00326885*pow(value,6)
			+0.000624217*pow(value,5)
			+0.0888064*pow(value,4)
			+0.0474312*pow(value,3)
			-0.630738*pow(value,2) 
			-1.10534*value +4);
}

int main(int argc, char* argv[]) {
	const int imagecount = 2;


	std::array<std::string, imagecount> outputNames;

	for (int  i = 0; i < imagecount; ++i) 
	{
		outputNames[i] = "scene" + std::to_string(i) + ".txt";
		
		std::cout << outputNames[i] <<"\n";
	}

	for (int i = 0; i < imagecount; ++i)
	{
		std::ofstream fOut("zurendern/"+outputNames[i]);
		//BASIC SCENE GEN:
		fOut
			<<"define material red   1 0 0 1 0 0 1 1 1 0 0 40" << std::endl
			<<"define material green 0 1 0 0 1 0 1 1 1 0 0 40" << std::endl
			<<"define material blue  0 0 1 0 0 1 1 1 1 0 0 40" << std::endl
			<<"define material mat_yellow  0.70 0.30 0.15 0.70 0.30 0.15 0.90 0.90 0.90 0.5 0 40" << std::endl
			<<"define material mat_red     0.46 0.00 0.18 0.46 0.00 0.18 0.90 0.90 0.90 0.1 0.3 40" << std::endl
			<<"define material mat_blue    0.36 0.48 0.78 0.36 0.48 0.78 0.90 0.90 0.90 0.3 0 40" << std::endl
			<<"define material mat_lblue   0.42 0.82 1.00 0.42 0.82 1.00 0.90 0.90 0.90 0 0 40" << std::endl
			<<"define material mat_orange  0.60 0.20 0.20 0.60 0.20 0.20 0.90 0.90 0.90 0.3 0 40" << std::endl
			<<"define material yellow  1 1 0 1 1 0 0.90 0.90 0.90 0.8 0 40" << std::endl;


		int anglex;
		float z = 1;
		float x = 1;
				
		int objects=2000;
		//
		float dist=-30.0f;
		float HIy=5.0f;
		float LOy=-5.0f;
		float radius;
		for(int j=0;j<objects; j++) //SET UP: SPHERERS
		{
			float x;
			float y;
			float z;

			float r;
			//y=LOy+static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2-0.0)));

			y=LOy + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HIy-LOy)));
			radius=calcradius(-y);
			//LOx=-(−0.00326885x^6+0.000624217x^5+0.0888064x^4+0.0474312x^3−0.630738x^2−1.10534x+4)
			x=-radius + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2*radius)));
			z=dist-radius+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2*radius)));		

			r=0.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.125-0.0)));

			fOut
			<<"define shape sphere num"+std::to_string(j)+" "
/* cen*/	+std::to_string(x)+" "
			+std::to_string(y)+" "
			+std::to_string(z)+" "

			+std::to_string(r)+" "

			+"mat_orange" << std::endl;
		}
			
			//Box
		/*
		fOut
			<<"define shape box num1  -1  -1   -1    1    1    1   mat_orange" << std::endl
			<<"define shape box num2   7  -6  -93    17 -16  -83   mat_blue" << std::endl
			<<"define shape box num3 -29   5  -93   -19  -5  -83   red" << std::endl
			<<"define shape box num4  -5   5  -93     5  -5  -83   red" << std::endl
			<<"define shape box num5  19   5  -93    29  -5  -83   mat_lblue" << std::endl
			<<"define shape box num6  -1  -1   -1     1   1    1   mat_red" << std::endl
			<<"define shape box num7   7  16  -93    17   6  -83   mat_orange" << std::endl
			*/	
		
			//SET UP: COMPOSITE!
			fOut
			<<"define shape composite root";
			for(int j=0;j<objects; j++)
			{
				fOut
				<<"num"+std::to_string(j)+" ";
			}
			fOut
			<<std::endl;
			

			//transform
			//<<"transform num1 rotate " << to_string(anglex)<< " 1 1 0" << endl
			//<<"transform num6 rotate " << to_string(anglex)<< " 1 1 0"<< endl

			/*
			<<"transform num14 scale "<< " 1 " << std::to_string(z) << " 1 "<< std::endl
			<<"transform num9 scale " << std::to_string(z)<< " 1 1"<< std::endl
			<<"transform num4 scale " << std::to_string(z)<< " " << std::to_string(x) <<"  1"<< std::endl
			
			
			
			
			<<"transform num1 scale 5 5 5" << std::endl 
			<<"transform num2 scale 1 1 1" << std::endl 
			<<"transform num3 scale 1 1 1" << std::endl 
			<<"transform num4 scale 1 1 1" << std::endl 
			<<"transform num5 scale 1 1 1" << std::endl 
			<<"transform num6 scale 5 5 5" << std::endl 
			<<"transform num7 scale 1 1 1" << std::endl 


			<<"transform num6 translate -10 11 -88" << std::endl 
			<<"transform num1 translate -10 -11 -88" << std::endl 
			//<<"define shape box num1 -17  -6  -93    -7 -16  -83   mat_orange" << endl
			//<<"define shape box num6 -17  16  -93    -7   6  -83   mat_red" << endl
			
			

			<<"#transform num2 translate 0 -1 0"<< std::endl
			<<"#transform num2 scale 100 0 1000"<< std::endl
			<<"#transform num3 scale " << std::to_string(z) << " 1 2" << std::endl
			*/

			//Lights
			fOut
			<<"define light diffuse sun1 0 0 3 1 1 1" << std::endl
			<<"define light ambient ambient 0.1 0.08 0.1" << std::endl

			//Camera
			<<"define camera guck 30 0 0 0" << std::endl;
			//<< cameraCmd << endl
		fOut.close();

	}

	return 0;
}