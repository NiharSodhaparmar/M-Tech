close all
clear
clc

% Read image into a
img = imread('./1.jpeg');
img = rgb2gray(img);
imshow(img)

out = my_standard_box_filter_padding(img,11,11);
figure
imshow(out)
title('11*11 Filter')