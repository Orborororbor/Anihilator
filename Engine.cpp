#include "Engine.h"

Engine engine;

Engine::Engine():
    world   ( b2Vec2( 0, 0.5 ) ),
    _actors ( nullptr )
{
    world.SetContactListener( &listener );
}

Engine::~Engine()
{
    delete[] _actors;

    for( auto i : _allActors )
        delete i;
}

const std::vector < AnyActor* >  & Engine::getAllActors()
{
    return _allActors;
}

const std::vector < AnyActor* >  & Engine::getActorsToDelete()
{
    return _toDelete;
}

AnyActor* Engine::addActor( AnyActor * actor )
{
    if( !_actors )
        _actors = new std::vector<AnyActor*>[ ID::getCount() ];

    _allActors.push_back( actor );

    _actors[ actor->getTypeID() ].push_back( actor );

    return actor;
}

void Engine::deleteActor( AnyActor * actor )
{
    _toDelete.push_back( actor );
}

bool Engine::deleteActorNow( AnyActor * actor )
{
    for( std::vector<AnyActor*>::iterator i = _allActors.begin() ; i != _allActors.end() ; ++i )
    {
        if( *i == actor )
        {
            _allActors.erase( i );
            delete actor;
            return true;
        }
    }
    return false;
}

void Engine::updateAll()
{
    world.Step( 0.01, 8, 3 );

    for( auto i : _allActors )
        i->update();

    updateDelete();
}

void Engine::updateDelete()
{
    for( auto i : _toDelete )
        deleteActorNow( i );

    _toDelete.clear();
}
