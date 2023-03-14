#include <string>
#include <vector>

enum class Currency {USD, AMD, RUB, EUR};

class User;

class Product
{
public:
	Product(const std::string&, double, Currency);
	void setName(const std::string&);
	std::string getName() const;
	void setPrice(double);
	double getPrice() const;
	double convertByCurrency(Currency);
	Currency getCurrency() const;
	void purchase(User&);
	virtual ~Product();
private:
	std::string name;
	double price;
	Currency currency;
	virtual double applyDiscount(double) = 0;
};

class PhysicalProduct : public Product
{
public:
	PhysicalProduct(const std::string&, double, Currency, double);
	double getWeight() const;
	void setWeight(double);
	~PhysicalProduct();
private:
	double weight;
	double applyDiscount(double) override;
};

class DigitalProduct : public Product
{
public:
	DigitalProduct(const std::string&, double, Currency, const std::string&);
	void setURL(const std::string&);
	std::string getURL() const;
	~DigitalProduct();
private:
	std::string url;
	double applyDiscount(double) override;
};

class ShoppingCart
{
public:
	ShoppingCart(const std::vector<Product*>&);
	void addProduct(Product*);
	void removeProduct(Product*);
	double getCartAmount();
private:
	std::vector<Product*> products;
};

enum class ReceiptMethod {Email, mail, notification, SMS};

class User
{
public:
	User(const std::string&, double, ShoppingCart&, ReceiptMethod);
	void buyProduct(Product*, ShoppingCart&);
	ReceiptMethod getReceiptMethod();
private:
	std::string name;
	double money;
	ShoppingCart cart;
	ReceiptMethod receipt;
};