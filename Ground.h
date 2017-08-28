#ifndef GROUND_H
#define GROUND_H

#include "Global.h"

class Ground : public Actor < Ground >
{
private:
    b2Body* body;
    sf::RectangleShape _sprite;

    virtual void update() override;

public:
    Ground( const sf::FloatRect & rect );

};

#endif // GROUND_H
