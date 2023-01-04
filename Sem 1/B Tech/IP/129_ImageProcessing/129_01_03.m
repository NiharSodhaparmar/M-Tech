clear
clc

% matrix A
a = [ 5,2,4 ; 1,7,-3 ; 6,-10,0 ]

% matrix B
b = [ 11,5,-3 ; 0,-12,4 ; 2,6,1 ]

% matrix c
c = [ 7,14,1 ; 10,3,-2 ; 8,-5,9 ]

% A+B = B+A
a_plus_b = a + b
b_plus_a = b + a
ans_a = a_plus_b == b_plus_a

% A+(B+C) = (A+B)+C
a_mul_b_plus_c = a*(b+c)
a_mul_b_plus_a_mul_c = a*b + a*c
ans_b = a_mul_b_plus_c == a_mul_b_plus_a_mul_c

% 5(A+C) = 5A+5C
const_star_a_plus_c = 5 * (a + c)
const_star_a_plus_const_star_c = 5*a + 5*c
ans_c = const_star_a_plus_c == const_star_a_plus_const_star_c

% A*(B+C) = A*B+A*C
a_star_b_plus_c = a * (b + c)
a_star_b_plus_a_star_c = a*b + a*c
ans_d = a_star_b_plus_c == a_star_b_plus_a_star_c