clc;
clear;
close all;
pkg load image;
r = rgb2gray(imread('./myImage.jpg'));

subplot(2,3,1);imshow(r);title("Original Image");
[m,n]=size(r);
M=2*m;
N=2*n;
pad=zeros(M,N);
pad(1:m,1:n)=r;
subplot(2,3,2);imshow(uint8(pad));title("Padded Image");

for i=1:M
  for j=1:N
    pad(i,j)=pad(i,j)*(-1)^(i-1+j-1);
  endfor
endfor

subplot(2,3,3);imshow(uint8(pad));title("-1^{x+y}");

F = fft2(pad);
H = zeros(M,N);
D0=50;
for i=1:M
  for j=1:N
    D=sqrt((i-M/2)^2+(j-N/2)^2);
    if(D<=D0)
      H(i,j)=0;
    else
      H(i,j)=1;
    endif
  endfor
endfor

subplot(2,3,4);imshow(H);title("Mask");

G=H.*F;
Gp = real(ifft2(G));
for i=1:M
  for j=1:N
    st(i,j)=Gp(i,j)*(-1)^(i-1+j-1);
endfor
endfor

subplot(2,3,5);imshow(real(G));title("Applied Mask");

subplot(2,3,6);s=st(1:m,1:n);
imshow(uint8(s));title("Ideal High Pass Filtered Image");
