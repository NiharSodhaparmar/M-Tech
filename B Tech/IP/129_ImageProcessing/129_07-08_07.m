r = imread('./sample_noise.jfif');
subplot(1,3,1);
imshow(r);
title("Original Image");

s1 = my_adaptive_median_filter(r,3,3);
subplot(1,3,3);
imshow(s1);
title("After Adaptive Median Filter");

s2 = my_median_filter(r,3,3);
subplot(1,3,2);
imshow(s2);
title("After Median Filter");