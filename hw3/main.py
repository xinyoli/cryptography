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
p = 0xdaaefe65_2cad1614_f17e87f2_cd80973f
q = 0xf9998862_6723eef2_a54ed484_dfa735c7
m = 0xbe000bad_bebadbad_bad00deb_deadface_deafbeef_add00add_bed00bed
c = rabinRSA.RabinEnc(m, p, q)
print("Ciphertext=", end='')
rabinRSA.PrintBigNum(c)

