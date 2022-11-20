clc;
clear all;
close all;

pkg load image
img = rgb2gray(imread('./my.jpeg'));
subplot(1,2,1)
imshow(img);
title('My Image');

a=10;
b=20;
noisy = uniform_noise(img,a,b);
subplot(1,2,2)
imshow(noisy);
title("Uniform noise with probability 1  and a=10 , b=20");