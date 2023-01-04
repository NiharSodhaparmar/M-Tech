close all
clear
clc

% Read Image
a = imread('./image1.jpg');
figure
imshow(a)
[m,n,p] = size(a);

%b=zeros(m,n);
for i=1:m
  for j=1:n
    if(j<481 || j>762)
      if((a(i,j,1)<150 && a(i,j,2)>150 && a(i,j,3)<100) 
        || (a(i,j,1)>195 && a(i,j,2)<125 && a(i,j,3)<110))
          b(i,j)=1;
      else
          b(i,j)=0;
      endif
    endif
  endfor
endfor

figure
imshow(b)

final = a .* b;
figure
imshow(final)