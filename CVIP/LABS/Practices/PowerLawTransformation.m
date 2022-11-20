clear;
clc;
close all;

img = imread("C:/Nihar/M Tech/CVIP/Practices/9.jpg");
img = im2double(img);

figure;
subplot(1,2,1);
imshow(img);

c = 1;
gammaValue = 0.4;
s = c * (img .** gammaValue);

subplot(1,2,2);
imshow(s/max(max(s)));
