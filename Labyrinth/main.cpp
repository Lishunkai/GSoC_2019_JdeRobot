/*
	This program solve the Labyrinth problem proposed by JdeRobot for GSoC 2018.
	It finds the largest pathway moving only between holes.

	Author: Shunkai Li
	Education: a senior student of Nankai University, China,
			   and an incoming student of Peking University, China.
*/

#include <iostream>
#include <fstream>
#include <vector>

#include "Labyrinth.h"

using namespace std;

// Define the global variable
Labyrinth labyrinth;

int main(int argc, char *argv[])
{
    // Step 1: Check number of input parameters.
    if (argc != 2)
	{
        cout << "Wrong number of arguments. Please check the input parameters." << endl;
        return 1;
    }

    // Step 2: Load the labyrinth pattern from txt file.
    ifstream InputLabyrinth;
    InputLabyrinth.open(argv[1]);
    if (!InputLabyrinth.is_open())
	{
        cout << "Couldn't open the file:" << argv[1] << endl << "Please check the file path." << endl;
        return 1;
    }
    labyrinth = Labyrinth(InputLabyrinth);
    InputLabyrinth.close();

    // Step 3: Solve the labyrinth problem. 
    Labyrinth result = labyrinth.FindMaxPath();

    // Step 4: Output the result.
    ofstream outputFile;
    outputFile.open("Result.txt");
    outputFile << result.MaxPath() << endl;
    outputFile << result;

    return 0;
}