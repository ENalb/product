#include "physical.h"
#include <string>

PhysicalProduct::PhysicalProduct(const std::string& n, double p, Currency cur, double w)
    : Product(n, p, cur), weight(w) {}

double PhysicalProduct::getWeight() const
{
	return weight;
}

void PhysicalProduct::setWeight(double w)
{
	weight = w;
}

double PhysicalProduct::applyDiscount(double p)
{
	return p;
}

PhysicalProduct::~PhysicalProduct() {}