% ͼ��ļӼ��˳�
I=imread('jx.png');  %����Ҷ�ͼ��

% ��ͼ��ĻҶ�ֵ���мӼ��˲���
Add_I = imadd(I,80);
Sub_I = imsubtract(I,80);
Mul_I = immultiply(I,3);
Mul_I2 = immultiply(I,0.6);

% ��ʾԭͼ��������ͼ��
subplot(2,3,1),imshow(I),title('ԭͼ');
subplot(2,3,2),imshow(Add_I),title('+80 ͼ��');
subplot(2,3,5),imshow(Sub_I),title('-80 ͼ��');
subplot(2,3,3),imshow(Mul_I),title('x3 ͼ��');
subplot(2,3,6),imshow(Mul_I2),title('x0.6 ͼ��');