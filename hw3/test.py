#######################################################
# file: test.py
# Project: COM 5336 cyptography hw assignment3
# Description: 
#	implement Rabin crypto-system
#
# Change history: May. 14, 2018 - file created.
#
#######################################################

import rabinRSA


# n = 1223
# if MillerRabin(n):
	# print("Number ", n, "is a prime")
# else:
	# print("Number ", n, "is a composition")

	
# an 256-bit prime number generator
# n = secrets.randbits(256)
# while not MillerRabin(n):
	# print(hex(n), "is a composition!")
	# n = secrets.randbits(256)
# print(hex(n), "is a prime!")

# print(SmallPrimeTest(1223))

p = rabinRSA.GenPrime256()
print("an 256-bit prime number: \n", hex(p))
