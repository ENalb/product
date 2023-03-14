#include "digital.h"

DigitalProduct::DigitalProduct(const std::string& n, double p, Currency cur, const std::string& u) 
	:Product(n,p,cur), url {u} {}

void DigitalProduct::setURL(const std::string& u)
{
	url = u;
}

std::string DigitalProduct::getURL() const
{
	return url;
}

double DigitalProduct::applyDiscount(double p)
{
	return p - (p * 20 / 100);
}

DigitalProduct::~DigitalProduct() {}