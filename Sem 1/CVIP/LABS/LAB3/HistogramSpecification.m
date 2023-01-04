clc;
clear;
close all;

pkg load image;

img = imread("6.jpg");
spec = imread("test4.jpg");

% Original Image
figure;
subplot(3,4,1);
imshow(img);
title("Original Image");

subplot(3,4,2);
imhist(img(:,:,1));
title("R histogram");

subplot(3,4,3);
imhist(img(:,:,2));
title("G histogram");

subplot(3,4,4);
imhist(img(:,:,3));
title("B histogram");

% Specified Image
subplot(3,4,5);
imshow(spec);
title("Specified Image");

subplot(3,4,6);
imhist(spec(:,:,1));

subplot(3,4,7);
imhist(spec(:,:,2));

subplot(3,4,8);
imhist(spec(:,:,3));

% Histogram specified image
final(:,:,1) = my_hist_matcher(img(:,:,1),spec(:,:,1));
final(:,:,2) = my_hist_matcher(img(:,:,2),spec(:,:,2));
final(:,:,3) = my_hist_matcher(img(:,:,3),spec(:,:,3));

subplot(3,4,9);
imshow(final);
title("Final Image");

subplot(3,4,10);
imhist(final(:,:,1));

subplot(3,4,11);
imhist(final(:,:,2));

subplot(3,4,12);
imhist(final(:,:,3));
