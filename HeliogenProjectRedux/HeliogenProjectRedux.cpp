// HeliogenProjectRedux.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Heliostat.h"
#include <string>

using namespace std;

string Vector2String(const std::vector<double> vec)
{
    string s;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        s += std::to_string(vec[i]);
        s += ", ";
    }
    s += std::to_string(vec.back());
    return s;
}

int main()
{    
    Heliostat h1 = Heliostat(std::vector<double> { 0, 10, 0 });
    cout << "Mirror 1 position: (" << Vector2String(h1.Position) << ")" << endl;
    Heliostat h2 = Heliostat(std::vector<double> { 0, 20, 0 });
    cout << "Mirror 2 position: (" << Vector2String(h2.Position) << ")" << endl;
    std::vector<double> target{ 0, 0, 10 };
    cout << "Target position: (" << Vector2String(target) << ")" << endl;
    double azimuth1 = 180;
    double elevation1 = 45;
    double azimuth2 = 175;
    double elevation2 = 40;
    std::vector<double> n1 = h1.GetPointingNormal(azimuth1, elevation1, target);
    std::vector<double> n2 = h2.GetPointingNormal(azimuth1, elevation1, target);
    cout << "Sun Position (Azimuth, Elevation): (" << azimuth1 << ", " << elevation1 << ") deg" << endl;
    cout << "Mirror 1 normal: (" << Vector2String(n1) << ")" << endl;
    cout << "Mirror 2 normal: (" << Vector2String(n2) << ")" << endl;
    n1 = h1.GetPointingNormal(azimuth2, elevation2, target);
    n2 = h2.GetPointingNormal(azimuth2, elevation2, target);
    cout << "Sun Position (Azimuth, Elevation): (" << azimuth2 << ", " << elevation2 << ") deg" << endl;
    cout << "Mirror 1 normal: (" << Vector2String(n1) << ")" << endl;
    cout << "Mirror 2 normal: (" << Vector2String(n2) << ")" << endl;
    cout << "Press [ENTER] to exit" << endl;
    cin.ignore();
}


