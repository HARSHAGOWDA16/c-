#include "location.h"
#include <iostream>

// Location class implementation
Location::Location(char s) : visited(false), symbol(s) {}

Location::~Location() {}

bool Location::getVisited() const {
    return visited;
}

char Location::getSymbol() const {
    return symbol;
}

void Location::setVisited(bool visited) {
    this->visited = visited;
}

void Location::setSymbol(char symbol) {
    this->symbol = symbol;
}

void Location::draw() {
    if (visited)
        std::cout << symbol;
    else
        std::cout << ".";
}

int Location::visit(Player &p) {
    visited = true;
    return 1;
}

// Crystal class implementation
Crystal::Crystal() : taken(false) {
    setSymbol('$');
}

Crystal::~Crystal() {}

bool Crystal::isTaken() const {
    return taken;
}

void Crystal::setTaken(bool taken) {
    this->taken = taken;
}

void Crystal::draw() {
    if (visited && !taken)
        std::cout << symbol;
    else if (taken)
        std::cout << " ";
    else
        std::cout << ".";
}

int Crystal::visit(Player &p) {
    if (!visited) {
        visited = true;
        std::cout << "You found a magic crystal." << std::endl;
    }
    return 1;
}

// Define other derived classes similarly
