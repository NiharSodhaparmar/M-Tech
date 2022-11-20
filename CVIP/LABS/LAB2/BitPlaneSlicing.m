close all;
clear;
clc;

img = imread("sodhaparmarnihar.jpeg");
grayImg = rgb2gray(img);

figure;
for i=1:8
  bp(:,:,i) = bitget(grayImg, i);
  subplot(2,4,i);
  imshow(bp(:,:,i));
  title(["Bit Plane ", num2str(i)]);
endfor
