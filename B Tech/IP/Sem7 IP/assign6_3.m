clear all
close all
clc

pkg load image
image = rgb2gray(imread('C:\Users\nihar\Downloads\1.jpeg'));
subplot(2,3,1)
imshow(image);
title('My Image');
mean=0;
variance=0.03;
gaussianNoisy = imnoise (image, 'gaussian', mean, variance);
subplot(2,3,2)
imshow(gaussianNoisy);
title('Gaussian Noise');
poissionNoisy=imnoise (image, 'poisson');
subplot(2,3,3)
imshow(poissionNoisy);
title('Poission Noise');
density=0.07;
saltpaperNoisy = imnoise (image, 'salt & pepper', density);
subplot(2,3,4)
imshow(saltpaperNoisy);
title('Salt & Pepper Noise');
speckleNoisy=imnoise (image, 'speckle', variance);
subplot(2,3,5)
imshow(speckleNoisy);
title('Speckle Noise');