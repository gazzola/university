function out = mapFeature(X1, X2)
% MAPFEATURE Feature mapping function to polynomial features
%
%   MAPFEATURE(X1, X2) maps the two input features
%   to quadratic features used in the regularization exercise.
%
%   Returns a new feature array with more features, comprising of 
%   X1, X2, X1.^2, X2.^2, X1*X2, X1*X2.^2, etc..
%
%   Inputs X1, X2 must be the same size
%

degree = 6;
out = ones(size(X1(:,1)));
for i = 1:degree
    for j = 0:i
        out(:, end+1) = (X1.^(i-j)).*(X2.^j);
    end
end


% MY OTHER FEATURES:
% out = ones(size(X1(:,1)));
% out(:, 2) = X1;
% out(:, 3) = X2;
% out(:, 4) = X1 .^ 2;
% out(:, 5) = X2 .^ 2;
% out(:, 6) = (X1 .^ 2) + (X2 .^ 2);


end