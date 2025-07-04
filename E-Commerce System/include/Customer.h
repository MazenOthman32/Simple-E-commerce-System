#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <stdexcept>

class Customer {
public:
    std::string name;
    double balance;

    Customer(std::string name, double balance);
    void deduct(double amount);
};

#endif
