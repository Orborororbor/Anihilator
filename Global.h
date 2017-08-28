#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream> //DEBUG
#include <SFML/Graphics.hpp>
#include "Engine.h"

extern sf::RenderWindow window;

extern bool win;

extern sf::Font font;

#define DGtoRD(deg) (b2_pi * (deg) / 180.0f)
#define RDtoDG(rad) ((rad) * (180.0f / b2_pi))

float pxToM( float px );

float MToPx( float m );

#include <string>
#include <sstream>

template<typename T>
std::string to_string(const T& obj)
{
    std::stringstream ss;
    ss << obj;
    return ss.str();
}

#endif // GLOBAL_H
