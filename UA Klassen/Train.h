/*
 * Train.h
 *
 *  Created on: Oct 9, 2025
 *      Author: HaiPH
 */

#ifndef TRAIN_H_
#define TRAIN_H_

#include <iostream>
#include <string>
#include <memory>
#include "Station.h"

class Train
{
	private:
		static inline int p_iIDCounter = 0;
		const int p_iID = p_iIDCounter++;
	protected:
		float p_fDelay = 0.0;
		std::shared_ptr<Station> p_pIsAt;

	public:
		Train() = default;
		Train(int speed, bool electric);
		virtual ~Train() = default;

		void vGoTo(std::shared_ptr<Station> station);
		virtual void vPrintProperties(std::ostream& ausgabe) const;
};

void Train::vPrintProperties(std::ostream& ausgabe) const // any ostream defined as "ausgabe". it could be cout, printf, etc. call by value cause we need direct change in there
{
	ausgabe << "ID: " << p_iID << std::endl; // works like a normal cout, just that this time it is a variable "ausgabe"
	ausgabe << "Delay: " << p_fDelay << std::endl;
}

void Train::vGoTo(std::shared_ptr<Station> station)
{
	if((p_pIsAt == nullptr) || (p_pIsAt->bIsNeighbor(station)))
	{
		p_pIsAt = station;
		std::cout << "Zug ist nach " << p_pIsAt->getName() << " gefahren" << std::endl;
	}
	else
	{
		std::cout << "Zug kann nicht dahin fahren" << std::endl;
	}
}


#endif /* TRAIN_H_ */
