clear
clc

% Read image
r = imread('E:\SEM 7\IP\Lab_2_exercise_images\8.jpg');

figure
imshow(r)

c = 1;
s = c * log(1 + r);
figure
imshow(s/max(max(s)))