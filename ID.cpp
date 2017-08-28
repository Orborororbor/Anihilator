#include "ID.h"

unsigned int ID::count = 0;

ID::ID()
{
    myNumber = count;
    ++count;
}

unsigned int ID::getCount()
{
    return count;
}

ID::operator unsigned int()
{
    return myNumber;
}
