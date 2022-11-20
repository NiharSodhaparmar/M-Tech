clc
clear all
close all

pkg load image
img = rgb2gray(imread('./my.jpeg'));
subplot(1,2,1)
imshow(img);
title('My Image');

prob =  0.3;
noisy = salt_noise(img,prob);

prob =  0.2;
noisy = pepper_noise(noisy,prob);
subplot(1,2,2)
imshow(noisy);
title("Gaussian and SaltPaper Noise");