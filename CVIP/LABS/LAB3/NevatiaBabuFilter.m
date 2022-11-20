close all;
clc;
clear;
pkg load image;

img = imread("1.jpeg");
img = rgb2gray(img);
img = imresize(img, [512, 628]);
img = im2double(img);

figure;
subplot(2,2,1);
imshow(img);
title("Original Image");

kernel = [ 100, 100, 0, -100, -100;
           100, 100, 0, -100, -100;
           100, 100, 0, -100, -100;
           100, 100, 0, -100, -100;
           100, 100, 0, -100, -100; ];

[M,N] = size(img);
[m,n] = size(kernel);
a = (m-1)/2;
b = (n-1)/2;
new_imsize = zeros(M + 2*a,N + 2*b);
new_imsize(1+a:M+a,1+b:N+b) = img;
kernel = ((1/(1000)).*kernel);
out = zeros(size(img));
for i = 1+a:M+a,
  for j = 1+b:N+b,
    k = new_imsize(i-a:i+a,j-b:j+b);
    out(i-a,j-b) = sum(sum(k.*kernel));
  endfor
endfor

subplot(2,2,2);
imshow(out);
title("0 Degree Nevatia Babu Filtered Image");

kernel = [ 100, -32, -100, -100, -100;
           100, -78,  -92, -100, -100;
           100, 100,    0, -100, -100;
           100, 100,   92,  -78, -100;
           100, 100,  100,   32, -100; ];

[M,N] = size(img);
[m,n] = size(kernel);
a = (m-1)/2;
b = (n-1)/2;
new_imsize = zeros(M + 2*a,N + 2*b);
new_imsize(1+a:M+a,1+b:N+b) = img;
kernel = ((1/(1102)).*kernel);
out = zeros(size(img));
for i = 1+a:M+a,
  for j = 1+b:N+b,
    k = new_imsize(i-a:i+a,j-b:j+b);
    out(i-a,j-b) = sum(sum(k.*kernel));
  endfor
endfor

subplot(2,2,3);
imshow(out);
title("30 Degree Nevatia Babu Filtered Image");

kernel = [ -100, -100, -100, -100, -100;
             32,  -78, -100, -100, -100;
            100,   92,    0,  -92, -100;
            100,  100,  100,   78,  -32;
            100,  100,  100,  100,  100; ];

[M,N] = size(img);
[m,n] = size(kernel);
a = (m-1)/2;
b = (n-1)/2;
new_imsize = zeros(M + 2*a,N + 2*b);
new_imsize(1+a:M+a,1+b:N+b) = img;
kernel = ((1/(1102)).*kernel);
out = zeros(size(img));
for i = 1+a:M+a,
  for j = 1+b:N+b,
    k = new_imsize(i-a:i+a,j-b:j+b);
    out(i-a,j-b) = sum(sum(k.*kernel));
  endfor
endfor

subplot(2,2,4);
imshow(out);
title("60 Degree Nevatia Babu Filtered Image");
