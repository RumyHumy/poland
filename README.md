# poland
Polish prefix/postfix method to write math expressions
```text
$ infix_to_postfix.py "2+2*3-(6+3)"
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
