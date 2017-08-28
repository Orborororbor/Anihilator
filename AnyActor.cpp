#include "Engine.h"

b2Body* AnyActor::createBody( b2BodyDef* bodyDef )
{
    b2Body* ptr = engine.world.CreateBody( bodyDef );
    ptr->SetUserData( this );
    bodies.push_back( ptr );
    return ptr;
}

b2Joint* AnyActor::createJoint( b2JointDef* jointDef )
{
    b2Joint* ptr = engine.world.CreateJoint( jointDef );
    ptr->SetUserData( this );
    joints.push_back( ptr );
    return ptr;
}

AnyActor::~AnyActor()
{
    for( auto i : bodies )
        engine.world.DestroyBody( i );

    for( auto i : joints )
        engine.world.DestroyJoint( i );
}
