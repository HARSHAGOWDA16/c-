#ifndef LOCATION_H
#define LOCATION_H

#include "player.h"

class Location {
protected:
    bool visited;
    char symbol;

public:
    Location(char s = ' ');
    virtual ~Location();

    // Accessors
    bool getVisited() const;
    char getSymbol() const;

    // Mutators
    void setVisited(bool visited);
    void setSymbol(char symbol);

    // Functionality methods
    virtual void draw();
    virtual int visit(Player &p);
};

class Crystal : public Location {
private:
    bool taken;

public:
    Crystal();
    virtual ~Crystal();

    // Accessors
    bool isTaken() const;

    // Mutator
    void setTaken(bool taken);

    // Functionality methods
    virtual void draw() override;
    virtual int visit(Player &p) override;
};

// Define other derived classes similarly

#endif // LOCATION_H
