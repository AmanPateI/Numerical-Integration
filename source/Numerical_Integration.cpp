/* Author: Aman Patel
Class: ECE 4122
Last Date Modified: 10/13/2021
Description: Calculating the solution of an Integral using the Rectangular Method
*/
#include <fstream>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
// main method
// Integration process 
int main(int argc, char* argv[])
{
    long numberOfSteps;
    // check for error in user input
    if (argc < 2)
    {
        std::cout << "Please enter a value for numberOfSteps" << std::endl;
        return 0;
    }
    else
    {
        numberOfSteps = atol(argv[1]);
    }
    // Rectangular Integration process
    double VALUE = 0;
    double Initial = 0;
    double ending = log(2) / 7;
    double x = (ending -Initial) / numberOfSteps;
    double sum = 0;
    double firstMidpoint = (Initial + x) / 2;
    #pragma omp parallel for reduction(+  : sum)
    for (long i = 0; i < numberOfSteps; i++)
    {
        sum += 14 * exp(7 * (firstMidpoint+ i*x));
    }
    VALUE = sum * x;
    // Streaming output to textfile
    std::ofstream myfile;
    myfile.open("Lab2Prob2.txt");
    myfile << std::fixed << std::setprecision(6) << VALUE << std::endl;
    myfile.close();

    return 0;
}