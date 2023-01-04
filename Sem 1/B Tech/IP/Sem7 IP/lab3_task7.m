clear
close all
clc

a = imread('E:\SEM 7\IP\lab3images\3.tif');
imshow(a)

for i=1:8;
  bp(:,:,i)=bitget(a,i);
  subplot(2,4,i)
  imshow(bp(:,:,i))
endfor

