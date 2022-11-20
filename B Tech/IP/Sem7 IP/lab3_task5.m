% Intensity slicing

a = imread('E:\SEM 7\IP\lab3images\3.tif');
[m,n] = size(a);
a = im2double(a);
%b=zeros(m,n);
for i=1:m
  for j=1:n
    if(a(i,j)>150/255 && a(i,j)<240/255)
      b(i,j)=a(i,j);
     else
      b(i,j)=0;
     endif
  endfor
endfor
figure
imshow(b)