clear all
clc
close all

pkg load image
img = rgb2gray(imread('./my.jpeg'));
subplot(1,2,1)
imshow(img);
title('My Image');
[M,N] = size(img);

sigma=10;
mean=5;
prob=0.4;
noisy = gaussian_noise_with_prob(img,sigma,mean,prob);
subplot(1,2,2)
imshow(noisy);
title('Gaussian Noise with 0.4');
imwrite(noisy,"./gaussian_noise.jpeg")