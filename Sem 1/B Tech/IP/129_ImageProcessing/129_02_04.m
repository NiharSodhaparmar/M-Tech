clear
clc

% Read images
original_img = imread('./4.jpg');
mask = imread('./5.jpg');
background_img = imread('./6.jpg');

% Resize mask to 357*512
mask=imresize(mask,[357,512]);

original_img = im2double(original_img);
mask = im2double(mask);
background_img = im2double(background_img);

a = original_img .* mask;

neg = 1 - mask;
b = background_img .* neg;

c = a + b;
imshow(c);
