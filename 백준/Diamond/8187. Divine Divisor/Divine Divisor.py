import sys

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def is_prime(k):
    if k <= 97: return k in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
    else: return all(miller_rabin(k, i) for i in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29])

def miller_rabin(n, a):
    r = 0
    d = n - 1
    while d % 2 == 0:
        r += 1
        d //= 2
    x = pow(a, d, n)
    if x == 1 or x == n - 1: return True
    for _ in range(r - 1):
        x = pow(x, 2, n)
        if x == n - 1: return True
    return False

def g(x, n):
    return ((x * x) + 1) % n

def pollards_rho(n, x):
    p = x
    if is_prime(n): return n
    else:
        for i in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]:
            if n % i == 0: return i
        y = x
        d = 1
        while d == 1:
            x = g(x, n)
            y = g(g(y, n), n)
            d = gcd(abs(x - y), n)
        if d == n: return pollards_rho(n, p + 1)
        else:
            if is_prime(d): return d
            else: return pollards_rho(d, 2)

def factorize(n, factors):
    while n != 1:
        k = int(pollards_rho(n, 2))
        if k not in factors: factors[k] = 1
        else: factors[k] += 1
        n //= k
    return factors

n = int(sys.stdin.readline())
factors = {}
num_li = list(map(int, sys.stdin.readline().split()))
for i in range(n): factors = factorize(num_li[i], factors)
max_key = max(factors, key=factors.get)
max_value = factors[max_key]
count = list(factors.values()).count(max_value)
print(max_value)
print(2 ** count - 1)