import random

def MillerRabin(n, t=10):	# n: should be a positive odd number, t: number of repetition.
	
	def check(a, k, m, n):
		y = pow(a, m, n)
		if y == 1:
			return True
		for i in range(k - 1):
			if y == n - 1:
				return True
			y = pow(y, 2, n)
		return y == n - 1
	
	
	if n == 2:			# if n == 2
		return True
	if not n & 1:		# if n is even 
		return False
		
	# Compute k & odd m s.t. n — 1 = m2^k
	k = 0
	m = n - 1
	while m % 2 == 0:
		m >>= 1
		k += 1
	
	for i in range(t):	
		a = random.randrange(2, n-1)		# Choose a random integer a s.t. 2 <= a <= n — 2
		if not check(a, k, m, n):
			return False
	return True

n = 1223
if MillerRabin(n):
	print("Number ", n, "is a prime")
else:
	print("Number ", n, "is a composition")