#!/bin/python3

import sys

opdic = { "+": 1, "-": 1, "*": 2, "/": 2, "^": 3 }

if __name__ == "__main__":
    if len(sys.argv) != 2:
        if sys.argv < 1: print("Not enough arguments.")
        else: print("Too much arguments.")
        exit(1)

    # T O K E N I Z E

    infix = ""
    for c in sys.argv[1]:
        infix += f" {c} " if opdic.get(c) or c in "()" else c
    infix = [t for t in infix.split() if len(t)]
    print(infix)

    # D U P L I C A T I O N   C H E C K

    for i in range(len(infix)-1):
        if opdic.get(infix[i]) != None and opdic.get(infix[i+1]) != None:
            print("Invalid expression: two operators in a row.")
            exit(1)
    
    # T R E E

    #class TreeNode:
    #    v = None
    #    l, r = None, None

    #def FillRec(toks):
        
