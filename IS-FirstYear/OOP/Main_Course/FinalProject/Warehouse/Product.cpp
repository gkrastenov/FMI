#include "Product.h"
#include<cstring>

Product::Product()
{
    description = nullptr;
    expiryDate = nullptr;
    entryDate = nullptr;
    manufacturer = nullptr;
    quantity = 0;
    location = 0;
    comment = nullptr;
}

Product::~Product()
{
    delete[] description;
    delete[] manufacturer;
    delete[] comment;

    description = nullptr;
    expiryDate = nullptr;
    entryDate = nullptr;
    manufacturer = nullptr;
    quantity = 0;
    location = 0;
    comment = nullptr;
}

void Product::setDescription(const char* description) {
    size_t lengthDescription = strlen(description) + 1;
    this->description = new char[lengthDescription];
    strcpy_s(this->description, lengthDescription, description);
}

void Product::setManufacturer(const char* manufacturer) {
    size_t lengthManufacturer = strlen(manufacturer) + 1;
    this->manufacturer = new char[lengthManufacturer];
    strcpy_s(this->manufacturer, lengthManufacturer, manufacturer);
}

void Product::setComment(const char* comment) {
    size_t lengthComment = strlen(comment) + 1;
    this->comment = new char[lengthComment];
    strcpy_s(this->comment, lengthComment, comment);
}

void Product::setQuantity(const int quantity) {
    this->quantity = quantity;
}

void Product::setLocation(const int location) {
    this->location = location;
}

void Product::setExpiryDate(const char* expiryDate) {
    this->expiryDate = DateTime(expiryDate);
}

void Product::setEntryDate(const char* entryDate) {
    this->expiryDate = DateTime(entryDate);
}

char* Product::getDescription() {
    return this->description;
}

char* Product::getManufacturer() {
    return this->manufacturer;
}

void Product::getExpiryDate() {
    this->expiryDate.toString();
}

void Product::getEntryDate() {
    this->entryDate.toString();
}

int Product::getQuantity() {
    return this->quantity;
}

int Product::getLocation() {
    return this->location;
}

char* Product::getComment() {
    return this->comment;
}