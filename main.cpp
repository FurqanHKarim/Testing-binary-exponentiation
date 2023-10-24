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


static void Benchmarknormalexponent(benchmark::State& state) {
    for (auto _ : state) {
        for (long long  i = 0; i < state.range(0); i++)
        {
            
            multiply(666,i);
        }
        
    }
}
static void BenchmarkForBinaryExpo(benchmark::State& state) {
    for (auto _ : state) {
        for (long long  i = 0; i < state.range(0); i++)
        {
            
            binpow(666,i);
        }
    }
}
BENCHMARK(BenchmarkForBinaryExpo)->Range(1,10000);
BENCHMARK(Benchmarknormalexponent)->Range(1,10000);

//BENCHMARK_MAIN();

int main(int argc, char** argv) {

        benchmark::Initialize(&argc, argv);
        benchmark::RunSpecifiedBenchmarks();
	
	
	return 0;

}