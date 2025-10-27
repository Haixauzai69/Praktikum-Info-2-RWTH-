//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

Vektor* Vektor::sub(Vektor* v) const
{
	// subtract v from this (object) and return result
	return new Vektor(this->x - v->x, this->y - v->y, this->z - v->z);
}

double Vektor::laenge() const
{
	return sqrt(x*x + y*y + z*z);
}

double Vektor::skalarProd(Vektor* v) const
{
	return (this->x*v->x + this->y*v->y + this->z*v->z);
}

void Vektor::rotiereUmZ(double rad)
{
	double new_x = x*cos(rad) - y*sin(rad);
	double new_y = x*sin(rad) + y*cos(rad);
	this->x = new_x;
	this->y = new_y;
}
