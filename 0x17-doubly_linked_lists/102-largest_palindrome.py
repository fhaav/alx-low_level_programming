#!/usr/bin/python3

def is_palindrome(n):
    return str(n) == str(n)[::-1]

def largest_palindrome():
    l_palindrome = 0
    for x in range(100, 1000):
        for h in range(x, 1000):
            product = x * h
            if is_palindrome(product) and product > l_palindrome:
                l_palindrome = product
    return l_palindrome

result = largest_palindrome()
