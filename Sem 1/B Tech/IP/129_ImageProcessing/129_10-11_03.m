pkg load image;
r=im2bw(imread("./1.jpeg"));
subplot(2,3,1);
imshow(r);
title("Original Image");

#Erosion
struct_ele = ones(7);
s1 = imerode(r,struct_ele);
subplot(2,3,2);
imshow(s1);
title("Erosion");

#Dilation
s2 = imdilate(r,struct_ele);
subplot(2,3,3);
imshow(s2); title("Dilation");

#Opening
s3 = imdilate(imerode(r,struct_ele),struct_ele);
subplot(2,3,4);
imshow(s3); title("Opening");

#Closing
s4 = imerode(imdilate(r,struct_ele),struct_ele);
subplot(2,3,5);
imshow(s4); title("Closing");

#Boundary extraction
s5 = r-s1;
subplot(2,3,6);
imshow(s5); title("Boundry extraction");