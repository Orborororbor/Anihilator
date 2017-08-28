#include "Box.h"

Box::Box( const sf::FloatRect & rect )
{
    _sprite.setOrigin( rect.width/2, rect.height/2 );
    _sprite.setPosition( rect.left+rect.width/2, rect.top+rect.height/2 );
    _sprite.setSize( sf::Vector2f( rect.width, rect.height ) );
    _sprite.setFillColor( sf::Color::Yellow );

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = b2Vec2( pxToM(_sprite.getPosition().x), pxToM(_sprite.getPosition().y) );
    body = createBody( &bodyDef );
    b2PolygonShape shape;
    shape.SetAsBox( pxToM(_sprite.getSize().x/2), pxToM(_sprite.getSize().y/2) );
    body->CreateFixture( &shape, 1 );
}

void Box::update()
{
    _sprite.setPosition( MToPx(body->GetPosition().x), MToPx(body->GetPosition().y) );
    _sprite.setRotation( RDtoDG(body->GetAngle()) );
    window.draw( _sprite );
}

void Box::setColor( const sf::Color& color )
{
    _sprite.setFillColor( color );
}
