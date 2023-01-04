clc;
clear;
close all;
pkg load image;

img = rgb2gray(imread('./myImage.jpg'));
subplot(2,3,1);imshow(img);title("Original Image");

F = fft2(img);
subplot(2,3,2);imshow(F);title("FFT Image");

FShift = fftshift(F);
subplot(2,3,3);imshow(FShift);title("FFT Shift Image");

[M, N]=size(img);
H = zeros(M,N);
D0=50;
for i=1:M
  for j=1:N
    D=sqrt((i-M/2)^2+(j-N/2)^2);
    if(D<=D0)
      H(i,j)=1;
    else
      H(i,j)=0;
    endif
  endfor
endfor

subplot(2,3,4);imshow(H);title("Mask");

GShift=FShift.*H;
subplot(2,3,5);imshow(GShift);title("Applied Mask");

G = ifftshift(GShift);
FilteredImg = ifft2(G);
subplot(2,3,6);imshow(FilteredImg);title("Low Pass Filtered Image");
