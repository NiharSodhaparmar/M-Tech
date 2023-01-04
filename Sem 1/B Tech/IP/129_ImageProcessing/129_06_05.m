clc
clear all
close all

pkg load image
img = rgb2gray(imread('./my.jpeg'));
subplot(1,2,1)
imshow(img);
title('My Image');

prob =  0.2;
noisy = salt_and_pepper_noise(img,prob);
subplot(1,2,2)
imshow(noisy);
title("Salt and Pepper noise with probability 0.2");
imwrite(noisy,"./salt_and_pepper_noise.jpeg")