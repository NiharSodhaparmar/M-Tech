close all
clear
clc

% Read Image
a = imread('./IMG_2018.jpg');

% Gray scale image
b=rgb2gray(a);
b=b-70;
b = im2double(b);
b = lowcont(b);
figure
imshow(b)

s = highcont(b);
figure
imshow(s)