#include "../include/Cart.h"
#include <stdexcept>

void Cart::add(std::shared_ptr<Product> product, int qty) {
    if (product->isExpired()) throw std::runtime_error(product->getName() + " is expired.");
    if (qty > product->getQuantity()) throw std::runtime_error("Not enough quantity for " + product->getName());
    items.push_back({ product, qty });
}

const std::vector<CartItem>& Cart::getItems() const { return items; }
bool Cart::isEmpty() const { return items.empty(); }