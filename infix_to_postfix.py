#!/bin/python3

import sys

opdic = { "+": 1, "-": 1, "*": 2, "/": 2, "^": 3 }

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Not enough arguments.")
        exit(1)

    # T O K E N I Z E

    exp = sys.argv[1]
    infix = ""
    for c in exp:
        if opdic.get(c) or c == "(" or c == ")":
            infix += " "+c+" "
        else:
            infix += c
    infix = [t for t in infix.split() if len(t) > 0]
    print(f"Infix: {' '.join(infix)}")

    for i in range(len(infix)-1):
        if opdic.get(infix[i]) != None and opdic.get(infix[i+1]) != None:
            print("Invalid expression: two operators in a row")
            exit(1)

    # P O S T F I X

    print("Rewriting in postfix: ")
    print("token/stack")
    stack = []
    postfix = []
    for t in infix:
        print(f"  '{t}' | '{''.join(stack)}' ", end="")
        if t == "(":
            stack.append(t)
        elif t == ")":
            while len(stack) and stack[-1] != "(":
                postfix.append(stack.pop())
            if not len(stack):
                print("\nInvalid expression: Excess ')'")
                exit(1)
            stack.pop()
        elif opdic.get(t[0]):
            while len(stack) and stack[-1] != "(" and opdic.get(t[0]) <= opdic.get(stack[-1][0]):
                postfix.append(stack.pop())
            stack.append(t)
        else:
            postfix.append(t)
        print(f"-> '{''.join(stack)}'")

    while len(stack):
        if stack[-1] == '(':
            print("Invalid expression: Excess '('")
            exit(1)
        postfix.append(stack.pop())

    print(f"Postfix: {' '.join(postfix)}")
