#include "vect2.hpp"

vect2::vect2()
{
    this->x = 0;
    this->y = 0;
}

vect2::vect2(int x, int y)
{
    this->x = x;
    this->y = y;
}

vect2::vect2(const vect2& source)
{
    this->x = source.x;
    this->y = source.y;
}

vect2& vect2::operator=(const vect2& source)
{
    this->x = source.x;
    this->y = source.y;
    return *this;
}

int& vect2::operator[](int index)
{
    if (index == 0)
        return this->x;
    return this->y;
}

int vect2::operator[](int index) const
{
    if (index == 0)
        return this->x;
    return this->y;
}

vect2 vect2::operator-() const
{
    vect2 temp =*this;
    temp.x = -temp.x;
    temp.y = -temp.y;
    return temp;
}

vect2 vect2::operator*(int n) const
{
    vect2 temp = *this;
    temp.x = temp.x * n;
    temp.y = temp.y * n;
    return temp;
}

vect2& vect2::operator*=(int n)
{
    this->x = this->x * n;
    this->y = this->y * n;
    return *this;
}

vect2& vect2::operator++()
{
    this->x += 1;
    this->y += 1;
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 temp = *this;
    ++(*this);
    return temp;
}

vect2& vect2::operator--()
{
    this->x -= 1;
    this->y -= 1;
    return *this;
}

vect2 vect2::operator--(int)
{
    vect2 temp = *this;
    --(*this);
    return temp;
}

vect2 vect2::operator+(const vect2& other) const
{
    vect2 temp = *this;
    temp.x += other.x;
    temp.y += other.y;
    return temp;
}

vect2 vect2::operator-(const vect2& other) const
{
    vect2 temp = *this;
    temp.x -= other.x;
    temp.y -= other.y;
    return temp;
}

vect2 vect2::operator*(const vect2& other) const
{
    vect2 temp = *this;
    temp.x *= other.x;
    temp.y *= other.y;
    return temp;
}

vect2& vect2::operator+=(const vect2& other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

vect2& vect2::operator-=(const vect2& other)
{
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

vect2& vect2::operator*=(const vect2& other)
{
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}

bool vect2::operator==(const vect2& other) const
{
    return this->x == other.x && this->y == other.y;
}

bool vect2::operator!=(const vect2& other) const
{
    return !(*this == other);
}

vect2 operator*(int n, const vect2& other)
{
    vect2 temp(other);
    temp *= n;
    return temp;
}

std::ostream& operator<<(std::ostream& output, const vect2& obj)
{
    output << "{" << obj[0] << ", " << obj[1] << "}";
    return output;
}