# Problem Statement: https://www.hackerrank.com/challenges/standardize-mobile-number-using-decorators/problem

def wrapper(f):
    def fun(l):
    	l = map(lambda x: f'+91 {x[-10:-5]} {x[-5:]}', l)
    	f(l)
    return fun