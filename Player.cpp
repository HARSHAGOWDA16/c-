#include "player.h"
#include <iostream>

// Constructors
Player::Player() : name(""), age(0) {}

Player::Player(std::string name, int age) : name(name), age(age) {}

// Accessors
std::string Player::getName() const {
    return name;
}

int Player::getAge() const {
    return age;
}

// Mutators
void Player::setName(std::string name) {
    this->name = name;
}

void Player::setAge(int age) {
    this->age = age;
}

// Functionality methods
void Player::print() const {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}
