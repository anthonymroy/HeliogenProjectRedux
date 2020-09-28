#pragma once
#include <iostream>
#include <vector>

#define PI 3.1415926

class Heliostat
{
public:
	Heliostat(std::vector<double> p) { Position = p; };
	std::vector<double> GetPointingNormal(double sunAzimuth, double sunElevation, std::vector<double> target);
	double X() { return Position[0]; };
	double Y() { return Position[0]; };
	double Z() { return Position[0]; };
	std::vector<double> Position;
private:
	
};

double VectorNorm(std::vector<double> vec);
std::vector<double> Normalize(const std::vector<double> vec);
std::vector<double> CalculateSunVector(double sunAzimuth, double sunElevation);
std::vector<double> VectorSubtract(const std::vector<double> vec1, const std::vector<double> vec2);
std::vector<double> VectorAdd(const std::vector<double> vec1, const std::vector<double> vec2);