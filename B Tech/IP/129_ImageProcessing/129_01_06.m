clear
clc
% Read image into a
a=imread('./n.jpg');

% Gray scale image
b=rgb2gray(a);
figure
imshow(b)

% Black and white image
%c=double(b)/255;
c=im2bw(b);
figure
imshow(c)

% Over Exposed image
d=b+60;
figure
imshow(d)

% Under Exposed image
d=b-50;
figure
imshow(d)

% face only-crop rest of the image
f=imcrop(a,[370 35 565 620]);
figure
imshow(f)

% Resize the image to 256*256.
g=imresize(a,[256,256]);
figure
imshow(g)