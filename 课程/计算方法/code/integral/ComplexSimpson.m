function [result] = ComplexSimpson(x_LowBound, x_Up_Bound,n)
% simpson�����ʽ
% Inputs:
%        x_LowBound:���������½�
%        x_UpBound :���������Ͻ�
%        n         ���ȷ�����,��ҪΪ2n�ȷ֣����ڵ������������2n+1
% Outputs:
%        result    : ����Simpson���ֽ��

% �жϻ�����������Ƿ���2�ı�������������м��㣬�����ӡ��ʾ
if mod(n,2) == 0
    % ��ȡ����h
    step_length = (x_Up_Bound - LowBound)/n;
    %�ۻ�����
    result = 0;
    for i = 1:2:n-1
        result = result + CalcuFunctionValue(x_LowBound+step_length*(i-1))...
                 +4*CalcuFunctionValue(x_LowBound+step_length*i)...
                 +CalcuFunctionValue(x_LowBound+step_length*(i+1));
    end % ѭ������
    result = result*step_length/6;
else
??? print('�ȷ�����������');
end % if�жϽ���
end % ��������