#ifndef CORE_H
#define CORE_H
#include <iostream>
#include <assert.h>
#include <cmath>
#include <limits>

#define PI 3.141592653589793

namespace util
{

/**
    Vector2D class has nothing to do with physics what so ever, it is purely here for the graphics.
*/
class Vector2D
{
public:
    float x;
    float y;

    //Set all vectors to zero.
    Vector2D() : x(0.0), y(0.0) {}
    //Sets up the vectors
    Vector2D(float x, float y) : x(x), y(y){}

    float operator[](unsigned int i) const
    {
        return ((&x)[i]);
    }

    float& operator[](unsigned int i)
    {
        return ((&x)[i]);
    }

    //This overloader operator checks to see if two vectors are the same.
    bool operator==(const Vector2D& rhs) const
    {
        return(x == rhs.x && y == rhs.y);
    }

    //Multiplies the vectors to give a scalar value.
    void operator*=(float value)
    {
        x *= value;
        y *= value;
    }

    //Returns a copy of the give in the arguments
    Vector2D operator*(float value) const
    {
        return Vector2D(x * value, y * value);
    }

    //Works out the scalar product of a vector and returns it, with the operator.
    float operator*(const Vector2D& vec) const
    {
        return (x * vec.x + y * vec.y);
    }

    //Adds to vectors together
    void operator+=(const Vector2D& v)
    {
        x += v.x;
        y += v.y;
    }

    //Returns the added vectors together
    Vector2D operator+(const Vector2D& v) const
    {
        return Vector2D(x + v.x, y + v.y);
    }

    //subtracts to vectors together
    void operator-=(const Vector2D& v)
    {
        x -= v.x;
        y -= v.y;
    }

    //Returns the subtracts vectors together
    Vector2D operator-(const Vector2D& v) const
    {
        return Vector2D(x - v.x, y - v.y);
    }

    //Uses operator == to test to see if both vectors unequal, if this is true it returns true.
    bool operator!=(const Vector2D& rhs) const
    {
        return!(*this == rhs);
    }

    //Returns true if all of the vectors values are the same as the arguments.
    bool operator<(const Vector2D& rhs) const
    {
        return(x < rhs.x && y < rhs.y);
    }

    //Returns true if all of the vectors values are the same as the arguments.
    bool operator>(const Vector2D& rhs) const
    {
        return(x > rhs.x && y > rhs.y);
    }

    //Returns true if all of the vectors values are the same as the arguments.
    bool operator<=(const Vector2D& rhs) const
    {
        return(x <= rhs.x && y <= rhs.y);
    }

    //Returns true if all of the vectors values are the same as the arguments.
    bool operator>=(const Vector2D& rhs) const
    {
        return(x >= rhs.x && y >= rhs.y);
    }

    //This is not often talked about in mathematics and it doesn't yet have a operator that is constant to denote this type of vector operation.
    //Mainly this is not talked about because the product component doesn't have a geometric interpretation.
    //What this means is that if we multiply to vectors together represents new positions, then it isn't clear geometrically how the components product is related to the positions to their locations.
    //This function calculates and returns the wise-component product of this vector with the given vector.
    Vector2D componentProduct(const Vector2D& vec) const
    {
        return Vector2D(x * vec.x, y * vec.y);
    }

    //This function calculates and sets the wise-component product of this vector with the given vector to the vectors in this class.
    void componentProductUpdate(const Vector2D& vec)
    {
        x *= vec.x;
        y *= vec.y;
    }

    //Works out the scalar product of a vector and returns it.
    //AKA dot product.
    float scalarProduct(const Vector2D& vec)
    {
        return (x * vec.x + y * vec.y);
    }

    // Limits the size of the vector to the given maximum.
    void trim(float size)
    {
        if(squareMagnitude() > size * size)
        {
            normalise();
            x *= size;
            y *= size;
        }
    }

    //This function inverts the vectors
    void invert()
    {
        x = -x;
        y = -y;
    }

    //This function clears all values
    void clear()
    {
        x = y = 0;
    }

    //This function gets the magnitude of a vector, with a function.
    float magnitude() const
    {
        return std::sqrt(x * x + y * y);
    }

    //This gets the squared magnitude of the vector used for comparing vector magnitude.
    //This function is faster.
    float squareMagnitude() const
    {
        return (x * x + y * y);
    }

    //This function is used for adding vectors together and then scales it up.
    void addScaledVector(const Vector2D& vec, float scale)
    {
        x += vec.x * scale;
        y += vec.y * scale;
    }

    //Turns a none-zero vector into normalises the vector basically gets the length of the vector.
    void normalise()
    {
        float l = magnitude();
        if(l > 0)
        {
            (*this) *= (static_cast<float>(1)) / l;
        }
    }

    //This function returns the normal of a vector that this class is currently handling.
    Vector2D unitVector() const
    {
        Vector2D Result = *this;
        Result.normalise();
        return Result;
    }

    //This only works in 2D, it takes a degree value turns it into a radian and uses the rotation formula for to rotate the vector.
    Vector2D rotate(float degree) const
    {
        float radian = degree * PI / 180.0;
        float rotcos = std::cos(radian);
        float rotsin = std::sin(radian);

        return Vector2D((x * rotcos - y * rotsin), (x * rotsin + y * rotcos));
    }

};
};
#endif // CORE_H
