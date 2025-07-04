#include "../include/Product.h"
#include <stdexcept>

Product::Product(std::string name, double price, int quantity)
    : name(name), price(price), quantity(quantity) {}

std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }
void Product::reduceStock(int q) {
    if (q > quantity) throw std::runtime_error("Not enough stock.");
    quantity -= q;
}
