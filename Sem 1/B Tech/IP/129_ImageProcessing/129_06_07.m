clc
clear all
close all

pkg load image
img = rgb2gray(imread('./my.jpeg'));
subplot(1,2,1)
imshow(img);
title('My Image');

prob =  0.3;
noisy = pepper_noise(img,prob);
subplot(1,2,2)
imshow(noisy);
title("Pepper noise with probability 0.3");
imwrite(noisy,"./pepper_noise.jpeg")