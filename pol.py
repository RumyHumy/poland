#!/bin/python3

import sys

opdic = { "+": 1, "-": 1, "*": 2, "/": 2, "^": 3, "(": -1, ")": -1 }

def opord(c):
    return opdic.get(c)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Not enough arguments.")
        exit(1)

    # Tokenize
    exp = sys.argv[1]
    infix = ""
    for c in exp:
        if opord(c):
            infix += " "+c+" "
        else:
            infix += c
    infix = [t for t in infix.split() if len(t) > 0]
    print(f"Infix: {' '.join(infix)}")
    
    # Rewrite
    #print("Rewriting in postfix: ")
    #stack = []
    #postfix = []
    #for t in infix:
    #    print(f"  token/stack: '{t}': {', '.join(stack)}")
    #    if t == "(":
    #        stack.append(t)
    #    elif t == ")":
    #        while len(stack) and stack[-1] != "(":
    #            postfix.append(stack.pop())
    #        stack.pop()
    #    elif opord(t[0]):
    #        while len(stack) and opord(t[0]) <= opord(stack[-1][0]):
    #            postfix.append(stack.pop())
    #        stack.append(t)
    #    else:
    #        postfix.append(t)

    #while len(stack):
    #    postfix.append(stack.pop())

    #print(f"Postfix: {' '.join(postfix)}")
