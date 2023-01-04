function out = my_weighted_box_filter(img,window)
  [m,n] = size(window);
  [M,N]=size(img);
  a=(m-1)/2;
  b=(n-1)/2;
  new=zeros(M+2*a,N+2*b);
  new(1+a:M+a,1+b:N+b)=img;

  for i=1+a:M+a
    for j=1+b:N+b
      k=new(i-a:i+a,j-b:j+b);
      out(i-a,j-b)=sum(sum(k.*window));
    endfor
  endfor

  out = uint8(out);
endfunction