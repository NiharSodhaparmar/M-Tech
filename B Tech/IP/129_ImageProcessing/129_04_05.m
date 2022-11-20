clc
clear
close all

a = imread("./test3.tif");
imshow(a);

[b,b_histogram_y,s] = MyHistEqulizer(a);
figure;
imshow(b);
