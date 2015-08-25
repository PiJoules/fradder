#include <stdio.h>
#include <stdlib.h>

unsigned long gcd(unsigned long a, unsigned long b){
	while (b > 0){
		unsigned long rem = a % b;
		a = b;
		b = rem;
	}
	return a;
}

int main(int argc, char* argv[]){
	unsigned long num = 0;
	unsigned long den = 1;
	unsigned long n;
	scanf("%lu", &n);
	unsigned long nums[n], dens[n];
	unsigned long i;
	for (i = 0; i < n; i++){
		scanf("%lu/%lu", nums+i, dens+i);
	}

	for (i = 0; i < n; i++){
		den *= dens[i];
	}

	for (i = 0; i < n; i++){
		num += nums[i]*den/dens[i];
	}

	unsigned long GCD = gcd(num, den);
	num /= GCD;
	den /= GCD;
	printf("%lu/%lu\n", num, den);

	return 0;
}