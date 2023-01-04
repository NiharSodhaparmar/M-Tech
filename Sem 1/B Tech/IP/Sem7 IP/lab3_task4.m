clear
clc

a = imread('E:\SEM 7\IP\lab3images\4.tif');
a = im2double(a);
imshow(a)

rmin = min(min(a))
rmax = max(max(a))
smin = 0/255;
smax = 255/255;
s = (smax-smin)/(rmax-rmin)*(a-rmin)+smin;
figure
imshow(s)

a = imread('E:\SEM 7\IP\lab3images\2.jpg');
a = im2double(a);
figure
imshow(a)

rmin = min(min(a))
rmax = max(max(a))
smin = 70/255;
smax = 100/255;
s = (smax-smin)/(rmax-rmin)*(a-rmin)+smin;
figure
imshow(s)

a = imread('E:\SEM 7\IP\lab3images\2.jpg');
th = 128;
[m,n] = size(a);
for i=1:m
  for j=1:n
    if(a(i,j)>th)
      b(i,j)=1;
     else
      b(i,j)=0;
     endif
  endfor
endfor
figure
imshow(b)

