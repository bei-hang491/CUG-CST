%�����Ա任����ǿ�Ҷ�ͼ��

I=imread('jx.png');                     %��ͼ��������I
I1=im2double(I);                        %ͼ��Ҷ�ֵ˫���Ȼ�
I2=imadjust(I1,stretchlim(I1),[0 1]);   %ͨ��stretchlim����Ӧ�ҵ��ָ���ֵ�����Ҷȷ�Χ���쵽[0 1]

%��ʾ��ǿǰ���ͼ���ֱ��ͼ
subplot(2,2,1),imshow(I),title('ԭͼ');
subplot(2,2,2),imhist(I1),title('ԭͼֱ��ͼ');
subplot(2,2,3),imshow(I2),title('��ǿ���ͼ��');
subplot(2,2,4),imhist(I2),title('��ǿ��ֱ��ͼ');