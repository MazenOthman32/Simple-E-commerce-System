#ifndef CART_H
#define CART_H

#include "Product.h"
#include <memory>
#include <vector>

struct CartItem {
    std::shared_ptr<Product> product;
    int quantity;
};

class Cart {
    std::vector<CartItem> items;

public:
    void add(std::shared_ptr<Product> product, int qty);
    const std::vector<CartItem>& getItems() const;
    bool isEmpty() const;
};

#endif