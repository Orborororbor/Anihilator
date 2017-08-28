#ifndef PLAYER_H
#define PLAYER_H

#include "Box.h"

class Player : public Actor < Player >
{
private:
    b2Body* body;
    sf::RectangleShape _sprite;

    const float SPEED;
    const float JUMP_FORCE;

    bool _direction;

    void jump();

    virtual void update() override;

    virtual void BeginContact(b2Contact* contact) override;
	virtual void EndContact(b2Contact* contact) override;

public:
    Player( const sf::FloatRect & rect );

    void setPosition( sf::Vector2f position );

};

#endif // PLAYER_H
