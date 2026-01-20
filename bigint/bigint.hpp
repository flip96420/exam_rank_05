#pragma once

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

class bigint
{
	private:
		std::string num;
	public:
		bigint();
		bigint(unsigned int num);
		bigint(const bigint &source);
		bigint &operator=(const bigint &source);
		~bigint();

		// Getter
		std::string getStr() const;

		// Addition
		bigint operator+(const bigint &other) const;
		bigint &operator+=(const bigint &other);

		// Increments
		bigint &operator++(); // ++x
		bigint operator++(int); // x++

		// Shift with num
		bigint operator<<(unsigned int n) const;
		bigint operator>>(unsigned int n) const;
		bigint &operator<<=(unsigned int n);
		bigint &operator>>=(unsigned int n);

		// Shift with object
		bigint operator<<(const bigint &other) const;
		bigint operator>>(const bigint &other) const;
		bigint &operator<<=(const bigint &other);
		bigint &operator>>=(const bigint &other);

		// Bools
		bool operator==(const bigint &other) const;
		bool operator!=(const bigint &other) const;
		bool operator<(const bigint &other) const;
		bool operator>(const bigint &other) const;
		bool operator<=(const bigint &other) const;
		bool operator>=(const bigint &other) const;
};

// Non-member function
std::ostream &operator<<(std::ostream &output, const bigint &obj);
