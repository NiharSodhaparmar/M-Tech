function s=highcont(r)
  
  a=im2double(r);
  rmin=min(min(a));
  rmax=max(max(a));

  smax=255/255;
  smin=0/255;
  s=(smax-smin)/(rmax-rmin)*(a-rmin) +smin;
endfunction