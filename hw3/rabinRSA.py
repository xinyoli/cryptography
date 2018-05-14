import random
import secrets

def SmallPrimeTest(n):		# check whether n is times of any prime number listed 
	# prime number < 1000
	p = ((
		3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
		37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
		83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137,
		139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
		197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
		263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317,
		331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389,
		397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457,
		461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523,
		541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
		607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661,
		673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743,
		751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823,
		827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
		907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977,
		983, 991, 997
	))
	
	for x in p:
		if n % x == 0:
			return False
	return True


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
	if not SmallPrimeTest(n):
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

	
def GenPrime256():
	n = secrets.randbits(256)
	while not MillerRabin(n):
		# print(hex(n), "is a composition!")
		n = secrets.randbits(256)
	# print(hex(n), "is a prime!")
	return n
	


