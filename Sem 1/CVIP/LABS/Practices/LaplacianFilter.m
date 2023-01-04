close all;
clc;
clear;
pkg load image;

img = imread("1.jpeg");
img = rgb2gray(img);
img = imresize(img, [240, 240]);
img = im2double(img);

figure;
subplot(1,2,1);
imshow(img);

mask = [ 0, 1, 0;
         1, -4, 1;
         0, 1, 0;];

lines = my_filter(img, mask);
subplot(1,2,2);
imshow(lines);
