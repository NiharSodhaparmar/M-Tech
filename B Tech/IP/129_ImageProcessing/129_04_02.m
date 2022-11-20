clc
clear all
close all

image1 = imread("./1.png");
image2 = imread("./2.png");
figure
subplot(1,2,1)
imshow(image1)

subplot(1,2,2)
imshow(image2)

%load package image
pkg load image;

%check for histogram
figure
subplot(1,2,1)
imhist(image1)

subplot(1,2,2)
imhist(image2)
