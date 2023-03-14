#include <memory>
#include "receipt.h"

Product::Product(const std::string& n, double p, Currency cur) : name {n}, price {p}, currency {cur} {}

void Product::setName(const std::string& n)
{
	name = n;
}

std::string Product::getName() const
{
	return name;
}

void Product::setPrice(double p)
{
	price = p;
}

double Product::getPrice() const
{
	return price;
}

double Product::convertByCurrency(Currency c)
{
	if(c == Currency::USD)
	{
		return applyDiscount(price);
	}
	else if(c == Currency::AMD)
	{
		return applyDiscount(price* 386.57);
	}
	else if(c == Currency::EUR)
	{
		return applyDiscount(price * 0.94);
	}
	return applyDiscount(price * 75.45);
}

Currency Product::getCurrency() const
{
	return currency;
}

void Product::purchase(User& u)
{
	ReceiptMethod preferredMethod = u.getReceiptMethod();

    	std::unique_ptr<IReceipSender> emailSender = std::make_unique<EmailReceiptSender>();
    	std::unique_ptr<IReceipSender> mailSender = std::make_unique<MailReceiptSender>();
    	std::unique_ptr<IReceipSender> notificationSender = std::make_unique<NotificationReceiptSender>();
    	std::unique_ptr<IReceipSender> smsSender = std::make_unique<SMSReceiptSender>();

	emailSender->setNextSender(std::move(mailSender));
    	mailSender->setNextSender(std::move(notificationSender));
    	notificationSender->setNextSender(std::move(smsSender));

    	switch (preferredMethod) {
       		case ReceiptMethod::Email:
            		emailSender->sendReceipt(&u);
            		break;
        	case ReceiptMethod::mail:
            		mailSender->sendReceipt(&u);
            		break;
        	case ReceiptMethod::notification:
            		notificationSender->sendReceipt(&u);
            		break;
        	case ReceiptMethod::SMS:
            		smsSender->sendReceipt(&u);
            		break;
    	}
}

Product::~Product() {}
