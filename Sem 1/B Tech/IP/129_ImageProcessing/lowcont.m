function s = lowcont(r)
  
  a = im2double(r);
  rmax = max(max(a));
  rmin = min(min(a));
  
  smax = 180/255;
  smin = 70/255;
  s = (smax-smin)/(rmax-rmin) * (a-rmin)+smin;
  
endfunction