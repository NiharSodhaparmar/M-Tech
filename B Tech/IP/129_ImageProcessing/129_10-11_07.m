pkg load image;
r = rgb2gray(imread("./1.jpeg"));
r = imresize(r,[1024,1024]);
r = im2double(r);

figure;

#Prewitt Filter
x = [-1,-1,-1;0,0,0;1,1,1];
y = [-1,0,1;-1,0,1;-1,0,1];

#without Smoothing
bx = my_filter(r,x);
by = my_filter(r,y);

m = abs(bx) + abs(by);

subplot(2,2,1);
imshow(m);
title("Gradient Magnitude without Smoothing(Prewitt)");

alpha = atan(by./bx);

subplot(2,2,2);
imshow(alpha);
title("Angle without Smoothing(Prewitt)");

#with Smoothing
r1 = my_filter(r,ones(5)*(1/25));
bx = my_filter(r1,x);
by = my_filter(r1,y);

m = abs(bx) + abs(by);

subplot(2,2,3);
imshow(m);
title("Gradient Magnitude with Smoothing(Prewitt)");

alpha = atan(by./bx);
subplot(2,2,4);
imshow(alpha);
title("Angle with Smoothing(Prewitt)");

figure;

#Sobel Filter
x = [-1,-2,-1;0,0,0;1,2,1];
y = [-1,0,1;-2,0,2;-1,0,1];

#without Smoothing
bx = my_filter(r,x);
by = my_filter(r,y);

m = abs(bx) + abs(by);

subplot(2,2,1);
imshow(m);
title("Gradient Magnitude without Smoothing(Sobel)");

alpha = atan(by./bx);

subplot(2,2,2);
imshow(alpha);
title("Angle without Smoothing(Sobel)");

#with Smoothing
r2 = my_filter(r,ones(5)*(1/25));
bx = my_filter(r2,x);
by = my_filter(r2,y);

m = abs(bx) + abs(by);

subplot(2,2,3);
imshow(m);
title("Gradient Magnitude with Smoothing(Sobel)");

alpha = atan(by./bx);

subplot(2,2,4);
imshow(alpha);
title("Angle with Smoothing(Sobel)");