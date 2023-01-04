clc
clear
close all
%load the image;
a = imread("./after_first_histogram_equlization.jpg");

%r channel histogram equilzation
[final(:,:,1),r_histogram_y,r_s] = MyHistEqulizer(a(:,:,1));
figure;
subplot(1,2,1)
plot(0:255,r_histogram_y);
title("r channel histogram before EQ");
subplot(1,2,2)
imhist(final(:,:,1));
title("r channel histogram after EQ");

%g channel histogram equlization
[final(:,:,2),g_histogram_y,g_s] = MyHistEqulizer(a(:,:,2));
figure;
subplot(1,2,1)
plot(0:255,g_histogram_y);
title("g channel histogram before EQ");
subplot(1,2,2)
imhist(final(:,:,2));
title("g channel histogram after EQ");
    
%b channel histogram equlization
[final(:,:,3),b_histogram_y,b_s] = MyHistEqulizer(a(:,:,3));
figure;
subplot(1,2,1)
plot(0:255,b_histogram_y);
title("b channel histogram before EQ");
subplot(1,2,2)
imhist(final(:,:,3));
title("b channel histogram after EQ");

%see the final image
figure;
imshow(final);