pkg load image;
r = rgb2gray(imread('./my.jpeg'));
subplot(2,3,1);
imshow(r);
title("Original Image");

[m,n]=size(r);
M=2*m;
N=2*n;
pad=zeros(M,N);
pad(1:m,1:n)=r;

subplot(2,3,2);
imshow(uint8(pad));
title("1");

for i=1:M
  for j=1:N
    pad(i,j)=pad(i,j)*(-1)^(i-1+j-1);
  endfor
endfor

subplot(2,3,3);imshow(uint8(pad));title("2");

F = fft2(pad);
H = zeros(M,N);
D0=40;
order=2;
u=[100,-100];
v=[0,0];
for i=1:M,
  for j=1:N,
    H(i,j)=1;
    for k =1:2,      
      D1=sqrt((i-(M/2)-u(k))^2+(j-(N/2)-v(k))^2);
      D2=sqrt((i-(M/2)+u(k))^2+(j-(N/2)+v(k))^2);
      t1=1/(1+power(D0/D1,2*order));
      t2=1/(1+power(D0/D2,2*order));
      H(i,j)=H(i,j)*t1*t2;    
    endfor  
  endfor
endfor
H = 1-H;

subplot(2,3,4);imshow(H);title("3");

G=H.*F;
Gp = real(ifft2(G));
for i=1:M,
  for j=1:N,
    st(i,j)=Gp(i,j)*(-1)^(i-1+j-1);
  endfor
endfor

subplot(2,3,5);imshow(uint8(st));title("4");

subplot(2,3,6);s=st(1:m,1:n);
imshow(uint8(s));title("Final Result");
