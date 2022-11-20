clc
clear
close all

%load the image;
a = imread("./IMG_1566.JPG");
imshow(a);

%r channel histogram equilzation
[final(:,:,1),r_histogram_y,r_s] = MyHistEqulizer(a(:,:,1));
figure;
plot(0:255,r_histogram_y);
title("r channel histogram");

%g channel histogram equlization
[final(:,:,2),g_histogram_y,g_s] = MyHistEqulizer(a(:,:,2));
figure;
plot(0:255,g_histogram_y);
title("g channel histogram");

%b channel histogram equlization
[final(:,:,3),b_histogram_y,b_s] = MyHistEqulizer(a(:,:,3));
figure;
plot(0:255,b_histogram_y);
title("b channel histogram");

%see the final image
figure;
imshow(final);
imwrite(final,"after_first_histogram_equlization.jpg")