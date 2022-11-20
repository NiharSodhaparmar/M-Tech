clear all
clc
close all

pkg load image

board = uint8(zeros(64,64));

block = 0;
blockm = 8,blockn = 8; 
mr=1,nr=8;
mc=1,nc=8;
black = 50,white = 170;

for ib=1:8 %block row
  for jb=1:8 %block coloum
    if(mod(block,2)==0)
         board(mr:nr,mc:nc)= white;
    elseif(mod(block,2)==1)
        board(mr:nr,mc:nc)=black;            
    endif
    mc = mc+blockm;
    nc = nc+blockn;
    block = block+1;
  endfor
  block = block-1;
  mc=1;
  nc=8;
  mr = mr+blockm;
  nr = nr+blockn;
endfor

img = board;
subplot(2,3,1)
imshow(img)
title("Chess Board");
subplot(2,3,4)
stem(0:255,imhist(img));
title("Histogram of Chess Board");

[M,N] = size(img);

a=0.5;
b=19;

%gamma noise

k=-1/a;
n=zeros(M,N);
for i=1:b
  n=n+k*log(1-rand(M,N));
endfor

noisy = img+n;
subplot(2,3,2)
imshow(noisy);
title("Noisy Gamma");
subplot(2,3,5)
stem(0:255,imhist(noisy));
title("Histogram of Noisy Gamma.");

%exponential noise;
k=-1/a;
n=k*log(1-rand(M,N));

noisy = img+n;
subplot(2,3,3)
imshow(noisy);
title("Noisy Exponential");
subplot(2,3,6)
stem(0:255,imhist(noisy));
title("Histogrm of Noisy Expo.");