clear
clc

% Read image
r1 = imread('./9.jpg');
r2 = imread('./10.jpg');
r1 = im2double(r1);
r2 = im2double(r2);

figure
imshow(r1)

c = 1;

gamma_value = 0.4;
s = c * (r1 .** gamma_value);
figure
imshow(s/max(max(s)))

figure
imshow(r2)

gamma_value = 1.8;
s = c * (r2 .** gamma_value);
figure
imshow(s/max(max(s)))