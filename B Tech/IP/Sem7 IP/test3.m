clear
clc

a=imread('G:\My Pic\n.jpg');

%r=a(:,:,1);
%g=a(:,:,2);
%b=a(:,:,3);

%figure
%imshow(a)
%figure
%imshow(r)
%figure
%imshow(g)
%figure
%imshow(b)

%b=rgb2gray(a);
%figure
%imshow(b)

title("bw")
b=rgb2gray(a);
imwrite(b,"test.jpg");
b=double(b)/255;
c=im2bw(b,0.3);
figure
imshow(b)

e=imresize(b,[256,256]);
figure
imshow(e)

size(e)

subplot(2,2,1);
imshow(a)
subplot(2,2,2);
imshow(b)
subplot(2,2,3);
imshow(c)
subplot(2,2,4);
imshow(e)

%iminfo
