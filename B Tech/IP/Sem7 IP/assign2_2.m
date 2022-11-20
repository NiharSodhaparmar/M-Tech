clear
clc

% Read image into a
my_img = imread('E:\SEM 7\IP\Sem7 IP\my_img.jpg');
a = imread('E:\SEM 7\IP\Lab_2_exercise_images\3.jpg');

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