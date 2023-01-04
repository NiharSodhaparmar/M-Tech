close all;
clc;
clear;
pkg load image;

img = imread("1.jpeg");
img = rgb2gray(img);
img = imresize(img, [1024, 1024]);

figure;
subplot(1,2,1);
imshow(img);
title("Original Image");

blurredImg = my_standard_box_filter(img, 7, 7);
subplot(1,2,2);
imshow(blurredImg);
title("Blurred Image");
