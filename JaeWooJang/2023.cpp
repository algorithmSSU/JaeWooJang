#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class AmazingPrime {
private :
	bool* eratosArr;
	int eratosSize;

public :
	AmazingPrime() {
		eratosArr = NULL;
		eratosSize = 0;
	}

	~AmazingPrime() {
		if (eratosArr != NULL) {
			delete eratosArr;
			eratosArr = NULL;
		}
	}

	//! caution : you must FREE MEMORY after using it.
	vector<int>* getAmazingPrimeArr(int n) {
		/* ���� �Ҽ� : n�ڸ� ���� �Ҽ� => n-1�ڸ� ���� �Ҽ��� �� �ڸ��� �߰��� �� �� �Ҽ��� ��
		 *   => 1. n-1�ڸ� ���� �Ҽ� �迭�� ��´�.
		 *		2. �� n-1�ڸ� �Ҽ��� ����
		 *		3. 1~9�� �ڿ� �̾� ���� �� ���� �Ҽ��̸� => n�ڸ� ���� �Ҽ�
		 *		4. ������ �����ϴ� ���� �Ҽ��� �迭�� �־� return
		 */

		vector<int>* nPrimeArr = new vector<int>;

		if (eratosArr == NULL)
			getEratos(pow(10, n));

		if (n < 1) {
			nPrimeArr->push_back(0);
			return nPrimeArr;
		}

		// n-1�ڸ� ����Ҽ� 
		vector<int>* n_1PrimeArr = getAmazingPrimeArr(n - 1);

		// n-1�ڸ� ����Ҽ� => n�ڸ� ����Ҽ�
		for (vector<int>::iterator iter = n_1PrimeArr->begin(); iter != n_1PrimeArr->end(); ++iter) {
			int tmp = *iter * 10;
			for (int i = 0; i < 10; ++i) {
				if (isPrime(tmp + i))
					nPrimeArr->push_back(tmp + i);
			}
		}

		delete n_1PrimeArr;

		return nPrimeArr;
	}

	int getEratos(int n) {
		int len = sqrt(n) + 1;

		// Case : Causes OverFlow
		if (len > 46349)
			return -1;

		eratosSize = (len < 2) ? 2 : len;

		if (eratosArr != NULL)
			delete[] eratosArr;

		eratosArr = new bool[eratosSize];
		for (int i = 0; i < eratosSize; ++i)
			eratosArr[i] = true;

		eratosArr[0] = false;
		eratosArr[1] = false;

		for (int i = 2; i < eratosSize; ++i) {
			if (eratosArr[i] == true) {
				for (int j = i * i; j < eratosSize; j += i)
					eratosArr[j] = false;
			}
		}

		return len;
	}

	bool isPrime(int n) {
		if (n < 2)
			return false;

		// Case : In EratosArr
		if (n < eratosSize)
			return eratosArr[n];

		// Case : Greater than Eratos;
		for (int i = 0; i < eratosSize; ++i) {
			if (eratosArr[i])
				if (n % i == 0)
					return false;
		}

		return true;
	}
};

int problem2023() {
	int n;

	cin >> n;

	AmazingPrime* amp = new AmazingPrime();
	vector<int>* nPrimeArr = amp->getAmazingPrimeArr(n);

	for (vector<int>::iterator iter = nPrimeArr->begin(); iter != nPrimeArr->end(); ++iter)
		cout << *iter << "\n";

	delete amp;
	delete nPrimeArr;

	return 0;
}