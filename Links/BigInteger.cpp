#include "BigInteger.h"

void BigInteger::init()
{
	for (int i = 0; i < N; i ++) num[i] = 0;
}

BigInteger::BigInteger()
{
	num = new int[N];
	init();
	l_size = 1;
	l_sign = 1;
}

BigInteger::BigInteger(int n)
{
	num = new int[N];
	init();
	l_sign = n > 0 ? 1 : -1;
	l_size = 0;
	while (n) {
		num[l_size++] = n % 10;
		n /= 10;
	}
}

BigInteger::BigInteger(string s)
{
	num = new int[N];
	init();
	l_size = s.size();
	int i = 0;
	bool flag = 1;
	if (s[0] == '-') l_sign = -1, i = 1, flag = 0;
	else l_sign = 1;
	l_size -= i;
	if (l_size > N) throw OVER_FLOW;

	for (; i < s.size(); i++) {
		if (s[s.size() - i - flag] < '0' || s[s.size() - i - flag] > '9') throw SYNTAX_ERROR;
		num[i - !flag] = s[s.size() - i - flag] - '0';
	}
}

BigInteger::BigInteger(int* n, int size, int sign)
{
	num = new int[N];
	init();
	l_sign = sign;
	l_size = size;
	if (l_size > N) throw OVER_FLOW;
	for (int i = 0; i < l_size; i ++) {
		num[i] = n[l_size - i - 1];
	}
}

BigInteger::BigInteger(const BigInteger& b)
{
	*this = b;
}

BigInteger::~BigInteger()
{
	delete[] num;
}

int BigInteger::size() const
{
	return l_size;
}

int BigInteger::sign() const
{
	return l_sign;
}

bool BigInteger::operator<(const BigInteger& b) const
{
	if (sign() < b.sign()) return true;
	if (sign() > b.sign()) return false;
	if (size() < b.size()) return true;
	if (size() > b.size()) return false;
	for (int i = size() - 1; i >= 0; i--) {
		if (num[i] < b.num[i]) return true;
		if (num[i] > b.num[i]) return false;
	}
	return false;
}

bool BigInteger::operator>(const BigInteger& b) const
{
	if (sign() < b.sign()) return false;
	if (sign() > b.sign()) return true;
	if (size() < b.size()) return false;
	if (size() > b.size()) return true;
	for (int i = size() - 1; i >= 0; i--) {
		if (num[i] < b.num[i]) return false;
		if (num[i] > b.num[i]) return true;
	}
	return false;
}

bool BigInteger::operator<=(const BigInteger& b) const
{
	if (sign() < b.sign()) return true;
	if (sign() > b.sign()) return false;
	if (size() < b.size()) return true;
	if (size() > b.size()) return false;
	for (int i = size() - 1; i >= 0; i--) {
		if (num[i] < b.num[i]) return true;
		if (num[i] > b.num[i]) return false;
	}
	return true;
}

bool BigInteger::operator>=(const BigInteger& b) const
{
	if (sign() < b.sign()) return false;
	if (sign() > b.sign()) return true;
	if (size() < b.size()) return false;
	if (size() > b.size()) return true;
	for (int i = size() - 1; i >= 0; i--) {
		if (num[i] < b.num[i]) return false;
		if (num[i] > b.num[i]) return true;
	}
	return true;
}

bool BigInteger::operator==(const BigInteger& b) const
{
	if (sign() != b.sign()) return false;
	if (size() != b.size()) return false;
	for (int i = 0; i < size(); i ++) {
		if (num[i] != b.num[i]) return false;
	}
	return true;
}

BigInteger& BigInteger::operator=(const BigInteger& b)
{
	num = new int[N];
	init();
	l_size = b.size();
	l_sign = b.sign();
	for (int i = 0; i < l_size; i ++) {
		num[i] = b.num[i];
	}
	return *this;
}

BigInteger BigInteger::operator+(const BigInteger& b) const
{
	if (sign() * b.sign() < 0) {
		// 一正一负
		if (sign() > b.sign()) {
			BigInteger ret = b;
			ret.l_sign *= -1;
			ret = *this - ret;
			return ret;
		}
		else {
			BigInteger ret = *this;
			ret.l_sign *= -1;
			ret = ret - *this;
			return ret;
		}
	}
	int more = 0;
	BigInteger ret;
	if (sign() < 0) ret.l_sign = -1;
	int i = 0;
	for (; i < max(size(), b.size()); i++) {
		if (i < size()) ret.num[i] += num[i];
		if (i < b.size()) ret.num[i] += b.num[i];
		ret.num[i] += more;
		more = ret.num[i] / 10;
		ret.num[i] %= 10;
	}
	while (more) {
		if (i >= N) throw OVER_FLOW;
		ret.num[i++] = more % 10;
		more /= 10;
	}
	ret.l_size = i;
	return ret;
}

BigInteger BigInteger::operator-(const BigInteger& b) const
{
	if (sign() * b.sign() < 0) {
		// 一正一负
		BigInteger ret = b;
		ret.l_sign *= -1;
		return *this + ret;
	}
	BigInteger ret;
	int more = 0;
	int i = 0;
	bool flag = (*this) >= b; // 判断符号
	//cout << flag << endl;
	if (sign() < 0) ret.l_sign *= -1;
	if (!flag) ret.l_sign *= -1;
	for (; i < max(size(), b.size()); i ++) {
		if (i < size()) {
			if (flag) ret.num[i] += num[i];
			else ret.num[i] -= num[i];
		}
		if (i < b.size()) {
			if (flag) ret.num[i] -= b.num[i];
			else ret.num[i] += b.num[i];
		}
		//cout << ret.num[i] << endl;
		ret.num[i] -= more;
		more = 0;
		if (ret.num[i] < 0) {
			more = (-1) * ret.num[i] / 10 + 1;
			ret.num[i] = ret.num[i] % 10 + 10;
		}
	}
	while (more) {
		if (i >= N) throw OVER_FLOW;
		ret.num[i++] -= more % 10;
		more /= 10;
	}
	ret.l_size = i;
	return ret;
}

BigInteger BigInteger::operator*(const BigInteger& b) const
{
	BigInteger ret;
	//cout << "ret.num[18]=" << ret.num[18] << endl;
	ret.l_sign = sign() * b.sign();
	for (int i = 0; i < size(); i ++) {
		int more = 0;
		int j = 0;
		for (; j < b.size(); j ++) {
			//cout << j << endl;
			if (i + j >= N) throw OVER_FLOW;
			ret.num[i + j] += num[i] * b.num[j] + more;
			more = ret.num[i + j] / 10;
			ret.num[i + j] %= 10;
		}
		while (more) {
			if (i + j >= N) throw OVER_FLOW;
			ret.num[i + j] += more % 10;
			more /= 10;
			j += 1;
		}
		ret.l_size = max(ret.l_size, i + j);
		//cout << "i=" << i << endl;
		//cout << "i+j=" << i + j << endl;
	}
	return ret;
}

BigInteger BigInteger::operator-() const
{
	BigInteger ret = *this;
	ret.l_sign *= -1;
	return ret;
}

BigInteger abs(const BigInteger& b)
{
	BigInteger ret = b;
	ret.l_sign = 1;
	return ret;
}

ostream& operator<<(ostream& out, const BigInteger& b)
{
	if (b.sign() < 0) out << '-';
	for (int i = b.size() - 1; i >= 0; i --) {
		out << b.num[i];
	}
	return out;
}
