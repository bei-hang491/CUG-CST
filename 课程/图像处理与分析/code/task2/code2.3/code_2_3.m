%�ö����任����С�Ҷ�ͼ��̬��Χ

I=imread('jx.png');                 %��ͼ��������I
I1=double(I);                       %˫���Ȼ�
I2=im2double(I);                    %ͼ��Ҷ�ֵ˫���Ȼ�
I3=mat2gray(log(I1+1));             %�����任����ͼ��ĻҶȷ�Χ�任Ϊ[0,1]

%�����任��Сǰ���ͼ���ֱ��ͼ
subplot(2,2,1),imshow(I),title('ԭͼ');
subplot(2,2,2),imhist(I2),title('ԭͼֱ��ͼ');
subplot(2,2,3),imshow(I3),title('�����任��С���ͼ��');
subplot(2,2,4),imhist(I3),title('�����任��С��ֱ��ͼ');