#ifndef PRODUCT_TYPES_H
#define PRODUCT_TYPES_H

#include "Product.h"

class ExpirableShippableProduct : public Product, public Shippable {
    time_t expiryDate;
    double weight;
public:
    ExpirableShippableProduct(std::string name, double price, int quantity, time_t expiryDate, double weight);
    bool isExpired() const override;
    bool isShippable() const override;
    double getWeight() const override;
    std::string getName() const override;
};

class ExpirableNonShippableProduct : public Product {
    time_t expiryDate;
public:
    ExpirableNonShippableProduct(std::string name, double price, int quantity, time_t expiryDate);
    bool isExpired() const override;
    bool isShippable() const override;
};

class NonExpirableShippableProduct : public Product, public Shippable {
    double weight;
public:
    NonExpirableShippableProduct(std::string name, double price, int quantity, double weight);
    bool isExpired() const override;
    bool isShippable() const override;
    double getWeight() const override;
    std::string getName() const override;
};

class NonExpirableNonShippableProduct : public Product {
public:
    NonExpirableNonShippableProduct(std::string name, double price, int quantity);
    bool isExpired() const override;
    bool isShippable() const override;
};

#endif