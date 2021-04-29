#ifndef _MARKET_H_
#define _MARKET_H_

#include<vector>
#include"Stock.h"
#include"Order.h"
#include"Trade.h"

class Market {
private:
	std::vector<Stock> Stocks;
	std::vector<Order> BuyOrders;
	std::vector<Order> SellOrders;
	std::vector<Trade> Trades;
};

#endif//!_MARKET_H_