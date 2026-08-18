#include "vect2.hpp"

vect2::vect2()
{
    this->x = 0;
    this->y = 0;
}

vect2::vect2(int num1, int num2)
{
    this->x = num1;
    this->y = num2;
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

int vect2::operator[](int index) const
{
    if (index == 0)
        return this->x;
    return this->y;
}

int& vect2::operator[](int index)
{
    if (index == 0)
        return this->x;
    return this->y;
}

vect2 vect2::operator-() const
{
    vect2 temp = *this;
    temp.x = -temp.x;
    temp.y = -temp.y;
    return temp;
}

vect2 vect2::operator*(int num) const
{
    vect2 temp;
    temp.x = this->x * num;
    temp.y = this->y * num;
    return temp;
}

vect2& vect2::operator*=(int num)
{
    this->x *= num;
    this->y *= num;
    return *this;
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

vect2 vect2::operator+(const vect2& other) const
{
    vect2 temp;
    temp.x = this->x + other.x;
    temp.y = this->y + other.y;
    return temp;
}

vect2 vect2::operator-(const vect2& other) const
{
    vect2 temp;
    temp.x = this->x - other.x;
    temp.y = this->y - other.y;
    return temp;
}

vect2 vect2::operator*(const vect2& other) const
{
    vect2 temp;
    temp.x = this->x * other.x;
    temp.y = this->y * other.y;
    return temp;
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

bool vect2::operator==(const vect2& other) const
{
    if (this->x == other.x && this->y == other.y)
        return true;
    return false;
}

bool vect2::operator!=(const vect2& other) const
{
    return !(*this == other);
}

vect2::~vect2()
{

}

vect2 operator*(int num, const vect2& obj)
{
    vect2 temp(obj);
    temp *= num;
    return temp;
}

std::ostream& operator<<(std::ostream& output, const vect2& obj)
{
    output << "{" << obj[0] << ", " << obj[1] << "}";
    return output;
}