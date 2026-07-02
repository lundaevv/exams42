# Operator overloads

We have a class so we can use it for examples later
```cpp
class Point
{
public:
    Point()
    {
        x = y = z = 0;
    }
    Point(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    int x;
    int y;
    int z;
}
```

Then we create an object
```cpp
Point p(121, 245, 241)
```

Overloads
ostream, fstream, cout and etc. are linked to each other with the chain 
of inheritance. Hence, 

operator<< for exemple is call for a method inside a class that is why we take the parameter ostream& os (or any of its inheritance)
```cpp
std::ostream& operator<<(ostream& output, const Point& point)
{
    output << point.x << " " << point.y << " " << point.z;
    return output;
}
```

Increment and decrement overloads

prefix has a higher priority than postfix! ++i > i++

parameters difference () and (int value) is just to differentiate operators. int value is actually not taken in rwality

```cpp
Point& operator++() //prefix (++a)
{
    this->x++;
    this->y += 1;

    return *this;
}

Point& operator++(int value) //postfix (a++)
{
    Point temp(this); //just to store the initial value because the postfix has a lowest priority
    this->x++;
    this->y++;

    return temp
}
```