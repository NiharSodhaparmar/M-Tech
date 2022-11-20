function s=my_adaptive_median_filter(r,m,n)
[M,N]=size(r);
a=(m-1)/2;
b=(n-1)/2;
new_imsize = zeros(M+2*a,N+2*b);
new_imsize(1+a:M+a,1+b:N+b)= r;
s = zeros(size(r));
for i=1+a:M+a,
  for j=1+b:N+b,
    ws=3;
    smax=9;
    k=new_imsize(i-a:i+a,j-b:j+b);
    z_med = median(median(k));
    z_min = min(min(k));
    z_max = max(max(k));
    A1 = z_med-z_min;
    A2 = z_med-z_max;
    flag=0;
    while(not(A1>0 && A2<0))
      ws=ws+2;
      new_a=(ws-1)/2;
      new_b=(ws-1)/2;
      if(ws>smax)
        flag=1;
        break;
      endif
      k=new_imsize(i-new_a:i+new_a,j-new_b:j+new_b);
      z_med = median(median(k));
      z_min = min(min(k));
      z_max = max(max(k));
      A1 = z_med-z_min;
      A2 = z_med-z_max;     
    endwhile
    if(flag==1)
      s(i-a,j-b)=new_imsize(i,j);
    else
      B1 = new_imsize(i,j)-z_min;
      B2 = new_imsize(i,j)-z_max;
      if(B1>0 && B2<0),
        s(i-a,j-b)=new_imsize(i,j);
      else
        s(i-a,j-b)=z_med;
      endif      
    endif
  endfor
endfor
s=uint8(s);
endfunction