#include "Player.h"

Player::Player( const sf::FloatRect & rect ):
    SPEED( 0.05 ),
    JUMP_FORCE( 0.25 )
{
    _sprite.setOrigin( rect.width/2, rect.height/2 );
    _sprite.setPosition( rect.left+rect.width/2, rect.top+rect.height/2 );
    _sprite.setSize( sf::Vector2f( rect.width, rect.height ) );
    _sprite.setFillColor( sf::Color::Green );

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.fixedRotation = true;
    bodyDef.linearDamping = 0.1;
    bodyDef.position = b2Vec2( pxToM(_sprite.getPosition().x), pxToM(_sprite.getPosition().y) );
    body = createBody( &bodyDef );
    b2PolygonShape shape;
    shape.SetAsBox( pxToM(_sprite.getSize().x/2), pxToM(_sprite.getSize().y/2) );
    body->CreateFixture( &shape, 5 );
}

void Player::update()
{
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) || sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
    {
        body->ApplyLinearImpulseToCenter( b2Vec2( SPEED, 0 ), true );
        _direction = true;
    }

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
    {
        body->ApplyLinearImpulseToCenter( b2Vec2( -SPEED, 0 ), true );
        _direction = false;
    }

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) || sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
        jump();

    _sprite.setPosition( MToPx(body->GetPosition().x), MToPx(body->GetPosition().y) );
    window.draw( _sprite );
}

void Player::jump()
{
    body->ApplyLinearImpulseToCenter( b2Vec2( 0, -JUMP_FORCE ), true );
}

void Player::setPosition( sf::Vector2f position )
{
    body->SetTransform( b2Vec2( pxToM(position.x), pxToM(position.y) ), 0 );
}

void Player::BeginContact(b2Contact* contact)
{
    AnyActor* ptr;

    ptr = static_cast<AnyActor*>( contact->GetFixtureA()->GetBody()->GetUserData() );
    if( ptr->getTypeID() == Box::getID() )
        static_cast<Box*>(ptr)->setColor(sf::Color( 200, 150, 0 ) );

    ptr = static_cast<AnyActor*>( contact->GetFixtureB()->GetBody()->GetUserData() );
    if( ptr->getTypeID() == Box::getID() )
        static_cast<Box*>(ptr)->setColor(sf::Color( 200, 150, 0 ) );
}

void Player::EndContact(b2Contact* contact)
{
    AnyActor* ptr;

    ptr = static_cast<AnyActor*>( contact->GetFixtureA()->GetBody()->GetUserData() );
    if( ptr->getTypeID() == Box::getID() )
        static_cast<Box*>(ptr)->setColor( sf::Color::Yellow );

    ptr = static_cast<AnyActor*>( contact->GetFixtureB()->GetBody()->GetUserData() );
    if( ptr->getTypeID() == Box::getID() )
        static_cast<Box*>(ptr)->setColor( sf::Color::Yellow );
}
