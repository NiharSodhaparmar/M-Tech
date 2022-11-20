pkg load image;
r1 = imread("./pepper_noise.jpeg");
subplot(1,2,1);
imshow(r1);
title("Image with pepper noise");

s1 = my_contra_harmonic_mean_filter(r1,5,5,-1);
subplot(1,2,2);
imshow(s1);
title("Q - Value for pepper noise");

figure;
r2 = imread("./salt_noise.jpeg");
subplot(1,2,1);
imshow(r2);
title("Image with salt noise");

s2 = my_contra_harmonic_mean_filter(r2,5,5,-1);
subplot(1,2,2);
imshow(s2);
title("Q - Value for salt noise");

figure;
r3 = imread("./salt_and_pepper_noise.jpeg");
subplot(1,2,1);
imshow(r3);
title("Image with salt & pepper noise");

s3 = my_contra_harmonic_mean_filter(r3,5,5,-1);
subplot(1,2,2);
imshow(s3);
title("Q - Value for salt & pepper noise");