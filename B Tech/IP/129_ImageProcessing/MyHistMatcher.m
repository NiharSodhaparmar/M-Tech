function output_image = MyHistMatcher(input_image,specific_image)
  rImg = input_image;
  spImg = specific_image;

  [m,n] = size(rImg);
  [final1,r_fv,r_s1] = MyHistEqulizer(rImg);
  [final2,sp_fv,sp_g1] = MyHistEqulizer(spImg);

  L=256;

  for i=0:(L-1)
    [value,index(i+1)] = min(abs(sp_g1-r_s1(i+1)));
  endfor

  index = index-1;

  final = zeros(m,n);
  for i=0:(L-1);
    final = final+(rImg == i)*index(i+1);
  endfor
  finalImg = uint8(final);
  output_image = uint8(finalImg);
endfunction
