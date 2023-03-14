#include "product.h"

User::User(const std::string& n, double m, ShoppingCart& c, ReceiptMethod r) 
	: name{n}, money{m}, cart{c}, receipt{r} {}

void User::buyProduct(Product* p, ShoppingCart& c)
{
	cart.addProduct(p);
}

ReceiptMethod User::getReceiptMethod()
{
	return receipt;
}