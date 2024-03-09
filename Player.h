#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int age;

public:
    // Constructors
    Player();
    Player(std::string name, int age);

    // Accessors
    std::string getName() const;
    int getAge() const;

    // Mutators
    void setName(std::string name);
    void setAge(int age);

    // Functionality methods
    void print() const;
};

#endif // PLAYER_H
