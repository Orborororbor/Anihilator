#include "Player.h"
#include "Ground.h"
#include "loadLevel.h"

#include <fstream>

int main()
{
    font.loadFromFile( "DejaVuSans-BoldOblique.ttf" );

    Player* player = dynamic_cast< Player* > ( engine.addActor( new Player( sf::FloatRect( 0, 0, 25, 50 ) ) ) );

    loadLevel("1", player );

    short currentLevel = 1;

    sf::Clock zegar;

    while( window.isOpen() )
    {

        window.clear();

        engine.updateAll();

        window.display();

        if( win )
        {
            currentLevel++;
            if( !loadLevel( to_string(currentLevel), player ) )
                window.close();
            win = false;
        }

        sf::Event event;
        while( window.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
                window.close();
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
                window.close();
        }

        while( zegar.getElapsedTime().asMilliseconds() < 1/60 );
    }

    return 0;
}
