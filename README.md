# poland
Polish prefix/postfix method to write math expressions
```text
$ pol.py "2+2*3-(6+3)"
Infix: 2 + 2 * 3 - ( 6 + 3 )
Rewriting in postfix:
token/stack
  '2' | '' -> ''
  '+' | '' -> '+'
  '2' | '+' -> '+'
  '*' | '+' -> '+*'
  '3' | '+*' -> '+*'
  '-' | '+*' -> '-'
  '(' | '-' -> '-('
  '6' | '-(' -> '-('
  '+' | '-(' -> '-(+'
  '3' | '-(+' -> '-(+'
  ')' | '-(+' -> '-'
Postfix: 2 2 3 * + 6 3 + -
```
