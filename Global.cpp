#include "Global.h"

sf::RenderWindow window( sf::VideoMode( 1000, 700 ), "Annihilation time!" );

bool win = false;

sf::Font font;

float pxToM( float px )
{
    return px/20;
}

float MToPx( float m )
{
    return m*20;
}
