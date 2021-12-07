# useful-dev

On Twitter there was a discussion about what every developer should undestand. Useful knowledge on a daily basis to help you, at least, understand how your tools work and make your job easier. The list ended with the following items, in order:

1. Recursion
2. Trees and basic operations on them
3. Write a bad parser
4. Interpret the lambda calculus

This repo contains examples of this list in C programming language.

## Recursion
Recursion is the same as for loop, you don't study, you have to practice. Literally any loop can be translated to a recursion version and vice versa.

That's why trees are mentioned in second in the list. Trees without recursion is really terrible.

## Trees and basic operations on them
There are a lot of data structures over there, take a look at graphs for example, it's an insane field. But one data structure developers should know but don't, it's trees.

Trees are a subset of graphs which you really use it in practice, because code is a tree and data derived from code too (like JSON).

## Write a bad parser
The best way to understand motivations of an AST is writing a parser for it.

To understand tools you need to understand an AST and parsers helps a lot on it.

Also, it helps to debug because you understand how the parser you're using it works, so when you see a error at line 182 in a file with 181 lines you know it happened because something wasn't closed and the parser is waiting for a token which doesn't exists.

## Interpret the lambda calculus
The lambda calculus is the mathematical basis for what it is most modern in programming languages.
