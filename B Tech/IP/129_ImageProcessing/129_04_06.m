clc
clear
close all

r = imread("./after_first_histogram_equlization.jpg");
spec = imread("./test4.jpg");

%Original image
figure;
imshow(r);
%histogram of input images
figure;
subplot(1,3,1);
imhist(r(:,:,1));
title("r histogram original");
subplot(1,3,2);
imhist(r(:,:,2));
title("g histogram original");
subplot(1,3,3);
imhist(r(:,:,3));
title("b histogram original");

%Specific image
figure;
imshow(spec);
%histogram of input images
figure;
subplot(1,3,1);
imhist(spec(:,:,1));
title("r histogram specific");
subplot(1,3,2);
imhist(spec(:,:,2));
title("g histogram specific");
subplot(1,3,3);
imhist(spec(:,:,3));
title("b histogram specific");

%final image
final(:,:,1) = MyHistMatcher(r(:,:,1),spec(:,:,1));
final(:,:,2) = MyHistMatcher(r(:,:,2),spec(:,:,2));
final(:,:,3) = MyHistMatcher(r(:,:,3),spec(:,:,3));
figure;
imshow(final);

%histogram of final image
figure;
subplot(1,3,1);
imhist(final(:,:,1));
title("r histogram final");
subplot(1,3,2);
imhist(final(:,:,2));
title("g histogram final");
subplot(1,3,3);
imhist(final(:,:,3));
title("b histogram final");