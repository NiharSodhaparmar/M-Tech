close all;
clc;
clear;
pkg load image;

img = imread("1.jpeg");
img = rgb2gray(img);
img = imresize(img, [512, 628]);
img = im2double(img);

figure;
subplot(1,2,1);
imshow(img);
title("Original Image");

kernel = [  0,  0, -1,  0,  0;
            0, -1, -2, -1,  0;
           -1, -2, 16, -2, -1;
            0, -1, -2, -1,  0;
            0,  0, -1,  0,  0; ];

[M,N] = size(img);
[m,n] = size(kernel);
a = (m-1)/2;
b = (n-1)/2;
new_imsize = zeros(M + 2*a,N + 2*b);
new_imsize(1+a:M+a,1+b:N+b) = img;
%sub_image = ((1/(m*n)).*ones(m,n));
out = zeros(size(img));
for i = 1+a:M+a,
  for j = 1+b:N+b,
    k = new_imsize(i-a:i+a,j-b:j+b);
    out(i-a,j-b) = sum(sum(k.*kernel));
  endfor
endfor

subplot(1,2,2);
imshow(out);
title("Laplacian of Gaussian Filtered Image");
