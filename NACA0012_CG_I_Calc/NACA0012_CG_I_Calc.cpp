// NACA0012_CG_I_Calc.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <Eigen/Dense>
#include <fstream>
#include "stdlib.h"
#include <iostream> 


int main()
{

	// Define data allocation matrices

	int num = 0;

	Eigen::MatrixXf X(110, 1);
	Eigen::MatrixXf Y(110, 1);
	std::ifstream file_X("profile_X.txt");
	std::ifstream file_Y("profile_Y.txt");

	// X.dat and Y.dat contain the X & Y coordinates of NACA64A010 airfoil

	int i, j;

	// Check for file existence 

	if (!file_X)
	{
		std::cerr << "Failed to open X.dat file \n ";
		exit(EXIT_FAILURE);
	}

	else
	{
		std::cout << "X.dat file read sucessfully \n";

	}

	if (!file_Y)
	{
		std::cerr << "Failed to open Y.dat file \n ";
		exit(EXIT_FAILURE);
	}

	else
	{
		std::cout << "Y.dat file read sucessfully \n";

	}

	// Read and assign coordinates to X & Y coloumn matrices

	for (i = 0; i < 110; i++)
	{
		file_X >> X(i, 0);
	}


	for (j = 0; j < 110; j++)
	{
		file_Y >> Y(j, 0);
	}

	// Airfoil geometric characteritics


	std::cout << " Airfoil chord length : " << X.maxCoeff() - X.minCoeff() << "\n";

	std::cout << " Airfoil thickness : " << Y.maxCoeff() - Y.minCoeff() << "\n";


	// Lumped Model Analysis



	std::cin.get();



	return 0;
}


