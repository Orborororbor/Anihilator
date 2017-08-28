#ifndef LOADLEVEL_H
#define LOADLEVEL_H

#include <fstream>
#include "Player.h"
#include "Ground.h"
#include "Box.h"

bool loadLevel( const std::string & filename, Player* player );

#endif // LOADLEVEL_H
