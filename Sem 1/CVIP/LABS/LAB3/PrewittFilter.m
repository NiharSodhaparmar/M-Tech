close all;
clear;
clc;
pkg load image;

img = rgb2gray(imread("1.jpeg"));
img = imresize(img, [512, 628]);
img = im2double(img);

x = [-1, -1, -1;
     0, 0, 0;
     1, 1, 1;];

[M,N] = size(img);
[m,n] = size(x);
a = (m-1)/2;
b = (n-1)/2;
new_imsize = zeros(M + 2*a,N + 2*b);
new_imsize(1+a:M+a,1+b:N+b) = img;
%sub_image = ((1/(m*n)).*ones(m,n));
outx = zeros(size(img));
for i = 1+a:M+a,
  for j = 1+b:N+b,
    k = new_imsize(i-a:i+a,j-b:j+b);
    outx(i-a,j-b) = sum(sum(k.*x));
  endfor
endfor

y = [-1, 0, 1;
     -1, 0, 1;
     -1, 0, 1;];

[M,N] = size(img);
[m,n] = size(y);
a = (m-1)/2;
b = (n-1)/2;
new_imsize = zeros(M + 2*a,N + 2*b);
new_imsize(1+a:M+a,1+b:N+b) = img;
%sub_image = ((1/(m*n)).*ones(m,n));
outy = zeros(size(img));
for i = 1+a:M+a,
  for j = 1+b:N+b,
    k = new_imsize(i-a:i+a,j-b:j+b);
    outy(i-a,j-b) = sum(sum(k.*y));
  endfor
endfor

out = abs(outx) + abs(outy);

figure;
subplot(1,2,1);
imshow(img);
title("Original Image");

subplot(1,2,2);
imshow(out);
title("Prewitt Filtered Image");
