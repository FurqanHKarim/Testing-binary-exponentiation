#include<iostream>
#include<benchmark/benchmark.h>

using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

long long multiply(long long a, long long b) {
    long long res = 1;

    for (long long i = 0; i < b; i++)
    {
        res *= a;
    }
    return res;
}


int main() {

    cout << binpow(666, 5) << endl;
    cout << multiply(666, 5) << endl;
	
	
	
	return 0;

}