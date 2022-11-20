clear all
close all
clc
 
pkg load image
img = rgb2gray(imread('./my.jpeg'));
subplot(2,3,1)
imshow(image);
title('My Image');

mean=0;
variance=0.01;
gaussianNoisy = imnoise(image,"gaussian",mean,variance);
subplot(2,3,2)
imshow(gaussianNoisy);
title('Gaussian Noise');

poissionNoisy=imnoise(image,"poisson");
subplot(2,3,3)
imshow(poissionNoisy);
title('Poission Noise');

density=0.05;
saltpaperNoisy = imnoise(image,"salt & pepper",density);
subplot(2,3,4)
imshow(saltpaperNoisy);
title('Salt & Pepper Noise');

speckleNoisy=imnoise(image,"speckle",variance);
subplot(2,3,5)
imshow(speckleNoisy);
title('Speckle Noise');