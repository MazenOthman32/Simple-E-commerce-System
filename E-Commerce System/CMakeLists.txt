cmake_minimum_required(VERSION 3.23)
project(e-commerce)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        src/Product.cpp
        include/Product.h
        src/ProductTypes.cpp
        include/ProductTypes.h
        src/Customer.cpp
        include/Customer.h
        src/Cart.cpp
        include/Cart.h
        src/ShippingService.cpp
        include/ShippingService.h)
