%���㣨4/1+X^2����0��1����Ļ���
a = 0
b = 1
epsilon = 5e-6
f = @(x)4 ./ (1 + x^2);
y = romberg(f,a,b,epsilon) ;