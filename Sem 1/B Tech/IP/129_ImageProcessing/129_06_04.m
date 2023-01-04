clear all
clc
close all

pkg load image
img = rgb2gray(imread('./my.jpeg'));
subplot(1,2,1)
imshow(img);
title('My Image');

variance=0.06;
mean=1;

noisy =  imnoise(img,'gaussian',mean,variance);
subplot(1,2,2)
imshow(noisy);
title("Gaussian Noise");