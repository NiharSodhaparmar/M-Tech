function s= lowcont(r)
  a = im2double(r);
  rmin = min(min(r));
  rmax = max(max(r));
  smin = 70/255;
  smax = 100/255;
  s = (smax-smin)/(rmax-rmin)*(r-rmin)+smin;
endfunction
