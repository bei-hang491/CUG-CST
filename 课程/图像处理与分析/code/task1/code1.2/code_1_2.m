%��ͼ�������������
I=imread('bg.png');

I1=rgb2gray(I);
subplot(2,3,1),imshow(I1),title('8���أ�256����');

I2=double(I1); %��ʾ��ֵ��I2��ֵ�������ã���Ҳ����ô���õģ����ϵĴ���Ӧ���е�����
I2=round(I1/4)*4;
subplot(2,3,2),imshow(uint8(I2)),title('6����(64��)');

I3=round(I1/16)*16;
subplot(2,3,3),imshow(uint8(I3)),title('6����(64��)');

I4=round(I1/32)*32;
subplot(2,3,4),imshow(uint8(I4)),title('4����(16��)');

I5=round(I1/64)*64;
subplot(2,3,5),imshow(uint8(I5)),title('2����(4��)');

I6=round(I1/128)*128;
subplot(2,3,6),imshow(uint8(I6)),title('1����(2��)');