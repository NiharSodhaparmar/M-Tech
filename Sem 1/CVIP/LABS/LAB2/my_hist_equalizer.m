function [out_image,frequncy_vector,equilze_vector_s] = my_hist_equalizer(input_image)
  img = input_image;
  [m,n] = size(img);
  L=256;
  %find frequncy_vector out intensity range is [0,255]
  fv = zeros(1,L);
  for i=1:L
    fv(1,i) = sum(sum(img == (i-1)));
  endfor
  frequncy_vector = fv;
  %find PDF for each intensity
  PDF = fv/(m*n);
  %find a equilze_vector_s
  s = zeros(1,L);
  for i=1:L
    temp = 0;
    for j=1:i
      temp = temp + PDF(1,j);
    endfor
    s(1,i) = round((L-1)*temp);
  endfor
  equilze_vector_s = s;

  %create final image
  final = zeros(m,n);
  for i=0:255
    final = final + (img==i)*s(1,i+1);
  endfor
  finalImg = uint8(final);
  out_image = finalImg;
endfunction
