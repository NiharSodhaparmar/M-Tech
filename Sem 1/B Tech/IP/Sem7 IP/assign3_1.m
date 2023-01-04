close all
clear
clc

% Read Image
a = imread('E:\SEM 7\IP\DIP3E_Original_Images_CH03\1.tif');
a = im2double(a);
imshow(a)

rmin = min(min(a))
rmax = max(max(a))
smin = 0/255;
smax = 255/255;
s = (smax-smin)/(rmax-rmin)*(a-rmin)+smin;
figure
imshow(s)