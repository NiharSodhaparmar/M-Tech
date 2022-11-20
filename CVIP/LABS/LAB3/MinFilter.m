close all;
clc;
clear;
pkg load image;

img = imread("1.jpeg");
img = rgb2gray(img);
img = imresize(img, [512, 628]);

figure;
subplot(1,2,1);
imshow(img);
title("Original Image");

m=3;
n=3;

[M,N]=size(img);
a=(m-1)/2;
b=(n-1)/2;
new_imsize = zeros(M+2*a,N+2*b);
new_imsize(1+a:M+a,1+b:N+b)= img;
out = zeros(size(img));
for i=1+a:M+a,
  for j=1+b:N+b,
    k=new_imsize(i-a:i+a,j-b:j+b);
    out(i-a,j-b)=min(min(k));
  endfor
endfor
out=uint8(out);

subplot(1,2,2);
imshow(out);
title("Min Filtered Image (3*3)");
