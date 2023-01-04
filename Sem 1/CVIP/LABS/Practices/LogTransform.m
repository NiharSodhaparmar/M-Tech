clear;
clc;
close all;

img = imread("8.jpg");

figure;
subplot(1,2,1);
imshow(img);

c = 1;
s = c * log(1 + img);

subplot(1,2,2);
imshow(s/max(max(s)));
