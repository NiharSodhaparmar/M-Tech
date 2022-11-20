close all;
clear;
clc;

img = imread("sodhaparmarnihar.jpeg");
grayImg = rgb2gray(img);

b = grayImg - 90;
b = im2double(b);
figure;
subplot(1,2,1);
imshow(b);
title("Original Image");

rmin = min(min(b));
rmax = max(max(b));
smin = 0 / 255;
smax = 255 / 255;
s = (smax - smin)/(rmax - rmin)*(b - rmin) + smin;

subplot(1,2,2);
imshow(s);
title("Contrast Enhanced Image");
