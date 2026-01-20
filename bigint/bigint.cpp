#include "bigint.hpp"

// Canonical Form
bigint::bigint() : number("0") {}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	this->number = ss.str();
}

bigint::bigint(const bigint &source) { *this = source; }

bigint &bigint::operator=(const bigint &source)
{
	if (this == &source)
		return (*this);
	this->number = source.number;
	return (*this);
}

bigint::~bigint() {}


// Getter
std::string bigint::getStr() const
{
	return (this->number);
}

// Addition
std::string reverse(const std::string &str)
{
	std::string rev_str;
	for (int i = str.length(); i > 0; i--)
	{
		rev_str.push_back(str[i - 1]);
	}
	return (rev_str);
}

std::string addition(const std::string str1, const std::string str2)
{
	std::string num1 = reverse(str1);
	std::string num2 = reverse(str2);
	std::string result;
	int len1 = num1.length();
	int len2 = num2.length();

	if (len1 > len2)
	{
		int digits = len1 - len2;
		while (digits > 0)
		{
			num2.push_back('0');
			digits--;
		}
	}
	else if (len2 > len1)
	{
		int digits = len2 - len1;
		while (digits > 0)
		{
			num1.push_back('0');
			digits--;
		}
	}

	int carry = 0, digit1, digit2, len = num1.length(), res;
	for (int i = 0; i < len; i++)
	{
		digit1 = num1[i] - '0';
		digit2 = num2[i] - '0';

		res = digit1 + digit2 + carry;
		if (res > 9)
		{
			carry = res / 10;
			result.push_back((res % 10) + '0');
		}
		else
		{
			carry = 0;
			result.push_back(res + '0');
		}
	}
	if (carry != 0)
		result.push_back(carry + '0');
	return (reverse(result));
}

bigint bigint::operator+(const bigint &other) const
{
	bigint temp(other);
	temp.number = addition(this->number, other.number);
	return (temp);
}

bigint &bigint::operator+=(const bigint &other)
{
	*this = *this + other;
	return (*this);
}


// Increments
bigint &bigint::operator++()
{
	*this = *this + bigint(1);
	return (*this);
}

bigint bigint::operator++(int)
{
	bigint temp = (*this);
	*this = *this + bigint(1);
	return (temp);
}


// Shift with num
bigint bigint::operator<<(unsigned int n) const
{
	bigint temp = *this;
	temp.number.insert(temp.number.end(), n, '0');
	return (temp);
}

bigint bigint::operator>>(unsigned int n) const
{
	bigint temp = *this;
	if (n >= temp.number.length())
		temp.number = "0";
	else
		temp.number.erase(temp.number.length() - n, n);
	return (temp);
}

bigint &bigint::operator<<=(unsigned int n)
{
	*this = *this << n;
	return (*this);
}

bigint &bigint::operator>>=(unsigned int n) 
{
	*this = *this >> n;
	return (*this);
}


// Shift with object
unsigned int stringToUint(std::string str)
{
	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return (res);
}

bigint bigint::operator<<(const bigint &other) const
{
	bigint temp;
	temp = *this << stringToUint(other.number);
	return (temp);
}

bigint bigint::operator>>(const bigint &other) const
{
	bigint temp;
	temp = *this >> stringToUint(other.number);
	return (temp);
}

bigint &bigint::operator<<=(const bigint &other)
{
	return (*this <<= stringToUint(other.number));
}

bigint &bigint::operator>>=(const bigint &other)
{
	return (*this >>= stringToUint(other.number));
}


// Bools
bool bigint::operator==(const bigint &other) const
{
	return (this->number == other.number);
}

bool bigint::operator!=(const bigint &other) const
{
	return (this->number != other.number);
}

bool bigint::operator<(const bigint &other) const
{
	size_t len1 = this->number.length();
	size_t len2 = other.number.length();
	
	if (len1 != len2)
		return (len1 < len2);
	return (this->number < other.number);
}

bool bigint::operator>(const bigint &other) const
{
	return (other < *this);
}

bool bigint::operator<=(const bigint &other) const
{
	return (*this < other || *this == other);
}

bool bigint::operator>=(const bigint &other) const
{
	return (*this > other || *this == other);
}

// Non-member function
std::ostream &operator<<(std::ostream &output, const bigint &obj)
{
	output << obj.getStr();
	return (output);
}


// 3363
// 460

// 3633
// 064

// 3633
// 0640

// 3 + 0 + 0 = 3
// 6 + 6 + 0 = 12 --> (12 / 10 = 1) --> (12 % 10 = 2)
// 3 + 4 + 1 = 8
// 3 + 0 + 0 = 3

// 3283

// result:
// 3823