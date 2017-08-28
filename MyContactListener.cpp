#include "MyContactListener.h"

#include <iostream>

MyContactListener::MyContactListener()
{
    //ctor
}

void MyContactListener::BeginContact(b2Contact* contact)
{
    static_cast<AnyActor*>( contact->GetFixtureA()->GetBody()->GetUserData() )->BeginContact( contact );
}

void MyContactListener::EndContact(b2Contact* contact)
{
    static_cast<AnyActor*>( contact->GetFixtureA()->GetBody()->GetUserData() )->EndContact( contact );
}

void MyContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
    static_cast<AnyActor*>( contact->GetFixtureA()->GetBody()->GetUserData() )->PreSolve( contact, oldManifold );
}

void MyContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
    static_cast<AnyActor*>( contact->GetFixtureA()->GetBody()->GetUserData() )->PostSolve( contact, impulse );
}
