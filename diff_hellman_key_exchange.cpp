#include <iostream>
#include <random>
#include <cmath>
using namespace std;

// Function to calculate modular exponentiation (a^b % p)
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    // Step 1: Choose a large prime number and a primitive root modulo
    long long p = 66;
    long long g = 15;

    // Step 2: Both parties choose private keys
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<long long> distribution(1, p - 1);
    
    long long a = distribution(generator);  // DhruvVaria's private key
    long long b = distribution(generator);  // VishalShingala's private key

    // Step 3: Compute public keys
    long long A = mod_pow(g, a, p);  // DhruvVaria's public key
    long long B = mod_pow(g, b, p);  // VishalShingala's public key

    // Step 4: Exchange public keys
    // In a real scenario, DhruvVaria and VishalShingala would send A and B to each other

    // Step 5: Compute the shared secret
    long long shared_secret_DhruvVaria = mod_pow(B, a, p);
    long long shared_secret_VishalShingala = mod_pow(A, b, p);

    // Both DhruvVaria and VishalShingala now have the same shared secret
    cout << "Shared secret for DhruvVaria: " << shared_secret_DhruvVaria << endl;
    cout << "Shared secret for VishalShingala: " << shared_secret_VishalShingala << endl;

    return 0;
}
