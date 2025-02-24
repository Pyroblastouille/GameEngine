#ifndef _HPP_OBJECT
#define _HPP_OBJECT


#include "Transform.hpp"

class Object
{
private:
    /* data */
public:
    Transform transform;
    Object(/* args */);
    ~Object();
};


#endif