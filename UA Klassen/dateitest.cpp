/*
 * dateitest.cpp
 *
 *  Created on: Nov 7, 2025
 *      Author: HaiPH
 */

#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
	// Testvariablen
	std::string name = "Arthur";
	int semester = 42;
	double schnitt = 4.2;
	const std::string& dateiname = "Ausgabedatei.dat";
	// Öffnen des Files für die Ausgabe
	std::ofstream outfile(dateiname);
	// Schreibe die Daten in das File
	outfile << "Name: " << name << std::endl;
	outfile << "Semester: " << semester << std::endl;
	outfile << "Notenschnitt: " << std::setprecision(1)
	<< std::setiosflags(std::ios::fixed) << schnitt << std::endl;
	return 0;
}


