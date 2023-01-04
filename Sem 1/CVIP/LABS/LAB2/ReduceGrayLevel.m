close all;
clear;
clc;
pkg load image;

img = imread("sodhaparmarnihar.jpeg");
grayImg = rgb2gray(img);

k = 8;
figure
while (k > 0)
 target_levels = 2^k;
 target_compr_factor = 256 / target_levels;
 reduced_image = uint8(floor(double(grayImg)/256 * target_levels) * target_compr_factor);
 subplot(3, 3, k);
 imshow(reduced_image, [0 255]);
 title(['Grey-level resolution 2^',num2str(k)]);
 k = k - 1;
end

