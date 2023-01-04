clc
close all
clear

r=imread('E:\SEM 7\IP\DIP3E_Original_Images_CH03\3.tif');

pkg load image
b=1+r;
%c=im2double(b);
d=1*log(b);
imshow(d/max(max(d)));

%gamma g=imread('E:\SEM 7\IP\DIP3E_Original_Images_CH03\Fig0308(a)(fractured_spine).tif');