function [J, grad] = costFunctionReg(theta, X, y, lambda)
%COSTFUNCTIONREG Compute cost and gradient for logistic regression with regularization
%   J = COSTFUNCTIONREG(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples
n = length(theta); % number of features + 1

% You need to return the following variables correctly 
J = 0;
grad = zeros(n, 1);

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta



A = log(sigmoid(X*theta))' * y;
B = log(1 - sigmoid(X*theta))' * (1 - y);
J = -(A+B)/m;
J = J + (lambda/(2*m)) * sum(theta(2:n) .^ 2);



grad(1) = (X(:, 1)' * (sigmoid(X*theta) - y))/m;
grad(2:n) = ((X(:, 2:n)' * (sigmoid(X*theta) - y))/m) + (lambda/m) * theta(2:n);

% Or in a pretty way:
% grad = ((X' * (sigmoid(X*theta) - y))/m) + (lambda/m) * theta;
% grad(1) = (X(:, 1)' * (sigmoid(X*theta) - y))/m;


% =============================================================

end

%   112 x 27
%   (27 x 112) * (112x1)
%   (27 x 1)/m = (27 x 1)
%   (27x1) + a*(27x1)