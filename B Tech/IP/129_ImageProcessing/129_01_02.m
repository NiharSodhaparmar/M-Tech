clear
clc

% matrix A
a = [ 6,43,2,11,87 ; 12,6,34,0,5 ; 34,18,7,41,9 ]

% a) row vector va contains elements of second row of A
va = a(2,:)

% b) row vector vb contains elements of fourth column of A
vb1 = a(:,4);
vb =[];
[n m] = size(vb1);
for i = 1:n
  vb(1,i) = vb1(i,1);
endfor
vb

% c) row vector vc contains elements of first and second row of A
vc = [ a(1,:) a(2,:)]

% d) row vector vd contains elements of second and fifth column of A
vd1 = [ a(:,2);a(:,5) ];
vd =[];
[n m] = size(vd1);
for i = 1:n
  vd(1,i) = vd1(i,1);
endfor
vd