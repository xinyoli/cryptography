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
rabinRSA.PrintPrime256(p)

