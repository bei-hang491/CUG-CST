function [result] = ComplexTrap( x_LowBound, x_Up_Bound,n)
% Inputs:
%        x_LowBound:���������½�
%        x_UpBound :���������Ͻ�
%        n         ���ȷ�����
% Outputs:
%        result    : �������λ��ֽ��

% ��ȡ����h
step_length = (x_Up_Bound - LowBound)/n;
%�ۻ�����
result = 0;
for i = 1:n-1
    result = result + CalcuFunctionValue(x_LowBound+step_length*(i-1))+CalcuFunctionValue(x_LowBound+step_length*i);
end % ѭ������
result = result * step_length / 2;
end % ��������