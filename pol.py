#!/bin/python3

import sys

op = [0]*255
op[ord('+')] = 1
op[ord('-')] = 1
op[ord('*')] = 2
op[ord('/')] = 2
op[ord('^')] = 3
op[ord('(')] = 3
op[ord(')')] = 3

def opord(c):
    return op[ord(c)] if ord(c)<=255 else 0

if __name__ == '__main__':
    if len(sys.argv) < 1:
        print('Not enough arguments.')
        exit(1)

    # Tokenize
    exp = sys.argv[1]
    infix = ""
    for c in exp:
        if opord(c):
            infix += ' '+c+' '
        else:
            infix += c
    infix = [t for t in infix.split() if len(t) > 0]
    
    # Rewrite
    #stack = []
    #postfix = []
    #for t in tok:
    #    if opord(t[0]):
    #        postfix.append(t)
    #    else:
    #        while len(stack) and opord(stack[]
