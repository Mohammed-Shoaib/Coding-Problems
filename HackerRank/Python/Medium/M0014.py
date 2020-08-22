# Problem Statement: https://www.hackerrank.com/challenges/class-1-dealing-with-complex-numbers/problem

import math

class Complex(object):
	def __init__(self, real, imaginary):
		self.real = real
		self.imaginary = imaginary
		
	def __add__(self, no):
		return Complex(self.real + no.real, self.imaginary + no.imaginary)
		
	def __sub__(self, no):
		return Complex(self.real - no.real, self.imaginary - no.imaginary)
		
	def __mul__(self, no):
		return Complex(self.real*no.real - self.imaginary*no.imaginary,
					   self.real*no.imaginary + self.imaginary*no.real)

	def __truediv__(self, no):
		x = self.real*no.real + self.imaginary*no.imaginary
		y = self.imaginary*no.real - self.real*no.imaginary
		z = no.real*no.real + no.imaginary*no.imaginary
		return Complex(x / z, y / z)

	def mod(self):
		return Complex(math.sqrt(self.real*self.real + self.imaginary*self.imaginary), 0)

	def __str__(self):
		return f'{self.real:.2f}{self.imaginary:+.2f}i'