#include "../include/Customer.h"

Customer::Customer(std::string name, double balance) : name(name), balance(balance) {}

void Customer::deduct(double amount) {
    if (amount > balance) throw std::runtime_error("Insufficient balance.");
    balance -= amount;
}
