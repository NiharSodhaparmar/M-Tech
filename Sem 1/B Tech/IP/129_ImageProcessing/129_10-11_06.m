#load image
pkg load image;
r = rgb2gray(imread("./1.jpeg"));
imshow(r);  
title("Original Image");
r = im2double(r);
figure;

#Horizontal Lines
horizontal_mask = [-1,-1,-1;2,2,2;-1,-1,-1];
horizontal_lines = my_filter(r, horizontal_mask);
subplot(2,2,1);
imshow(abs(horizontal_lines));  title("Horizontal Lines");

#Vertical Lines
vertical_mask = [-1,2,-1;-1,2,-1;-1,2,-1];
vertical_lines = my_filter(r, vertical_mask);
subplot(2,2,2);
imshow(abs(vertical_lines));  title("Vertical Lines");

#Oblique +45 Lines
positive45_mask = [-1,-1,2;-1,2,-1;2,-1,-1];
positive45_lines = my_filter(r,positive45_mask);
subplot(2,2,3);
imshow(abs(positive45_lines));  title("+ 45 Lines");

#Oblique -45 Lines
negative45_mask = [2,-1,-1;-1,2,-1;-1,-1,2];
negative45_lines = my_filter(r,negative45_mask);
subplot(2,2,4);
imshow(abs(negative45_lines));  title("- 45 Lines");