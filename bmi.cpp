/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    

    double weight;
    double height;
    double bmi;

    cout << "Enter weight in pounds: ";
    cin >> weight;
    cout << "Enter height in inches: ";
    cin >> height;

    if (weight <= 0 || height <= 0)
    {
        cout << "Error: weight and height must be positive." << endl;
        return 0;
    } 
    
    bmi = weight * 703.0 / (height * height);

    cout << fixed << setprecision(2);
    cout << "BMI: " << bmi << " - ";

    if (bmi < 18.5)
    {
        cout << "Underweight" << endl;
    }
    else if (bmi <=25.0)
    {
        cout << "Optimal weight" << endl;
    }
    else
    {
        cout << "Overweight" << endl;
    }

    return 0;
}