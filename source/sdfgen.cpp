
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <iostream>
#include <sys/stat.h>
#include <cmath>
#include <math.h> 
#include <tuple>

float calcradius(float value)
{	
	//SPECIAL FUNCTION ACHIEVED WITH LAGRANGE INTERPOLATION
	return (-0.00326885*pow(value,6)
			+0.000624217*pow(value,5)
			+0.0888064*pow(value,4)
			+0.0474312*pow(value,3)
			-0.630738*pow(value,2) 
			-1.10534*value +4);
}

std::tuple<float, float, float> generateCoord()
{
	float dist=-30.0f; //Distance in z-axis
	float y_max=5.0f;
	float y_min=-5.0f;
	float xz_max;
	//
	std::tuple<float, float, float> coordinate;
	std::get<1>(coordinate)=y_min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(y_max-y_min)));
		xz_max=calcradius(-(std::get<1>(coordinate)));
		//std::cout<<std::to_string(xz_max)<<"\n";
	std::get<0>(coordinate)=-xz_max + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2*xz_max)));
	std::get<2>(coordinate)=dist-xz_max+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2*xz_max)));
	
	return coordinate;
}

float generateRadius()
{
	return (0.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.0f-0.0f))));
}

std::string generateMat(std::tuple<float, float, float> coordinate)
{
	float glass=(std::get<2>(coordinate)+40)/10;
	glass=0;
	
	int Summe=abs(std::get<0>(coordinate))+abs(std::get<1>(coordinate));
	/*
	//std::cout<<std::to_string(Summe)<<"\n";
	std::string r=std::to_string(abs(std::get<0>(coordinate))/Summe);
	std::string g=std::to_string(abs(std::get<1>(coordinate))/Summe);
	std::string b=std::to_string(abs(std::get<2>(coordinate))/Summe);
	b="0,0";
	std::cout<<r+" "+g+" "+b<<"\n";
	return( r+" "+g+" "+b+" "+r+" "+g+" "+b+" 1 1 1 0 "+std::to_string(glass)+" 40");
	*/
	return("1 1 1 0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.0 0.0 40"); //+std::to_string(static_cast <float> (rand()) /( static_cast <float> (RAND_MAX)))+" 0.0 0.0 40");
	/*
	std::to_string(
		//ka
		//kd
		//ks
		//kr
		//ko
		//opac
		//faktor
		)"1 1 0 1 1 0 1 1 1 0 0 40");*/
}
/*
###############################*/
int main(int argc, char* argv[]) 
{
	const int imagecount = 60;	//total number of images

	for (int i = 0; i < imagecount; ++i)
	{
		std::ofstream fOut("zurendern/scene" + std::to_string(i) + ".txt"); //SDF-Datei

		//BASIC SCENE GEN:
		

		int objects=500; //total number of objects per scene 

		for(int j=0;j<objects; j++) //SET UP: SPHERERS
		{
			//generate Coordinates:
			std::tuple<float, float, float> coordinate=generateCoord();

			//generate Radius:
			float r=generateRadius();

			//generate Material:
			fOut
			<<"define material num"<<std::to_string(j)<<" "<<generateMat(coordinate)<< std::endl;

			fOut//WRITE SPHERE
				<<"define shape sphere num"+std::to_string(j)+" "

				+std::to_string(std::get<0>(coordinate))+" "
				+std::to_string(std::get<1>(coordinate))+" "
				+std::to_string(std::get<2>(coordinate))+" "

				+std::to_string(r)+" "

				+"num"+std::to_string(j) << std::endl;
		}
			
			//Box
		
		fOut
		<<"define material eye 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0 0.0 0 40"<<std::endl
		<<"define material nana 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 1 0 0 40"<<std::endl;


		fOut
			<<"define shape box nana1  -50 -50 49 50 50 50   nana" << std::endl
			<<"define shape box eye2  -3 1 -27 -2 2 -26   eye" << std::endl
			<<"define shape box eye1  2 1 -27 3 2 -26   eye" << std::endl
			<<"define shape box nana2  -50 -50 -50 50 50 -49   nana" << std::endl;
			/*
			<<"define shape box num2   7  -6  -93    17 -16  -83   mat_blue" << std::endl
			<<"define shape box num3 -29   5  -93   -19  -5  -83   red" << std::endl
			<<"define shape box num4  -5   5  -93     5  -5  -83   red" << std::endl
			<<"define shape box num5  19   5  -93    29  -5  -83   mat_lblue" << std::endl
			<<"define shape box num6  -1  -1   -1     1   1    1   mat_red" << std::endl
			<<"define shape box num7   7  16  -93    17   6  -83   mat_orange" << std::endl
			*/	
		
			//SET UP: COMPOSITE!
			fOut
			<<"define shape composite root ";
			for(int j=0;j<objects; j++)
			{
				fOut
				<<"num"+std::to_string(j)+" ";
			}
			fOut
			<<"nana1 nana2 eye1 eye2"<<std::endl;
			

			//fOut
			//<<"transform nana scale 2" << std::endl
			//<<"transform nana translate 0 0 0" << std::endl;
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
			<<"define light diffuse sun1 15 5 -15 0.1 0.1 0.7" << std::endl
			<<"define light diffuse sun2 -15 -5 -15 0.0 0.7 0.1" << std::endl
			<<"define light ambient ambient 0.0 0.0 0.0" << std::endl;

			//Camera
			float posx=0+15*std::sin(2*M_PI*i/60);
			float posy=0;
			float posz=-30+15*std::cos(2*M_PI*i/60);

			float dirx=0-posx;
			float diry=0-posy;
			float dirz=-30-posz;
			fOut
			<<"define camera guck 50 "
			+std::to_string(posx)+" "+std::to_string(posy)+" "+std::to_string(posz)+" "
			+std::to_string(dirx)+" "+std::to_string(diry)+" "+std::to_string(dirz)+" 0 1 0" << std::endl;
			//<< cameraCmd << endl
		fOut.close();

	}

	return 0;
}