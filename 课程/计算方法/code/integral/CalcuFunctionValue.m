%����x��Ӧ�ĺ���ֵf(x)
function [y_x] = CalcuFunctionValue(x)
% inputs:
%        x:����ֵ
% outputs:
%        y_x:x��Ӧ�ĺ���ֵ

% ���ݼ��޼��㣬��x��0ʱ��y_x��1.
if x == 0
    y_x = 1;
else
    y_x = sin(x)/x;
end
end