close all;
clear;
clc;
pkg load image;

img = imread("sodhaparmarnihar.jpeg");

grayImg = rgb2gray(img);
figure;
subplot(1,2,1);
imshow(grayImg);

negativeImg = 255 - grayImg;
subplot(1,2,2);
imshow(negativeImg);

