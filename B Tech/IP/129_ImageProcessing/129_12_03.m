k=length(pdf);
start=0;
range=zeros(k+1,1);
span=1;
res=zeros(m,n);
total = 1;
figure
l=1
for i=1:m
  for t=1:n
    if mod(i,2)==0
      t = n-t+1;
    endif
    for j=1:k
      range(j+1)=start+pdf(j)*span;
      if(start<=code && range(j+1)>=code)
        res(i,t)=j;
        span=range(j+1)-start;
        break;
      endif
      start=range(j+1);
    endfor
    subplot(3,3,l)
    imshow(uint8(res))
    total+=1;
    l+=1;
  endfor
endfor
psnr = psnr(img,uint8(res))