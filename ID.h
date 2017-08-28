#ifndef ID_H
#define ID_H

class ID
{
public:
    ID();

    static unsigned int getCount();

    operator unsigned int();

private:
    static unsigned int count;
    unsigned int myNumber;
};

#endif // ID_H
