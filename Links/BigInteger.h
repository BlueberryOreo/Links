#pragma once
#include "utility.h"

// 大整数类
class BigInteger
{
private:
	int* num; // 存储大整数
	int l_size; // 大整数的长度
	int l_sign; // 大整数的符号
	void init(); // 初始化
public:
	BigInteger();
	BigInteger(int n); // 通过int类型构造大整数
	BigInteger(string s); // 通过string构造大整数
	BigInteger(int *n, int size, int sign); // 通过数组构造大整数
	BigInteger(const BigInteger &b); // 拷贝构造函数
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
	BigInteger operator-() const; // 单目运算符-
	friend BigInteger abs(const BigInteger& b); // 取绝对值
	friend ostream& operator<<(ostream& out, const BigInteger& b); // 重载输出
};

BigInteger abs(const BigInteger &b);
ostream& operator<<(ostream &out, const BigInteger &b);
