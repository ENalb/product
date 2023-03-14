#include <iostream>
#include "product.h"

int main()
{
	PhysicalProduct physical("computer", 500000, Currency::AMD, 3);
	DigitalProduct digital("e-book", 3625, Currency::AMD, "https:book.com");
	std::vector<Product*> products_vector;
	products_vector.push_back(&physical);
	products_vector.push_back(&digital);
	ShoppingCart cart(products_vector);
	User user("Emi", 25000, cart, ReceiptMethod::Email);
	std::cout << cart.getCartAmount() << std::endl;
}