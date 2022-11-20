clc
close all
clear all
pkg load image;
r = imread("./1.jpeg");
r = im2bw(r);
subplot(1,2,1);
imshow(r);
title("Image before hole filling");

[m,n] = size(r);
rc = not(r);
struct_ele = strel('square',3);
x0 = zeros(m,n);
x0(300,800) = 1;  x0(400,790) = 1;  x0(360,850) = 1;
x0(360,850) = 1;  x0(540,650) = 1;  x0(470,755) = 1;
x0(455,800) = 1;  x0(620,800) = 1;  x0(530,720) = 1;
x0(610,550) = 1;

dilate_image = imdilate(x0,struct_ele);
x1 = dilate_image.*rc;

while(!isequal(x0,x1))
  x0=x1;
  dilate_image = imdilate(x0,struct_ele);
  x1 = dilate_image.*rc;
endwhile

subplot(1,2,2); 
s = r+x1;
imshow(s);
title("Image after hole filling");