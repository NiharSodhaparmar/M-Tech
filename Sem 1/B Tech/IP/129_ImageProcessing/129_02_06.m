clear
clc

% Read image
r = imread('./8.jpg');

figure
imshow(r)

c = 1;
s = c * log(1 + r);
figure
imshow(s/max(max(s)))