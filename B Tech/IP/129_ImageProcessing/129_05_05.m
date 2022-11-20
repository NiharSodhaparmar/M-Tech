close all
clear
clc

% Read Image
img = imread("./face.jpeg");
figure
subplot(1,2,1)
imshow(img)

out(:,:,1) = my_standard_box_filter_padding(img(:,:,1),11,11);
out(:,:,2) = my_standard_box_filter_padding(img(:,:,2),11,11);
out(:,:,3) = my_standard_box_filter_padding(img(:,:,3),11,11);

subplot(1,2,2)
imshow(out)