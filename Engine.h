
#ifndef ENGINE_H
#define ENGINE_H

#include "ID.h"
#include "MyContactListener.h"

class Engine
{
public:

    Engine();
    ~Engine();

    /** Nie używać createBody() i createJoint(), zamiast tego
     *  @see AnyActor::createBody() AnyActor::createJoint()
    */
    b2World world;

    /// Zwraca referencję na wektor wszystkich aktorów znanych silnikowi.
    const std::vector < AnyActor* > & getAllActors();

    /// Zwraca referencję na wektor wszystkich aktorów tego samego typu, co podanego aktora.
    const std::vector < AnyActor* > & getActorsByType( AnyActor* actor );

    /// Zwraca referencję na wektor wszystkich aktorów podanego typu.
    template < class T >
    const std::vector < T* > & getActorByType();

    /// Zwraca referencję na wektor aktorów, którzy mają zostać usunięci po bierzącej klatce.
    const std::vector < AnyActor* > & getActorsToDelete();

    /** Rejestruje aktora w silniku. Silnik przejmuje zwialnianie pamięci po aktorze, nie próbuj zwalniać jej samodzielnie.
     *  @see destroyActor()
    */
    AnyActor* addActor( AnyActor* actor );


    /** Usuwa aktora z silnika i zwalnia po nim pamięć.
     *  Faktyczne usunięcie obiektu następuje po zakończeniu klatki w metodzie updateDestoring().
     *  Od tego czasu wskaźniki na aktora tracą ważność.
     *  @see addActor()
    */
    void deleteActor( AnyActor * actor );

    /// Wykonuje klatkę gry.
    void updateAll();

private:

    /** Usuwa aktorów wyznaczonych do tego przez destroyActor(); wywołuje deleteActorNow().
     *  W sumie to nie wiem, dlaczego wywołuje deleteActorNow() zamiast robić to samemu.
     *  @see destroyActor() deleteActorNow()
    */
    void updateDelete();

    /** Usuwa aktora. Wskaźniki do niego tracą ważność.
     *  W sumie to nie wiem, dlaczego wyodrębniłem tą funkcję z updateDelete().
     *  @see destroyActor() deleteActorNow()
    */
    bool deleteActorNow( AnyActor * actor );

    /// Tablica wektorów przechowujących wszystkich aktorów wg typów.
    std::vector < AnyActor* >* _actors;

    /// Wszyscy aktorzy w grze.
    std::vector < AnyActor* >  _allActors;

    /// Aktorzy wyznaczeni do usunięcia przez destoryActor().
    std::vector < AnyActor* >  _toDelete;

    MyContactListener listener;

};

extern Engine engine;

template < class T >
const std::vector < T* > & Engine::getActorByType()
{
    return _actors[ T::getTypeID() ];
}

#endif // ENGINE_H
