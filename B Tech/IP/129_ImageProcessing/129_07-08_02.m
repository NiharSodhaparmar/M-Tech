clc
clear all
close all

pkg load image;

r1 = imread("./pepper_noise.jpeg");
r1 = imresize(r1,[512,512]);
subplot(1,2,1);
imshow(r1);
title("Peeper Noise Image");

s1 = my_homomorphic_filter(r1,2,6);
subplot(1,2,2);
imshow(s1);
title("Filtered Image");

figure;

r2 = imread("./salt_noise.jpeg");
r2 = imresize(r2,[512,512]);
subplot(1,2,1);
imshow(r2);
title("Salt Noise Image");

s2 = my_homomorphic_filter(r2,2,6);
subplot(1,2,2);
imshow(s2);
title("Filtered Image");

figure;

r3 = imread("./salt_and_pepper_noise.jpeg");
r3 = imresize(r3,[512,512]);
subplot(1,2,1);
imshow(r3);
title("Salt and Peeper Noise Image");

s3 = my_homomorphic_filter(r3,1,6);
subplot(1,2,2);
imshow(s3);
title("Filtered Image");