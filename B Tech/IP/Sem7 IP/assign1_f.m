clear
clc

% Read image into a
a=imread('G:\My Pic\n.jpg');

% flip your image vertically
b=flipud(a); 
figure
imshow(b);

% create the mirror image
c=fliplr(a);  %c=flip(a,2);
figure
imshow(c);

% rotate the image by 90 degree
d=imrotate(a,90);
figure
imshow(d);

% rotate the image by 270 degree
e=imrotate(a,270);
figure
imshow(e);

figure
subplot(2,2,1);
imshow(b)
subplot(2,2,2);
imshow(c)
subplot(2,2,3);
imshow(d)
subplot(2,2,4);
imshow(e)