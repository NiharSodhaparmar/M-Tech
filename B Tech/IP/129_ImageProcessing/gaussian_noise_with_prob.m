function noisy = gaussian_noise_with_prob(img,sigma,mean,prob)
  [M,N]=size(img);
  mask = rand(M,N)<prob;
  n = round(sigma*randn(M,N))+mean;
  n = n.*mask;
  noisy = img+n;
endfunction
