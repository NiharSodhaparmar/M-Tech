pkg load image;
r = imread("./Fig0905(a)(wirebond-mask).tif");
subplot(1,3,1);
imshow(r);
title("Original Image");

struct_ele1 = ones(45);
s1 = imerode(r,struct_ele1);
subplot(1,3,2);
imshow(r-s1);
title("Given Image B");

struct_ele2 = ones(11);
s2 = imerode(r,struct_ele2);
subplot(1,3,3);
imshow(r-s2);
title("GIven Image C");