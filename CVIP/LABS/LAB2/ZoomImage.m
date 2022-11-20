close all;
clear;
clc;

img = imread("sodhaparmarnihar.jpeg");
b = im2double(rgb2gray(img));

s=size(b);
c = [];
d = [];
zoomFactor = 2;

for n=1:s(1,1)
    for p=1:zoomFactor
        c=[c;b(n,:)];
    end
end


for m=1:s(1,2)
    for p=1:zoomFactor
        d=[d,c(:,m)];
    end
end

figure;
subplot(1,2,1);
imshow(b);
subplot(1,2,2);
imshow(d);
