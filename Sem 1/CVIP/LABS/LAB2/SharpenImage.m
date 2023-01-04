close all;
clear;
clc;
pkg load image;

img = imread("rice.png");
img = im2double(img);

x = [0, -1, 0;
     -1, 5, -1;
     0, -1, 0;];

out = my_filter(img, x);

figure;
subplot(1,2,1);
imshow(img);
title("Original Image");

subplot(1,2,2);
imshow(out);
title("Sharpened Image");
