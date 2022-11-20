ra = imread("./salt_pepper_random_prob.jpeg");
imshow(ra);
title("Original Image");

figure;

#Arithmetic filter
s1 = my_arithmetic_mean_filter(ra,3,3);
subplot(2,2,1);
imshow(s1);
title("3 x 3");

s2 = my_arithmetic_mean_filter(ra,5,5);
subplot(2,2,2);
imshow(s2);
title("5 x 5");

s3 = my_arithmetic_mean_filter(ra,7,7);
subplot(2,2,3);
imshow(s3);
title("7 x 7");

s4 = my_arithmetic_mean_filter(ra,9,9);
subplot(2,2,4);
imshow(s4);
title("9 x 9");

figure;

rb = imread("./salt_noise.jpeg");
imshow(rb);
title("Original Image");

figure;

#Geometric filter
s1 = my_geometric_mean_filter(rb,3,3);
subplot(2,2,1);
imshow(s1);
title("3 x 3");

s2 = my_geometric_mean_filter(rb,5,5);
subplot(2,2,2);
imshow(s2);
title("5 x 5");

s3 = my_geometric_mean_filter(rb,7,7);
subplot(2,2,3);
imshow(s3);
title("7 x 7");

s4 = my_geometric_mean_filter(rb,9,9);
subplot(2,2,4);
imshow(s4);
title("9 x 9");