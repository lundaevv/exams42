#pragma once

#include <iostream>


class vect2
{
    private:
        int x;
        int y;
    public:
        vect2();
        vect2(int x, int y);
        vect2(const vect2& source);
        vect2& operator=(const vect2& source);

        int& operator[](int index);
        int operator[](int index) const;

        vect2 operator-() const;
        
        vect2 operator*(int n) const;;
        vect2& operator*=(int n);

        vect2& operator++();
        vect2 operator++(int);
        vect2& operator--();
        vect2 operator--(int);

        vect2 operator+(const vect2& other) const;
        vect2& operator+=(const vect2& other);
        vect2 operator-(const vect2& other) const;
        vect2& operator-=(const vect2& other);
        vect2 operator*(const vect2& other) const;
        vect2& operator*=(const vect2& other);

        bool operator==(const vect2& other) const;
        bool operator!=(const vect2& other) const;
};

vect2 operator*(int n, const vect2& other);
std::ostream& operator<<(std::ostream& output, const vect2& obj);