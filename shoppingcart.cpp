#include "product.h"
#include <vector>
#include <algorithm>

ShoppingCart::ShoppingCart(const std::vector<Product*>& vec) : products {vec} {}

void ShoppingCart::addProduct(Product* p)
{
	products.push_back(p);
}

void ShoppingCart::removeProduct(Product* p)
{
	auto it = std::find(products.begin(), products.end(), p);
	if (it != products.end()) {
		products.erase(it);
	}
}

double ShoppingCart::getCartAmount()
{
	double sum = 0.0;
	for(const auto& product : products)
	{
		sum += product->convertByCurrency(product->getCurrency());
	}
	return sum;
}