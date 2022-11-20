f = [1,0,0,1];

# 1-D Discrete Fourier Transform
[S,M] = size(f);
F = zeros(S,M);
for i=1:M,
   for k=1:M
     F(i) = F(i)+f(k)*e.^(-j*2*pi*((i-1)*(k-1))/M);
   endfor
endfor

# 1-D Inverse Discrete Fourier Transform
[IS,IM] = size(F);
inverse_f = zeros(IS,IM);
for i=1:IM,
  for k=1:IM,
    inverse_f(i) = inverse_f(i)+F(k)*e.^(j*2*pi*((k-1)*(i-1)/M));
  endfor
  inverse_f(i) = (1/IM)*(inverse_f(i));
endfor
