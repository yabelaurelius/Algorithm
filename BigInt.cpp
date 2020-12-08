#include <bits/stdc++.h>

using namespace std;

enum sign { PLUS, MINUS };

struct bigint {
	deque<int> num;
	sign isSign = PLUS;

	bigint() {
		// default bigint
	}

	bigint(int x) { // convert int to bigint
		num.clear();
		if (x < 0) isSign = MINUS, x = -x;
		do {
			num.push_back(x % 10);
			x /= 10;
		} while (x > 0);
	}

	bigint(long long int x) { // convert long long int to bigint
		num.clear();
		if (x < 0) isSign = MINUS, x = -x;
		do {
			num.push_back(x % 10);
			x /= 10;
		} while (x > 0);
	}

	bigint abs() {
		(*this).isSign = PLUS;
		return *this;
	}


	// COMPARE OPERATORS

	bool operator == (bigint x) {
		if (isSign == x.isSign && num.size() == x.num.size()) {
			for (int i=0; i<num.size(); i++)
				if (num[i] != x.num[i])
					return false;
			return true;
		}
		return false;
	}

	bool operator < (bigint x) {
		if (isSign != x.isSign) return isSign < x.isSign;
		int n = num.size();
		int m = x.num.size();

		if (n != m) {
			bool res = n < m;
			if (isSign == PLUS) return res;
			else if (isSign == MINUS) return !res;
		}

		for (int i=n-1; i>=0; i--) {
			if (num[i] != x.num[i]) {
				bool res = num[i] < x.num[i];
				if (isSign == PLUS) return res;
				else if (isSign == MINUS) return !res;
			}
		}

		return false;
	}

	bool operator <= (bigint x) {
		return *this < x || *this == x;
	}

	bool operator > (bigint x) {
		return !(*this <= x);
	}

	bool operator >= (bigint x) {
		return *this > x || *this == x;
	}

	bool operator != (bigint x) {
		return !(*this == x);
	}


	// MATH OPERATORS

	bigint operator + (bigint x) {
		if (isSign == x.isSign) {
			bigint result;
			result.isSign = isSign;

			int carry = 0;
			for (int i=0; i<max(num.size(), x.num.size()); i++) {
				int a = (i < num.size()) ? num[i] : 0;
				int b = (i < x.num.size()) ? x.num[i] : 0;
				int c = a + b + carry;

				result.num.push_back(c % 10);
				carry = c / 10;
			}
			if (carry != 0) result.num.push_back(carry);
			return result;
		}
		if (isSign == PLUS) return *this - x.abs();
		if (isSign == MINUS) return x - (*this).abs();
	}

	void operator += (bigint x) {
		*this = *this + x;
	}

	void operator ++ () {
		bigint x;
		x.num.push_back(1);

		*this += x;
	}

	bigint operator - (bigint x) {
		bigint result;
		bigint a = (*this).abs();
		bigint b = x.abs();

		if (*this == x) {
			result.isSign = PLUS;
			result.num.push_back(0);
			return result;
		}

		if (isSign == x.isSign) {
			if (a < b) {
				for (int i = 0; i < b.num.size(); i++) {
					int e = b.num[i];
					int f = (i < a.num.size()) ? a.num[i] : 0;
					if (e >= f) result.num.push_back(e - f);
					else {
						result.num.push_back(10 + e - f);
						b.num[i+1]--;
					}
				}
				if (isSign == PLUS) result.isSign = MINUS;
			}
			else {
				for (int i = 0; i < a.num.size(); i++) {
					int e = a.num[i];
					int f = (i < b.num.size()) ? b.num[i] : 0;
					if (e >= f) result.num.push_back(e - f);
					else {
						result.num.push_back(10 + e - f);
						a.num[i+1]--;
					}
				}
				if (isSign == MINUS) result.isSign = MINUS;
			}
			return result;
		}

		if (isSign == MINUS) {
			result = (*this).abs() + x;
			result.isSign = MINUS;
			return result;
		}
		else return *this + x.abs();
	}

	void operator -= (bigint x) {
		*this = *this - x;
	}

	void operator -- () {
		bigint x;
		x.num.push_back(1);

		*this -= x;
	}

	bigint operator * (bigint x) {
		bigint result;
		if (isSign == x.isSign) result.isSign = PLUS;
		else result.isSign = MINUS;

		for (int i=0; i<x.num.size(); i++) {
			bigint temp;
			int carry = 0;

			for (int j=0; j<i; j++) temp.num.push_back(0);
			for (int j=0; j<num.size(); j++) {
				int c = num[j] * x.num[i] + carry;
				temp.num.push_back(c % 10);
				carry = c / 10;
			}
			if (carry != 0) temp.num.push_back(carry);
			result += temp;
		}

		return result;
	}

	void operator *= (bigint x) {
		*this = *this * x;
	}

	bigint operator / (bigint x) {
		bigint carry;
		bigint result;
		if (isSign == x.isSign) result.isSign = PLUS;
		else result.isSign = MINUS;

		for (int i=num.size()-1; i>=0; i--) {
			carry.num.push_front(num[i]);
			if (carry < x) result.num.push_front(0);
			else {
				for (int j=1; j<=10; j++) {
					bigint temp = bigint(j);
					temp *= x;
					if (temp > carry) {
						result.num.push_front(j-1);
						temp -= x;
						carry -= temp;
						break;
					}
				}
			}
		}

		return result;
	}

	void operator /= (bigint x) {
		*this = *this / x;
	}

	bigint operator % (bigint x) {
		bigint carry;
		bigint result;
		for (int i=num.size()-1; i>=0; i--) {
			carry.num.push_front(num[i]);
			if (carry < x) result.num.push_front(0);
			else {
				for (int j=1; j<=10; j++) {
					bigint temp = bigint(j);
					temp *= x;
					if (temp > carry) {
						result.num.push_front(j-1);
						temp -= x;
						carry -= temp;
						break;
					}
				}
			}
		}

		// Same with operator / . The different is...
		if (result.isSign == MINUS) return *this - x;
		else return carry;
	}

	void operator %= (bigint x) {
		*this = *this % x;
	}

	void print() {
		if (isSign == MINUS) cout << '-';
		for (int i=num.size()-1; i>=0; i--) {
			cout << num[i];
		}
		cout << endl;
	}
};

bigint power(bigint x, bigint y) { // Fast / Modular Exponentiation
	bigint res = bigint(1);
	while (y > bigint(0)) {
		if (y % bigint(2) == bigint(1))
			res = res * x;
		y /= 2;
		x *= x;
	}
	return res;
}

int main() {
	bigint a = bigint(10);
	bigint b = bigint(2);

	cout << "a = "; a.print();
	cout << "b = "; b.print();

	bigint jumlah = a + b;
	bigint kurangPositif = a - b;
	bigint kurangNegatif = b - a;
	bigint perkalian = a * b;
	bigint pembagian = a / b;
	bigint sisaBagi = bigint(8) % bigint(3);
	bigint duaPangkatLima = power(bigint(2), bigint(5));

	cout << "jumlah = "; jumlah.print();
	cout << "kurangPositif = "; kurangPositif.print();
	cout << "kurangNegatif = "; kurangNegatif.print();
	cout << "perkalian = "; perkalian.print();
	cout << "pembagian = "; pembagian.print();
	cout << "sisaBagi = "; sisaBagi.print();
	cout << "duaPangkatLima = "; duaPangkatLima.print();
}
