clear
clc

% Read image into a
my_img = imread('./my_img.jpg');
a = imread('./3.jpg');

% Resize the image to 256*256.
my_img=imresize(my_img,[256,256]);
figure
imshow(my_img)

% Logical and
b = and(my_img,a);
figure
imshow(b)

% Logical or
b = or(my_img,a);
figure
imshow(b)

% Logical not
b = not(my_img);
figure
imshow(b)