close all
clear
clc

% Read image
img = imread('./1.jpeg');
img = rgb2gray(img);

window = 1/50*[1,1,2,1,1;1,2,4,2,1;2,4,8,4,2;1,2,4,2,1;1,1,2,1,1];
out = my_weighted_box_filter(img,window);
figure
imshow(out)