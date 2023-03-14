#include "product.h"
#include <memory>

class IReceipSender
{
public:
	virtual void sendReceipt(User*) = 0;
	virtual void setNextSender(std::unique_ptr<IReceipSender> next) = 0;
};

class EmailReceiptSender : public IReceipSender
{
public:
	void sendReceipt(User*) override;
	void setNextSender(std::unique_ptr<IReceipSender> next) override;
private:
    std::unique_ptr<IReceipSender> nextSender;
};

class MailReceiptSender : public IReceipSender
{
public:
	void sendReceipt(User*) override;
	void setNextSender(std::unique_ptr<IReceipSender> next) override;
private:
    std::unique_ptr<IReceipSender> nextSender;
};

class NotificationReceiptSender : public IReceipSender
{
public:
	void sendReceipt(User*) override;
	void setNextSender(std::unique_ptr<IReceipSender> next) override;
private:
    std::unique_ptr<IReceipSender> nextSender;
};

class SMSReceiptSender : public IReceipSender
{
public:
	void sendReceipt(User*) override;
	void setNextSender(std::unique_ptr<IReceipSender> next) override;
private:
    std::unique_ptr<IReceipSender> nextSender;
};

class ReceiptHandler
{
public:
	virtual bool handleRequest(User*, IReceipSender*&) = 0;
};

class EmailReceiptHandler : public ReceiptHandler
{
public:
	bool handleRequest(User*, IReceipSender*&) override;
};

class MailReceiptHandler : public ReceiptHandler
{
public:
	bool handleRequest(User*, IReceipSender*&) override;
};

class NotificationReceiptHandler : public ReceiptHandler
{
public:
	bool handleRequest(User*, IReceipSender*&) override;
};

class SMSReceiptHandler : public ReceiptHandler
{
public:
	bool handleRequest(User*, IReceipSender*&) override;
};