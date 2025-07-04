#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <ctime>

class Shippable {
public:
    virtual double getWeight() const = 0;
    virtual std::string getName() const = 0;
    virtual ~Shippable() = default;
};

class Product {
protected:
    std::string name;
    double price;
    int quantity;

public:
    Product(std::string name, double price, int quantity);
    virtual bool isExpired() const = 0;
    virtual bool isShippable() const = 0;

    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;
    void reduceStock(int q);
    virtual ~Product() = default;
};

#endif
