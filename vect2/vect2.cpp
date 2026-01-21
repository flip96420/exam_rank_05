#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::vect2(int num1, int num2) : x(num1), y(num2) {}

vect2::vect2(const vect2 &source) { *this = source; }

vect2 &vect2::operator=(const vect2 &source)
{
	if (this != &source)
	{
		this->x = source.x;
		this->y = source.y;
	}
	return (*this);
}

vect2::~vect2() {}


// Index
int vect2::operator[](int index) const
{
	if (index == 0)
		return (this->x);
	return (this->y);
}

int &vect2::operator[](int index)
{
	if (index == 0)
		return (this->x);
	return (this->y);
}


// Const Math
vect2 vect2::operator+(const vect2 &other) const
{
	vect2 temp = *this;

	temp.x += other.x;
	temp.y += other.y;
	return (temp);
}

vect2 vect2::operator-(const vect2 &other) const
{
	vect2 temp = *this;

	temp.x -= other.x;
	temp.y -= other.y;
	return (temp);
}

vect2 vect2::operator-() const
{
	vect2 temp = *this;

	temp.x = -temp.x;
	temp.y = -temp.y;
	return (temp);
}

vect2 vect2::operator*(const vect2 &other) const
{
	vect2 temp = *this;

	temp.x *= other.x;
	temp.y *= other.y;
	return (temp);
}

vect2 vect2::operator*(int num) const
{
	vect2 temp = *this;

	temp.x *= num;
	temp.y *= num;
	return (temp);
}


// Math
vect2 &vect2::operator+=(const vect2 &other)
{
	this->x += other.x;
	this->y += other.y;
	return (*this);
}

vect2 &vect2::operator-=(const vect2 &other)
{
	this->x -= other.x;
	this->y -= other.y;
	return (*this);
}

vect2 &vect2::operator*=(const vect2 &other)
{
	this->x *= other.x;
	this->y *= other.y;
	return (*this);
}

vect2 &vect2::operator*=(int num)
{
	this->x *= num;
	this->y *= num;
	return (*this);
}


// Increment, Decrement
vect2 &vect2::operator++()
{
	this->x++;
	this->y++;
	return (*this);
}

vect2 vect2::operator++(int)
{
	vect2 temp = *this;

	++(*this);
	return (temp);
}

vect2 &vect2::operator--()
{
	this->x--;
	this->y--;
	return (*this);
}

vect2 vect2::operator--(int)
{
	vect2 temp = *this;
	
	--(*this);
	return (temp);
}


// Bools
bool vect2::operator==(const vect2 &other) const
{
	if (this->x == other.x && this->y == other.y)
		return (true);
	return (false);
}

bool vect2::operator!=(const vect2 &other) const
{
	if (this->x != other.x || this->y != other.y)
		return (true);
	return (false);
}


// Non-member functions
vect2 operator*(int num, const vect2 &other)
{
	vect2 temp = other;

	temp *= num;
	return (temp);
}

std::ostream &operator<<(std::ostream &output, const vect2 &obj)
{
	output << "{" << obj[0] << ", " << obj[1] << "}";
	return (output);
}