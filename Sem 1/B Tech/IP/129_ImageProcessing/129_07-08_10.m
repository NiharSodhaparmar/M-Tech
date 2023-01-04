r = imread("./gaussian_noise.jpeg");
subplot(1,2,1);
imshow(r);
title("Original Image");

s = my_median_filter(r,5,5);
subplot(1,2,2);
imshow(s);
title("After Applying Median Filter");