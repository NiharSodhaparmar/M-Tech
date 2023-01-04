close all
clear
clc

% Read Image
a = imread('E:\SEM 7\IP\lab3images\IMG_2018.jpg');

% Gray scale image
b=rgb2gray(a);
figure
imshow(b)