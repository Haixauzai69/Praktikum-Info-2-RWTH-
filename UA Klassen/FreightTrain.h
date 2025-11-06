/*
 * FreightTrain.h
 *
 *  Created on: Oct 10, 2025
 *      Author: HaiPH
 */

#ifndef FREIGHTTRAIN_H_
#define FREIGHTTRAIN_H_
#include <iostream>
#include <string>
#include "Train.h"

class FreightTrain : public Train
{
	public:
		FreightTrain() = default;
		FreightTrain(float charge_quantity , std::string charge_type);
		virtual ~FreightTrain() = default;

		void vPrintProperties(std::ostream& ausgabe) const override;
		float fLoadCharge(float amountIn, float amountOut);
	private:
		float p_fChargequantity = 0.0;
		std::string p_sChargeType = "empty";
};

FreightTrain::FreightTrain(float charge_quantity , std::string charge_type) : Train()
{
	p_fChargequantity = charge_quantity;
	p_sChargeType = charge_type;
}

void FreightTrain::vPrintProperties(std::ostream& ausgabe) const
{
	ausgabe << "Freight Train" << std::endl;
	Train::vPrintProperties(ausgabe);
	ausgabe << "Charge quantity: " << p_fChargequantity << std::endl;
	ausgabe << "Charge type: " << p_sChargeType << std::endl;
}

float FreightTrain::fLoadCharge(float amountIn, float amountOut)
{
	if ((p_fChargequantity + amountIn) < amountOut)
		{
			std::cout << "Mehr Güte abgeladen als vorhanden" << std::endl;
			return 0;
		}

	p_fChargequantity = p_fChargequantity + amountIn - amountOut;

	float minutesChange = (120 - amountIn * 10 - amountOut * 5)/60;
	p_fDelay = ((minutesChange < 0) ? p_fDelay - minutesChange : 0);
	return minutesChange;
}

#endif /* FREIGHTTRAIN_H_ */
