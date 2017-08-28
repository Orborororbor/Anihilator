#include "loadLevel.h"

bool loadLevel( const std::string & filename, Player* player )
{
    enum Type{ type_end, type_player, type_ground, type_menemy, type_senemy, type_spikes, type_ladder, type_php, type_penergy, type_ppoints, type_win, type_box };

    const std::vector < AnyActor* > & actors = engine.getAllActors();
    for( std::vector<AnyActor*>::const_iterator i = actors.begin() ; i != actors.end() ; i++ )
        if( !( dynamic_cast<Player*>(*i) ) )
            engine.deleteActor(*i);

    std::fstream file;
    file.open( filename.c_str(), std::ios_base::in );
    if( file.good() )
    {
        void* pointer = malloc( sizeof(sf::FloatRect) );
        sf::Vector2f position;
        sf::FloatRect rect;

        while( file.good() )
        {
            Type type;
            file.read( static_cast < char* > ( pointer ), sizeof( type ) );
            switch( * static_cast < Type* > ( pointer ) )
            {
            case type_player:
                file.read( (char*)(&position ), sizeof( sf::Vector2f ) );
                player->setPosition( position );
                break;

            case type_ground:
                file.read( (char*)(&rect ), sizeof( sf::FloatRect ) );
                engine.addActor( new Ground( rect ) );
                break;

            case type_box:
                file.read( (char*)(&rect ), sizeof( sf::FloatRect ) );
                engine.addActor( new Box( rect ) );
                break;

            default:
                break;
            }
        }
        free( pointer );
        file.close();

        //engine.addObject( new Ground( sf::FloatRect( -1000, -1000, 1000, 2700 ) ) );
        //engine.addObject( new Ground( sf::FloatRect(  1000, -1000, 1000, 2700 ) ) );
        //engine.addObject( new Ground( sf::FloatRect(     0,   700, 1000, 1000 ) ) );

        return true;
    }
    else
        return false;
}

