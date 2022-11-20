clear
clc

% Read images
img1 = imread('E:\SEM 7\IP\Lab_2_exercise_images\1.jpg');
img2 = imread('E:\SEM 7\IP\Lab_2_exercise_images\2.jpg');

figure
imshow(img1)

figure
imshow(img2)

c = img2- img1;
figure
imshow(c)

c = img1- img2;
figure
imshow(c)