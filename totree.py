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

    # D U P L I C A T I O N   C H E C K

    for i in range(len(infix)-1):
        if opdic.get(infix[i]) != None and opdic.get(infix[i+1]) != None:
            print("Invalid expression: two operators in a row.")
            exit(1)
    
    # T R E E

    class ExpNode:
        def __init__(self, value, left, right):
            self.value = value
            self.left = left
            self.right = right

    stack = [] # Node stack
    ops = [] # Operand stack

    def AddOp(stack, ops):
        right = stack.pop()
        left = stack.pop()
        node = ExpNode(ops.pop(), left, right)
        stack.append(node)

    for t in infix:
        if opdic.get(t):
            while ops and opdic.get(t) <= opdic.get(ops[-1]):
                AddOp(stack, ops)
            ops.append(t)
        else:
            stack.append(ExpNode(t, None, None))
    print()
    while ops:
        AddOp(stack, ops)

    # P R I N T

    def PrintInfix(node):
        if node:
            PrintInfix(node.left)
            print(node.value, end=' ')
            PrintInfix(node.right)

    def PrintPrefix(node):
        if node:
            print(node.value, end=' ')
            PrintInfix(node.left)
            PrintInfix(node.right)

    def PrintPostfix(node):
        if node:
            PrintInfix(node.left)
            PrintInfix(node.right)
            print(node.value, end=' ')

    print("INFIX: ")
    PrintInfix(stack[0])
    print()
    print("PREFIX: ")
    PrintPrefix(stack[0])
    print()
    print("POSTFIX: ")
    PrintPostfix(stack[0])
    print()
