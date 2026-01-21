#include "bigint.hpp"

bigint::bigint() : num("0") {}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	this->num = ss.str();
}

bigint::bigint(const bigint &source) { *this = source; }

bigint &bigint::operator=(const bigint &source)
{
	if (this == &source)
		return (*this);
	this->num = source.num;
	return (*this);
}

bigint::~bigint() {}


// Getter
std::string bigint::getStr() const
{
	return (this->num);
}


// Addition
std::string reverse(std::string str)
{
	std::string rev_str;

	for (int i = (str.length() - 1); i >= 0; i--)
		rev_str.push_back(str[i]);
	return (rev_str);
}

std::string addition(std::string str1, std::string str2)
{
	std::string num1 = reverse(str1);
	std::string num2 = reverse(str2);
	int len1 = num1.length();
	int len2 = num2.length();
	
	if (len1 > len2)
	{
		int digits = len1 - len2;
		for (int i = 0; i < digits; i++)
		num2.push_back('0');
	}
	else if (len2 > len1)
	{
		int digits = len2 - len1;
		for (int i = 0; i < digits; i++)
		num1.push_back('0');
	}
	
	std::string result;
	int carry = 0, digit1, digit2, res;
	for (size_t i = 0; i < num1.length(); i++)
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
	temp.num = addition(this->num, other.num);
	return (temp);
}

bigint &bigint::operator+=(const bigint &other)
{
	*this = *this + other;
	return (*this);
}


// Increment
bigint &bigint::operator++()
{
	*this = *this + bigint(1);
	return (*this);
}

bigint bigint::operator++(int)
{
	bigint temp = *this;
	*this = *this + bigint(1);
	return (temp);
}


// Shift with num
bigint bigint::operator<<(unsigned int n) const
{
	bigint temp = *this;
	temp.num.insert(temp.num.end(), n, '0');
	return (temp);
}

bigint bigint::operator>>(unsigned int n) const
{
	bigint temp = *this;
	if (n >= temp.num.length())
		temp.num = "0";
	else
		temp.num.erase(temp.num.length() - n, n);
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


// Shift with bigint
unsigned int stringToUint(std::string str)
{
	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return (res);
}

bigint bigint::operator<<(const bigint &other) const
{
	bigint temp = *this << stringToUint(other.num);
	return (temp);
}

bigint bigint::operator>>(const bigint &other) const
{
	bigint temp = *this >> stringToUint(other.num);
	return (temp);
}

bigint &bigint::operator<<=(const bigint &other)
{
	return (*this <<= stringToUint(other.num));
}

bigint &bigint::operator>>=(const bigint &other)
{
	return (*this >>= stringToUint(other.num));
}


// Bools
bool bigint::operator==(const bigint &other) const
{
	return (this->num == other.num);
}

bool bigint::operator!=(const bigint &other) const
{
	return (this->num != other.num);
}

bool bigint::operator<(const bigint &other) const
{
	int len1 = this->num.length();
	int len2 = other.num.length();

	if (len1 != len2)
		return (len1 < len2);
	return (this->num < other.num);
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

std::ostream &operator<<(std::ostream &output, const bigint &obj)
{
	output << obj.getStr();
	return (output);
}