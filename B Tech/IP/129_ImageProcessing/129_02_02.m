clear
clc

% Read images
img1 = imread('./1.jpg');
img2 = imread('./2.jpg');

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