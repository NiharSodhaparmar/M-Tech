clc
clear all
close all

pkg load image
img = rgb2gray(imread('./my.jpeg'));
subplot(1,2,1)
imshow(img);
title('My Image');

prob =  0.5;
noisy = salt_noise(img,prob);
subplot(1,2,2)
imshow(noisy);
title("Salt noise with probability 0.5");
imwrite(noisy,"./Lab6/salt_noise.jpeg")