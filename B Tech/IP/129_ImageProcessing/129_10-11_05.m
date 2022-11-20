pkg load image;
r = imread("./1.jpeg");
r = im2bw(r);
subplot(1,2,1);
imshow(r);
title("Original Image");

[m,n] = size(r);
struct_ele = strel('diamond',1);
x0 = zeros(m,n);
x0(460,585) = 1;
x0(265,190) = 1;
x0(125,110) = 1;
dilate_image = imdilate(x0,struct_ele);
x1 = dilate_image.*r;

while(!isequal(x0,x1))
  x0=x1;
  dilate_image = imdilate(x0,struct_ele);
  x1 = dilate_image.*r;
endwhile

subplot(1,2,2); 
imshow(x1);
title("Extracted Connected Components"); 