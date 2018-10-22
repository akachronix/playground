#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include <chrono>

static long long power(long long base, long long exponent)
{
	long long x = base;
	for (long long i = 1; i < exponent; ++i)
		x *= base;
	return x;
}

static long long factorial(long long n)
{
	if (n > 1)
		return n * factorial(n - 1);
	
	return 1;
}

static bool prime(long long n) 
{
	for (int i = 2; i < n; ++i)
		if (n % i == 0) 
			return false;
	
	return true;
}

int main(void)
{
	std::future<bool> prime_thread = std::async(prime, 444444443);
	std::future<long long> power_thread = std::async(power, 2, 16);
	std::future<long long> factorial_thread = std::async(factorial, 10);

	std::cout << "calculating";
	std::chrono::milliseconds span(100);

	while (power_thread.wait_for(span) == std::future_status::timeout 
		&& factorial_thread.wait_for(span) == std::future_status::timeout
		&& prime_thread.wait_for(span) == std::future_status::timeout)
		std::cout << ".";

	bool prime_answer = prime_thread.get();
	long long power_answer = power_thread.get();
	long long factorial_answer = factorial_thread.get();

	std::cout << '\n';
	std::cout << "prime: 444444443 " << (prime_answer ? "is" : "is not") << " prime.\n";
	std::cout << "power: " << power_answer << '\n';
	std::cout << "factorial: " << factorial_answer << '\n';

	std::cin.get();
	return 0;
}