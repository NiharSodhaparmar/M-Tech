close all;
clear;
clc;
pkg load image;

img = imread("./1.jpeg");
img = rgb2gray(img);

figure;
subplot(1,2,1);
imshow(img);
title("Original Image");

cannyEdgeImage = edge(img, 'Canny');

subplot(1,2,2);
imshow(cannyEdgeImage);
title("Canny Edge Detector Image");
