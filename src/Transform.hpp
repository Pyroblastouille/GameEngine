#ifndef _HPP_TRANSFORM
#define _HPP_TRANSFORM

#include "Vector3.hpp"

class Transform
{
private:
    /* data */
public:
    Transform(/* args */);
    ~Transform();
    
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
};

#endif