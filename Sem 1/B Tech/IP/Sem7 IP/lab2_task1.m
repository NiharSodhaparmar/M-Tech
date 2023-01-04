% add two image
clc
close all
clear

% Read image into a
a=imread('E:\SEM 7\IP\lab\cameraman.tif');
b=imread('E:\SEM 7\IP\lab\rice.png');
b=imread('E:\SEM 7\IP\lab\4.jpg');

a1=im2double(a);
b1=im2double(b);
c1=a1-b1;
c1=c1/max(max(c1));

c = a.*b;
imshow(a1);
figure
imshow(b1);
figure
imshow(c);
title("sum");
imwrite(c,'E:\SEM 7\IP\lab\test_sum.jpg')