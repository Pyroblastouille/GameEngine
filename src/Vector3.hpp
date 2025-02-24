#ifndef _HPP_VECTOR3
#define _HPP_VECTOR3

class Vector3
{
private:
public:
    float x;
    float y;
    float z;
    Vector3(float x = 0,float y= 0,float z = 0);
    ~Vector3();
    Vector3 operator+(const Vector3& other){
        Vector3 res;
        res.x = x + other.x;
        res.y = y + other.y;
        res.z = z + other.z;
        return res;
    }
    Vector3 operator-(const Vector3& other){
        Vector3 res;
        res.x = x - other.x;
        res.y = y - other.y;
        res.z = z - other.z;
        return res;
    }
    Vector3 operator*(const float& other){
        Vector3 res;
        res.x = x*other;
        res.y = y*other;
        res.z = z * other;
        return res;
    }
    Vector3 operator*(const Vector3& other){
        Vector3 res;
        res.x = x * other.x;
        res.y = y * other.y;
        res.z = z * other.z;
        return res;
    }
    Vector3 operator/(const float& other){
        Vector3 res;
        res.x = x/other;
        res.y = y/other;
        res.z = z/other;
        return res;
    }
    Vector3 operator/(const Vector3& other){
        Vector3 res;
        res.x = x / other.x;
        res.y = y / other.y;
        res.z = z / other.z;
        return res;
    }
};

#endif