clc;
clear;
close all;

img = imread("./myImage.jpg");
img = rgb2gray(img);

figure;
subplot(1,2,1);
imshow(img);
title("Original Image");

#High Boost Filter with central value=4 and A=1.
kernel = [  0,  -1,  0;
            -1,  5, -1;
            0,  -1,  0; ];

[M,N] = size(img);
[m,n] = size(kernel);
a = (m-1)/2;
b = (n-1)/2;
new_imsize = zeros(M + 2*a,N + 2*b);
new_imsize(1+a:M+a,1+b:N+b) = img;
out = zeros(size(img));
for i = 1+a:M+a,
  for j = 1+b:N+b,
    k = new_imsize(i-a:i+a,j-b:j+b);
    out(i-a,j-b) = sum(sum(k.*kernel));
  endfor
endfor

subplot(1,2,2);
imshow(out);
title("High Boost Filtered Image");
