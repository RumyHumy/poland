# poland
Convert infix to postfix/prefix notation

## Python version
```text
$ ./pol.py "a+b*c-(d+e)^f/g"

INFIX:
a + b * c - d + e ^ f / g
PREFIX:
- + a * b c / ^ + d e f g
POSTFIX:
a b c * + d e + f ^ g / -
```

## C version
```text
$ gcc pol.c -o pol
$ ./pol "a+b*c-(d+e)^f/g"
'a', '+', 'b', '*', 'c', '-', '(', 'd', '+', 'e', ')', '^', 'f', '/', 'g'
PREFIX:
- + a * b c / ^ + d e f g
POSTFIX:
g f e d + ^ / c b * a + -
```
