r=imread("./salt_and_pepper_noise.jpeg");
r=imresize(r,[512,512]);
imshow(r);
title("Original Image");

figure;

s1 = my_median_filter(r,3,3);
subplot(2,2,1);
imshow(s1);
title("1");

for i=2:4,
  s1 = my_median_filter(s1,3,3);
  subplot(2,2,i);
  imshow(s1);
  title(i);
endfor

figure; 

s2 = my_median_filter(r,5,5);
subplot(2,2,1);
imshow(s2);
title("1");

for i=2:4
  s2 = my_median_filter(s2,5,5);
  subplot(2,2,i);
  imshow(s2);
  title(i);
endfor

figure; 

s3 = my_median_filter(r,7,7);
subplot(2,2,1);
imshow(s3);
title("1");

for i=2:4
  s3 = my_median_filter(s3,7,7);
  subplot(2,2,i);
  imshow(s3);
  title(i);
endfor

figure; 

s4 = my_median_filter(r,9,9);
subplot(2,2,1);
imshow(s4);
title("1");

for i=2:4
  s4 = my_median_filter(s4,9,9);
  subplot(2,2,i);
  imshow(s4);
  title(i);
endfor