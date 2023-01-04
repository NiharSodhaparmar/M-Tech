function noisy = salt_and_pepper_noise(img,prob)
  [M,N]=size(img);
  for i=1:(M*N*prob)
    p = round(1+(M-1)*rand());
    q = round(1+(N-1)*rand());
    if(round(rand()) == 0)
      img(p,q) = 255;
    else
      img(p,q) = 0;      
    endif    
  endfor
  noisy = img;
endfunction