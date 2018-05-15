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

# p = rabinRSA.GenPrime256()
# print("an 256-bit prime number: \n", hex(p))

# m = 0xbe000bad_bebadbad_bad00deb_deadface_deafbeef_add00add_bed00bed
# print("Plaintext: ", end='')
# rabinRSA.PrintBigNum(m)
# last16 = (m & 0xffff)
# print("m last16: ", end='')
# rabinRSA.PrintBigNum(last16)
# m_append = (m << 16) + last16
# print("m appended: ", end='')
# rabinRSA.PrintBigNum(m_append)
# print("m appended: ", end='')
# print(hex(m_append))

a, b = 46, 240
s, t = rabinRSA.xgcd(a,b)
print("xgcd(",a,",",b,"): \ns =", s, "t =", t)
