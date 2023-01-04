clc
close all
clear

a=imread('E:\SEM 7\IP\lab\cameraman.tif');
b=imread('E:\SEM 7\IP\lab\4.jpg');
pkg load image
neg = 255 - a;

c=im2bw(a);
imshow(c);

d=and(c,b);
figure
imshow(d);

d=or(c,b);
figure
imshow(d);

d=not(c);
figure
imshow(d);

figure
imshow(neg);