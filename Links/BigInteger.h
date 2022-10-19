#pragma once
#include "utility.h"

// ��������
class BigInteger
{
private:
	int* num; // �洢������
	int l_size; // �������ĳ���
	int l_sign; // �������ķ���
	void init(); // ��ʼ��
public:
	BigInteger();
	BigInteger(int n); // ͨ��int���͹��������
	BigInteger(string s); // ͨ��string���������
	BigInteger(int *n, int size, int sign); // ͨ�����鹹�������
	BigInteger(const BigInteger &b); // �������캯��
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
	BigInteger operator-() const; // ��Ŀ�����-
	friend BigInteger abs(const BigInteger& b); // ȡ����ֵ
	friend ostream& operator<<(ostream& out, const BigInteger& b); // �������
};

BigInteger abs(const BigInteger &b);
ostream& operator<<(ostream &out, const BigInteger &b);
