#ifndef _ORDER_H_
#define _ORDER_H_

#include<string>
class Order {
private:
	std::string ISIN;
	float Price;
	enum OrderType{Buy,Sell};
	int Quantity;
	int OrderID;
};

#endif //!_ORDER_H_