close all
clear
clc

% Read Image
a = imread('./1.tif');
a = im2double(a);
imshow(a)

rmin = min(min(a))
rmax = max(max(a))
smin = 0/255;
smax = 255/255;
s = (smax-smin)/(rmax-rmin)*(a-rmin)+smin;
figure
imshow(s)