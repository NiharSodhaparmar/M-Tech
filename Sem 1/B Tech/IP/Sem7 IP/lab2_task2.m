clc
close all
clear

a=imread('E:\SEM 7\IP\lab\input.jpg');
b=imread('E:\SEM 7\IP\lab\background.jpg');
c=imread('E:\SEM 7\IP\lab\mask.jpg');
a1=im2double(a);
b1=im2double(b);
c1=im2double(c);
d1=a1.*c1;
neg=1-c1;
d2=b1.* neg;
d=d1+d2;
imshow(d);