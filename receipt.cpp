#include "receipt.h"
#include <iostream>
#include <memory>

void EmailReceiptSender::sendReceipt(User* u)
{
	std::cout << "Sending receipt by Email" << std::endl;
}

void EmailReceiptSender::setNextSender(std::unique_ptr<IReceipSender> next) {
    	nextSender = std::move(next);
}

void MailReceiptSender::sendReceipt(User* u)
{
	std::cout << "Sending receipt by Mail" << std::endl;
}

void MailReceiptSender::setNextSender(std::unique_ptr<IReceipSender> next) {
    	nextSender = std::move(next);
}

void NotificationReceiptSender::sendReceipt(User* u)
{
	std::cout << "Sending receipt by Notification" << std::endl;
}

void NotificationReceiptSender::setNextSender(std::unique_ptr<IReceipSender> next) {
    	nextSender = std::move(next);
}

void SMSReceiptSender::sendReceipt(User* u)
{
	std::cout << "Sending receipt by SMS" << std::endl;
}

void SMSReceiptSender::setNextSender(std::unique_ptr<IReceipSender> next) {
    	nextSender = std::move(next);
}

bool EmailReceiptHandler::handleRequest(User* u, IReceipSender*& i)
{
	if (u->getReceiptMethod() == ReceiptMethod::Email) {
        	i = new EmailReceiptSender();
        	return true;
    	}
    	return false;
}

bool MailReceiptHandler::handleRequest(User* u, IReceipSender*& i)
{
	if (u->getReceiptMethod() == ReceiptMethod::mail) {
        	i = new MailReceiptSender();
        	return true;
    	}
    	return false;
}

bool NotificationReceiptHandler::handleRequest(User* u, IReceipSender*& i)
{
	if (u->getReceiptMethod() == ReceiptMethod::notification) {
        	i = new NotificationReceiptSender();
        	return true;
    	}
    	return false;
}

bool SMSReceiptHandler::handleRequest(User* u, IReceipSender*& i)
{
	if (u->getReceiptMethod() == ReceiptMethod::SMS) {
        	i = new SMSReceiptSender();
        	return true;
    	}
    	return false;
}
