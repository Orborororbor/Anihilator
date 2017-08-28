#ifndef ACTOR_H
#define ACTOR_H

#include "AnyActor.h"
#include "ID.h"

template<class T>
class Actor : public AnyActor
{
public:
    virtual unsigned int getTypeID() const override;

    static unsigned int getID();

private:
    static ID id;

};


template<class T>
ID Actor<T>::id;

template<class T>
unsigned int Actor<T>::getTypeID() const
{
    return id;
}

template<class T>
unsigned int Actor<T>::getID()
{
    return id;
}


#endif // ACTOR_H
