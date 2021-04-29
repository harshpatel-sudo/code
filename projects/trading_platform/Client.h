#ifndef _CLIENT_H_
#define _CLIENT_H_

class Client {
private:
	int ClientID;
	int FundBalance;
public:
	int getClientID() { return ClientID; }
	int getFundBalance() { return FundBalance; }
	void setFundBalance(int _FundBalance) { FundBalance = _FundBalance; }
	void placeOrder(int _ISIN, int _Quantity, int _Price);
};

#endif // !_CLIENT_H_
