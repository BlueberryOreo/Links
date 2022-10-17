#pragma once
#include "utility.h"

class BigInteger
{
private:
	int* num;
	int l_size;
	int l_sign;
	void init();
public:
	BigInteger();
	BigInteger(int n);
	BigInteger(string s);
	BigInteger(int *n, int size, int sign);
	BigInteger(const BigInteger &b); // ¿½±´¹¹Ôìº¯Êý
	~BigInteger();
	int size() const;
	int sign() const;
	bool operator<(const BigInteger &b) const;
	bool operator>(const BigInteger &b) const;
	bool operator<=(const BigInteger &b) const;
	bool operator>=(const BigInteger &b) const;
	bool operator==(const BigInteger &b) const;
	BigInteger& operator=(const BigInteger &b);
	BigInteger operator+(const BigInteger &b) const;
	BigInteger operator-(const BigInteger &b) const;
	BigInteger operator*(const BigInteger &b) const;
	BigInteger operator-() const;
	friend BigInteger abs(const BigInteger& b);
	friend ostream& operator<<(ostream& out, const BigInteger& b);
};

BigInteger abs(const BigInteger &b);
ostream& operator<<(ostream &out, const BigInteger &b);
