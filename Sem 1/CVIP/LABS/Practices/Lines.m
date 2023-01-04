close all;
clc;
clear;
pkg load image;

img = imread("lines2.jpg");
% img = rgb2gray(img);
img = imresize(img, [240, 240]);
img = im2double(img);

# Horizontal Lines
h_mask = [-1, -1, -1;
          2, 2, 2;
          -1, -1, -1;];

h_lines = my_filter(img, h_mask);
figure;
subplot(2,2,1);
imshow(h_lines);

# Vertical Lines
v_mask = [-1, 2, -1;
          -1, 2, -1;
          -1, 2, -1;];

v_lines = my_filter(img, v_mask);
subplot(2,2,2);
imshow(v_lines);

# +45 Lines
p45_mask = [-1, -1, 2;
          -1, 2, -1;
          2, -1, -1;];

p45_lines = my_filter(img, p45_mask);
subplot(2,2,3);
imshow(p45_lines);

# -45 Lines
n45_mask = [2, -1, -1;
          -1, 2, -1;
          -1, -1, 2;];

n45_lines = my_filter(img, n45_mask);
subplot(2,2,4);
imshow(n45_lines);
