close all
clear
clc

% Read Image
img = imread("./cat.jpg");
figure
subplot(1,3,1)
imshow(img)
title("Original Image");
out = my_standard_box_filter_padding(img,9,9);
for i=1:4
  out = my_standard_box_filter_padding(out,9,9);
endfor
subplot(1,3,2)
imshow(out)
title("After 5 pass");

for i=1:5
  out = my_standard_box_filter_padding(out,9,9);
endfor
subplot(1,3,3)
imshow(out)
title("After 10 pass");