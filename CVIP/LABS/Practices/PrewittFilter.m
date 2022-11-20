close all;
clear;
clc;
pkg load image;

img = rgb2gray(imread("1.jpeg"));
img = imresize(img, [240, 240]);
img = im2double(img);

x = [-1, -1, -1;
     0, 0, 0;
     1, 1, 1;];

y = [-1, 0, 1;
     -1, 0, 1;
     -1, 0, 1;];

outx = my_filter(img, x);
outy = my_filter(img, y);

out = abs(outx) + abs(outy);

figure;
subplot(1,2,1);
imshow(img);
title("Original Image");

subplot(1,2,2);
imshow(out);
title("Prewitt Filtered Image");
