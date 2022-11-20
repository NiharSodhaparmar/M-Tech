function s = my_butter_worth_filter(r,d0,N)
  [m,n]=size(r);
  p=2*m;
  q=2*n;
  pad=zeros(p,q);
  pad(1:m,1:n)=im2double(r);  
  for i=1:p
    for j=1:q
      pad(i,j)=pad(i,j)*(-1)^(i-1+j-1);
    endfor
  endfor
  
  fta = fft2(pad);
  filt = zeros(p,q);
  for i=1:p
    for j=1:q
      d=sqrt((i-p/2)^2+(j-q/2)^2);
      denominator = 1+((d0/d)^(2*N));
      filt(i,j) = 1/denominator;  
    endfor
  endfor
  
  g=fta.*filt;
  sg = real(ifft2(g));
  for i=1:p
    for j=1:q
      t(i,j)=sg(i,j)*(-1)^(i-1+j-1);
    endfor
  endfor
  
  s=t(1:m,1:n);
endfunction