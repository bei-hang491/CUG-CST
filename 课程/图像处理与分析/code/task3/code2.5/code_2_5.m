% ֱ��ͼ���⻯
I=imread('jx.png');  %����Ҷ�ͼ��
[I1,T] = histeq(I);  %ֱ��ͼ���⻯

%��ʾ��ǿǰ���ͼ���ֱ��ͼ
subplot(2,3,1),imshow(I),title('ԭͼ');
subplot(2,3,2),imhist(I),title('ԭͼֱ��ͼ');
subplot(2,3,[3 6]),plot((0:255)/255,T),title('�任����');
subplot(2,3,4),imshow(I1),title('���⻯���ͼ��');
subplot(2,3,5),imhist(I1),title('���⻯���ֱ��ͼ');