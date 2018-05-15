#!/usr/bin/env python
#######################################################
# file: main.py
# Project: COM 5336 cyptography hw assignment3
# Description: 
#	implement Rabin crypto-system
#
# Change history: May. 14, 2018 - file created.
#
#######################################################

import rabinRSA

p = rabinRSA.GenPrime256()
print("<Miller-Robin>")
rabinRSA.PrintBigNum(p)
print("")

print("<Rabin Encryption>")
# p = 0xdaaefe65_2cad1614_f17e87f2_cd80973f
# q = 0xf9998862_6723eef2_a54ed484_dfa735c7
# m = 0xbe000bad_bebadbad_bad00deb_deadface_deafbeef_add00add_bed00bed
m, p , q = 0, 0, 0
c = rabinRSA.RabinEnc(m, p, q)
print("Ciphertext=", end='')
rabinRSA.PrintBigNum(c)

print("\n<Rabin Decryption>")
# c = 0x5452361a_db4c34be_04a5903a_e00793bc_1086e887_ebed06e2_3ffba0b4_a4348cc0
# p = 0xd5e68b2b_5855059a_d1a80dd6_c5dc03eb
# q = 0xc96c6afc_57ce0f53_396d3b32_049fe2d3
c, p, q = 0, 0, 0
m = rabinRSA.RabinDec(c, p, q)
print("Plaintext = ", end='')
rabinRSA.PrintBigNumHex56(m)