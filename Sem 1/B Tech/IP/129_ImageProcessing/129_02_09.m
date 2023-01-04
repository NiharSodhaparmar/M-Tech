clear
clc

% Read image into a
a = imread('./n.jpg');

% Gray scale image
b = rgb2gray(a);

% Over Exposed image
over_exp = b - 60;
over_exp = im2double(over_exp);
figure
imshow(over_exp)

% power law transformation
c = 1;
gamma_value = 0.6;
s = c * (over_exp .** gamma_value);
figure
imshow(s/max(max(s)))