clear
close all
clc

a = imread('E:\SEM 7\IP\lab3images\6.jpg');
imshow(a)
[m,n,p] = size(a);
%b=zeros(m,n);
for i=1:m
  for j=1:n
    if(a(i,j,1)>100 && a(i,j,2)<90 && a(i,j,3)<90)
      b(i,j)=1;
     else
      b(i,j)=0;
     endif
  endfor
endfor
figure
imshow(b)

final = a .* b;
figure
imshow(final)