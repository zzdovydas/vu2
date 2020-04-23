#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

double Average(int length, vector<double> arr)
{
    double avg = 0;
    for (int i = 0; i < length; i++)
        avg += arr[i];

    if (length > 0)
        avg /= length;

    return avg;
}

int GetNDLength()
{
    int length = 0;

    string fn, ln, rr;

    ifstream input;

    try
    {
    input.open("kursiokai.txt");
    }
    catch (std::exception& e){ return 0; }

    input >> fn >> ln;

    input >> rr;

    while(rr[0] == 'N' && rr[1] == 'D')
    {
        stringstream ss(rr.substr(2, rr.length()-2));
        ss >> length;
        input >> rr;
    }

    input.close();

    return length;
}
