close all
clear
clc

% Read Image
a = imread('./my.jpg');

for i=1:8;
  bp(:,:,i) = bitget(a,i);
  subplot(2,4,i)
  imshow(bp(:,:,i))
endfor

sum = bp(:,:,8)*2^(7) + bp(:,:,7)*2^(6);
figure
imshow(uint8(sum))

sum = bp(:,:,8)*2^(7) + bp(:,:,7)*2^(6) + bp(:,:,6)*2^(5) + bp(:,:,5)*2^(4);
figure
imshow(uint8(sum))