function s = my_homomorphic_filter(r,d0,N)
  log_img = log(0.001+im2double(r));
  high_pass_img  = my_butter_worth_filter(log_img,d0,N);
  s = exp(high_pass_img);
endfunction
