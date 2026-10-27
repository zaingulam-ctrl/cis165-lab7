/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    const int COLOR_SIZE = 20;
    char first_color[COLOR_SIZE];
    char second_color[COLOR_SIZE];

    cout << "Enter first primary color (red, blue, or yellow): ";
    cin >> setw(COLOR_SIZE) >> first_color;
    cout << "Enter second primary color (red, blue, or yellow): ";
    cin >> setw(COLOR_SIZE) >> second_color;

    bool first_red = strcmp(first_color, "red") == 0;
    bool first_blue = strcmp(first_color, "blue") == 0;
    bool first_yellow = strcmp(first_color, "yellow") == 0;
    bool second_red = strcmp(second_color, "red") == 0;
    bool second_blue = strcmp(second_color, "blue") == 0;
    bool second_yellow = strcmp(second_color, "yellow") == 0;

    bool first_valid = first_red || first_blue || first_yellow;
    bool second_valid = second_red || second_blue || second_yellow;

    if (!first_valid || !second_valid)
    {
        cout << "Error: enter red, blue, or yellow." << endl;
    }
    else if (strcmp(first_color, second_color) == 0)
    {
        cout << "Result: " << first_color << endl;
    }
    else if ((first_red && second_blue) || (first_blue && second_red))
    {
        cout << "Result: purple" << endl;
    }
    else if ((first_red && second_yellow) || (first_yellow && second_red))
    {
        cout << "Result: orange" << endl;
    }
    else
    {
        cout << "Result: green" << endl;
    }

    return 0;
}