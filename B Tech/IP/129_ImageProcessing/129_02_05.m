clear
clc

% Read image
my_img = imread('./IMG_4613.jpg');

% Gray scale image
a = rgb2gray(my_img);
figure
imshow(a)

% Negative image
a = 255 - a;
figure
imshow(a)