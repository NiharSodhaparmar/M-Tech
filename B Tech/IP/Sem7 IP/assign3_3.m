close all
clear
clc

% Read Image
a = imread('E:\SEM 7\IP\lab3images\my.jpg');
[m,n] = size(a);

for i=1:m
  for j=1:n
    if(a(i,j)>128)
      b(i,j)=1;
     else
      b(i,j)=0;
     endif
  endfor
endfor
figure
imshow(b)