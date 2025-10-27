/*
 * static_variable.cpp
 *
 *  Created on: Sep 26, 2025
 *      Author: HaiPH
 */
#include <iostream>

class Example
{
	private:
		static inline int p_iCounter = 0;
		const int p_iNumber = p_iCounter++;
	public:
		static void printCounter()
		{
			std::cout << "# erzeugter Objekte: " << p_iCounter << std::endl;
		}
		void printNumber()
		{
			std::cout << "Objekt #: " << p_iNumber << std::endl;
		}
};

//int main()
//{
//	Example::printCounter();
//
//	Example a;
//	Example::printCounter();
//	a.printNumber();
//
//	Example b;
//	Example::printCounter();
//	b.printNumber();
//
//	return 0;
//}


