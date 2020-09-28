#include "Heliostat.h"

std::vector<double> Heliostat::GetPointingNormal(double sunAzimuth, double sunElevation, std::vector<double> target)
{
	//Calculate sun vector
	std::vector<double> sunUnitVector = CalculateSunVector(sunAzimuth, sunElevation);
	//Calculate Target Vector
	std::vector<double> targetVector = VectorSubtract(target,Position);
	std::vector<double> targetUnitVector = Normalize(targetVector);
	//Calculate and return biscector
	std::vector<double> mirrorNormal = VectorAdd(sunUnitVector, targetUnitVector);
	return Normalize(mirrorNormal);
}

double VectorNorm(const std::vector<double> vec)
{
	double sum = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		sum += vec[i] * vec[i];
	}
	return sqrt(sum);
}

std::vector<double> Normalize(const std::vector<double> vec)
{
	double norm = VectorNorm(vec);
	std::vector<double> n = vec;
	for (int i = 0; i < n.size(); i++)
	{
		n[i] /= norm;
	}
	return n;
}

std::vector<double> CalculateSunVector(double sunAzimuth, double sunElevation)
{
	double azimuthInLocalCoordinates = 90 - sunAzimuth; //Converts given Azimuth to local coordinate system
	double x = cos(azimuthInLocalCoordinates * PI / 180) * cos(sunElevation * PI / 180);
	double y = sin(azimuthInLocalCoordinates * PI / 180) * cos(sunElevation * PI / 180);
	double z = sin(sunElevation * PI / 180);
	return std::vector<double> {x, y, z};
}

std::vector<double> VectorSubtract(const std::vector<double> vec1, const std::vector<double> vec2)
{
	std::vector<double> v = vec1;
	for (int i = 0; i < v.size(); i++)
	{
		v[i] -= vec2[i];
	}
	return v;
}

std::vector<double> VectorAdd(const std::vector<double> vec1, const std::vector<double> vec2)
{
	std::vector<double> v = vec1;
	for (int i = 0; i < v.size(); i++)
	{
		v[i] += vec2[i];
	}
	return v;
}