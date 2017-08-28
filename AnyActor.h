#ifndef ANYACTOR_H
#define ANYACTOR_H

#include <Box2D/Box2D.h>

class Engine;

/**
 * Klasa bazowa dla elementów gry zarządzanych przez Engine.
 * @see Engine
*/
class AnyActor
{
    friend class Engine;
public:
    virtual ~AnyActor();

    /// Metoda wywoływana co klatkę.
    virtual void update() = 0;

    /**
     * Zwraca ID typu aktora.
     * Nadpisywana automatycznie przez ACTOR_DATA_HPP.
    */
    virtual unsigned int getTypeID() const = 0;

    /// Funkcje do reakcji na zdarzeia fizyczne
    virtual void BeginContact(b2Contact* contact){};
	virtual void EndContact(b2Contact* contact){};
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold){};
	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){};


protected:

    b2Body* createBody( b2BodyDef* bodyDef );
    b2Joint* createJoint( b2JointDef* jointDef );

private:
    std::vector<b2Body*> bodies;
    std::vector<b2Joint*> joints;

};

#endif // ANYACTOR_H
