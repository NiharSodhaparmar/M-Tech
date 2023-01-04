function out = my_standard_box_filter_padding(img,m,n)
  window = (1/m/n)*ones(m,n);
  [M,N]=size(img);
  a1=(m-1)/2;
  b1=(n-1)/2;
  new=zeros(M+2*a1,N+2*b1);
  new(1+a1:M+a1,1+b1:N+b1)=img;
  
  temp = img(1,:);
  for i=1:a1
    new(i,b1+1:N+b1) = temp;
  endfor
  
  temp = img(M,:);
  for i=a1+M+1:M+(2*a1)
    new(i,b1+1:N+b1) = temp;
  endfor
  
  temp = img(:,1);
  for i=1:b1
    new(a1+1:M+a1,i) = temp;
  endfor
  
  temp = img(:,N);
  for i=b1+N+1:N+(2*b1)
    new(a1+1:M+a1,i) = temp;
  endfor
  
  for i=1+a1:M+a1
    for j=1+b1:N+b1
      k=new(i-a1:i+a1,j-b1:j+b1);
      out(i-a1,j-b1)=sum(sum(k.*window));
    endfor
  endfor
  out = uint8(out);
endfunction