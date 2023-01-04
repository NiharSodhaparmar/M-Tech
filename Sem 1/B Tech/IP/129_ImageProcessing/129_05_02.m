close all
clear
clc

% Read image into a
img = imread('./1.jpeg');
img = rgb2gray(img);
imshow(img)

out = my_standard_box_filter(img,3,3);
figure
imshow(out)
title('3*3 Filter')

out = my_standard_box_filter(img,5,5);
figure
imshow(out)
title('5*5 Filter')

out = my_standard_box_filter(img,7,7);
figure
imshow(out)
title('7*7 Filter')

out = my_standard_box_filter(img,9,9);
figure
imshow(out)
title('9*9 Filter')