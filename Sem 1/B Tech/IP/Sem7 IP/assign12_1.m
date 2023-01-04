img = imread("gray_scale.jpg");
subplot(121)
imshow(img)
[m,n] = size(img);
img = img(m/2-1:m/2+1,n/2-1:n/2+1);
subplot(122)
imshow(img);
[m,n] = size(img);
L = 256;
for i = 0:L-1
  his(i+1) = sum(sum(img==i));
endfor
pdf = his/(m*n);
k = length(pdf);
start = 0;
span=1;
for i=1:m
  for t=1:n
   if mod(i,2)==0
      t = n-t+1;
   endif
  for j=1:k
    range(j+1)=start+pdf(j)*span;
    start=range(j+1);
  endfor
    start=range(img(i,t));
    span=range(img(i,t)+1)-start;
    range(1)=start;
  endfor
endfor
l = length(range);
code = (range(l)+range(l-1))/2;
code = round(code*100)/100;
code