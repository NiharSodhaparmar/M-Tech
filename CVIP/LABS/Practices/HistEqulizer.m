close all;
clear;
clc;
pkg load image

img = imread("test3.tif");

figure;
subplot(2,2,1);
imshow(img);
title("Origianal Image");

subplot(2,2,2);
imhist(img);

[b, b_histogram_y, s] = MyHistEqulizer(img);
subplot(2,2,3);
imshow(b);
title("Histogram Equalized Image");

subplot(2,2,4);
imhist(b);
