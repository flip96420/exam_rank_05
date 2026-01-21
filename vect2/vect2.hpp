#pragma once

#include <iostream>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(int num1, int num2);
		vect2(const vect2 &source);
		vect2 &operator=(const vect2 &source);
		~vect2();

		// Index
		int operator[](int index) const;
		int &operator[](int index);

		// Const Math
		vect2 operator+(const vect2 &other) const;
		vect2 operator-(const vect2 &other) const;
		vect2 operator-() const;
		vect2 operator*(const vect2 &other) const;
		vect2 operator*(int num) const;

		// Math
		vect2 &operator+=(const vect2 &other);
		vect2 &operator-=(const vect2 &other);
		vect2 &operator*=(const vect2 &other);
		vect2 &operator*=(int num);

		// Increment, Decrement
		vect2 &operator++();
		vect2 operator++(int);
		vect2 &operator--();
		vect2 operator--(int);

		// Bools
		bool operator==(const vect2 &other) const;
		bool operator!=(const vect2 &other) const;
};

vect2 operator*(int num, const vect2 &other);
std::ostream &operator<<(std::ostream &output, const vect2 &obj);