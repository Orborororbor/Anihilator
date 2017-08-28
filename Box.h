#ifndef BOX_H
#define BOX_H

#include "Global.h"

class Box : public Actor < Box >
{
public:
    b2Body* body;
    Box( const sf::FloatRect & rect );

    void setColor( const sf::Color& color );

private:
    sf::RectangleShape _sprite;

    virtual void update() override;
};

#endif // BOX_H
