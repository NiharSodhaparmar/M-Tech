function s = my_contra_harmonic_mean_filter(r,m,n,Q)
[M,N]=size(r);
a=(m-1)/2;
b=(n-1)/2;
new_imsize = zeros(M+2*a,N+2*b);
new_imsize(1+a:M+a,1+b:N+b)= r;
s = zeros(size(r));
for i=1+a:M+a,
  for j=1+b:N+b,
	k = new_imsize(i-a:i+a,j-b:j+b);
	numerator = (sum(sum(k))).^(Q+1);
	denominator = (sum(sum(k.^(Q))));
  if(k==0)
    s(i-a,j-b)=0;
  elseif(Q<0)
	  s(i-a,j-b)=(m*n)*(numerator/denominator);
  elseif(Q>0)
    s(i-a,j-b)=(numerator/denominator)/(m*n);
  elseif(Q==0)
    s(i-a,j-b)=(numerator/denominator);
  endif
  endfor
endfor
s = uint8(s);
endfunction